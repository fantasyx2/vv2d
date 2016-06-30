#ifndef GIFUTILS_H
#define GIFUTILS_H

#include <stdio.h>
#include "cocos2d.h"
class GifData
{
public:
	GifData()
	{
		buff=nullptr;
		length=0;
		offset=0;
	}
	~GifData()
	{
		if(buff)
		{
			delete [] buff;
			buff=nullptr;
		}
		length=0;
		offset=0;
	}
	bool open(const char*name)
	{
		unsigned long size=0;
		buff = cocos2d::CCFileUtils::sharedFileUtils()->getFileData(name,"rb",&size);
		if(buff)
		{
			length = size;
			return true;
		}
	}
	unsigned char*buff;
	int length;
	int offset;
	int read(unsigned char*bytes,int size)
	{
		int sz  = size;
		if(sz>length-offset){
			sz = length-offset;
		}
		if(sz>=0)
		{
			memcpy(bytes,buff+offset,sz);
			offset+=sz;
		}
		return sz;
	}
	bool isGif()
	{
		bool res = false;
		unsigned char buf[GIF_STAMP_LEN];
		if(length<GIF_STAMP_LEN)
		{
			return false;
		}
		memcpy(buf,buff,GIF_STAMP_LEN);
		if (memcmp(GIF_STAMP,   buf, GIF_STAMP_LEN) == 0 ||
				memcmp(GIF87_STAMP, buf, GIF_STAMP_LEN) == 0 ||
				memcmp(GIF89_STAMP, buf, GIF_STAMP_LEN) == 0) {
					res =  true;
		}
		return res;
	}
};

class GIFFILE
{
	union 
	{
		GifData* data;
		FILE* file;
	};
};
#if 1
#define FILE GifData
class GifUtils
{
public:
	static GifData* openFile(const char* fileName)
	{
		GifData*data = new GifData();
		if(data && data->open(fileName))
		{
			return data;
		}
		if(data)
		{
			delete data;
		}
		return nullptr;

	}

	static void closeFile(GifData* file)
	{
		if(file)
		{
			delete file;
		}
	}

	static bool isGif(const char* fileName)
	{
		GifData* file = openFile(fileName);
		bool res = isGifFile(file);
		closeFile(file);
		return res;
	}

	static bool isGifFile(GifData* file)
	{
		if(file == NULL)
		{
			return false;
		}
		return file->isGif();		
	}

	static int fread(unsigned char*bytes,int size,GifData* file)
	{
		return file->read(bytes,size);
	}
};
#else

class GifUtils
{
public:
	static FILE* openFile(const char* fileName)
	{
		FILE* file = NULL;
#if defined(_MSC_VER) && (_MSC_VER >= 1400 ) && (CC_TARGET_PLATFORM != CC_PLATFORM_MARMALADE)
		errno_t err = fopen_s(&file, fileName, "rb" );

		if(err && file)
		{
			fclose(file);
			file = NULL;
		}
#else
		file = fopen(fileName, "rb" );
#endif
		return file;

	}

	static void closeFile(FILE* file)
	{
		if(file)
		{
			fclose(file);
		}
	}

	static bool isGif(const char* fileName)
	{
		FILE* file = openFile(fileName);
		bool res = isGifFile(file);
		closeFile(file);

		return res;
	}

	static bool isGifFile(FILE* file)
	{
		if(file == NULL)
		{
			return false;
		}
		long index = ftell(file);
		bool res = false;
		char buf[GIF_STAMP_LEN];
		int read = fread(buf,1,GIF_STAMP_LEN,file);
		if (read == GIF_STAMP_LEN) {
			if (memcmp(GIF_STAMP,   buf, GIF_STAMP_LEN) == 0 ||
				memcmp(GIF87_STAMP, buf, GIF_STAMP_LEN) == 0 ||
				memcmp(GIF89_STAMP, buf, GIF_STAMP_LEN) == 0) {
					res =  true;
			}
		}
		fseek(file,index,SEEK_SET);
		return res;
	}

	static int fread(unsigned char*bytes,int size,FILE* file)
	{
		return fread(bytes, 1, size, file);
	}


};

#endif

#endif//GIFUTILS_H