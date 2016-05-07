/****************************************************************************
Copyright (c) 2010-2013 cocos2d-x.org

http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/

#include "CCFileUtils.h"
#include "CCDirector.h"
#include "cocoa/CCDictionary.h"
#include "cocoa/CCString.h"
#include "CCSAXParser.h"
#include "support/tinyxml2/tinyxml2.h"
#include "support/zip_support/unzip.h"
#include <stack>

using namespace std;

#if (CC_TARGET_PLATFORM != CC_PLATFORM_IOS) && (CC_TARGET_PLATFORM != CC_PLATFORM_MAC)

NS_CC_BEGIN

typedef enum 
{
    SAX_NONE = 0,
    SAX_KEY,
    SAX_DICT,
    SAX_INT,
    SAX_REAL,
    SAX_STRING,
    SAX_ARRAY
}CCSAXState;

typedef enum
{
    SAX_RESULT_NONE = 0,
    SAX_RESULT_DICT,
    SAX_RESULT_ARRAY
}CCSAXResult;

class CCDictMaker : public CCSAXDelegator
{
public:
    CCSAXResult m_eResultType;
    CCArray* m_pRootArray;
    CCDictionary *m_pRootDict;
    CCDictionary *m_pCurDict;
    std::stack<CCDictionary*> m_tDictStack;
    std::string m_sCurKey;   ///< parsed key
    std::string m_sCurValue; // parsed value
    CCSAXState m_tState;
    CCArray* m_pArray;

    std::stack<CCArray*> m_tArrayStack;
    std::stack<CCSAXState>  m_tStateStack;

public:
    CCDictMaker()        
        : m_eResultType(SAX_RESULT_NONE),
          m_pRootArray(NULL), 
          m_pRootDict(NULL),
          m_pCurDict(NULL),
          m_tState(SAX_NONE),
          m_pArray(NULL)
    {
    }

    ~CCDictMaker()
    {
    }

    CCDictionary* dictionaryWithContentsOfFile(const char *pFileName)
    {
        m_eResultType = SAX_RESULT_DICT;
        CCSAXParser parser;

        if (false == parser.init("UTF-8"))
        {
            return NULL;
        }
        parser.setDelegator(this);

        parser.parse(pFileName);
        return m_pRootDict;
    }

    CCArray* arrayWithContentsOfFile(const char* pFileName)
    {
        m_eResultType = SAX_RESULT_ARRAY;
        CCSAXParser parser;

        if (false == parser.init("UTF-8"))
        {
            return NULL;
        }
        parser.setDelegator(this);

        parser.parse(pFileName);
        return m_pArray;
    }

    void startElement(void *ctx, const char *name, const char **atts)
    {
        CC_UNUSED_PARAM(ctx);
        CC_UNUSED_PARAM(atts);
        std::string sName((char*)name);
        if( sName == "dict" )
        {
            m_pCurDict = new CCDictionary();
            if(m_eResultType == SAX_RESULT_DICT && m_pRootDict == NULL)
            {
                // Because it will call m_pCurDict->release() later, so retain here.
                m_pRootDict = m_pCurDict;
                m_pRootDict->retain();
            }
            m_tState = SAX_DICT;

            CCSAXState preState = SAX_NONE;
            if (! m_tStateStack.empty())
            {
                preState = m_tStateStack.top();
            }

            if (SAX_ARRAY == preState)
            {
                // add the dictionary into the array
                m_pArray->addObject(m_pCurDict);
            }
            else if (SAX_DICT == preState)
            {
                // add the dictionary into the pre dictionary
                CCAssert(! m_tDictStack.empty(), "The state is wrong!");
                CCDictionary* pPreDict = m_tDictStack.top();
                pPreDict->setObject(m_pCurDict, m_sCurKey.c_str());
            }

            m_pCurDict->release();

            // record the dict state
            m_tStateStack.push(m_tState);
            m_tDictStack.push(m_pCurDict);
        }
        else if(sName == "key")
        {
            m_tState = SAX_KEY;
        }
        else if(sName == "integer")
        {
            m_tState = SAX_INT;
        }
        else if(sName == "real")
        {
            m_tState = SAX_REAL;
        }
        else if(sName == "string")
        {
            m_tState = SAX_STRING;
        }
        else if (sName == "array")
        {
            m_tState = SAX_ARRAY;
            m_pArray = new CCArray();
            if (m_eResultType == SAX_RESULT_ARRAY && m_pRootArray == NULL)
            {
                m_pRootArray = m_pArray;
                m_pRootArray->retain();
            }
            CCSAXState preState = SAX_NONE;
            if (! m_tStateStack.empty())
            {
                preState = m_tStateStack.top();
            }

            if (preState == SAX_DICT)
            {
                m_pCurDict->setObject(m_pArray, m_sCurKey.c_str());
            }
            else if (preState == SAX_ARRAY)
            {
                CCAssert(! m_tArrayStack.empty(), "The state is wrong!");
                CCArray* pPreArray = m_tArrayStack.top();
                pPreArray->addObject(m_pArray);
            }
            m_pArray->release();
            // record the array state
            m_tStateStack.push(m_tState);
            m_tArrayStack.push(m_pArray);
        }
        else
        {
            m_tState = SAX_NONE;
        }
    }

    void endElement(void *ctx, const char *name)
    {
        CC_UNUSED_PARAM(ctx);
        CCSAXState curState = m_tStateStack.empty() ? SAX_DICT : m_tStateStack.top();
        std::string sName((char*)name);
        if( sName == "dict" )
        {
            m_tStateStack.pop();
            m_tDictStack.pop();
            if ( !m_tDictStack.empty())
            {
                m_pCurDict = m_tDictStack.top();
            }
        }
        else if (sName == "array")
        {
            m_tStateStack.pop();
            m_tArrayStack.pop();
            if (! m_tArrayStack.empty())
            {
                m_pArray = m_tArrayStack.top();
            }
        }
        else if (sName == "true")
        {
            CCString *str = new CCString("1");
            if (SAX_ARRAY == curState)
            {
                m_pArray->addObject(str);
            }
            else if (SAX_DICT == curState)
            {
                m_pCurDict->setObject(str, m_sCurKey.c_str());
            }
            str->release();
        }
        else if (sName == "false")
        {
            CCString *str = new CCString("0");
            if (SAX_ARRAY == curState)
            {
                m_pArray->addObject(str);
            }
            else if (SAX_DICT == curState)
            {
                m_pCurDict->setObject(str, m_sCurKey.c_str());
            }
            str->release();
        }
        else if (sName == "string" || sName == "integer" || sName == "real")
        {
            CCString* pStrValue = new CCString(m_sCurValue);

            if (SAX_ARRAY == curState)
            {
                m_pArray->addObject(pStrValue);
            }
            else if (SAX_DICT == curState)
            {
                m_pCurDict->setObject(pStrValue, m_sCurKey.c_str());
            }

            pStrValue->release();
            m_sCurValue.clear();
        }
        
        m_tState = SAX_NONE;
    }

    void textHandler(void *ctx, const char *ch, int len)
    {
        CC_UNUSED_PARAM(ctx);
        if (m_tState == SAX_NONE)
        {
            return;
        }

        CCSAXState curState = m_tStateStack.empty() ? SAX_DICT : m_tStateStack.top();
        CCString *pText = new CCString(std::string((char*)ch,0,len));

        switch(m_tState)
        {
        case SAX_KEY:
            m_sCurKey = pText->getCString();
            break;
        case SAX_INT:
        case SAX_REAL:
        case SAX_STRING:
            {
                if (curState == SAX_DICT)
                {
                    CCAssert(!m_sCurKey.empty(), "key not found : <integer/real>");
                }
                
                m_sCurValue.append(pText->getCString());
            }
            break;
        default:
            break;
        }
        pText->release();
    }
};

CCDictionary* CCFileUtils::createCCDictionaryWithContentsOfFile(const std::string& filename)
{
    std::string fullPath = fullPathForFilename(filename.c_str());
    CCDictMaker tMaker;
    return tMaker.dictionaryWithContentsOfFile(fullPath.c_str());
}

CCArray* CCFileUtils::createCCArrayWithContentsOfFile(const std::string& filename)
{
    std::string fullPath = fullPathForFilename(filename.c_str());
    CCDictMaker tMaker;
    return tMaker.arrayWithContentsOfFile(fullPath.c_str());
}

/*
 * forward statement
 */
