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


#ifndef __CC_FILEMOUNT_H__
#define __CC_FILEMOUNT_H__

#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include "CCPlatformMacros.h"
#include "ccTypes.h"
#include "ccTypeInfo.h"
#include "CCZipFile.h"

using namespace std;
NS_CC_BEGIN
#define MOUNT_PREFIX "@"

class CCMountInfo
{

public:    
	CCMountInfo()
	{
		prefix="";
		source="";
		order=0;
		iszip=false;
		zip =nullptr;
	}
	~CCMountInfo()
	{
		if(zip)
		{
			CC_SAFE_RELEASE(zip);
			zip =nullptr;
		}
	}
	std::string prefix;
	std::string source;
	int order;
	bool iszip;
	CCZipFile* zip;
	unsigned char* getFileData(const char* pszFileName, const char* pszMode, unsigned long * pSize);
	static CCMountInfo* create(std::string& prefix,std::string source,bool iszip=false,int order=0);
};


class CCMountList
{
public:
	CCMountList(){
		count=0;
	}
	~CCMountList(){
		clean(std::string(""));
	}
	int count;
	std::map<std::string,std::vector<CCMountInfo*>> list;
	bool mount(std::string& prefix,std::string source,bool iszip=false,int order=0);
	void unmount(std::string& source);
	void clean(std::string& prefix);
	unsigned char* getFileData(const char* pszFileName, const char* pszMode, unsigned long * pSize);
};


NS_CC_END

#endif    // __CC_FILEMOUNT_H__
