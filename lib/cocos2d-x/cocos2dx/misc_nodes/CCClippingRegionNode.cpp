
#include "CCClippingRegionNode.h"
#include "CCDirector.h"
#include "CCEGLView.h"

NS_CC_BEGIN
//Setclip 不重新设置ContentSize

CCClippingRegionNode* CCClippingRegionNode::create(const CCRect& clippingRegion)
{
    CCClippingRegionNode* node = new CCClippingRegionNode();
    node->setClippingRegion(clippingRegion);
	node->setContentSize(clippingRegion.size);
    node->autorelease();
    return node;
}

CCClippingRegionNode* CCClippingRegionNode::create(void)
{
    CCClippingRegionNode* node = new CCClippingRegionNode();
    node->autorelease();
    return node;
}

void CCClippingRegionNode::setClippingRegion(const CCRect &clippingRegion)
{
    m_clippingRegion = clippingRegion;
    //setContentSize(clippingRegion.size);
}

void CCClippingRegionNode::visit() 
{
    if (m_clippingEnabled)
    {
        glEnable(GL_SCISSOR_TEST);
        
        float scaleX = m_fScaleX;
        float scaleY = m_fScaleY;
        CCNode *parent = this->getParent();
        while (parent) {
            scaleX *= parent->getScaleX();
            scaleY *= parent->getScaleY();
            parent = parent->getParent();
        }
        
        const CCPoint pos = convertToWorldSpace(CCPoint(m_clippingRegion.origin.x, m_clippingRegion.origin.y));
        CCDirector::sharedDirector()->getOpenGLView()->setScissorInPoints(pos.x,
                                                                          pos.y,
                                                                          m_clippingRegion.size.width * scaleX,
                                                                          m_clippingRegion.size.height * scaleY);
    }
    
    CCNode::visit();
    
    if (m_clippingEnabled)
    {
        glDisable(GL_SCISSOR_TEST);
    }
}

NS_CC_END
