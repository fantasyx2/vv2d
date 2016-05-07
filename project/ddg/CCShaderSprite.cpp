
#include "sprite_nodes/CCShaderSprite.h"
#include "sprite_nodes/CCSpriteFrame.h"
#include "sprite_nodes/CCSpriteFrameCache.h"
#include "textures/CCTexture2D.h"
#include "shaders/ccShaders.h"
#include "shaders/CCShaderCache.h"

USING_NS_CC;

/**
 * Creates an empty sprite without texture. You can call setTexture method subsequently.
 *
 * @return An empty sprite object that is marked as autoreleased.
 */
CCShaderSprite* CCShaderSprite::create()
{
    CCShaderSprite *pSprite = new CCShaderSprite();
    if (pSprite && pSprite->init())
    {
        pSprite->autorelease();
        return pSprite;
    }
    CC_SAFE_DELETE(pSprite);
    return NULL;
}

/**
 * Creates a sprite with an image filename.
 *
 * After creation, the rect of sprite will be the size of the image,
 * and the offset will be (0,0).
 *
 * @param   pszFileName The string which indicates a path to image file, e.g., "scene1/monster.png".
 * @return  A valid sprite object that is marked as autoreleased.
 */
CCShaderSprite* CCShaderSprite::create(const char *pszFileName)
{
    CCShaderSprite *pobSprite = new CCShaderSprite();
    if (pobSprite && pobSprite->initWithFile(pszFileName))
    {
        pobSprite->autorelease();
        return pobSprite;
    }
    CC_SAFE_DELETE(pobSprite);
    return NULL;
}

/**
 * Creates a sprite with an image filename and a rect.
 *
 * @param   pszFileName The string wich indicates a path to image file, e.g., "scene1/monster.png"
 * @param   rect        Only the contents inside rect of pszFileName's texture will be applied for this sprite.
 * @return  A valid sprite object that is marked as autoreleased.
 */
CCShaderSprite* CCShaderSprite::create(const char *pszFileName, const CCRect& rect)
{
    CCShaderSprite *pobSprite = new CCShaderSprite();
    if (pobSprite && pobSprite->initWithFile(pszFileName, rect))
    {
        pobSprite->autorelease();
        return pobSprite;
    }
    CC_SAFE_DELETE(pobSprite);
    return NULL;
}

/**
 * Creates a sprite with an exsiting texture contained in a CCTexture2D object
 * After creation, the rect will be the size of the texture, and the offset will be (0,0).
 *
 * @param   pTexture    A pointer to a CCTexture2D object.
 * @return  A valid sprite object that is marked as autoreleased.
 */
CCShaderSprite* CCShaderSprite::createWithTexture(CCTexture2D *pTexture)
{
    CCShaderSprite *pobSprite = new CCShaderSprite();
    if (pobSprite && pobSprite->initWithTexture(pTexture, CCRectZero))
    {
        pobSprite->autorelease();
        return pobSprite;
    }
    CC_SAFE_DELETE(pobSprite);
    return NULL;
}

/**
 * Creates a sprite with a texture and a rect.
 *
 * After creation, the offset will be (0,0).
 *
 * @param   pTexture    A pointer to an existing CCTexture2D object.
 *                      You can use a CCTexture2D object for many sprites.
 * @param   rect        Only the contents inside the rect of this texture will be applied for this sprite.
 * @return  A valid sprite object that is marked as autoreleased.
 */
CCShaderSprite* CCShaderSprite::createWithTexture(CCTexture2D *pTexture, const CCRect& rect)
{
    CCShaderSprite *pobSprite = new CCShaderSprite();
    if (pobSprite && pobSprite->initWithTexture(pTexture, rect))
    {
        pobSprite->autorelease();
        return pobSprite;
    }
    CC_SAFE_DELETE(pobSprite);
    return NULL;
}

/**
 * Creates a sprite with an sprite frame.
 *
 * @param   pSpriteFrame    A sprite frame which involves a texture and a rect
 * @return  A valid sprite object that is marked as autoreleased.
 */
CCShaderSprite* CCShaderSprite::createWithSpriteFrame(CCSpriteFrame *pSpriteFrame)
{
    CCShaderSprite *pobSprite = new CCShaderSprite();
    if (pSpriteFrame && pobSprite && pobSprite->initWithSpriteFrame(pSpriteFrame))
    {
        pobSprite->autorelease();
        return pobSprite;
    }
    CC_SAFE_DELETE(pobSprite);
    return NULL;
}