static tinyxml2::XMLElement* generateElementForArray(cocos2d::CCArray *array, tinyxml2::XMLDocument *pDoc);
static tinyxml2::XMLElement* generateElementForDict(cocos2d::CCDictionary *dict, tinyxml2::XMLDocument *pDoc);

/*
 * Use tinyxml2 to write plist files
 */
bool CCFileUtils::writeToFile(cocos2d::CCDictionary *dict, const std::string &fullPath)
{
    //CCLOG("tinyxml2 CCDictionary %d writeToFile %s", dict->m_uID, fullPath.c_str());
    tinyxml2::XMLDocument *pDoc = new tinyxml2::XMLDocument();
    if (NULL == pDoc)
        return false;
    
    tinyxml2::XMLDeclaration *pDeclaration = pDoc->NewDeclaration("xml version=\"1.0\" encoding=\"UTF-8\"");
    if (NULL == pDeclaration)
    {
        delete pDoc;
        return false;
    }
    
    pDoc->LinkEndChild(pDeclaration);
    tinyxml2::XMLElement *docType = pDoc->NewElement("!DOCTYPE plist PUBLIC \"-//Apple//DTD PLIST 1.0//EN\" \"http://www.apple.com/DTDs/PropertyList-1.0.dtd\"");
    pDoc->LinkEndChild(docType);
    
    tinyxml2::XMLElement *pRootEle = pDoc->NewElement("plist");
    pRootEle->SetAttribute("version", "1.0");
    if (NULL == pRootEle)
    {
        delete pDoc;
        return false;
    }
    pDoc->LinkEndChild(pRootEle);
    
    tinyxml2::XMLElement *innerDict = generateElementForDict(dict, pDoc);
    if (NULL == innerDict )
    {
        delete pDoc;
        return false;
    }
    pRootEle->LinkEndChild(innerDict);
    
    bool bRet = tinyxml2::XML_SUCCESS == pDoc->SaveFile(fullPath.c_str());
    
    delete pDoc;
    return bRet;
}

