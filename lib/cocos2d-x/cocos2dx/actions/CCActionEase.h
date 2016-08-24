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

#ifndef __ACTION_CCEASE_ACTION_H__
#define __ACTION_CCEASE_ACTION_H__

#include "CCActionInterval.h"

NS_CC_BEGIN

class CCObject;
class CCZone;

enum FrameEaseType
{
    FrameEase_Custom = -1,

    FrameEase_Linear = 0,

    FrameEase_Sine_EaseIn,
    FrameEase_Sine_EaseOut,
    FrameEase_Sine_EaseInOut,


    FrameEase_Quad_EaseIn,
    FrameEase_Quad_EaseOut,
    FrameEase_Quad_EaseInOut,

    FrameEase_Cubic_EaseIn,
    FrameEase_Cubic_EaseOut,
    FrameEase_Cubic_EaseInOut,

    FrameEase_Quart_EaseIn,
    FrameEase_Quart_EaseOut,
    FrameEase_Quart_EaseInOut,

    FrameEase_Quint_EaseIn,
    FrameEase_Quint_EaseOut,
    FrameEase_Quint_EaseInOut,

    FrameEase_Expo_EaseIn,
    FrameEase_Expo_EaseOut,
    FrameEase_Expo_EaseInOut,

    FrameEase_Circ_EaseIn,
    FrameEase_Circ_EaseOut,
    FrameEase_Circ_EaseInOut,

    FrameEase_Elastic_EaseIn,
    FrameEase_Elastic_EaseOut,
    FrameEase_Elastic_EaseInOut,

    FrameEase_Back_EaseIn,
    FrameEase_Back_EaseOut,
    FrameEase_Back_EaseInOut,

    FrameEase_Bounce_EaseIn,
    FrameEase_Bounce_EaseOut,
    FrameEase_Bounce_EaseInOut,

    FrameEase_TWEEN_EASING_MAX = 10000
};

/**
 * @addtogroup actions
 * @{
 */

/** 
 @brief Base class for Easing actions
 @ingroup Actions
 */
class CC_DLL CCActionEase : public CCActionInterval
{
public:
    /**
     *  @js NA
     *  @lua NA
     */
    virtual ~CCActionEase(void);

    /** initializes the action */
    bool initWithAction(CCActionInterval *pAction);
    /**
     *  @js NA
     *  @lua NA
     */
    virtual CCObject* copyWithZone(CCZone* pZone);
    virtual void startWithTarget(CCNode *pTarget);
    virtual void stop(void);
    virtual void update(float time);
    virtual CCActionInterval* reverse(void);
    virtual CCActionInterval* getInnerAction();

public:

    /** creates the action */
    static CCActionEase* create(CCActionInterval *pAction);

protected:
    /** The inner action */
    CCActionInterval *m_pInner;
};

/** 
 @brief Base class for Easing actions with rate parameters
 @ingroup Actions
 */
class CC_DLL CCEaseRateAction : public CCActionEase
{
public:
    /**
     *  @js NA
     *  @lua NA
     */
    virtual ~CCEaseRateAction(void);

    /** set rate value for the actions */
    inline void setRate(float rate) { m_fRate = rate; }
    /** get rate value for the actions */
    inline float getRate(void) { return m_fRate; }

    /** Initializes the action with the inner action and the rate parameter */
    bool initWithAction(CCActionInterval *pAction, float fRate);
    /**
     *  @js NA
     *  @lua NA
     */
    virtual CCObject* copyWithZone(CCZone* pZone);
    virtual CCActionInterval* reverse(void);

public:

    /** Creates the action with the inner action and the rate parameter */
    static CCEaseRateAction* create(CCActionInterval* pAction, float fRate);

protected:
    float m_fRate;
};

/** 
 @brief CCEaseIn action with a rate
 @ingroup Actions
 */