/**
 * Creates a sprite with an sprite frame name.
 *
 * A CCSpriteFrame will be fetched from the CCSpriteFrameCache by pszSpriteFrameName param.
 * If the CCSpriteFrame doesn't exist it will raise an exception.
 *
 * @param   pszSpriteFrameName A null terminated string which indicates the sprite frame name.
 * @return  A valid sprite object that is marked as autoreleased.
 */
CCShaderSprite* CCShaderSprite::createWithSpriteFrameName(const char *pszSpriteFrameName)
{
    CCSpriteFrame *pFrame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(pszSpriteFrameName);

#if COCOS2D_DEBUG > 0
    char msg[256] = {0};
    sprintf(msg, "Invalid spriteFrameName: %s", pszSpriteFrameName);
    CCAssert(pFrame != NULL, msg);
#endif

    return createWithSpriteFrame(pFrame);
}

CCShaderSprite::CCShaderSprite(void)
{
	__initsd();
}

CCShaderSprite::~CCShaderSprite(void)
{
	__deinitsd();
}

void CCShaderSprite::draw(void)
{
	CC_PROFILER_START_CATEGORY(kCCProfilerCategorySprite, "CCShaderSprite - draw");

	CCAssert(!m_pobBatchNode, "If CCShaderSprite is being rendered by CCSpriteBatchNode, CCSprite#draw SHOULD NOT be called");

	CC_NODE_DRAW_SETUP();

	ccGLBlendFunc( m_sBlendFunc.src, m_sBlendFunc.dst );

	ccGLBindTexture2D( m_pobTexture->getName() );

	//add for shader
	if(m_Texture1)
	{
		glActiveTexture(GL_TEXTURE1);
		ccGLBindTexture2DN(1,m_Texture1->getName());
		if(m_Texture2)
		{
			glActiveTexture(GL_TEXTURE2);
			ccGLBindTexture2DN(2,m_Texture2->getName());
		}
		if(m_Texture3)
		{
			glActiveTexture(GL_TEXTURE3);
			ccGLBindTexture2DN(3,m_Texture3->getName());
		}
	}
	do{
		if(!m_sdf_b[1]){
			break;
		}
		getShaderProgram()->setUniformLocationV4P1(m_sdf[1],m_sdf[2],m_sdf[3],m_sdf[4]);
		//--------------------
		if(!m_sdf_b[5]){
			break;
		}
		getShaderProgram()->setUniformLocationV4P1(m_sdf[5],m_sdf[6],m_sdf[7],m_sdf[8]);
		//--------------------
		if(!m_sdf_b[9]){
			break;
		}
		getShaderProgram()->setUniformLocationV4P1(m_sdf[9],m_sdf[10],m_sdf[11],m_sdf[12]);
		//--------------------
	}
	while(0);
	//add end


	ccGLEnableVertexAttribs( kCCVertexAttribFlag_PosColorTex );

#define kQuadSize sizeof(m_sQuad.bl)
#ifdef EMSCRIPTEN
	long offset = 0;
	setGLBufferData(&m_sQuad, 4 * kQuadSize, 0);
#else
	long offset = (long)&m_sQuad;
#endif // EMSCRIPTEN

	// vertex
	int diff = offsetof( ccV3F_C4B_T2F, vertices);
	glVertexAttribPointer(kCCVertexAttrib_Position, 3, GL_FLOAT, GL_FALSE, kQuadSize, (void*) (offset + diff));

	// texCoods
	diff = offsetof( ccV3F_C4B_T2F, texCoords);
	glVertexAttribPointer(kCCVertexAttrib_TexCoords, 2, GL_FLOAT, GL_FALSE, kQuadSize, (void*)(offset + diff));

	// color
	diff = offsetof( ccV3F_C4B_T2F, colors);
	glVertexAttribPointer(kCCVertexAttrib_Color, 4, GL_UNSIGNED_BYTE, GL_TRUE, kQuadSize, (void*)(offset + diff));


	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

	CHECK_GL_ERROR_DEBUG();


#if CC_SPRITE_DEBUG_DRAW == 1
	// draw bounding box
	CCPoint vertices[4]={
		ccp(m_sQuad.tl.vertices.x,m_sQuad.tl.vertices.y),
		ccp(m_sQuad.bl.vertices.x,m_sQuad.bl.vertices.y),
		ccp(m_sQuad.br.vertices.x,m_sQuad.br.vertices.y),
		ccp(m_sQuad.tr.vertices.x,m_sQuad.tr.vertices.y),
	};
	ccDrawPoly(vertices, 4, true);
#elif CC_SPRITE_DEBUG_DRAW == 2
	// draw texture box
	CCSize s = this->getTextureRect().size;
	CCPoint offsetPix = this->getOffsetPosition();
	CCPoint vertices[4] = {
		ccp(offsetPix.x,offsetPix.y), ccp(offsetPix.x+s.width,offsetPix.y),
		ccp(offsetPix.x+s.width,offsetPix.y+s.height), ccp(offsetPix.x,offsetPix.y+s.height)
	};
	ccDrawPoly(vertices, 4, true);
#endif // CC_SPRITE_DEBUG_DRAW

	CC_INCREMENT_GL_DRAWS(1);

	CC_PROFILER_STOP_CATEGORY(kCCProfilerCategorySprite, "CCShaderSprite - draw");
}


