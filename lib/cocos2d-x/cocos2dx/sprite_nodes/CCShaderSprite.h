
#ifndef _SHADER_SPRITE_H_
#define _SHADER_SPRITE_H_

#include "sprite_nodes/CCSprite.h"

NS_CC_BEGIN

class CCSpriteFrame;

class CCShaderSprite: public CCSprite
{
public:
    /// @{
    /// @name Creators

    /**
     * Creates an empty sprite without texture. You can call setTexture method subsequently.
     *
     * @return An empty sprite object that is marked as autoreleased.
     */
    static CCShaderSprite* create();

    /**
     * Creates a sprite with an image filename.
     *
     * After creation, the rect of sprite will be the size of the image,
     * and the offset will be (0,0).
     *
     * @param   pszFileName The string which indicates a path to image file, e.g., "scene1/monster.png".
     * @return  A valid sprite object that is marked as autoreleased.
     */
    static CCShaderSprite* create(const char *pszFileName);

    /**
     * Creates a sprite with an image filename and a rect.
     *
     * @param   pszFileName The string wich indicates a path to image file, e.g., "scene1/monster.png"
     * @param   rect        Only the contents inside rect of pszFileName's texture will be applied for this sprite.
     * @return  A valid sprite object that is marked as autoreleased.
     */
    static CCShaderSprite* create(const char *pszFileName, const CCRect& rect);

    /**
     * Creates a sprite with an exsiting texture contained in a CCTexture2D object
     * After creation, the rect will be the size of the texture, and the offset will be (0,0).
     *
     * @param   pTexture    A pointer to a CCTexture2D object.
     * @return  A valid sprite object that is marked as autoreleased.
     */
    static CCShaderSprite* createWithTexture(CCTexture2D *pTexture);

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
    static CCShaderSprite* createWithTexture(CCTexture2D *pTexture, const CCRect& rect);

    /**
     * Creates a sprite with an sprite frame.
     *
     * @param   pSpriteFrame    A sprite frame which involves a texture and a rect
     * @return  A valid sprite object that is marked as autoreleased.
     */
    static CCShaderSprite* createWithSpriteFrame(CCSpriteFrame *pSpriteFrame);

    /**
     * Creates a sprite with an sprite frame name.
     *
     * A CCShaderSpriteFrame will be fetched from the CCShaderSpriteFrameCache by pszSpriteFrameName param.
     * If the CCShaderSpriteFrame doesn't exist it will raise an exception.
     *
     * @param   pszSpriteFrameName A null terminated string which indicates the sprite frame name.
     * @return  A valid sprite object that is marked as autoreleased.
     */
    static CCShaderSprite* createWithSpriteFrameName(const char *pszSpriteFrameName);

    /// @}  end of creators group

	virtual void draw(void);
public:
	CCShaderSprite(void);
	~CCShaderSprite(void);
	CC_SYNTHESIZE_RETAIN(CCTexture2D*,m_Texture1,CC_Texture1);
	CC_SYNTHESIZE_RETAIN(CCTexture2D*,m_Texture2,CC_Texture2);
	CC_SYNTHESIZE_RETAIN(CCTexture2D*,m_Texture3,CC_Texture3);
    #define __M_SDF_N 13
	float m_sdf[__M_SDF_N];//more 1 begin with 1
	bool m_sdf_b[__M_SDF_N];
	void setSdf4(int id,float v1,float v2=0,float v3=0,float v4=0);
    void setSdf(int id,float v);
    float getSdf(int id);
	bool setShaderFromFile(const char*vecfile,const char*frgfile);
	bool setShaderFromByte(const char*vbytes,const char*fbytes,const char*name);
	bool setShader(CCGLProgram* pProgram,const char*key);
	bool resetShader();

    void inline __initsd(){
        m_Texture1 = NULL;
        m_Texture2 = NULL;
        m_Texture3 = NULL;
        for(int i=0;i<__M_SDF_N;i++)
        {
            m_sdf[i]=0;
            m_sdf_b[i]=false;
        }
    }
    void inline __deinitsd(){
        CC_SAFE_RELEASE(m_Texture1);
        CC_SAFE_RELEASE(m_Texture2);
        CC_SAFE_RELEASE(m_Texture3);
    }
	//1 tl
	//2 tr
	//3 bl
	//4 br
	void setQuadVertex(float tl_x,float tl_y,float tr_x,float tr_y,float bl_x,float bl_y,float br_x,float br_y);
	////mesh
	ccV3F_C4B_T2F* m_Vertices;
	int m_VericesCount;
	int m_meshmode;
	void initVertices()
	{
		m_Vertices=nullptr;
		m_VericesCount=0;
		m_meshmode=GL_TRIANGLE_STRIP;
	}
	void allocVertices(int c)
	{
		deinitVertices();
		m_VericesCount = c;
		m_Vertices = new ccV3F_C4B_T2F[m_VericesCount];
	}
	void deinitVertices()
	{
		if(m_Vertices)
		{
			delete [] m_Vertices;
			m_Vertices=nullptr;
		}
	}
	void initVertices(int mode,std::string& meshstr);
	void initVerticesWithRegex(int mode,std::string& meshstr,std::string& ra,std::string& rb);
	virtual bool drawMesh(void);
	void initForTest();
};

NS_CC_END

#endif