/*
 * Generate tinyxml2::XMLElement for CCObject through a tinyxml2::XMLDocument
 */
static tinyxml2::XMLElement* generateElementForObject(cocos2d::CCObject *object, tinyxml2::XMLDocument *pDoc)
{
    // object is CCString
    if (CCString *str = dynamic_cast<CCString *>(object))
    {
        tinyxml2::XMLElement* node = pDoc->NewElement("string");
        tinyxml2::XMLText* content = pDoc->NewText(str->getCString());
        node->LinkEndChild(content);
        return node;
    }
    
    // object is CCArray
    if (CCArray *array = dynamic_cast<CCArray *>(object))
        return generateElementForArray(array, pDoc);
    
    // object is CCDictionary
    if (CCDictionary *innerDict = dynamic_cast<CCDictionary *>(object))
        return generateElementForDict(innerDict, pDoc);
    
    CCLOG("This type cannot appear in property list");
    return NULL;
}

/*
 * Generate tinyxml2::XMLElement for CCDictionary through a tinyxml2::XMLDocument
 */
static tinyxml2::XMLElement* generateElementForDict(cocos2d::CCDictionary *dict, tinyxml2::XMLDocument *pDoc)
{
    tinyxml2::XMLElement* rootNode = pDoc->NewElement("dict");
    
    CCDictElement *dictElement = NULL;
    CCDICT_FOREACH(dict, dictElement)
    {
        tinyxml2::XMLElement* tmpNode = pDoc->NewElement("key");
        rootNode->LinkEndChild(tmpNode);
        tinyxml2::XMLText* content = pDoc->NewText(dictElement->getStrKey());
        tmpNode->LinkEndChild(content);
        
        CCObject *object = dictElement->getObject();
        tinyxml2::XMLElement *element = generateElementForObject(object, pDoc);
        if (element)
            rootNode->LinkEndChild(element);
    }
    return rootNode;
}

/*
 * Generate tinyxml2::XMLElement for CCArray through a tinyxml2::XMLDocument
 */
static tinyxml2::XMLElement* generateElementForArray(cocos2d::CCArray *array, tinyxml2::XMLDocument *pDoc)
{
    tinyxml2::XMLElement* rootNode = pDoc->NewElement("array");
    
    CCObject *object = NULL;
    CCARRAY_FOREACH(array, object)
    {
        tinyxml2::XMLElement *element = generateElementForObject(object, pDoc);
        if (element)
            rootNode->LinkEndChild(element);
    }
    return rootNode;
}


#else
NS_CC_BEGIN

