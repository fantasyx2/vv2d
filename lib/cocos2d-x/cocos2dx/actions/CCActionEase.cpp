/****************************************************************************
Copyright (c) 2010-2012 cocos2d-x.org
Copyright (c) 2008-2009 Jason Booth

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

/*
 * Elastic, Back and Bounce actions based on code from:
 * http://github.com/NikhilK/silverlightfx/
 *
 * by http://github.com/NikhilK
 */

#include "CCActionEase.h"
#include "cocoa/CCZone.h"

NS_CC_BEGIN

#ifndef M_PI_X_2
#define M_PI_X_2 (float)M_PI * 2.0f
#endif

//
// EaseAction
//

CCActionEase* CCActionEase::create(CCActionInterval *pAction)
{
    CCActionEase *pRet = new CCActionEase();
    if (pRet)
    {
        if (pRet->initWithAction(pAction))
        {
            pRet->autorelease();
        }
        else
        {
            CC_SAFE_RELEASE_NULL(pRet);
        }
    }

    return pRet;
}

bool CCActionEase::initWithAction(CCActionInterval *pAction)
{
    CCAssert(pAction != NULL, "");

    if (CCActionInterval::initWithDuration(pAction->getDuration()))
    {
        m_pInner = pAction;
        pAction->retain();

        return true;
    }

    return false;
}

CCObject* CCActionEase::copyWithZone(CCZone *pZone)
{
    CCZone* pNewZone = NULL;
    CCActionEase* pCopy = NULL;
    if(pZone && pZone->m_pCopyObject) 
    {
        //in case of being called at sub class
        pCopy = (CCActionEase*)(pZone->m_pCopyObject);
    }
    else
    {
        pCopy = new CCActionEase();
        pZone = pNewZone = new CCZone(pCopy);
    }

    CCActionInterval::copyWithZone(pZone);

    pCopy->initWithAction((CCActionInterval *)(m_pInner->copy()->autorelease()));
    
    CC_SAFE_DELETE(pNewZone);
    return pCopy;
}

CCActionEase::~CCActionEase(void)
{
    CC_SAFE_RELEASE(m_pInner);
}

void CCActionEase::startWithTarget(CCNode *pTarget)
{
    CCActionInterval::startWithTarget(pTarget);
    m_pInner->startWithTarget(m_pTarget);
}

void CCActionEase::stop(void)
{
    m_pInner->stop();
    CCActionInterval::stop();
}

void CCActionEase::update(float time)
{
    m_pInner->update(time);
}

CCActionInterval* CCActionEase::reverse(void)
{
    return CCActionEase::create(m_pInner->reverse());
}

CCActionInterval* CCActionEase::getInnerAction()
{
    return m_pInner;
}

//
// EaseRateAction
//

CCEaseRateAction* CCEaseRateAction::create(CCActionInterval *pAction, float fRate)
{
    CCEaseRateAction *pRet = new CCEaseRateAction();
    if (pRet)
    {
        if (pRet->initWithAction(pAction, fRate))
        {
            pRet->autorelease();
        }
        else
        {
            CC_SAFE_RELEASE_NULL(pRet);
        }
    }

    return pRet;
}

bool CCEaseRateAction::initWithAction(CCActionInterval *pAction, float fRate)
{
    if (CCActionEase::initWithAction(pAction))
    {
        m_fRate = fRate;
        return true;
    }

    return false;
}

CCObject* CCEaseRateAction::copyWithZone(CCZone *pZone)
{
    CCZone* pNewZone = NULL;
    CCEaseRateAction* pCopy = NULL;
    if(pZone && pZone->m_pCopyObject) 
    {
        //in case of being called at sub class
        pCopy = (CCEaseRateAction*)(pZone->m_pCopyObject);
    }
    else
    {
        pCopy = new CCEaseRateAction();
        pNewZone = new CCZone(pCopy);
    }

    pCopy->initWithAction((CCActionInterval*)(m_pInner->copy()->autorelease()), m_fRate);

    CC_SAFE_DELETE(pNewZone);
    return pCopy;
}

CCEaseRateAction::~CCEaseRateAction(void)
{
}

CCActionInterval* CCEaseRateAction::reverse(void)
{
    return CCEaseRateAction::create(m_pInner->reverse(), 1 / m_fRate);
}

//
// EeseIn
//

CCEaseIn* CCEaseIn::create(CCActionInterval *pAction, float fRate)
{
    CCEaseIn *pRet = new CCEaseIn();
    if (pRet)
    {
        if (pRet->initWithAction(pAction, fRate))
        {
            pRet->autorelease();
        }
        else
        {
            CC_SAFE_RELEASE_NULL(pRet);
        }
    }

    return pRet;
}

CCObject* CCEaseIn::copyWithZone(CCZone *pZone)
{
    CCZone* pNewZone = NULL;
    CCEaseIn* pCopy = NULL;
    if(pZone && pZone->m_pCopyObject) 
    {
        //in case of being called at sub class
        pCopy = (CCEaseIn*)(pZone->m_pCopyObject);
    }
    else
    {
        pCopy = new CCEaseIn();
        pNewZone = new CCZone(pCopy);
    }

    pCopy->initWithAction((CCActionInterval*)(m_pInner->copy()->autorelease()), m_fRate);

    CC_SAFE_DELETE(pNewZone);
    return pCopy;
}

void CCEaseIn::update(float time)
{
    m_pInner->update(powf(time, m_fRate));
}

CCActionInterval* CCEaseIn::reverse(void)
{
    return CCEaseIn::create(m_pInner->reverse(), 1 / m_fRate);
}

//
// EaseOut
//
CCEaseOut* CCEaseOut::create(CCActionInterval *pAction, float fRate)
{
    CCEaseOut *pRet = new CCEaseOut();
    if (pRet)
    {
        if (pRet->initWithAction(pAction, fRate))
        {
            pRet->autorelease();
        }
        else
        {
            CC_SAFE_RELEASE_NULL(pRet);
        }
    }

    return pRet;   
}

CCObject* CCEaseOut::copyWithZone(CCZone *pZone)
{
    CCZone* pNewZone = NULL;
    CCEaseOut* pCopy = NULL;
    if(pZone && pZone->m_pCopyObject) 
    {
        //in case of being called at sub class
        pCopy = (CCEaseOut*)(pZone->m_pCopyObject);
    }
    else
    {
        pCopy = new CCEaseOut();
        pNewZone = new CCZone(pCopy);
    }

    pCopy->initWithAction((CCActionInterval*)(m_pInner->copy()->autorelease()), m_fRate);

    CC_SAFE_DELETE(pNewZone);
    return pCopy;
}

void CCEaseOut::update(float time)
{
    m_pInner->update(powf(time, 1 / m_fRate));
}

CCActionInterval* CCEaseOut::reverse()
{
    return CCEaseOut::create(m_pInner->reverse(), 1 / m_fRate);
}

//
// EaseInOut
//
CCEaseInOut* CCEaseInOut::create(CCActionInterval *pAction, float fRate)
{
    CCEaseInOut *pRet = new CCEaseInOut();
    if (pRet)
    {
        if (pRet->initWithAction(pAction, fRate))
        {
            pRet->autorelease();
        }
        else
        {
            CC_SAFE_RELEASE_NULL(pRet);
        }
    }

    return pRet; 
}

CCObject* CCEaseInOut::copyWithZone(CCZone *pZone)
{
    CCZone* pNewZone = NULL;
    CCEaseInOut* pCopy = NULL;
    if(pZone && pZone->m_pCopyObject) 
    {
        //in case of being called at sub class
        pCopy = (CCEaseInOut*)(pZone->m_pCopyObject);
    }
    else
    {
        pCopy = new CCEaseInOut();
        pNewZone = new CCZone(pCopy);
    }

    pCopy->initWithAction((CCActionInterval*)(m_pInner->copy()->autorelease()), m_fRate);

    CC_SAFE_DELETE(pNewZone);
    return pCopy;
}

