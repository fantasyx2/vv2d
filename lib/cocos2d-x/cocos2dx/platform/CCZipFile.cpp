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

#include "CCZipFile.h"
#include "ccMacros.h"
#include "platform/CCFileUtils.h"

NS_CC_BEGIN

static const std::string emptyFilename("");

CCZipFile *CCZipFile::create(const char *zipFilename)
{
    CCZipFile *zip = new CCZipFile();
    if (zip->initWithFilename(zipFilename))
    {
        zip->autorelease();
        return zip;
    }
    else
    {
        delete zip;
        return NULL;
    }
}

CCZipFile *CCZipFile::createWithBuffer(const void* buffer, uLong size)
{
    CCZipFile *zip = new CCZipFile();
    if (zip->initWithBuffer(buffer, size))
    {
        zip->autorelease();
        return zip;
    }
    else
    {
        delete zip;
        return NULL;
    }
}

CCZipFile *CCZipFile::createWithPathName(const char *zipPathName)
{
    uLong size;
    void *buffer = CCFileUtils::sharedFileUtils()->getFileData(zipPathName,"rb",&size);
    if(buffer)
    {
        CCZipFile *zip = createWithBuffer(buffer,size);
        if(zip)
        {
            zip->m_buff = buffer;
            return zip;
        }
        delete[] buffer;
    }
    return NULL;
}

unsigned char *CCZipFile::unZipIfNeed(unsigned char * buffer,uLong insize,uLong& outsize)
{
    //50,4B,03,04
    if(insize>4 && buffer[0]==0x50 && buffer[1]==0x4B && buffer[2]==0x03 && buffer[3]==0x04)
    {
        CCZipFile *zip = createWithBuffer(buffer,insize);
        if(zip)
        {
             std::string name = zip->getFirstFilename();
             uLong newsize=0;
             unsigned char* newbuff = zip->getFileData(name.c_str(), &newsize);
             if(newbuff)
             {
                outsize = newsize;
                return newbuff;
             }
        }
    }
    return NULL;
}

bool CCZipFile::initWithFilename(const char *zipFilename)
{
    if (!zipFilename || strlen(zipFilename) == 0) return false;

    m_zipFile = unzOpen(zipFilename);
    if (!m_zipFile) return false;
    
    return true;
}

bool CCZipFile::initWithBuffer(const void *buffer, uLong size)
{
    if (!buffer || size == 0) return false;

    m_zipFile = unzOpenBuffer(buffer, size);
    if (!m_zipFile) return false;
    return true;
}

CCZipFile::~CCZipFile(void)
{
    close();
	m_fileList.clear();
    if(m_buff) delete[] m_buff;
    m_buff=NULL;
}

const std::string CCZipFile::getFirstFilename(void)
{
    if (unzGoToFirstFile(m_zipFile) != UNZ_OK) return emptyFilename;
    std::string path;
    unz_file_info info;
    getCurrentFileInfo(&path, &info);
    return path;
}

const std::string CCZipFile::getNextFilename(void)
{
    if (unzGoToNextFile(m_zipFile) != UNZ_OK) return emptyFilename;
    std::string path;
    unz_file_info info;
    getCurrentFileInfo(&path, &info);
    return path;
}

unsigned char* CCZipFile::getFileData(const char *filename, unsigned long *filesize)
{
    unsigned char *buffer = NULL;
    *filesize = 0;
    
    do 
    {
        int ret = unzLocateFile(m_zipFile, filename, 1);
        CC_BREAK_IF(UNZ_OK != ret);

        std::string path;
        unz_file_info info;
        CC_BREAK_IF(UNZ_OK != getCurrentFileInfo(&path, &info));
        
        ret = unzOpenCurrentFile(m_zipFile);
        CC_BREAK_IF(UNZ_OK != ret);
        
        buffer = new unsigned char[info.uncompressed_size];
        int size = 0;
        size = unzReadCurrentFile(m_zipFile, buffer, info.uncompressed_size);
        CCAssert(size == 0 || size == (int)info.uncompressed_size, "the file size is wrong");
        
        *filesize = info.uncompressed_size;
        unzCloseCurrentFile(m_zipFile);
    } while (0);
    
    return buffer;
}
#define UNZ_MAXFILENAMEINZIP 256
unsigned char* CCZipFile::getFileDataNoOrder(const char *fileName, unsigned long *pSize)
{
    unsigned char * pBuffer = NULL;
    if (pSize)
    {
        *pSize = 0;
    }    
    do
    {
        CC_BREAK_IF(!m_zipFile);
        CC_BREAK_IF(m_fileList.empty());
        
        std::map<std::string, struct __ZipEntryInfo>::const_iterator it = m_fileList.find(fileName);
        CC_BREAK_IF(it ==  m_fileList.end());
        
        __ZipEntryInfo fileInfo = it->second;
        
        int nRet = unzGoToFilePos(m_zipFile, &fileInfo.pos);
        CC_BREAK_IF(UNZ_OK != nRet);
        
        nRet = unzOpenCurrentFile(m_zipFile);
        CC_BREAK_IF(UNZ_OK != nRet);
        
        pBuffer = new unsigned char[fileInfo.uncompressed_size];
        int CC_UNUSED nSize = unzReadCurrentFile(m_zipFile, pBuffer, fileInfo.uncompressed_size);
        CCAssert(nSize == 0 || nSize == (int)fileInfo.uncompressed_size, "the file size is wrong");
        
        if (pSize)
        {
            *pSize = fileInfo.uncompressed_size;
        }
        unzCloseCurrentFile(m_zipFile);
    } while (0);
    
    return pBuffer;

}

bool  CCZipFile::genFileList()
{
    bool ret = false;
    do
    {
        CC_BREAK_IF(!m_zipFile);
        
        // clear existing file list
        m_fileList.clear();
        
        // UNZ_MAXFILENAMEINZIP + 1 - it is done so in unzLocateFile
        char szCurrentFileName[UNZ_MAXFILENAMEINZIP + 1];
        unz_file_info64 fileInfo;
        
        // go through all files and store position information about the required files
        int err = unzGoToFirstFile64(m_zipFile, &fileInfo,
                                     szCurrentFileName, sizeof(szCurrentFileName) - 1);
        while (err == UNZ_OK)
        {
            unz_file_pos posInfo;
            int posErr = unzGetFilePos(m_zipFile, &posInfo);
            if (posErr == UNZ_OK)
            {
                std::string currentFileName = szCurrentFileName;
                {
                    __ZipEntryInfo entry;
                    entry.pos = posInfo;
                    entry.uncompressed_size = (uLong)fileInfo.uncompressed_size;
                    m_fileList[currentFileName] = entry;
                }
            }
            // next file - also get the information about it
            err = unzGoToNextFile64(m_zipFile, &fileInfo,
                                    szCurrentFileName, sizeof(szCurrentFileName) - 1);
        }
        ret = true;
        
    } while(false);
    
    return ret;
}

void CCZipFile::close(void)
{
    if (m_zipFile)
    {
        unzClose(m_zipFile);
        m_zipFile = NULL;
    }
}

int CCZipFile::getCurrentFileInfo(std::string *filename, unz_file_info *info)
{
    char path[FILENAME_MAX + 1];
    int ret = unzGetCurrentFileInfo(m_zipFile, info, path, sizeof(path), NULL, 0, NULL, 0);
    if (ret != UNZ_OK)
    {
        *filename = emptyFilename;
    }
    else
    {
        filename->assign(path);
    }
    return ret;
}

NS_CC_END