/* The subclass CCFileUtilsIOS and CCFileUtilsMac should override these two method. */
CCDictionary* CCFileUtils::createCCDictionaryWithContentsOfFile(const std::string& filename) {return NULL;}
bool CCFileUtils::writeToFile(cocos2d::CCDictionary *dict, const std::string &fullPath) {return NULL;}
CCArray* CCFileUtils::createCCArrayWithContentsOfFile(const std::string& filename) {return NULL;}

#endif /* (CC_TARGET_PLATFORM != CC_PLATFORM_IOS) && (CC_TARGET_PLATFORM != CC_PLATFORM_MAC) */

////////////////////////////////////////////////////////////////////////////////////////////////////////////

//PNG读取专用
#define LOBYTE(w)           ((unsigned char)(w))
#define HIBYTE(w)           ((unsigned char)(((unsigned short)(w) >> 8) & 0xFF))
#define MAKEWORD(hi, lo)    (((unsigned short)((unsigned char)(hi))<<8) + (unsigned short)((unsigned char)(lo)))
#define LOWORD(dw)          ((unsigned short)(dw))
#define HIWORD(dw)          ((unsigned short)(((unsigned int)(dw) >> 16) & 0xFFFF))
#define MAKELONG(hi, lo)    (((unsigned int)((unsigned short)(hi))<<16) + (unsigned int)((unsigned short)(lo)))


/* 下面的宏用于解决奇地址读写出错的问*/
/* 得到一16的数 */
#define READ_WORD(ptr)          MAKEWORD((*(unsigned char*)(ptr)), (*((unsigned char*)(ptr)+1)))
/* 向某地址中写入一16的数 */
#define WRITE_WORD(ptr, w)      do{ *(unsigned char*)(ptr) = LOBYTE(w); \
                                    *((unsigned char*)(ptr)+1) = HIBYTE(w); }while(0)

/* 得到一32的数 */
#define READ_DWORD(ptr)         MAKELONG(READ_WORD((unsigned char*)(ptr)), \
                                          READ_WORD(((unsigned char*)(ptr)+2)))
/* 向某地址中写入一32的数 */
#define WRITE_DWORD(ptr, dw)    do{ WRITE_WORD((ptr), LOWORD(dw));  \
                                    WRITE_WORD((unsigned char*)(ptr)+2, HIWORD(dw)); }while(0)

static unsigned char XOR_BUFFER[]=
{
    0x9d,0xF3,0x00,0x25,0xef,0x02,0x77,
    0xfd,0xe3,0x39,0xcd,0x02,0x98,0x67,
    0x25,0xDC,0x10,0x95,0x68,0x69,0x49,
    0x56,0x75,0x20,0x85,0x39,0x99,0xDF,
    0xF6,0x7E,0x70,0x95,0xe8,0xCC,0xEF,
    0x40,0x79,0x99,0xd1,0xae,0x76,0x9F,
};
static unsigned char XOR_END[]=
{
	0x39,0xcd,0x02,0x98,0x67,0x25
};
static char* XOR_KEY = "XYTEA";

static unsigned char XOR_BUFFER_GEN[42];

static void gen_key(char*shorname,unsigned char** ppKEY,unsigned int *keylen)
{
    int xorlen = sizeof(XOR_BUFFER)/sizeof(unsigned char);
    unsigned char*newKey = XOR_BUFFER_GEN;
    //unsigned char*newKey = (unsigned char*)malloc(xorlen);
    memcpy(newKey,XOR_BUFFER,xorlen);
    int buffsize = strlen(shorname);
    unsigned char* buff = (unsigned char* )shorname;
    for(int i=0;i<buffsize;i++)
    {
        if(shorname[i]=='_' && i!=buffsize-1)
        {
            buffsize = strlen(shorname+i+1);
            buff = (unsigned char* )(shorname+i+1);
            break;
        }
    }
    for(int i=0;i<xorlen && i<buffsize;i++)
    {
        newKey[i] = XOR_BUFFER[i]^(buff[i%buffsize]);
    }
    for(int i=xorlen-1,j=0;i>=0 && j<buffsize;i--,j++)
    {
        newKey[i] = XOR_BUFFER[i]^(buff[j%buffsize]);
    }
    * ppKEY = newKey;
    * keylen = xorlen;
}

static void xor_memory__(unsigned char* buff,unsigned int buffsize,unsigned char*KEY,int KEYLEN)
{
    int xorlen = KEYLEN;
    for(int i=0;i<buffsize;i++)
    {
        buff[i] = buff[i]^KEY[i%xorlen];
    }
}