void CCEaseInOut::update(float time)
{
    time *= 2;
    if (time < 1)
    {
        m_pInner->update(0.5f * powf(time, m_fRate));
    }
    else
    {
        m_pInner->update(1.0f - 0.5f * powf(2-time, m_fRate));
    }
}

// InOut and OutIn are symmetrical
CCActionInterval* CCEaseInOut::reverse(void)
{
    return CCEaseInOut::create(m_pInner->reverse(), m_fRate);
}

//
// EaseExponentialIn
//
CCEaseExponentialIn* CCEaseExponentialIn::create(CCActionInterval* pAction)
{
    CCEaseExponentialIn *pRet = new CCEaseExponentialIn();
    if (pRet)
    {
        if (pRet->initWithAction(pAction))
        {
            pRet->autorelease();
        }
        else
        {
            CC_SAFE_RELEASE_NULL(pRet);
        }
    }

    return pRet;    
}

CCObject* CCEaseExponentialIn::copyWithZone(CCZone *pZone)
{
    CCZone* pNewZone = NULL;
    CCEaseExponentialIn* pCopy = NULL;
    if(pZone && pZone->m_pCopyObject) 
    {
        //in case of being called at sub class
        pCopy = (CCEaseExponentialIn*)(pZone->m_pCopyObject);
    }
    else
    {
        pCopy = new CCEaseExponentialIn();
        pNewZone = new CCZone(pCopy);
    }

    pCopy->initWithAction((CCActionInterval *)(m_pInner->copy()->autorelease()));
    
    CC_SAFE_DELETE(pNewZone);
    return pCopy;
}

void CCEaseExponentialIn::update(float time)
{
    m_pInner->update(time == 0 ? 0 : powf(2, 10 * (time/1 - 1)) - 1 * 0.001f);
}

CCActionInterval* CCEaseExponentialIn::reverse(void)
{
    return CCEaseExponentialOut::create(m_pInner->reverse());
}

//
// EaseExponentialOut
//
CCEaseExponentialOut* CCEaseExponentialOut::create(CCActionInterval* pAction)
{
    CCEaseExponentialOut *pRet = new CCEaseExponentialOut();
    if (pRet)
    {
        if (pRet->initWithAction(pAction))
        {
            pRet->autorelease();
        }
        else
        {
            CC_SAFE_RELEASE_NULL(pRet);
        }
    }

    return pRet; 
}

CCObject* CCEaseExponentialOut::copyWithZone(CCZone *pZone)
{
    CCZone* pNewZone = NULL;
    CCEaseExponentialOut* pCopy = NULL;
    if(pZone && pZone->m_pCopyObject) 
    {
        //in case of being called at sub class
        pCopy = (CCEaseExponentialOut*)(pZone->m_pCopyObject);
    }
    else
    {
        pCopy = new CCEaseExponentialOut();
        pNewZone = new CCZone(pCopy);
    }

    pCopy->initWithAction((CCActionInterval *)(m_pInner->copy()->autorelease()));
    
    CC_SAFE_DELETE(pNewZone);
    return pCopy;
}

void CCEaseExponentialOut::update(float time)
{
    m_pInner->update(time == 1 ? 1 : (-powf(2, -10 * time / 1) + 1));
}

CCActionInterval* CCEaseExponentialOut::reverse(void)
{
    return CCEaseExponentialIn::create(m_pInner->reverse());
}

//
// EaseExponentialInOut
//

CCEaseExponentialInOut* CCEaseExponentialInOut::create(CCActionInterval *pAction)
{
    CCEaseExponentialInOut *pRet = new CCEaseExponentialInOut();
    if (pRet)
    {
        if (pRet->initWithAction(pAction))
        {
            pRet->autorelease();
        }
        else
        {
            CC_SAFE_RELEASE_NULL(pRet);
        }
    }

    return pRet; 
}

CCObject* CCEaseExponentialInOut::copyWithZone(CCZone *pZone)
{
    CCZone* pNewZone = NULL;
    CCEaseExponentialInOut* pCopy = NULL;
    if(pZone && pZone->m_pCopyObject) 
    {
        //in case of being called at sub class
        pCopy = (CCEaseExponentialInOut*)(pZone->m_pCopyObject);
    }
    else
    {
        pCopy = new CCEaseExponentialInOut();
        pNewZone = new CCZone(pCopy);
    }

    pCopy->initWithAction((CCActionInterval *)(m_pInner->copy()->autorelease()));
    
    CC_SAFE_DELETE(pNewZone);
    return pCopy;
}

void CCEaseExponentialInOut::update(float time)
{
    time /= 0.5f;
    if (time < 1)
    {
        time = 0.5f * powf(2, 10 * (time - 1));
    }
    else
    {
        time = 0.5f * (-powf(2, -10 * (time - 1)) + 2);
    }

    m_pInner->update(time);
}

CCActionInterval* CCEaseExponentialInOut::reverse()
{
    return CCEaseExponentialInOut::create(m_pInner->reverse());
}

//
// EaseSineIn
//

CCEaseSineIn* CCEaseSineIn::create(CCActionInterval* pAction)
{
    CCEaseSineIn *pRet = new CCEaseSineIn();
    if (pRet)
    {
        if (pRet->initWithAction(pAction))
        {
            pRet->autorelease();
        }
        else
        {
            CC_SAFE_RELEASE_NULL(pRet);
        }
    }

    return pRet; 
}

CCObject* CCEaseSineIn::copyWithZone(CCZone *pZone)
{
    CCZone* pNewZone = NULL;
    CCEaseSineIn* pCopy = NULL;
    if(pZone && pZone->m_pCopyObject)
    {
        //in case of being called at sub class
        pCopy = (CCEaseSineIn*)(pZone->m_pCopyObject);
    }
    else
    {
        pCopy = new CCEaseSineIn();
        pNewZone = new CCZone(pCopy);
    }

    pCopy->initWithAction((CCActionInterval *)(m_pInner->copy()->autorelease()));
    
    CC_SAFE_DELETE(pNewZone);
    return pCopy;
}

void CCEaseSineIn::update(float time)
{
    m_pInner->update(-1 * cosf(time * (float)M_PI_2) + 1);
}

CCActionInterval* CCEaseSineIn::reverse(void)
{
    return CCEaseSineOut::create(m_pInner->reverse());
}

//
// EaseSineOut
//

CCEaseSineOut* CCEaseSineOut::create(CCActionInterval* pAction)
{
    CCEaseSineOut *pRet = new CCEaseSineOut();
    if (pRet)
    {
        if (pRet->initWithAction(pAction))
        {
            pRet->autorelease();
        }
        else
        {
            CC_SAFE_RELEASE_NULL(pRet);
        }
    }

    return pRet; 
}

CCObject* CCEaseSineOut::copyWithZone(CCZone *pZone)
{
    CCZone* pNewZone = NULL;
    CCEaseSineOut* pCopy = NULL;
    if(pZone && pZone->m_pCopyObject) 
    {
        //in case of being called at sub class
        pCopy = (CCEaseSineOut*)(pZone->m_pCopyObject);
    }
    else
    {
        pCopy = new CCEaseSineOut();
        pNewZone = new CCZone(pCopy);
    }

    pCopy->initWithAction((CCActionInterval *)(m_pInner->copy()->autorelease()));
    
    CC_SAFE_DELETE(pNewZone);
    return pCopy;
}

void CCEaseSineOut::update(float time)
{
    m_pInner->update(sinf(time * (float)M_PI_2));
}

CCActionInterval* CCEaseSineOut::reverse(void)
{
    return CCEaseSineIn::create(m_pInner->reverse());
}

//
// EaseSineInOut
//

CCEaseSineInOut* CCEaseSineInOut::create(CCActionInterval* pAction)
{
    CCEaseSineInOut *pRet = new CCEaseSineInOut();
    if (pRet)
    {
        if (pRet->initWithAction(pAction))
        {
            pRet->autorelease();
        }
        else
        {
            CC_SAFE_RELEASE_NULL(pRet);
        }
    }

    return pRet; 
}