class CC_DLL CCEaseIn : public CCEaseRateAction
{
public:
    virtual void update(float time);
    virtual CCActionInterval* reverse(void);
    /**
     *  @js NA
     *  @lua NA
     */
    virtual CCObject* copyWithZone(CCZone* pZone);
public:

    /** Creates the action with the inner action and the rate parameter */
    static CCEaseIn* create(CCActionInterval* pAction, float fRate);
};

/** 
 @brief CCEaseOut action with a rate
 @ingroup Actions
 */
class CC_DLL CCEaseOut : public CCEaseRateAction
{
public:
    virtual void update(float time);
    virtual CCActionInterval* reverse();
    /**
     *  @js NA
     *  @lua NA
     */
    virtual CCObject* copyWithZone(CCZone* pZone);

public:

    /** Creates the action with the inner action and the rate parameter */
    static CCEaseOut* create(CCActionInterval* pAction, float fRate);
};

/** 
 @brief CCEaseInOut action with a rate
 @ingroup Actions
 */
class CC_DLL CCEaseInOut : public CCEaseRateAction
{
public:
    virtual void update(float time);
    /**
     *  @js NA
     *  @lua NA
     */
    virtual CCObject* copyWithZone(CCZone* pZone);
    virtual CCActionInterval* reverse(void);

public:

    /** Creates the action with the inner action and the rate parameter */
    static CCEaseInOut* create(CCActionInterval* pAction, float fRate);
};

/** 
 @brief CCEase Exponential In
 @ingroup Actions
 */
class CC_DLL CCEaseExponentialIn : public CCActionEase
{
public:
    virtual void update(float time);
    virtual CCActionInterval* reverse(void);
    /**
     *  @js NA
     *  @lua NA
     */
    virtual CCObject* copyWithZone(CCZone* pZone);

public:
    /** creates the action */
    static CCEaseExponentialIn* create(CCActionInterval* pAction);
};

/** 
 @brief Ease Exponential Out
 @ingroup Actions
 */
class CC_DLL CCEaseExponentialOut : public CCActionEase
{
public:
    virtual void update(float time);
    virtual CCActionInterval* reverse(void);
    /**
     *  @js NA
     *  @lua NA
     */
    virtual CCObject* copyWithZone(CCZone* pZone);

public:
    /** creates the action */
    static CCEaseExponentialOut* create(CCActionInterval* pAction);
};

/** 
 @brief Ease Exponential InOut
 @ingroup Actions
 */
class CC_DLL CCEaseExponentialInOut : public CCActionEase
{
public:
    virtual void update(float time);
    /**
     *  @js NA
     *  @lua NA
     */
    virtual CCObject* copyWithZone(CCZone* pZone);
    virtual CCActionInterval* reverse();

public:

    /** creates the action */
    static CCEaseExponentialInOut* create(CCActionInterval* pAction);
};

/** 
 @brief Ease Sine In
 @ingroup Actions
 */
class CC_DLL CCEaseSineIn : public CCActionEase
{
public:
    virtual void update(float time);
    virtual CCActionInterval* reverse(void);
    /**
     *  @js NA
     *  @lua NA
     */
    virtual CCObject* copyWithZone(CCZone* pZone);

public:
    /** creates the action */
    static CCEaseSineIn* create(CCActionInterval* pAction);
};

/** 
 @brief Ease Sine Out
 @ingroup Actions
 */
class CC_DLL CCEaseSineOut : public CCActionEase
{
public:
    virtual void update(float time);
    virtual CCActionInterval* reverse(void);
    /**
     *  @js NA
     *  @lua NA
     */
    virtual CCObject* copyWithZone(CCZone* pZone);

public:

    /** creates the action */
    static CCEaseSineOut* create(CCActionInterval* pAction);
};

/** 
 @brief Ease Sine InOut
 @ingroup Actions
 */
