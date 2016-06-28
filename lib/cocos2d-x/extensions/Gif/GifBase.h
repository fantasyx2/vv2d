#ifndef GIFBASE_H
#define GIFBASE_H
#include "cocos2d.h"
#include "Bitmap.h"

class GifBase : public cocos2d::CCShaderSprite
{
public:
	GifBase()
	{
		showfirst = false;
		isplay = false;
        loop = true;
	}
	virtual void updateGif(uint32_t delta) = 0;
	virtual cocos2d::CCTexture2D* createTexture(Bitmap* bm, int index, bool getCache);

	virtual void update(float delta)
	{
		if(!showfirst)
		{
			showfirst = true;
		}
		else
		{
			if(!isplay)
			{
				return;
			}
		}
        //if delta>1, generally speaking  the reason is the device is stuck
        if(delta > 1)
        {
            return;
        }
		uint32_t ldelta = (uint32_t)(delta * 1000);
		updateGif(ldelta);
	};
    
	virtual std::string getGifFrameName(int index)
	{
		return m_gif_fullpath;
	};

	void pause()
	{
		isplay = false;
	};

	void play()
	{
		isplay = true;
	}
	bool isplaying()
	{
		return isplay;
	}
    void setloop(bool lp)
    {
        loop=lp;
    }

protected:
	std::string m_gif_fullpath;
	bool showfirst;
	bool isplay;
    bool loop;
};
#endif//GIFBASE_H