CCObject* CCEaseSineInOut::copyWithZone(CCZone *pZone)
{
    CCZone* pNewZone = NULL;
    CCEaseSineInOut* pCopy = NULL;
    if(pZone && pZone->m_pCopyObject) 
    {
        //in case of being called at sub class
        pCopy = (CCEaseSineInOut*)(pZone->m_pCopyObject);
    }
    else
    {
        pCopy = new CCEaseSineInOut();
        pNewZone = new CCZone(pCopy);
    }

    pCopy->initWithAction((CCActionInterval *)(m_pInner->copy()->autorelease()));
    
    CC_SAFE_DELETE(pNewZone);
    return pCopy;
}

void CCEaseSineInOut::update(float time)
{
    m_pInner->update(-0.5f * (cosf((float)M_PI * time) - 1));
}

CCActionInterval* CCEaseSineInOut::reverse()
{
    return CCEaseSineInOut::create(m_pInner->reverse());
}

//
// EaseElastic
//

CCEaseElastic* CCEaseElastic::create(CCActionInterval *pAction)
{
    return CCEaseElastic::create(pAction, 0.3f);
}

CCEaseElastic* CCEaseElastic::create(CCActionInterval *pAction, float fPeriod/* = 0.3f*/)
{
    CCEaseElastic *pRet = new CCEaseElastic();
    if (pRet)
    {
        if (pRet->initWithAction(pAction, fPeriod))
        {
            pRet->autorelease();
        }
        else
        {
            CC_SAFE_RELEASE_NULL(pRet);
        }
    }

    return pRet; 
}

bool CCEaseElastic::initWithAction(CCActionInterval *pAction, float fPeriod/* = 0.3f*/)
{
    if (CCActionEase::initWithAction(pAction))
    {
        m_fPeriod = fPeriod;
        return true;
    }

    return false;
}

CCObject* CCEaseElastic::copyWithZone(CCZone *pZone)
{
    CCZone* pNewZone = NULL;
    CCEaseElastic* pCopy = NULL;
    if(pZone && pZone->m_pCopyObject) 
    {
        //in case of being called at sub class
        pCopy = (CCEaseElastic*)(pZone->m_pCopyObject);
    }
    else
    {
        pCopy = new CCEaseElastic();
        pNewZone = new CCZone(pCopy);
    }

    pCopy->initWithAction((CCActionInterval *)(m_pInner->copy()->autorelease()), m_fPeriod);

    CC_SAFE_DELETE(pNewZone);
    return pCopy;
}

CCActionInterval* CCEaseElastic::reverse(void)
{
    CCAssert(0, "Override me");

    return NULL;
}

//
// EaseElasticIn
//

CCEaseElasticIn* CCEaseElasticIn::create(CCActionInterval *pAction)
{
    return CCEaseElasticIn::create(pAction, 0.3f);
}

CCEaseElasticIn* CCEaseElasticIn::create(CCActionInterval *pAction, float fPeriod/* = 0.3f*/)
{
    CCEaseElasticIn *pRet = new CCEaseElasticIn();
    if (pRet)
    {
        if (pRet->initWithAction(pAction, fPeriod))
        {
            pRet->autorelease();
        }
        else
        {
            CC_SAFE_RELEASE_NULL(pRet);
        }
    }

    return pRet; 
}

CCObject* CCEaseElasticIn::copyWithZone(CCZone *pZone)
{
    CCZone* pNewZone = NULL;
    CCEaseElasticIn* pCopy = NULL;
    if(pZone && pZone->m_pCopyObject) 
    {
        //in case of being called at sub class
        pCopy = (CCEaseElasticIn*)(pZone->m_pCopyObject);
    }
    else
    {
        pCopy = new CCEaseElasticIn();
        pNewZone = new CCZone(pCopy);
    }

    pCopy->initWithAction((CCActionInterval *)(m_pInner->copy()->autorelease()), m_fPeriod);

    CC_SAFE_DELETE(pNewZone);
    return pCopy;
}

void CCEaseElasticIn::update(float time)
{
    float newT = 0;
    if (time == 0 || time == 1)
    {
        newT = time;
    }
    else
    {
        float s = m_fPeriod / 4;
        time = time - 1;
        newT = -powf(2, 10 * time) * sinf((time - s) * M_PI_X_2 / m_fPeriod);
    }

    m_pInner->update(newT);
}

CCActionInterval* CCEaseElasticIn::reverse(void)
{
    return CCEaseElasticOut::create(m_pInner->reverse(), m_fPeriod);
}

//
// EaseElasticOut
//

CCEaseElasticOut* CCEaseElasticOut::create(CCActionInterval *pAction)
{
    return CCEaseElasticOut::create(pAction, 0.3f);
}

CCEaseElasticOut* CCEaseElasticOut::create(CCActionInterval *pAction, float fPeriod/* = 0.3f*/)
{
    CCEaseElasticOut *pRet = new CCEaseElasticOut();
    if (pRet)
    {
        if (pRet->initWithAction(pAction, fPeriod))
        {
            pRet->autorelease();
        }
        else
        {
            CC_SAFE_RELEASE_NULL(pRet);
        }
    }

    return pRet; 
}

CCObject *CCEaseElasticOut::copyWithZone(CCZone *pZone)
{
    CCZone* pNewZone = NULL;
    CCEaseElasticOut* pCopy = NULL;
    if(pZone && pZone->m_pCopyObject) 
    {
        //in case of being called at sub class
        pCopy = (CCEaseElasticOut*)(pZone->m_pCopyObject);
    }
    else
    {
        pCopy = new CCEaseElasticOut();
        pNewZone = new CCZone(pCopy);
    }

    pCopy->initWithAction((CCActionInterval *)(m_pInner->copy()->autorelease()), m_fPeriod);

    CC_SAFE_DELETE(pNewZone);
    return pCopy;
}

void CCEaseElasticOut::update(float time)
{
    float newT = 0;
    if (time == 0 || time == 1)
    {
        newT = time;
    }
    else
    {
        float s = m_fPeriod / 4;
        newT = powf(2, -10 * time) * sinf((time - s) * M_PI_X_2 / m_fPeriod) + 1;
    }

    m_pInner->update(newT);
}

CCActionInterval* CCEaseElasticOut::reverse(void)
{
    return CCEaseElasticIn::create(m_pInner->reverse(), m_fPeriod);
}

//
// EaseElasticInOut
//

CCEaseElasticInOut* CCEaseElasticInOut::create(CCActionInterval *pAction)
{
    return CCEaseElasticInOut::create(pAction, 0.3f);
}

CCEaseElasticInOut* CCEaseElasticInOut::create(CCActionInterval *pAction, float fPeriod/* = 0.3f*/)
{
    CCEaseElasticInOut *pRet = new CCEaseElasticInOut();
    if (pRet)
    {
        if (pRet->initWithAction(pAction, fPeriod))
        {
            pRet->autorelease();
        }
        else
        {
            CC_SAFE_RELEASE_NULL(pRet);
        }
    }

    return pRet; 
}

CCObject* CCEaseElasticInOut::copyWithZone(CCZone *pZone)
{
    CCZone* pNewZone = NULL;
    CCEaseElasticInOut* pCopy = NULL;
    if(pZone && pZone->m_pCopyObject) 
    {
        //in case of being called at sub class
        pCopy = (CCEaseElasticInOut*)(pZone->m_pCopyObject);
    }
    else
    {
        pCopy = new CCEaseElasticInOut();
        pNewZone = new CCZone(pCopy);
    }

    pCopy->initWithAction((CCActionInterval *)(m_pInner->copy()->autorelease()), m_fPeriod);

    CC_SAFE_DELETE(pNewZone);
    return pCopy;

}

void CCEaseElasticInOut::update(float time)
{
    float newT = 0;
    if (time == 0 || time == 1)
    {
        newT = time;
    }
    else
    {
        time = time * 2;
        if (! m_fPeriod)
        {
            m_fPeriod = 0.3f * 1.5f;
        }

        float s = m_fPeriod / 4;

        time = time - 1;
        if (time < 0)
        {
            newT = -0.5f * powf(2, 10 * time) * sinf((time -s) * M_PI_X_2 / m_fPeriod);
        }
        else
        {
            newT = powf(2, -10 * time) * sinf((time - s) * M_PI_X_2 / m_fPeriod) * 0.5f + 1;
        }
    }

    m_pInner->update(newT);
}