class CC_DLL CCEaseSineInOut : public CCActionEase
{
public:
    virtual void update(float time);
    /**
     *  @js NA
     *  @lua NA
     */
    virtual CCObject* copyWithZone(CCZone* pZone);
    virtual CCActionInterval* reverse();

public:

    /** creates the action */
    static CCEaseSineInOut* create(CCActionInterval* pAction);
};

/** 
 @brief Ease Elastic abstract class
 @since v0.8.2
 @ingroup Actions
 */
class CC_DLL CCEaseElastic : public CCActionEase
{
public:
    /** get period of the wave in radians. default is 0.3 */
    inline float getPeriod(void) { return m_fPeriod; }
    /** set period of the wave in radians. */
    inline void setPeriod(float fPeriod) { m_fPeriod = fPeriod; }

    /** Initializes the action with the inner action and the period in radians (default is 0.3) */
    bool initWithAction(CCActionInterval *pAction, float fPeriod = 0.3f);

    virtual CCActionInterval* reverse(void);
    /**
     *  @js NA
     *  @lua NA
     */
    virtual CCObject* copyWithZone(CCZone* pZone);

public:

    /** Creates the action with the inner action and the period in radians (default is 0.3) */
    static CCEaseElastic* create(CCActionInterval *pAction, float fPeriod);
    static CCEaseElastic* create(CCActionInterval *pAction);
protected:
    float m_fPeriod;
};

/** 
 @brief Ease Elastic In action.
 @warning This action doesn't use a bijective function. Actions like Sequence might have an unexpected result when used with this action.
 @since v0.8.2
 @ingroup Actions
 */
class CC_DLL CCEaseElasticIn : public CCEaseElastic
{
public:
    virtual void update(float time);
    virtual CCActionInterval* reverse(void);
    /**
     *  @js NA
     *  @lua NA
     */
    virtual CCObject* copyWithZone(CCZone* pZone);

public:

    /** Creates the action with the inner action and the period in radians (default is 0.3) */
    static CCEaseElasticIn* create(CCActionInterval *pAction, float fPeriod);
    static CCEaseElasticIn* create(CCActionInterval *pAction);
};

/** 
 @brief Ease Elastic Out action.
 @warning This action doesn't use a bijective function. Actions like Sequence might have an unexpected result when used with this action.
 @since v0.8.2
 @ingroup Actions
 */
class CC_DLL CCEaseElasticOut : public CCEaseElastic
{
public:
    virtual void update(float time);
    virtual CCActionInterval* reverse(void);
    /**
     *  @js NA
     *  @lua NA
     */
    virtual CCObject* copyWithZone(CCZone* pZone);

public:

    /** Creates the action with the inner action and the period in radians (default is 0.3) */
    static CCEaseElasticOut* create(CCActionInterval *pAction, float fPeriod);
    static CCEaseElasticOut* create(CCActionInterval *pAction);
};

/** 
 @brief Ease Elastic InOut action.
 @warning This action doesn't use a bijective function. Actions like Sequence might have an unexpected result when used with this action.
 @since v0.8.2
 @ingroup Actions
 */
class CC_DLL CCEaseElasticInOut : public CCEaseElastic
{
public:
    virtual void update(float time);
    virtual CCActionInterval* reverse(void);
    /**
     *  @js NA
     *  @lua NA
     */
    virtual CCObject* copyWithZone(CCZone* pZone);

public:

    /** Creates the action with the inner action and the period in radians (default is 0.3) */
    static CCEaseElasticInOut* create(CCActionInterval *pAction, float fPeriod);
    static CCEaseElasticInOut* create(CCActionInterval *pAction);
};

/** 
 @brief CCEaseBounce abstract class.
 @since v0.8.2
 @ingroup Actions
*/
class CC_DLL CCEaseBounce : public CCActionEase
{
public:
    float bounceTime(float time);
    /**
     *  @js NA
     *  @lua NA
     */
    virtual CCObject* copyWithZone(CCZone* pZone);
    virtual CCActionInterval* reverse();

public:

