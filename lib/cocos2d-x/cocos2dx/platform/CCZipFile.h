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

#ifndef __CC_ZIP_FILE_H_
#define __CC_ZIP_FILE_H_

#include <string>
#include "cocoa/CCObject.h"
#include "ccTypeInfo.h"
#include "support/zip_support/unzip.h"
#include <stdlib.h>
#include <map>

NS_CC_BEGIN
struct __ZipEntryInfo
{
    unz_file_pos pos;
    uLong uncompressed_size;
};
class CC_DLL CCZipFile : public CCObject
{
public:
    /**
     *  Returns an unique ID for this class.
     *  @note It's only used for JSBindings now.
     *  @return The unique ID for this class.
     */
    virtual long getClassTypeInfo() {
		static const long id = cocos2d::getHashCodeByString(typeid(cocos2d::CCZipFile).name());
		return id;
    }
    
    static CCZipFile *create(const char *zipFilename);
    static CCZipFile *createWithBuffer(const void* buffer, uLong size);
    static CCZipFile *createWithPathName(const char *zipPathName);
    static unsigned char *unZipIfNeed(unsigned char * buffer,uLong insize,uLong& outsize);
    ~CCZipFile(void);
    
    const std::string getFirstFilename(void);
    const std::string getNextFilename(void);
    
    unsigned char* getFileData(const char *filename, unsigned long *filesize);
    void close(void);

    unsigned char* getFileDataNoOrder(const char *filename, unsigned long *filesize);
    bool genFileList();
	void *m_buff;
    
    //for lua only
    void getFileDataNoOrder(const char *filename);
    void getFileDataOrder(const char *filename);
    void getFileList();
    
private:
    CCZipFile(void)
    : m_zipFile(NULL)
    ,m_buff(NULL)
    ,m_hasGenFlist(false)
    {        
    }
    bool initWithFilename(const char *zipFilename);
    bool initWithBuffer(const void *buffer, uLong size);

    int getCurrentFileInfo(std::string *filename, unz_file_info *info);

    unzFile m_zipFile; 

    std::map<std::string, struct __ZipEntryInfo> m_fileList;

    bool m_hasGenFlist;
    
};

NS_CC_END

#endif /* defined(__CC_ZIP_FILE_H_) */