CCActionInterval* CCEaseElasticInOut::reverse(void)
{
    return CCEaseElasticInOut::create(m_pInner->reverse(), m_fPeriod);
}

//
// EaseBounce
//

CCEaseBounce* CCEaseBounce::create(CCActionInterval* pAction)
{
    CCEaseBounce *pRet = new CCEaseBounce();
    if (pRet)
    {
        if (pRet->initWithAction(pAction))
        {
            pRet->autorelease();
        }
        else
        {
            CC_SAFE_RELEASE_NULL(pRet);
        }
    }

    return pRet; 
}

CCObject* CCEaseBounce::copyWithZone(CCZone *pZone)
{
    CCZone* pNewZone = NULL;
    CCEaseBounce* pCopy = NULL;
    if(pZone && pZone->m_pCopyObject) 
    {
        //in case of being called at sub class
        pCopy = (CCEaseBounce*)(pZone->m_pCopyObject);
    }
    else
    {
        pCopy = new CCEaseBounce();
        pNewZone = new CCZone(pCopy);
    }

    pCopy->initWithAction((CCActionInterval *)(m_pInner->copy()->autorelease()));
    
    CC_SAFE_DELETE(pNewZone);
    return pCopy;
}

float CCEaseBounce::bounceTime(float time)
{
    if (time < 1 / 2.75)
    {
        return 7.5625f * time * time;
    } else 
    if (time < 2 / 2.75)
    {
        time -= 1.5f / 2.75f;
        return 7.5625f * time * time + 0.75f;
    } else
    if(time < 2.5 / 2.75)
    {
        time -= 2.25f / 2.75f;
        return 7.5625f * time * time + 0.9375f;
    }

    time -= 2.625f / 2.75f;
    return 7.5625f * time * time + 0.984375f;
}

CCActionInterval* CCEaseBounce::reverse()
{
    return CCEaseBounce::create(m_pInner->reverse());
}

//
// EaseBounceIn
//

CCEaseBounceIn* CCEaseBounceIn::create(CCActionInterval* pAction)
{
    CCEaseBounceIn *pRet = new CCEaseBounceIn();
    if (pRet)
    {
        if (pRet->initWithAction(pAction))
        {
            pRet->autorelease();
        }
        else
        {
            CC_SAFE_RELEASE_NULL(pRet);
        }
    }

    return pRet; 
}

CCObject* CCEaseBounceIn::copyWithZone(CCZone *pZone)
{
    CCZone* pNewZone = NULL;
    CCEaseBounceIn* pCopy = NULL;
    if(pZone && pZone->m_pCopyObject) 
    {
        //in case of being called at sub class
        pCopy = (CCEaseBounceIn*)(pZone->m_pCopyObject);
    }
    else
    {
        pCopy = new CCEaseBounceIn();
        pNewZone = new CCZone(pCopy);
    }

    pCopy->initWithAction((CCActionInterval *)(m_pInner->copy()->autorelease()));
    
    CC_SAFE_DELETE(pNewZone);
    return pCopy;
}

void CCEaseBounceIn::update(float time)
{
    float newT = 1 - bounceTime(1 - time);
    m_pInner->update(newT);
}

CCActionInterval* CCEaseBounceIn::reverse(void)
{
    return CCEaseBounceOut::create(m_pInner->reverse());
}

//
// EaseBounceOut
//

CCEaseBounceOut* CCEaseBounceOut::create(CCActionInterval* pAction)
{
    CCEaseBounceOut *pRet = new CCEaseBounceOut();
    if (pRet)
    {
        if (pRet->initWithAction(pAction))
        {
            pRet->autorelease();
        }
        else
        {
            CC_SAFE_RELEASE_NULL(pRet);
        }
    }

    return pRet; 
}

CCObject* CCEaseBounceOut::copyWithZone(CCZone *pZone)
{
    CCZone* pNewZone = NULL;
    CCEaseBounceOut* pCopy = NULL;
    if(pZone && pZone->m_pCopyObject)
    {
        //in case of being called at sub class
        pCopy = (CCEaseBounceOut*)(pZone->m_pCopyObject);
    }
    else
    {
        pCopy = new CCEaseBounceOut();
        pNewZone = new CCZone(pCopy);
    }

    pCopy->initWithAction((CCActionInterval *)(m_pInner->copy()->autorelease()));
    
    CC_SAFE_DELETE(pNewZone);
    return pCopy;
}

void CCEaseBounceOut::update(float time)
{
    float newT = bounceTime(time);
    m_pInner->update(newT);
}

CCActionInterval* CCEaseBounceOut::reverse(void)
{
    return CCEaseBounceIn::create(m_pInner->reverse());
}

//
// EaseBounceInOut
//

CCEaseBounceInOut* CCEaseBounceInOut::create(CCActionInterval* pAction)
{
    CCEaseBounceInOut *pRet = new CCEaseBounceInOut();
    if (pRet)
    {
        if (pRet->initWithAction(pAction))
        {
            pRet->autorelease();
        }
        else
        {
            CC_SAFE_RELEASE_NULL(pRet);
        }
    }

    return pRet; 
}

CCObject* CCEaseBounceInOut::copyWithZone(CCZone *pZone)
{
    CCZone* pNewZone = NULL;
    CCEaseBounceInOut* pCopy = NULL;
    if(pZone && pZone->m_pCopyObject) 
    {
        //in case of being called at sub class
        pCopy = (CCEaseBounceInOut*)(pZone->m_pCopyObject);
    }
    else
    {
        pCopy = new CCEaseBounceInOut();
        pNewZone = new CCZone(pCopy);
    }

    pCopy->initWithAction((CCActionInterval *)(m_pInner->copy()->autorelease()));
    
    CC_SAFE_DELETE(pNewZone);
    return pCopy;
}

void CCEaseBounceInOut::update(float time)
{
    float newT = 0;
    if (time < 0.5f)
    {
        time = time * 2;
        newT = (1 - bounceTime(1 - time)) * 0.5f;
    }
    else
    {
        newT = bounceTime(time * 2 - 1) * 0.5f + 0.5f;
    }

    m_pInner->update(newT);
}

CCActionInterval* CCEaseBounceInOut::reverse()
{
    return CCEaseBounceInOut::create(m_pInner->reverse());
}

//
// EaseBackIn
//

CCEaseBackIn* CCEaseBackIn::create(CCActionInterval *pAction)
{
    CCEaseBackIn *pRet = new CCEaseBackIn();
    if (pRet)
    {
        if (pRet->initWithAction(pAction))
        {
            pRet->autorelease();
        }
        else
        {
            CC_SAFE_RELEASE_NULL(pRet);
        }
    }

    return pRet;
}

CCObject* CCEaseBackIn::copyWithZone(CCZone *pZone)
{
    CCZone* pNewZone = NULL;
    CCEaseBackIn* pCopy = NULL;
    if(pZone && pZone->m_pCopyObject) 
    {
        //in case of being called at sub class
        pCopy = (CCEaseBackIn*)(pZone->m_pCopyObject);
    }
    else
    {
        pCopy = new CCEaseBackIn();
        pNewZone = new CCZone(pCopy);
    }

    pCopy->initWithAction((CCActionInterval *)(m_pInner->copy()->autorelease()));
    
    CC_SAFE_DELETE(pNewZone);
    return pCopy;
}

void CCEaseBackIn::update(float time)
{
    float overshoot = 1.70158f;
    m_pInner->update(time * time * ((overshoot + 1) * time - overshoot));
}

CCActionInterval* CCEaseBackIn::reverse(void)
{
    return CCEaseBackOut::create(m_pInner->reverse());
}

//
// EaseBackOut
//