    /** creates the action */
    static CCEaseBounce* create(CCActionInterval* pAction);
};

/** 
 @brief CCEaseBounceIn action.
 @warning This action doesn't use a bijective function. Actions like Sequence might have an unexpected result when used with this action.
 @since v0.8.2
 @ingroup Actions
*/
class CC_DLL CCEaseBounceIn : public CCEaseBounce
{
public:
    virtual void update(float time);
    virtual CCActionInterval* reverse(void);
    /**
     *  @js NA
     *  @lua NA
     */
    virtual CCObject* copyWithZone(CCZone* pZone);

public:

    /** creates the action */
    static CCEaseBounceIn* create(CCActionInterval* pAction);
};

/** 
 @brief EaseBounceOut action.
 @warning This action doesn't use a bijective function. Actions like Sequence might have an unexpected result when used with this action.
 @since v0.8.2
 @ingroup Actions
 */
class CC_DLL CCEaseBounceOut : public CCEaseBounce
{
public:
    virtual void update(float time);
    virtual CCActionInterval* reverse(void);
    /**
     *  @js NA
     *  @lua NA
     */
    virtual CCObject* copyWithZone(CCZone* pZone);

public:

    /** creates the action */
    static CCEaseBounceOut* create(CCActionInterval* pAction);
};

/** 
 @brief CCEaseBounceInOut action.
 @warning This action doesn't use a bijective function. Actions like Sequence might have an unexpected result when used with this action.
 @since v0.8.2
 @ingroup Actions
 */
class CC_DLL CCEaseBounceInOut : public CCEaseBounce
{
public:
    virtual void update(float time);
    /**
     *  @js NA
     *  @lua NA
     */
    virtual CCObject* copyWithZone(CCZone* pZone);
    virtual CCActionInterval* reverse();

public:

    /** creates the action */
    static CCEaseBounceInOut* create(CCActionInterval* pAction);
};

/** 
 @brief CCEaseBackIn action.
 @warning This action doesn't use a bijective function. Actions like Sequence might have an unexpected result when used with this action.
 @since v0.8.2
 @ingroup Actions
 */
class CC_DLL CCEaseBackIn : public CCActionEase
{
public:
    virtual void update(float time);
    virtual CCActionInterval* reverse(void);
    /**
     *  @js NA
     *  @lua NA
     */
    virtual CCObject* copyWithZone(CCZone* pZone);

public:

    /** creates the action */
    static CCEaseBackIn* create(CCActionInterval* pAction);
};

/** 
 @brief CCEaseBackOut action.
 @warning This action doesn't use a bijective function. Actions like Sequence might have an unexpected result when used with this action.
 @since v0.8.2
 @ingroup Actions
 */
class CC_DLL CCEaseBackOut : public CCActionEase
{
public:
    virtual void update(float time);
    virtual CCActionInterval* reverse(void);
    /**
     *  @js NA
     *  @lua NA
     */
    virtual CCObject* copyWithZone(CCZone* pZone);

public:

    /** creates the action */
    static CCEaseBackOut* create(CCActionInterval* pAction);
};

/** 
 @brief CCEaseBackInOut action.
 @warning This action doesn't use a bijective function. Actions like Sequence might have an unexpected result when used with this action.
 @since v0.8.2
 @ingroup Actions
 */
class CC_DLL CCEaseBackInOut : public CCActionEase
{
public:
    virtual void update(float time);
    /**
     *  @js NA
     *  @lua NA
     */
    virtual CCObject* copyWithZone(CCZone* pZone);
    virtual CCActionInterval* reverse();

public:

    /** creates the action */
    static CCEaseBackInOut* create(CCActionInterval* pAction);
};

//add for ccs
//
//
//
//
/** 
 @brief Ease Bezier
 @ingroup Actions
 */