static void xor_memory(unsigned char* buff,unsigned int buffsize,char*shorname)
{
//  int xorlen = sizeof(XOR_BUFFER)/sizeof(unsigned char);
//  xor_memory__(buff,buffsize,XOR_BUFFER,xorlen);
    unsigned char*key = 0;
    unsigned int keylen = 0;
    gen_key(shorname,&key,&keylen);
    xor_memory__(buff,buffsize,key,keylen);
}

static void xor_memory_end(unsigned char* buff,unsigned int buffsize)
{
	int xorlen = sizeof(XOR_END)/sizeof(unsigned char);
	for(int i=0;i<buffsize;i++)
	{
		buff[i] = buff[i]^XOR_END[i%xorlen];
	}
}

unsigned long CCFileUtils::dencypt_file(unsigned char*p_tmp,unsigned long filesize,char*shorname)
{
	bool ret;
	unsigned char PEND[20];
    int lena = strlen(XOR_KEY);
    int lenb = strlen(shorname);
    if(lena+lenb>20) lenb = 20-lena;    
    int lennn = lena+lenb;


    unsigned char *p_end= PEND;
	memset(p_end,0x00,lennn);
	memcpy(p_end,XOR_KEY,lena);
	memcpy(p_end+lena,shorname,lenb);
	xor_memory_end(p_end,lennn);
	//if no encrypt
	for(int i=1;i<=lennn;i++)
	{
		if(p_end[lennn-i]!=p_tmp[filesize-i])
		{
			return filesize;
		}
	}
	xor_memory(p_tmp,filesize-lennn,shorname);
	//more byte to 0
	for(int i=1;i<=lennn;i++)
	{
		p_tmp[filesize-i]=0x00;
	}
	return (unsigned long)filesize-lennn;
}

struct PNG_INFO
{   
    char a;
    char b;
    char c;
    char d;
    unsigned char*data;
    unsigned int datasz;
    unsigned int crc32;
    unsigned int cksize;
};
static PNG_INFO get_png_chuck(unsigned char*buff,int skip)
{
    PNG_INFO info;
    info.datasz = READ_DWORD(buff);
    info.data = (buff+8);
    info.crc32 = READ_DWORD(buff+8+info.datasz);
    info.a = (char)(*(buff+4));
    info.b = (char)(*(buff+5));
    info.c = (char)(*(buff+6));
    info.d = (char)(*(buff+7));
    info.cksize = info.datasz + 12;
    return info;
}


int deencypt_file_png_buff(const unsigned char*buff,unsigned int bufflen,char*shorname)
{
    if(shorname==NULL)
    {
        return 0;
    }
    if(strlen(shorname)==0)
    {
        return 0;
    }
    if(bufflen<12)
    {
        return 0;
    }
    unsigned char* pHead = (unsigned char*)buff;
    if (
        pHead[0] == 0x99
        && pHead[1] == 0x46
        && pHead[2] == 0xB8
        && pHead[3] == 0x0D

        && pHead[4] == 0x89
        && pHead[5] == 0x50
        && pHead[6] == 0x4E
        && pHead[7] == 0x47
        && pHead[8] == 0x0D
        && pHead[9] == 0x0A
        && pHead[10] == 0x1A
        && pHead[11] == 0x0A)
    {
        pHead = pHead+12;
        unsigned long skip = 8;
        int id=1;
        while(skip<bufflen)
        {
            PNG_INFO info = get_png_chuck(pHead,0);
            pHead = pHead + info.cksize;
            skip = skip + info.cksize;          
            //printf("==%d==--%c%c%c%c--%d\n",id,info.a,info.b,info.c,info.d,info.datasz);
            id = id + 1;
            if(info.a=='P' && info.b=='L' &&info.c=='T' &&info.d=='E')
            {
                xor_memory(info.data,info.datasz,shorname);
            }
            if(info.a=='I' && info.b=='D' &&info.c=='A' &&info.d=='T')
            {
                if(info.datasz<39)
                {
                    xor_memory(info.data,info.datasz,shorname);
                }
                else
                {
                    xor_memory(info.data,39,shorname);
                }
                break;
            }           
        }
        return 4;
    }
    else
    {
        return 0;
    }
}


////////////////////////////////////////////////////////////////////


CCFileUtils* CCFileUtils::s_sharedFileUtils = NULL;