void CCShaderSprite::setSdf4(int id,float v1,float v2,float v3,float v4)
{
	m_sdf_b[id]=true;
	m_sdf_b[id+1]=true;
	m_sdf_b[id+2]=true;
	m_sdf_b[id+3]=true;
	m_sdf[id]=v1;
	m_sdf[id+1]=v2;
	m_sdf[id+2]=v3;
	m_sdf[id+3]=v4;
}
void CCShaderSprite::setSdf(int id,float v)
{
	m_sdf_b[id]=true;
	m_sdf[id]=v;
}
float CCShaderSprite::getSdf(int id)
{
	return m_sdf[id];
}

bool CCShaderSprite::resetShader()
{
	setShaderProgram(CCShaderCache::sharedShaderCache()->programForKey(kCCShader_PositionTextureColor));
	return true;
}

bool CCShaderSprite::setShaderFromFile(const char*vfile,const char*ffile)
{
	CCGLProgram* pProgram = CCShaderCache::sharedShaderCache()->programForKey(ffile);
	if(NULL==pProgram)
	{
		pProgram = new CCGLProgram();
		if(false == pProgram->initWithVertexShaderFilename(vfile, ffile))
		{
			CCLOG("CCShaderSprite::setShaderFromFile false");
			return false;
		}
		setShader(pProgram,ffile);
	}
	setShaderProgram(pProgram);

	CHECK_GL_ERROR_DEBUG();
	return true;
}

bool CCShaderSprite::setShaderFromByte(const char*vbytes,const char*fbytes,const char*name)
{
	CCGLProgram* pProgram = CCShaderCache::sharedShaderCache()->programForKey(name);
	if(NULL==pProgram)
	{
		pProgram = new CCGLProgram();
		if(false == pProgram->initWithVertexShaderByteArray(vbytes, fbytes))
		{
			CCLOG("CCShaderSprite::setShaderFromByte false");
			return false;
		}
		setShader(pProgram,name);
	}
	setShaderProgram(pProgram);
	CHECK_GL_ERROR_DEBUG();
	return true;
}

bool CCShaderSprite::setShader(CCGLProgram* pProgram,const char*key)
{
	CCShaderCache::sharedShaderCache()->addProgram(pProgram, key);
	pProgram->release();
	CHECK_GL_ERROR_DEBUG();
	pProgram->addAttribute(kCCAttributeNamePosition, kCCVertexAttrib_Position);
	pProgram->addAttribute(kCCAttributeNameColor, kCCVertexAttrib_Color);
	pProgram->addAttribute(kCCAttributeNameTexCoord, kCCVertexAttrib_TexCoords);
	CHECK_GL_ERROR_DEBUG();
	pProgram->link();
	CHECK_GL_ERROR_DEBUG();
	pProgram->updateUniforms();
	return true;
}

void CCShaderSprite::setQuadVertex(float tl_x,float tl_y,float tr_x,float tr_y,float bl_x,float bl_y,float br_x,float br_y)
{
	m_sQuad.tl.vertices.x = tl_x;
	m_sQuad.tl.vertices.y = tl_y;
	m_sQuad.tr.vertices.x = tr_x;
	m_sQuad.tr.vertices.y = tr_y;
	m_sQuad.bl.vertices.x = bl_x;
	m_sQuad.bl.vertices.y = bl_y;
	m_sQuad.br.vertices.x = br_x;
	m_sQuad.br.vertices.y = br_y;	
	if (m_pobTextureAtlas)
	{
        m_pobTextureAtlas->updateQuad(&m_sQuad, m_uAtlasIndex);
    }
}