class CCEaseBezierAction:public CCActionEase
{
public:
    virtual void update(float time);
    virtual CCActionInterval* reverse(void);
    /**
    *  @js NA
    *  @lua NA
    */
    virtual CCObject* copyWithZone(CCZone* pZone);

    virtual void setBezierParamer( float p0, float p1, float p2, float p3);

public:
    /** creates the action */
    static CCEaseBezierAction* create(CCActionInterval* pAction);

private:
    float m_p0;
    float m_p1;
    float m_p2;
    float m_p3;
};

/** 
 @brief Ease Quadratic In
 @ingroup Actions
 */
class CCEaseQuadraticActionIn:public CCActionEase
{
public:
    virtual void update(float time);
    virtual CCActionInterval* reverse(void);
    /**
    *  @js NA
    *  @lua NA
    */
    virtual CCObject* copyWithZone(CCZone* pZone);

public:
    /** creates the action */
    static CCEaseQuadraticActionIn* create(CCActionInterval* pAction);
};

/** 
 @brief Ease Quadratic Out
 @ingroup Actions
 */
class CCEaseQuadraticActionOut:public CCActionEase
{
public:
    virtual void update(float time);
    virtual CCActionInterval* reverse(void);
    /**
    *  @js NA
    *  @lua NA
    */
    virtual CCObject* copyWithZone(CCZone* pZone);

public:
    /** creates the action */
    static CCEaseQuadraticActionOut* create(CCActionInterval* pAction);
};

/** 
 @brief Ease Quadratic InOut
 @ingroup Actions
 */
class CCEaseQuadraticActionInOut:public CCActionEase
{
public:
    virtual void update(float time);
    virtual CCActionInterval* reverse(void);
    /**
    *  @js NA
    *  @lua NA
    */
    virtual CCObject* copyWithZone(CCZone* pZone);

public:
    /** creates the action */
    static CCEaseQuadraticActionInOut* create(CCActionInterval* pAction);
};

/** 
 @brief Ease Quartic In
 @ingroup Actions
 */
class CCEaseQuarticActionIn:public CCActionEase
{
public:
    virtual void update(float time);
    virtual CCActionInterval* reverse(void);
    /**
    *  @js NA
    *  @lua NA
    */
    virtual CCObject* copyWithZone(CCZone* pZone);

public:
    /** creates the action */
    static CCEaseQuarticActionIn* create(CCActionInterval* pAction);
};

/** 
 @brief Ease Quartic Out
 @ingroup Actions
 */
class CCEaseQuarticActionOut:public CCActionEase
{
public:
    virtual void update(float time);
    virtual CCActionInterval* reverse(void);
    /**
    *  @js NA
    *  @lua NA
    */
    virtual CCObject* copyWithZone(CCZone* pZone);

public:
    /** creates the action */
    static CCEaseQuarticActionOut* create(CCActionInterval* pAction);
};

/** 
 @brief Ease Quartic InOut
 @ingroup Actions
 */
class CCEaseQuarticActionInOut:public CCActionEase
{
public:
    virtual void update(float time);
    virtual CCActionInterval* reverse(void);
    /**
    *  @js NA
    *  @lua NA
    */
    virtual CCObject* copyWithZone(CCZone* pZone);

public:
    /** creates the action */
    static CCEaseQuarticActionInOut* create(CCActionInterval* pAction);
};


/** 
 @brief Ease Quintic In
 @ingroup Actions
 */
class CCEaseQuinticActionIn:public CCActionEase
{
public:
    virtual void update(float time);
    virtual CCActionInterval* reverse(void);
    /**
    *  @js NA
    *  @lua NA
    */
    virtual CCObject* copyWithZone(CCZone* pZone);

public:
    /** creates the action */
    static CCEaseQuinticActionIn* create(CCActionInterval* pAction);
};

/** 
 @brief Ease Quintic Out
 @ingroup Actions
 */