void CCFileUtils::purgeFileUtils()
{
    CC_SAFE_DELETE(s_sharedFileUtils);
}

CCFileUtils::CCFileUtils()
: m_pFilenameLookupDict(NULL)
{
}

CCFileUtils::~CCFileUtils()
{
    CC_SAFE_RELEASE(m_pFilenameLookupDict);
}

bool CCFileUtils::init()
{
    m_searchPathArray.push_back(m_strDefaultResRootPath);
    m_searchResolutionsOrderArray.push_back("");
    updateSearchPathArrayCheck();
    return true;
}

void CCFileUtils::purgeCachedEntries()
{
    m_fullPathCache.clear();
}

unsigned char* CCFileUtils::getFileData(const char* pszFileName, const char* pszMode, unsigned long * pSize)
{
    unsigned char * pBuffer = NULL;
    CCAssert(pszFileName != NULL && pSize != NULL && pszMode != NULL, "Invalid parameters.");
    *pSize = 0;
    do
    {
		if(pszMode[0]=='r' && pszMode[1]==0x00)
		{
			pszMode = "rb";
		}
        // read the file from hardware
        std::string fullPath = fullPathForFilename(pszFileName);
        FILE *fp = fopen(fullPath.c_str(), pszMode);
        CC_BREAK_IF(!fp);
        
        fseek(fp,0,SEEK_END);
        *pSize = ftell(fp);
        fseek(fp,0,SEEK_SET);
        pBuffer = new unsigned char[*pSize];
        *pSize = fread(pBuffer,sizeof(unsigned char), *pSize,fp);
        fclose(fp);
    } while (0);
    
    if (! pBuffer)
    {
        std::string msg = "Get data from file(";
        msg.append(pszFileName).append(") failed!");
        
        CCLOG("%s", msg.c_str());
    }
	else
	{
		std::string sss = pszFileName;
		int posStart = sss.rfind('/');
		if(posStart>=0)
		{
			int nnn = sss.length() - (posStart + 1);
			sss = sss.substr(posStart+1,nnn);
		}		
		*pSize = dencypt_file(pBuffer,*pSize,(char*)sss.c_str());
	}
    return pBuffer;
}

unsigned char* CCFileUtils::getFileDataFromZip(const char* pszZipFilePath, const char* pszFileName, unsigned long * pSize)
{
    unsigned char * pBuffer = NULL;
    unzFile pFile = NULL;
    *pSize = 0;

    do 
    {
        CC_BREAK_IF(!pszZipFilePath || !pszFileName);
        CC_BREAK_IF(strlen(pszZipFilePath) == 0);

        pFile = unzOpen(pszZipFilePath);
        CC_BREAK_IF(!pFile);

        int nRet = unzLocateFile(pFile, pszFileName, 1);
        CC_BREAK_IF(UNZ_OK != nRet);

        char szFilePathA[260];
        unz_file_info FileInfo;
        nRet = unzGetCurrentFileInfo(pFile, &FileInfo, szFilePathA, sizeof(szFilePathA), NULL, 0, NULL, 0);
        CC_BREAK_IF(UNZ_OK != nRet);

        nRet = unzOpenCurrentFile(pFile);
        CC_BREAK_IF(UNZ_OK != nRet);

        pBuffer = new unsigned char[FileInfo.uncompressed_size];
        int CC_UNUSED nSize = unzReadCurrentFile(pFile, pBuffer, FileInfo.uncompressed_size);
        CCAssert(nSize == 0 || nSize == (int)FileInfo.uncompressed_size, "the file size is wrong");

        *pSize = FileInfo.uncompressed_size;
        unzCloseCurrentFile(pFile);
    } while (0);

    if (pFile)
    {
        unzClose(pFile);
    }

    return pBuffer;
}

std::string CCFileUtils::getNewFilename(const char* pszFileName)
{
    const char* pszNewFileName = NULL;
    // in Lookup Filename dictionary ?
    CCString* fileNameFound = m_pFilenameLookupDict ? (CCString*)m_pFilenameLookupDict->objectForKey(pszFileName) : NULL;
    if( NULL == fileNameFound || fileNameFound->length() == 0) {
        pszNewFileName = pszFileName;
    }
    else {
        pszNewFileName = fileNameFound->getCString();
        //CCLOG("FOUND NEW FILE NAME: %s.", pszNewFileName);
    }
    return pszNewFileName;
}