CCEaseBackOut* CCEaseBackOut::create(CCActionInterval* pAction)
{
    CCEaseBackOut *pRet = new CCEaseBackOut();
    if (pRet)
    {
        if (pRet->initWithAction(pAction))
        {
            pRet->autorelease();
        }
        else
        {
            CC_SAFE_RELEASE_NULL(pRet);
        }
    }

    return pRet;
}

CCObject* CCEaseBackOut::copyWithZone(CCZone *pZone)
{
    CCZone* pNewZone = NULL;
    CCEaseBackOut* pCopy = NULL;
    if(pZone && pZone->m_pCopyObject) 
    {
        //in case of being called at sub class
        pCopy = (CCEaseBackOut*)(pZone->m_pCopyObject);
    }
    else
    {
        pCopy = new CCEaseBackOut();
        pNewZone = new CCZone(pCopy);
    }

    pCopy->initWithAction((CCActionInterval *)(m_pInner->copy()->autorelease()));
    
    CC_SAFE_DELETE(pNewZone);
    return pCopy;
}

void CCEaseBackOut::update(float time)
{
    float overshoot = 1.70158f;

    time = time - 1;
    m_pInner->update(time * time * ((overshoot + 1) * time + overshoot) + 1);
}

CCActionInterval* CCEaseBackOut::reverse(void)
{
    return CCEaseBackIn::create(m_pInner->reverse());
}

//
// EaseBackInOut
//

CCEaseBackInOut* CCEaseBackInOut::create(CCActionInterval* pAction)
{
    CCEaseBackInOut *pRet = new CCEaseBackInOut();
    if (pRet)
    {
        if (pRet->initWithAction(pAction))
        {
            pRet->autorelease();
        }
        else
        {
            CC_SAFE_RELEASE_NULL(pRet);
        }
    }

    return pRet;
}

CCObject* CCEaseBackInOut::copyWithZone(CCZone *pZone)
{
    CCZone* pNewZone = NULL;
    CCEaseBackInOut* pCopy = NULL;
    if(pZone && pZone->m_pCopyObject) 
    {
        //in case of being called at sub class
        pCopy = (CCEaseBackInOut*)(pZone->m_pCopyObject);
    }
    else
    {
        pCopy = new CCEaseBackInOut();
        pNewZone = new CCZone(pCopy);
    }

    pCopy->initWithAction((CCActionInterval *)(m_pInner->copy()->autorelease()));
    
    CC_SAFE_DELETE(pNewZone);
    return pCopy;
}

void CCEaseBackInOut::update(float time)
{
    float overshoot = 1.70158f * 1.525f;

    time = time * 2;
    if (time < 1)
    {
        m_pInner->update((time * time * ((overshoot + 1) * time - overshoot)) / 2);
    }
    else
    {
        time = time - 2;
        m_pInner->update((time * time * ((overshoot + 1) * time + overshoot)) / 2 + 1);
    }
}

CCActionInterval* CCEaseBackInOut::reverse()
{
    return CCEaseBackInOut::create(m_pInner->reverse());
}

//add for css
//
//
//
//
//

static inline float bezieratFunction( float a, float b, float c, float d, float t )
{
    return (powf(1-t,3) * a + 
        3*t*(powf(1-t,2))*b + 
        3*powf(t,2)*(1-t)*c +
        powf(t,3)*d );
}

//
// EaseBezier
//

CCEaseBezierAction* CCEaseBezierAction::create(CCActionInterval* pAction)
{
    CCEaseBezierAction *pRet = new CCEaseBezierAction();
    if (pRet)
    {
        if (pRet->initWithAction(pAction))
        {
            pRet->autorelease();
        }
        else
        {
            CC_SAFE_RELEASE_NULL(pRet);
        }
    }

    return pRet; 
}

void CCEaseBezierAction::setBezierParamer( float p0, float p1, float p2, float p3)
{
    m_p0 = p0;
    m_p1 = p1;
    m_p2 = p2;
    m_p3 = p3;
}

CCObject* CCEaseBezierAction::copyWithZone(CCZone *pZone)
{
    CCZone* pNewZone = NULL;
    CCEaseBezierAction* pCopy = NULL;
    if(pZone && pZone->m_pCopyObject) 
    {
        //in case of being called at sub class
        pCopy = (CCEaseBezierAction*)(pZone->m_pCopyObject);
    }
    else
    {
        pCopy = new CCEaseBezierAction();
        pNewZone = new CCZone(pCopy);
    }

    pCopy->initWithAction((CCActionInterval *)(m_pInner->copy()->autorelease()));
    pCopy->setBezierParamer(m_p0,m_p1,m_p2,m_p3);
    CC_SAFE_DELETE(pNewZone);
    return pCopy;
}

void CCEaseBezierAction::update(float time)
{
    m_pInner->update(bezieratFunction(m_p0,m_p1,m_p2,m_p3,time));
}

CCActionInterval* CCEaseBezierAction::reverse(void)
{
    CCEaseBezierAction* reverseAction = CCEaseBezierAction::create(m_pInner->reverse());
    reverseAction->setBezierParamer(m_p3,m_p2,m_p1,m_p0);
    return reverseAction;
}

//
// CCEaseQuadraticActionIn
//

CCEaseQuadraticActionIn* CCEaseQuadraticActionIn::create(CCActionInterval* pAction)
{
    CCEaseQuadraticActionIn *pRet = new CCEaseQuadraticActionIn();
    if (pRet)
    {
        if (pRet->initWithAction(pAction))
        {
            pRet->autorelease();
        }
        else
        {
            CC_SAFE_RELEASE_NULL(pRet);
        }
    }

    return pRet; 
}

CCObject* CCEaseQuadraticActionIn::copyWithZone(CCZone *pZone)
{
    CCZone* pNewZone = NULL;
    CCEaseQuadraticActionIn* pCopy = NULL;
    if(pZone && pZone->m_pCopyObject) 
    {
        //in case of being called at sub class
        pCopy = (CCEaseQuadraticActionIn*)(pZone->m_pCopyObject);
    }
    else
    {
        pCopy = new CCEaseQuadraticActionIn();
        pNewZone = new CCZone(pCopy);
    }

    pCopy->initWithAction((CCActionInterval *)(m_pInner->copy()->autorelease()));

    CC_SAFE_DELETE(pNewZone);
    return pCopy;
}

void CCEaseQuadraticActionIn::update(float time)
{
    m_pInner->update(powf(time,2));
}

CCActionInterval* CCEaseQuadraticActionIn::reverse(void)
{
    return CCEaseQuadraticActionIn::create(m_pInner->reverse());
}

//
// CCEaseQuadraticActionOut
//

CCEaseQuadraticActionOut* CCEaseQuadraticActionOut::create(CCActionInterval* pAction)
{
    CCEaseQuadraticActionOut *pRet = new CCEaseQuadraticActionOut();
    if (pRet)
    {
        if (pRet->initWithAction(pAction))
        {
            pRet->autorelease();
        }
        else
        {
            CC_SAFE_RELEASE_NULL(pRet);
        }
    }

    return pRet; 
}

CCObject* CCEaseQuadraticActionOut::copyWithZone(CCZone *pZone)
{
    CCZone* pNewZone = NULL;
    CCEaseQuadraticActionOut* pCopy = NULL;
    if(pZone && pZone->m_pCopyObject) 
    {
        //in case of being called at sub class
        pCopy = (CCEaseQuadraticActionOut*)(pZone->m_pCopyObject);
    }
    else
    {
        pCopy = new CCEaseQuadraticActionOut();
        pNewZone = new CCZone(pCopy);
    }

    pCopy->initWithAction((CCActionInterval *)(m_pInner->copy()->autorelease()));

    CC_SAFE_DELETE(pNewZone);
    return pCopy;
}

void CCEaseQuadraticActionOut::update(float time)
{   
    m_pInner->update(-time*(time-2));
}

CCActionInterval* CCEaseQuadraticActionOut::reverse(void)
{
    return CCEaseQuadraticActionOut::create(m_pInner->reverse());
}