class CCEaseQuinticActionOut:public CCActionEase
{
public:
    virtual void update(float time);
    virtual CCActionInterval* reverse(void);
    /**
    *  @js NA
    *  @lua NA
    */
    virtual CCObject* copyWithZone(CCZone* pZone);

public:
    /** creates the action */
    static CCEaseQuinticActionOut* create(CCActionInterval* pAction);
};

/** 
 @brief Ease Quintic InOut
 @ingroup Actions
 */
class CCEaseQuinticActionInOut:public CCActionEase
{
public:
    virtual void update(float time);
    virtual CCActionInterval* reverse(void);
    /**
    *  @js NA
    *  @lua NA
    */
    virtual CCObject* copyWithZone(CCZone* pZone);

public:
    /** creates the action */
    static CCEaseQuinticActionInOut* create(CCActionInterval* pAction);
};

/** 
 @brief Ease Circle In
 @ingroup Actions
 */
class CCEaseCircleActionIn:public CCActionEase
{
public:
    virtual void update(float time);
    virtual CCActionInterval* reverse(void);
    /**
    *  @js NA
    *  @lua NA
    */
    virtual CCObject* copyWithZone(CCZone* pZone);

public:
    /** creates the action */
    static CCEaseCircleActionIn* create(CCActionInterval* pAction);
};

/** 
 @brief Ease Circle Out
 @ingroup Actions
 */
class CCEaseCircleActionOut:public CCActionEase
{
public:
    virtual void update(float time);
    virtual CCActionInterval* reverse(void);
    /**
    *  @js NA
    *  @lua NA
    */
    virtual CCObject* copyWithZone(CCZone* pZone);

public:
    /** creates the action */
    static CCEaseCircleActionOut* create(CCActionInterval* pAction);
};

/** 
 @brief Ease Circle InOut
 @ingroup Actions
 */
class CCEaseCircleActionInOut:public CCActionEase
{
public:
    virtual void update(float time);
    virtual CCActionInterval* reverse(void);
    /**
    *  @js NA
    *  @lua NA
    */
    virtual CCObject* copyWithZone(CCZone* pZone);

public:
    /** creates the action */
    static CCEaseCircleActionInOut* create(CCActionInterval* pAction);
};

/** 
 @brief Ease Cubic In
 @ingroup Actions
 */
class CCEaseCubicActionIn:public CCActionEase
{
public:
    virtual void update(float time);
    virtual CCActionInterval* reverse(void);
    /**
    *  @js NA
    *  @lua NA
    */
    virtual CCObject* copyWithZone(CCZone* pZone);

public:
    /** creates the action */
    static CCEaseCubicActionIn* create(CCActionInterval* pAction);
};

/** 
 @brief Ease Cubic Out
 @ingroup Actions
 */
class CCEaseCubicActionOut:public CCActionEase
{
public:
    virtual void update(float time);
    virtual CCActionInterval* reverse(void);
    /**
    *  @js NA
    *  @lua NA
    */
    virtual CCObject* copyWithZone(CCZone* pZone);

public:
    /** creates the action */
    static CCEaseCubicActionOut* create(CCActionInterval* pAction);
};

/** 
 @brief Ease Cubic InOut
 @ingroup Actions
 */
class CCEaseCubicActionInOut:public CCActionEase
{
public:
    virtual void update(float time);
    virtual CCActionInterval* reverse(void);
    /**
    *  @js NA
    *  @lua NA
    */
    virtual CCObject* copyWithZone(CCZone* pZone);

public:
    /** creates the action */
    static CCEaseCubicActionInOut* create(CCActionInterval* pAction);
};

class CreateActionEasing
{
    //add for css
    //
    //
public:
    static CCActionInterval* create(CCActionInterval* action,int type,float p0,float p1,float p2,float p3);
    static CCActionInterval* create(CCActionInterval* action,int type);
    //
    //
    //add end
};
//
//
//
//
//
//add end

// end of actions group
/// @}

NS_CC_END

#endif // __ACTION_CCEASE_ACTION_H__