std::string CCFileUtils::getPathForFilename(const std::string& filename, const std::string& resolutionDirectory, const std::string& searchPath)
{
    std::string file = filename;
    std::string file_path = "";
    size_t pos = filename.find_last_of("/");
    if (pos != std::string::npos)
    {
        file_path = filename.substr(0, pos+1);
        file = filename.substr(pos+1);
    }
    
    // searchPath + file_path + resourceDirectory
    std::string path = searchPath;
    path += file_path;
    path += resolutionDirectory;
    
    path = getFullPathForDirectoryAndFilename(path, file);
    
    //CCLOG("getPathForFilename, fullPath = %s", path.c_str());
    return path;
}


std::string CCFileUtils::fullPathForFilename(const char* pszFileName)
{
    CCAssert(pszFileName != NULL, "CCFileUtils: Invalid path");
    
    std::string strFileName = pszFileName;
    if (isAbsolutePath(pszFileName))
    {
        //CCLOG("Return absolute path( %s ) directly.", pszFileName);
        return pszFileName;
    }
    
    // Already Cached ?
    std::map<std::string, std::string>::iterator cacheIter = m_fullPathCache.find(pszFileName);
    if (cacheIter != m_fullPathCache.end())
    {
        //CCLOG("Return full path from cache: %s", cacheIter->second.c_str());
        return cacheIter->second;
    }
    
    // Get the new file name.
    std::string newFilename = getNewFilename(pszFileName);
    
    string fullpath = "";
    
    for (std::vector<std::string>::iterator searchPathsIter = m_searchPathArrayCheck.begin();
         searchPathsIter != m_searchPathArrayCheck.end(); ++searchPathsIter) {
        for (std::vector<std::string>::iterator resOrderIter = m_searchResolutionsOrderArray.begin();
             resOrderIter != m_searchResolutionsOrderArray.end(); ++resOrderIter) {
            
            //CCLOG("\n\nSEARCHING: %s, %s, %s", newFilename.c_str(), resOrderIter->c_str(), searchPathsIter->c_str());
            
            fullpath = this->getPathForFilename(newFilename, *resOrderIter, *searchPathsIter);
            
            if (fullpath.length() > 0)
            {
                // Using the filename passed in as key.
                m_fullPathCache.insert(std::pair<std::string, std::string>(pszFileName, fullpath));
                //CCLOG("Returning path: %s", fullpath.c_str());
                return fullpath;
            }
        }
    }
    
    //CCLOG("cocos2d: fullPathForFilename: No file found at %s. Possible missing file.", pszFileName);

    // The file wasn't found, return the file name passed in.
    return pszFileName;
}

const char* CCFileUtils::fullPathFromRelativeFile(const char *pszFilename, const char *pszRelativeFile)
{
    std::string relativeFile = pszRelativeFile;
    CCString *pRet = CCString::create("");
    pRet->m_sString = relativeFile.substr(0, relativeFile.rfind('/')+1);
    pRet->m_sString += getNewFilename(pszFilename);
    return pRet->getCString();
}

void CCFileUtils::setSearchResolutionsOrder(const std::vector<std::string>& searchResolutionsOrder)
{
    bool bExistDefault = false;
    m_fullPathCache.clear();
    m_searchResolutionsOrderArray.clear();
    for (std::vector<std::string>::const_iterator iter = searchResolutionsOrder.begin(); iter != searchResolutionsOrder.end(); ++iter)
    {
        std::string resolutionDirectory = *iter;
        if (!bExistDefault && resolutionDirectory == "")
        {
            bExistDefault = true;
        }
        
        if (resolutionDirectory.length() > 0 && resolutionDirectory[resolutionDirectory.length()-1] != '/')
        {
            resolutionDirectory.append("/");
        }
        
        m_searchResolutionsOrderArray.push_back(resolutionDirectory);
    }
    if (!bExistDefault)
    {
        m_searchResolutionsOrderArray.push_back("");
    }
}

void CCFileUtils::addSearchResolutionsOrder(const char* order)
{
    m_searchResolutionsOrderArray.push_back(order);
}

const std::vector<std::string>& CCFileUtils::getSearchResolutionsOrder()
{
    return m_searchResolutionsOrderArray;
}

const std::vector<std::string>& CCFileUtils::getSearchPaths()
{
    return m_searchPathArray;
}

void CCFileUtils::setSearchPaths(const std::vector<std::string>& searchPaths)
{
    m_fullPathCache.clear();
    m_searchPathArray.clear();
    m_searchPathArray.assign(searchPaths.begin(), searchPaths.end());
    updateSearchPathArrayCheck();
        }
    