//
// CCEaseQuadraticActionInOut
//

CCEaseQuadraticActionInOut* CCEaseQuadraticActionInOut::create(CCActionInterval* pAction)
{
    CCEaseQuadraticActionInOut *pRet = new CCEaseQuadraticActionInOut();
    if (pRet)
    {
        if (pRet->initWithAction(pAction))
        {
            pRet->autorelease();
        }
        else
        {
            CC_SAFE_RELEASE_NULL(pRet);
        }
    }

    return pRet; 
}

CCObject* CCEaseQuadraticActionInOut::copyWithZone(CCZone *pZone)
{
    CCZone* pNewZone = NULL;
    CCEaseQuadraticActionInOut* pCopy = NULL;
    if(pZone && pZone->m_pCopyObject) 
    {
        //in case of being called at sub class
        pCopy = (CCEaseQuadraticActionInOut*)(pZone->m_pCopyObject);
    }
    else
    {
        pCopy = new CCEaseQuadraticActionInOut();
        pNewZone = new CCZone(pCopy);
    }

    pCopy->initWithAction((CCActionInterval *)(m_pInner->copy()->autorelease()));

    CC_SAFE_DELETE(pNewZone);
    return pCopy;
}

void CCEaseQuadraticActionInOut::update(float time)
{
    float resultTime = time;
    time = time*2;
    if (time < 1)
    {
        resultTime = time * time * 0.5f;
    }
    else
    {
        --time;
        resultTime = -0.5f * (time * (time - 2) - 1);
    }

    m_pInner->update(resultTime);
}

CCActionInterval* CCEaseQuadraticActionInOut::reverse(void)
{
    return CCEaseQuadraticActionInOut::create(m_pInner->reverse());
}

//
// CCEaseQuarticActionIn
//

CCEaseQuarticActionIn* CCEaseQuarticActionIn::create(CCActionInterval* pAction)
{
    CCEaseQuarticActionIn *pRet = new CCEaseQuarticActionIn();
    if (pRet)
    {
        if (pRet->initWithAction(pAction))
        {
            pRet->autorelease();
        }
        else
        {
            CC_SAFE_RELEASE_NULL(pRet);
        }
    }

    return pRet; 
}

CCObject* CCEaseQuarticActionIn::copyWithZone(CCZone *pZone)
{
    CCZone* pNewZone = NULL;
    CCEaseQuarticActionIn* pCopy = NULL;
    if(pZone && pZone->m_pCopyObject) 
    {
        //in case of being called at sub class
        pCopy = (CCEaseQuarticActionIn*)(pZone->m_pCopyObject);
    }
    else
    {
        pCopy = new CCEaseQuarticActionIn();
        pNewZone = new CCZone(pCopy);
    }

    pCopy->initWithAction((CCActionInterval *)(m_pInner->copy()->autorelease()));

    CC_SAFE_DELETE(pNewZone);
    return pCopy;
}

void CCEaseQuarticActionIn::update(float time)
{
    m_pInner->update(powf(time,4.0f));
}

CCActionInterval* CCEaseQuarticActionIn::reverse(void)
{
    return CCEaseQuarticActionIn::create(m_pInner->reverse());
}

//
// CCEaseQuarticActionOut
//

CCEaseQuarticActionOut* CCEaseQuarticActionOut::create(CCActionInterval* pAction)
{
    CCEaseQuarticActionOut *pRet = new CCEaseQuarticActionOut();
    if (pRet)
    {
        if (pRet->initWithAction(pAction))
        {
            pRet->autorelease();
        }
        else
        {
            CC_SAFE_RELEASE_NULL(pRet);
        }
    }

    return pRet; 
}

CCObject* CCEaseQuarticActionOut::copyWithZone(CCZone *pZone)
{
    CCZone* pNewZone = NULL;
    CCEaseQuarticActionOut* pCopy = NULL;
    if(pZone && pZone->m_pCopyObject) 
    {
        //in case of being called at sub class
        pCopy = (CCEaseQuarticActionOut*)(pZone->m_pCopyObject);
    }
    else
    {
        pCopy = new CCEaseQuarticActionOut();
        pNewZone = new CCZone(pCopy);
    }

    pCopy->initWithAction((CCActionInterval *)(m_pInner->copy()->autorelease()));

    CC_SAFE_DELETE(pNewZone);
    return pCopy;
}

void CCEaseQuarticActionOut::update(float time)
{
    float tempTime = time -1;   
    m_pInner->update(1- powf(tempTime,4.0f));
}

CCActionInterval* CCEaseQuarticActionOut::reverse(void)
{
    return CCEaseQuarticActionOut::create(m_pInner->reverse());
}

//
// CCEaseQuarticActionInOut
//

CCEaseQuarticActionInOut* CCEaseQuarticActionInOut::create(CCActionInterval* pAction)
{
    CCEaseQuarticActionInOut *pRet = new CCEaseQuarticActionInOut();
    if (pRet)
    {
        if (pRet->initWithAction(pAction))
        {
            pRet->autorelease();
        }
        else
        {
            CC_SAFE_RELEASE_NULL(pRet);
        }
    }

    return pRet; 
}

CCObject* CCEaseQuarticActionInOut::copyWithZone(CCZone *pZone)
{
    CCZone* pNewZone = NULL;
    CCEaseQuarticActionInOut* pCopy = NULL;
    if(pZone && pZone->m_pCopyObject) 
    {
        //in case of being called at sub class
        pCopy = (CCEaseQuarticActionInOut*)(pZone->m_pCopyObject);
    }
    else
    {
        pCopy = new CCEaseQuarticActionInOut();
        pNewZone = new CCZone(pCopy);
    }

    pCopy->initWithAction((CCActionInterval *)(m_pInner->copy()->autorelease()));

    CC_SAFE_DELETE(pNewZone);
    return pCopy;
}

void CCEaseQuarticActionInOut::update(float time)
{
    float tempTime = time * 2;
    if (tempTime < 1)
        tempTime =  powf(tempTime,4.0f) * 0.5f;
    else
    {
        tempTime -= 2;
        tempTime = 1 - powf(tempTime,4.0f)* 0.5f;
    }

    m_pInner->update(tempTime);
}

CCActionInterval* CCEaseQuarticActionInOut::reverse(void)
{
    return CCEaseQuarticActionInOut::create(m_pInner->reverse());
}

//
// CCEaseQuinticActionIn
//

CCEaseQuinticActionIn* CCEaseQuinticActionIn::create(CCActionInterval* pAction)
{
    CCEaseQuinticActionIn *pRet = new CCEaseQuinticActionIn();
    if (pRet)
    {
        if (pRet->initWithAction(pAction))
        {
            pRet->autorelease();
        }
        else
        {
            CC_SAFE_RELEASE_NULL(pRet);
        }
    }

    return pRet; 
}

CCObject* CCEaseQuinticActionIn::copyWithZone(CCZone *pZone)
{
    CCZone* pNewZone = NULL;
    CCEaseQuinticActionIn* pCopy = NULL;
    if(pZone && pZone->m_pCopyObject) 
    {
        //in case of being called at sub class
        pCopy = (CCEaseQuinticActionIn*)(pZone->m_pCopyObject);
    }
    else
    {
        pCopy = new CCEaseQuinticActionIn();
        pNewZone = new CCZone(pCopy);
    }

    pCopy->initWithAction((CCActionInterval *)(m_pInner->copy()->autorelease()));

    CC_SAFE_DELETE(pNewZone);
    return pCopy;
}

void CCEaseQuinticActionIn::update(float time)
{
    m_pInner->update(powf(time,5.0f));
}

CCActionInterval* CCEaseQuinticActionIn::reverse(void)
{
    return CCEaseQuinticActionIn::create(m_pInner->reverse());
}

//
// CCEaseQuinticActionOut
//

CCEaseQuinticActionOut* CCEaseQuinticActionOut::create(CCActionInterval* pAction)
{
    CCEaseQuinticActionOut *pRet = new CCEaseQuinticActionOut();
    if (pRet)
    {
        if (pRet->initWithAction(pAction))
        {
            pRet->autorelease();
        }
        else
        {
            CC_SAFE_RELEASE_NULL(pRet);
        }
    }

    return pRet; 
}

