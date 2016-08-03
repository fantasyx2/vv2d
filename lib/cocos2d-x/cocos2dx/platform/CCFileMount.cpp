/****************************************************************************
****************************************************************************/

#include "CCFileMount.h"
#include "CCFileUtils.h"

NS_CC_BEGIN

unsigned char* CCMountInfo::getFileData(const char* pszFileName, const char* pszMode, unsigned long * pSize)
{
	if(iszip)
	{
		if(zip)
		{
			unsigned long psz = 0;
			unsigned char* buf = nullptr;
			buf = zip->getFileDataNoOrder(pszFileName, &psz);
			if(buf)
			{
				*pSize = psz;
				return buf;
			}
		}
	}
	else
	{
		unsigned long psz = 0;
		unsigned char* buf = nullptr;
		std::string newpath = source+(pszFileName);
		buf = CCFileUtils::sharedFileUtils()->getFileData(newpath.c_str(), pszMode, &psz);
		if(buf)
		{
			*pSize = psz;
			return buf;
		}
	}
	return nullptr;

}


CCMountInfo* CCMountInfo::create(std::string& prefix,std::string source,bool iszip,int order)
{
	auto p = new CCMountInfo();
	if(!p) 
	{
		return nullptr;
	}
	if(iszip)
	{
		auto zip = CCZipFile::create(source.c_str());
		if(zip)
		{
			zip->retain();
			zip->genFileList();
			p->prefix = std::string(MOUNT_PREFIX)+prefix;
			p->source = source;
			p->iszip = iszip;
			p->zip=zip;
			return p;
		}
	}
	else
	{
		if(CCFileUtils::sharedFileUtils()->isAbsolutePath(source))
		{
			if(CCFileUtils::sharedFileUtils()->isDirectoryExist(source))
			{
				p->prefix = std::string(MOUNT_PREFIX)+prefix;
				p->source = source;
				return p; 
			}
		}
	}
	delete p;
	return nullptr;
}

bool CCMountList::mount(std::string& prefix,std::string source,bool iszip,int order)
{
	auto pp = CCMountInfo::create(prefix,source,iszip,order);
	if(pp)
	{
		auto key = std::string(MOUNT_PREFIX)+prefix;
		auto vv = list.find(key);
		if(vv==list.end())
		{
			std::vector<CCMountInfo*> nvv;
			nvv.push_back(pp);
			list[key] = nvv;
		}
		else
		{
			auto &nvv = vv->second;
			nvv.push_back(pp);
			if(nvv.size()>1)
			{
				std::sort(nvv.begin(), nvv.end(), [=](CCMountInfo* a,CCMountInfo* b)->int{
					return a->order>b->order;
				});
			}
		}
		return true;
	}
	return false;
}
void CCMountList::unmount(std::string& source)
{
	for(auto &pp : list)
	{			
		auto flag = true;
		do{
			flag = true;
			int ct = pp.second.size();
			for(int i=0;i<ct;i++)
			{
				auto &v = pp.second[i];
				if(v->source.compare(source)==0)
				{
					flag = false;
					delete v;
					pp.second.erase(pp.second.begin()+i);
					break;
				}
			}
			if(flag)
			{
				break;
			}

		}while(true);
	}
}
void CCMountList::clean(std::string& prefix)
{
	if(prefix.length()==0)
	{
		for(auto &pp : list)
		{
			for(auto v: pp.second)
			{
				delete v;
			}
		}
		list.clear();
	}
	else
	{
		auto pp = list.find(MOUNT_PREFIX+prefix);
		if(pp!=list.end())
		{
			for(auto v: pp->second)
			{
				delete v;
			}
			pp->second.clear();
			list.erase(MOUNT_PREFIX+prefix);
		}
	}
}

unsigned char* CCMountList::getFileData(const char* pszFileName, const char* pszMode, unsigned long * pSize)
{
	if(pszFileName[0]!=MOUNT_PREFIX[0])
	{
		return nullptr;
	}	
	char prefix[256];
	memset(prefix,0x00,sizeof(prefix));
	int i=1;
	int len = strlen(pszFileName);
	while(i<len)
	{
		if(pszFileName[i]=='/')
		{
			i++;
			break;
		}
		i++;
	}
	if(i>=256 || i<2)
	{
		return nullptr;
	}
	strncpy(prefix,pszFileName,i-1);

	const char* name = pszFileName+i;
	auto pp = list.find(prefix);
	if(pp!=list.end())
	{
		for(auto v: pp->second)
		{
			unsigned char* p=nullptr;
			unsigned long  s=0;
			p = v->getFileData(name,pszMode,&s);
			if(p)
			{
				*pSize=s;
				return p;
			}
		}

	}
	return nullptr;		 
}

NS_CC_END