void CCFileUtils::setSearchRootPath(const char* path)
    {
    m_fullPathCache.clear();
    m_strDefaultResRootPath = path ? path : "";
    updateSearchPathArrayCheck();
    }

void CCFileUtils::addSearchPath(const char* path)
{
    if (path && strlen(path) > 0)
    {
        m_searchPathArray.push_back(path);
        updateSearchPathArrayCheck();
    }
}

void CCFileUtils::removeAllPaths()
{
    m_fullPathCache.clear();
    m_searchPathArray.clear();
    updateSearchPathArrayCheck();
}

void CCFileUtils::addSearchPathToHead(const char* path)
{
    if (path && strlen(path) > 0)
    {
        std::vector<std::string> searchPaths;
        searchPaths.push_back(path);
        for (int i = 0; i < m_searchPathArray.size(); ++i) { 
            searchPaths.push_back(m_searchPathArray.at(i));
        }
        setSearchPaths(searchPaths);
    }
}

void CCFileUtils::setFilenameLookupDictionary(CCDictionary* pFilenameLookupDict)
{
    m_fullPathCache.clear();
    CC_SAFE_RELEASE(m_pFilenameLookupDict);
    m_pFilenameLookupDict = pFilenameLookupDict;
    CC_SAFE_RETAIN(m_pFilenameLookupDict);
}

void CCFileUtils::loadFilenameLookupDictionaryFromFile(const char* filename)
{
    std::string fullPath = this->fullPathForFilename(filename);
    if (fullPath.length() > 0)
    {
        CCDictionary* pDict = CCDictionary::createWithContentsOfFile(fullPath.c_str());
        if (pDict)
        {
            CCDictionary* pMetadata = (CCDictionary*)pDict->objectForKey("metadata");
            int version = ((CCString*)pMetadata->objectForKey("version"))->intValue();
            if (version != 1)
            {
                CCLOG("cocos2d: ERROR: Invalid filenameLookup dictionary version: %ld. Filename: %s", (long)version, filename);
                return;
            }
            setFilenameLookupDictionary((CCDictionary*)pDict->objectForKey("filenames"));
        }
    }
}

std::string CCFileUtils::getFullPathForDirectoryAndFilename(const std::string& strDirectory, const std::string& strFilename)
{
    std::string ret = strDirectory+strFilename;
    if (!isFileExist(ret)) {
        ret = "";
    }
    return ret;
}

std::string CCFileUtils::getCachePath()
{
    return m_strCachePath.length() > 0 ? m_strCachePath : getWritablePath();
}

void CCFileUtils::setWritablePath(const char *writablePath)
{
    m_strWritablePath = writablePath ? writablePath : "";
}

void CCFileUtils::setCachePath(const char *cachePath)
{
    m_strCachePath = cachePath ? cachePath : "";
}

bool CCFileUtils::isAbsolutePath(const std::string& strPath)
{
    return strPath[0] == '/' ? true : false;
}


//////////////////////////////////////////////////////////////////////////
// Notification support when getFileData from invalid file path.
//////////////////////////////////////////////////////////////////////////
static bool s_bPopupNotify = true;

void CCFileUtils::setPopupNotify(bool bNotify)
{
    s_bPopupNotify = bNotify;
}

bool CCFileUtils::isPopupNotify()
{
    return s_bPopupNotify;
}

void CCFileUtils::updateSearchPathArrayCheck(void)
{
    size_t len = m_strDefaultResRootPath.length();
    if (len > 0 && m_strDefaultResRootPath[len - 1] != '/' && m_strDefaultResRootPath[len - 1] != '\\')
    {
#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
        m_strDefaultResRootPath.append("\\");
#else
        m_strDefaultResRootPath.append("/");
#endif
    }

    m_searchPathArrayCheck.clear();
    for (std::vector<std::string>::iterator it = m_searchPathArray.begin(); it != m_searchPathArray.end(); ++it)
    {
        string path = *it;
        if (!isAbsolutePath(path))
        {
            path = m_strDefaultResRootPath + path;
        }
        m_searchPathArrayCheck.push_back(path);
    }
    if (m_strDefaultResRootPath.length())
    {
        m_searchPathArrayCheck.push_back(m_strDefaultResRootPath);
    }
}

NS_CC_END