CCObject* CCEaseQuinticActionOut::copyWithZone(CCZone *pZone)
{
    CCZone* pNewZone = NULL;
    CCEaseQuinticActionOut* pCopy = NULL;
    if(pZone && pZone->m_pCopyObject) 
    {
        //in case of being called at sub class
        pCopy = (CCEaseQuinticActionOut*)(pZone->m_pCopyObject);
    }
    else
    {
        pCopy = new CCEaseQuinticActionOut();
        pNewZone = new CCZone(pCopy);
    }

    pCopy->initWithAction((CCActionInterval *)(m_pInner->copy()->autorelease()));

    CC_SAFE_DELETE(pNewZone);
    return pCopy;
}

void CCEaseQuinticActionOut::update(float time)
{
    float tempTime = time -1;   
    m_pInner->update(1 + powf(tempTime,5.0f));
}

CCActionInterval* CCEaseQuinticActionOut::reverse(void)
{
    return CCEaseQuinticActionOut::create(m_pInner->reverse());
}

//
// CCEaseQuinticActionInOut
//

CCEaseQuinticActionInOut* CCEaseQuinticActionInOut::create(CCActionInterval* pAction)
{
    CCEaseQuinticActionInOut *pRet = new CCEaseQuinticActionInOut();
    if (pRet)
    {
        if (pRet->initWithAction(pAction))
        {
            pRet->autorelease();
        }
        else
        {
            CC_SAFE_RELEASE_NULL(pRet);
        }
    }

    return pRet; 
}

CCObject* CCEaseQuinticActionInOut::copyWithZone(CCZone *pZone)
{
    CCZone* pNewZone = NULL;
    CCEaseQuinticActionInOut* pCopy = NULL;
    if(pZone && pZone->m_pCopyObject) 
    {
        //in case of being called at sub class
        pCopy = (CCEaseQuinticActionInOut*)(pZone->m_pCopyObject);
    }
    else
    {
        pCopy = new CCEaseQuinticActionInOut();
        pNewZone = new CCZone(pCopy);
    }

    pCopy->initWithAction((CCActionInterval *)(m_pInner->copy()->autorelease()));

    CC_SAFE_DELETE(pNewZone);
    return pCopy;
}

void CCEaseQuinticActionInOut::update(float time)
{
    float tempTime = time * 2;
    if (tempTime < 1)
        tempTime =  powf(tempTime,5.0f) * 0.5f;
    else
    {
        tempTime -= 2;
        tempTime = 1 + powf(tempTime,5.0f)* 0.5f;
    }

    m_pInner->update(tempTime);
}

CCActionInterval* CCEaseQuinticActionInOut::reverse(void)
{
    return CCEaseQuinticActionInOut::create(m_pInner->reverse());
}

//
// CCEaseCircleActionIn
//

CCEaseCircleActionIn* CCEaseCircleActionIn::create(CCActionInterval* pAction)
{
    CCEaseCircleActionIn *pRet = new CCEaseCircleActionIn();
    if (pRet)
    {
        if (pRet->initWithAction(pAction))
        {
            pRet->autorelease();
        }
        else
        {
            CC_SAFE_RELEASE_NULL(pRet);
        }
    }

    return pRet; 
}

CCObject* CCEaseCircleActionIn::copyWithZone(CCZone *pZone)
{
    CCZone* pNewZone = NULL;
    CCEaseCircleActionIn* pCopy = NULL;
    if(pZone && pZone->m_pCopyObject) 
    {
        //in case of being called at sub class
        pCopy = (CCEaseCircleActionIn*)(pZone->m_pCopyObject);
    }
    else
    {
        pCopy = new CCEaseCircleActionIn();
        pNewZone = new CCZone(pCopy);
    }

    pCopy->initWithAction((CCActionInterval *)(m_pInner->copy()->autorelease()));

    CC_SAFE_DELETE(pNewZone);
    return pCopy;
}

void CCEaseCircleActionIn::update(float time)
{
    m_pInner->update(1-sqrt(1-powf(time,2.0f)));
}

CCActionInterval* CCEaseCircleActionIn::reverse(void)
{
    return CCEaseCircleActionIn::create(m_pInner->reverse());
}

//
// CCEaseCircleActionOut
//

CCEaseCircleActionOut* CCEaseCircleActionOut::create(CCActionInterval* pAction)
{
    CCEaseCircleActionOut *pRet = new CCEaseCircleActionOut();
    if (pRet)
    {
        if (pRet->initWithAction(pAction))
        {
            pRet->autorelease();
        }
        else
        {
            CC_SAFE_RELEASE_NULL(pRet);
        }
    }

    return pRet; 
}

CCObject* CCEaseCircleActionOut::copyWithZone(CCZone *pZone)
{
    CCZone* pNewZone = NULL;
    CCEaseCircleActionOut* pCopy = NULL;
    if(pZone && pZone->m_pCopyObject) 
    {
        //in case of being called at sub class
        pCopy = (CCEaseCircleActionOut*)(pZone->m_pCopyObject);
    }
    else
    {
        pCopy = new CCEaseCircleActionOut();
        pNewZone = new CCZone(pCopy);
    }

    pCopy->initWithAction((CCActionInterval *)(m_pInner->copy()->autorelease()));

    CC_SAFE_DELETE(pNewZone);
    return pCopy;
}

void CCEaseCircleActionOut::update(float time)
{
    float tempTime = time - 1;
    m_pInner->update(sqrt(1-powf(tempTime,2.0f)));
}

CCActionInterval* CCEaseCircleActionOut::reverse(void)
{
    return CCEaseCircleActionOut::create(m_pInner->reverse());
}

//
// CCEaseCircleActionInOut
//

CCEaseCircleActionInOut* CCEaseCircleActionInOut::create(CCActionInterval* pAction)
{
    CCEaseCircleActionInOut *pRet = new CCEaseCircleActionInOut();
    if (pRet)
    {
        if (pRet->initWithAction(pAction))
        {
            pRet->autorelease();
        }
        else
        {
            CC_SAFE_RELEASE_NULL(pRet);
        }
    }

    return pRet; 
}

CCObject* CCEaseCircleActionInOut::copyWithZone(CCZone *pZone)
{
    CCZone* pNewZone = NULL;
    CCEaseCircleActionInOut* pCopy = NULL;
    if(pZone && pZone->m_pCopyObject) 
    {
        //in case of being called at sub class
        pCopy = (CCEaseCircleActionInOut*)(pZone->m_pCopyObject);
    }
    else
    {
        pCopy = new CCEaseCircleActionInOut();
        pNewZone = new CCZone(pCopy);
    }

    pCopy->initWithAction((CCActionInterval *)(m_pInner->copy()->autorelease()));

    CC_SAFE_DELETE(pNewZone);
    return pCopy;
}

void CCEaseCircleActionInOut::update(float time)
{
    float tempTime = time * 2;
    if (tempTime < 1)
        tempTime =  (1- sqrt(1 - powf(tempTime,2.0f))) * 0.5f;
    else
    {
        tempTime -= 2;
        tempTime = (1+ sqrt(1 - powf(tempTime,2.0f))) * 0.5f;
    }

    m_pInner->update(time);
}

CCActionInterval* CCEaseCircleActionInOut::reverse(void)
{
    return CCEaseCircleActionInOut::create(m_pInner->reverse());
}

//
// CCEaseCubicActionIn
//

CCEaseCubicActionIn* CCEaseCubicActionIn::create(CCActionInterval* pAction)
{
    CCEaseCubicActionIn *pRet = new CCEaseCubicActionIn();
    if (pRet)
    {
        if (pRet->initWithAction(pAction))
        {
            pRet->autorelease();
        }
        else
        {
            CC_SAFE_RELEASE_NULL(pRet);
        }
    }

    return pRet; 
}

CCObject* CCEaseCubicActionIn::copyWithZone(CCZone *pZone)
{
    CCZone* pNewZone = NULL;
    CCEaseCubicActionIn* pCopy = NULL;
    if(pZone && pZone->m_pCopyObject) 
    {
        //in case of being called at sub class
        pCopy = (CCEaseCubicActionIn*)(pZone->m_pCopyObject);
    }
    else
    {
        pCopy = new CCEaseCubicActionIn();
        pNewZone = new CCZone(pCopy);
    }

    pCopy->initWithAction((CCActionInterval *)(m_pInner->copy()->autorelease()));

    CC_SAFE_DELETE(pNewZone);
    return pCopy;
}

void CCEaseCubicActionIn::update(float time)
{
    m_pInner->update(powf(time,3.0f));
}

CCActionInterval* CCEaseCubicActionIn::reverse(void)
{
    return CCEaseCubicActionIn::create(m_pInner->reverse());
}

//
// CCEaseCubicActionOut
//

CCEaseCubicActionOut* CCEaseCubicActionOut::create(CCActionInterval* pAction)
{
    CCEaseCubicActionOut *pRet = new CCEaseCubicActionOut();
    if (pRet)
    {
        if (pRet->initWithAction(pAction))
        {
            pRet->autorelease();
        }
        else
        {
            CC_SAFE_RELEASE_NULL(pRet);
        }
    }

    return pRet; 
}

CCObject* CCEaseCubicActionOut::copyWithZone(CCZone *pZone)
{
    CCZone* pNewZone = NULL;
    CCEaseCubicActionOut* pCopy = NULL;
    if(pZone && pZone->m_pCopyObject) 
    {
        //in case of being called at sub class
        pCopy = (CCEaseCubicActionOut*)(pZone->m_pCopyObject);
    }
    else
    {
        pCopy = new CCEaseCubicActionOut();
        pNewZone = new CCZone(pCopy);
    }

    pCopy->initWithAction((CCActionInterval *)(m_pInner->copy()->autorelease()));

    CC_SAFE_DELETE(pNewZone);
    return pCopy;
}

void CCEaseCubicActionOut::update(float time)
{
    time -= 1;
    m_pInner->update(1+powf(time,3.0f));
}

CCActionInterval* CCEaseCubicActionOut::reverse(void)
{
    return CCEaseCubicActionOut::create(m_pInner->reverse());
}

//
// CCEaseCubicActionInOut
//

CCEaseCubicActionInOut* CCEaseCubicActionInOut::create(CCActionInterval* pAction)
{
    CCEaseCubicActionInOut *pRet = new CCEaseCubicActionInOut();
    if (pRet)
    {
        if (pRet->initWithAction(pAction))
        {
            pRet->autorelease();
        }
        else
        {
            CC_SAFE_RELEASE_NULL(pRet);
        }
    }

    return pRet; 
}

CCObject* CCEaseCubicActionInOut::copyWithZone(CCZone *pZone)
{
    CCZone* pNewZone = NULL;
    CCEaseCubicActionInOut* pCopy = NULL;
    if(pZone && pZone->m_pCopyObject) 
    {
        //in case of being called at sub class
        pCopy = (CCEaseCubicActionInOut*)(pZone->m_pCopyObject);
    }
    else
    {
        pCopy = new CCEaseCubicActionInOut();
        pNewZone = new CCZone(pCopy);
    }

    pCopy->initWithAction((CCActionInterval *)(m_pInner->copy()->autorelease()));

    CC_SAFE_DELETE(pNewZone);
    return pCopy;
}

void CCEaseCubicActionInOut::update(float time)
{
    float tempTime = time * 2;
    if (tempTime < 1)
        tempTime =  powf(tempTime,3.0f) * 0.5f;
    else
    {
        tempTime -= 2;
        tempTime = 1 + powf(tempTime,3.0f)* 0.5f;
    }
    m_pInner->update(time);
}

CCActionInterval* CCEaseCubicActionInOut::reverse(void)
{
    return CCEaseCubicActionInOut::create(m_pInner->reverse());
}

CCActionInterval* CreateActionEasing::create(CCActionInterval* action,int type)
{
    return CreateActionEasing::create(action,type,0,0,0,0);
}

CCActionInterval* CreateActionEasing::create(CCActionInterval* action,int m_easingType,float p0,float p1,float p2,float p3)
{
    if (action == NULL)
    {
        return nullptr;
    }

    switch (m_easingType)
    {
    case FrameEase_Custom:
        {
            CCEaseBezierAction* cAction = CCEaseBezierAction::create(action);
            cAction->setBezierParamer(p0,p1,p2,p3);
            return cAction;
        }
        break;
    case FrameEase_Linear:
        return action;
        break;
    case FrameEase_Sine_EaseIn:
        return CCEaseSineIn::create(action);
        break;
    case FrameEase_Sine_EaseOut:
        return CCEaseSineOut::create(action);
        break;
    case FrameEase_Sine_EaseInOut:
        return CCEaseSineInOut::create(action);
        break;
    case FrameEase_Quad_EaseIn:
        return CCEaseQuadraticActionIn::create(action);
        break;
    case FrameEase_Quad_EaseOut:
        return CCEaseQuadraticActionOut::create(action);
        break;
    case FrameEase_Quad_EaseInOut:
        return CCEaseQuadraticActionInOut::create(action);
        break;
    case FrameEase_Cubic_EaseIn:
        return CCEaseCubicActionIn::create(action);
        break;
    case FrameEase_Cubic_EaseOut:
        return CCEaseCubicActionOut::create(action);
        break;
    case FrameEase_Cubic_EaseInOut:
        return CCEaseCubicActionInOut::create(action);
        break;
    case FrameEase_Quart_EaseIn:
        return CCEaseQuarticActionIn::create(action);
        break;
    case FrameEase_Quart_EaseOut:
        return CCEaseQuadraticActionOut::create(action);
        break;
    case FrameEase_Quart_EaseInOut:
        return CCEaseQuarticActionInOut::create(action);
        break;
    case FrameEase_Quint_EaseIn:
        return CCEaseQuinticActionIn::create(action);
        break;
    case FrameEase_Quint_EaseOut:
        return CCEaseQuinticActionOut::create(action);
        break;
    case FrameEase_Quint_EaseInOut:
        return CCEaseQuinticActionInOut::create(action);
        break;
    case FrameEase_Expo_EaseIn:
        return CCEaseExponentialIn::create(action);
        break;
    case FrameEase_Expo_EaseOut:
        return CCEaseExponentialOut::create(action);
        break;
    case FrameEase_Expo_EaseInOut:
        return CCEaseExponentialInOut::create(action);
        break;
    case FrameEase_Circ_EaseIn:
        return CCEaseCircleActionIn::create(action);
        break;
    case FrameEase_Circ_EaseOut:
        return CCEaseCircleActionOut::create(action);
        break;
    case FrameEase_Circ_EaseInOut:
        return CCEaseCircleActionInOut::create(action);
        break;
    case FrameEase_Elastic_EaseIn:
        {
            return CCEaseElasticIn::create(action);
        }
        break;
    case FrameEase_Elastic_EaseOut:
        {
            return CCEaseElasticOut::create(action);
        }
        break;
    case FrameEase_Elastic_EaseInOut:
        {
            return CCEaseElasticInOut::create(action);
        }
        break;
    case FrameEase_Back_EaseIn:
        return CCEaseBackIn::create(action);
        break;
    case FrameEase_Back_EaseOut:
        return CCEaseBackOut::create(action);
        break;
    case FrameEase_Back_EaseInOut:
        return CCEaseBackInOut::create(action);
        break;
    case FrameEase_Bounce_EaseIn:
        return CCEaseBounceIn::create(action);
        break;
    case FrameEase_Bounce_EaseOut:
        return CCEaseBounceOut::create(action);
        break;
    case FrameEase_Bounce_EaseInOut:
        return CCEaseBounceInOut::create(action);
        break;
    default:
        return action;
        break;
    }
    return nullptr;

}

//
//
//
//
//
//add end

NS_CC_END
