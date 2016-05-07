/*
** Lua binding: Spine
** Generated automatically by tolua++-1.0.92 on 03/16/16 16:29:35.
*/

/****************************************************************************
 Copyright (c) 2011 cocos2d-x.org

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

extern "C" {
#include "tolua_fix.h"
}

#include <map>
#include <string>
#include "cocos2d.h"
#include "CCLuaEngine.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;
using namespace CocosDenshion;

/* Exported function */
TOLUA_API int  tolua_Spine_open (lua_State* tolua_S);

#include "spine-cocos2dx.h"
using namespace spine;

/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"__spEventDataForScript");
 tolua_usertype(tolua_S,"spTrackEntry");
 toluafix_add_type_mapping(CLASS_HASH_CODE(typeid(spTrackEntry)), "spTrackEntry");
 tolua_usertype(tolua_S,"SkeletonAnimation");
 toluafix_add_type_mapping(CLASS_HASH_CODE(typeid(SkeletonAnimation)), "SkeletonAnimation");
 tolua_usertype(tolua_S,"SkeletonRenderer");
 toluafix_add_type_mapping(CLASS_HASH_CODE(typeid(SkeletonRenderer)), "SkeletonRenderer");
 tolua_usertype(tolua_S,"spAnimationState");
 toluafix_add_type_mapping(CLASS_HASH_CODE(typeid(spAnimationState)), "spAnimationState");
 
 tolua_usertype(tolua_S,"CCNode");
 toluafix_add_type_mapping(CLASS_HASH_CODE(typeid(CCNode)), "CCNode");
 tolua_usertype(tolua_S,"__spEventForScript");
 tolua_usertype(tolua_S,"spAnimation");
 toluafix_add_type_mapping(CLASS_HASH_CODE(typeid(spAnimation)), "spAnimation");
}

/* method: setSkin of class  SkeletonRenderer */
#ifndef TOLUA_DISABLE_tolua_Spine_SkeletonRenderer_setSkin00
static int tolua_Spine_SkeletonRenderer_setSkin00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SkeletonRenderer",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SkeletonRenderer* self = (SkeletonRenderer*)  tolua_tousertype(tolua_S,1,0);
  char* skinName = ((char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setSkin'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->setSkin(skinName);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setSkin'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setAttachment of class  SkeletonRenderer */
#ifndef TOLUA_DISABLE_tolua_Spine_SkeletonRenderer_setAttachment00
static int tolua_Spine_SkeletonRenderer_setAttachment00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SkeletonRenderer",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SkeletonRenderer* self = (SkeletonRenderer*)  tolua_tousertype(tolua_S,1,0);
  char* slotName = ((char*)  tolua_tostring(tolua_S,2,0));
  char* attachmentName = ((char*)  tolua_tostring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setAttachment'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->setAttachment(slotName,attachmentName);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setAttachment'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: name of class  spAnimation */
#ifndef TOLUA_DISABLE_tolua_get_spAnimation_name
static int tolua_get_spAnimation_name(lua_State* tolua_S)
{
  spAnimation* self = (spAnimation*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'name'",NULL);
#endif
  tolua_pushstring(tolua_S,(const char*)self->name);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: name of class  spAnimation */
#ifndef TOLUA_DISABLE_tolua_set_spAnimation_name
static int tolua_set_spAnimation_name(lua_State* tolua_S)
{
  spAnimation* self = (spAnimation*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'name'",NULL);
  if (!tolua_isstring(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->name = ((char*)  tolua_tostring(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: duration of class  spAnimation */
#ifndef TOLUA_DISABLE_tolua_get_spAnimation_duration
static int tolua_get_spAnimation_duration(lua_State* tolua_S)
{
  spAnimation* self = (spAnimation*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'duration'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->duration);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: duration of class  spAnimation */
#ifndef TOLUA_DISABLE_tolua_set_spAnimation_duration
static int tolua_set_spAnimation_duration(lua_State* tolua_S)
{
  spAnimation* self = (spAnimation*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'duration'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->duration = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: timelinesCount of class  spAnimation */
#ifndef TOLUA_DISABLE_tolua_get_spAnimation_timelinesCount
static int tolua_get_spAnimation_timelinesCount(lua_State* tolua_S)
{
  spAnimation* self = (spAnimation*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'timelinesCount'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->timelinesCount);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: timelinesCount of class  spAnimation */
#ifndef TOLUA_DISABLE_tolua_set_spAnimation_timelinesCount
static int tolua_set_spAnimation_timelinesCount(lua_State* tolua_S)
{
  spAnimation* self = (spAnimation*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'timelinesCount'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->timelinesCount = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: state of class  spTrackEntry */
#ifndef TOLUA_DISABLE_tolua_get_spTrackEntry_state_ptr
static int tolua_get_spTrackEntry_state_ptr(lua_State* tolua_S)
{
  spTrackEntry* self = (spTrackEntry*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'state'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->state,"spAnimationState");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: state of class  spTrackEntry */
#ifndef TOLUA_DISABLE_tolua_set_spTrackEntry_state_ptr
static int tolua_set_spTrackEntry_state_ptr(lua_State* tolua_S)
{
  spTrackEntry* self = (spTrackEntry*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'state'",NULL);
  if (!tolua_isusertype(tolua_S,2,"spAnimationState",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->state = ((spAnimationState*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: next of class  spTrackEntry */
#ifndef TOLUA_DISABLE_tolua_get_spTrackEntry_next_ptr
static int tolua_get_spTrackEntry_next_ptr(lua_State* tolua_S)
{
  spTrackEntry* self = (spTrackEntry*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'next'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->next,"spTrackEntry");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: next of class  spTrackEntry */
#ifndef TOLUA_DISABLE_tolua_set_spTrackEntry_next_ptr
static int tolua_set_spTrackEntry_next_ptr(lua_State* tolua_S)
{
  spTrackEntry* self = (spTrackEntry*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'next'",NULL);
  if (!tolua_isusertype(tolua_S,2,"spTrackEntry",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->next = ((spTrackEntry*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: previous of class  spTrackEntry */
#ifndef TOLUA_DISABLE_tolua_get_spTrackEntry_previous_ptr
static int tolua_get_spTrackEntry_previous_ptr(lua_State* tolua_S)
{
  spTrackEntry* self = (spTrackEntry*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'previous'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->previous,"spTrackEntry");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: previous of class  spTrackEntry */
#ifndef TOLUA_DISABLE_tolua_set_spTrackEntry_previous_ptr
static int tolua_set_spTrackEntry_previous_ptr(lua_State* tolua_S)
{
  spTrackEntry* self = (spTrackEntry*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'previous'",NULL);
  if (!tolua_isusertype(tolua_S,2,"spTrackEntry",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->previous = ((spTrackEntry*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: animation of class  spTrackEntry */
#ifndef TOLUA_DISABLE_tolua_get_spTrackEntry_animation_ptr
static int tolua_get_spTrackEntry_animation_ptr(lua_State* tolua_S)
{
  spTrackEntry* self = (spTrackEntry*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'animation'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->animation,"spAnimation");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: animation of class  spTrackEntry */
#ifndef TOLUA_DISABLE_tolua_set_spTrackEntry_animation_ptr
static int tolua_set_spTrackEntry_animation_ptr(lua_State* tolua_S)
{
  spTrackEntry* self = (spTrackEntry*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'animation'",NULL);
  if (!tolua_isusertype(tolua_S,2,"spAnimation",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->animation = ((spAnimation*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: loop of class  spTrackEntry */
#ifndef TOLUA_DISABLE_tolua_get_spTrackEntry_loop
static int tolua_get_spTrackEntry_loop(lua_State* tolua_S)
{
  spTrackEntry* self = (spTrackEntry*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'loop'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->loop);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: loop of class  spTrackEntry */
#ifndef TOLUA_DISABLE_tolua_set_spTrackEntry_loop
static int tolua_set_spTrackEntry_loop(lua_State* tolua_S)
{
  spTrackEntry* self = (spTrackEntry*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'loop'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->loop = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: delay of class  spTrackEntry */
#ifndef TOLUA_DISABLE_tolua_get_spTrackEntry_delay
static int tolua_get_spTrackEntry_delay(lua_State* tolua_S)
{
  spTrackEntry* self = (spTrackEntry*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'delay'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->delay);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: delay of class  spTrackEntry */
#ifndef TOLUA_DISABLE_tolua_set_spTrackEntry_delay
static int tolua_set_spTrackEntry_delay(lua_State* tolua_S)
{
  spTrackEntry* self = (spTrackEntry*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'delay'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->delay = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: time of class  spTrackEntry */
#ifndef TOLUA_DISABLE_tolua_get_spTrackEntry_time
static int tolua_get_spTrackEntry_time(lua_State* tolua_S)
{
  spTrackEntry* self = (spTrackEntry*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'time'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->time);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: time of class  spTrackEntry */
#ifndef TOLUA_DISABLE_tolua_set_spTrackEntry_time
static int tolua_set_spTrackEntry_time(lua_State* tolua_S)
{
  spTrackEntry* self = (spTrackEntry*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'time'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->time = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: lastTime of class  spTrackEntry */
#ifndef TOLUA_DISABLE_tolua_get_spTrackEntry_lastTime
static int tolua_get_spTrackEntry_lastTime(lua_State* tolua_S)
{
  spTrackEntry* self = (spTrackEntry*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'lastTime'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->lastTime);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: lastTime of class  spTrackEntry */
#ifndef TOLUA_DISABLE_tolua_set_spTrackEntry_lastTime
static int tolua_set_spTrackEntry_lastTime(lua_State* tolua_S)
{
  spTrackEntry* self = (spTrackEntry*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'lastTime'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->lastTime = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: endTime of class  spTrackEntry */
#ifndef TOLUA_DISABLE_tolua_get_spTrackEntry_endTime
static int tolua_get_spTrackEntry_endTime(lua_State* tolua_S)
{
  spTrackEntry* self = (spTrackEntry*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'endTime'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->endTime);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: endTime of class  spTrackEntry */
#ifndef TOLUA_DISABLE_tolua_set_spTrackEntry_endTime
static int tolua_set_spTrackEntry_endTime(lua_State* tolua_S)
{
  spTrackEntry* self = (spTrackEntry*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'endTime'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->endTime = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: timeScale of class  spTrackEntry */
#ifndef TOLUA_DISABLE_tolua_get_spTrackEntry_timeScale
static int tolua_get_spTrackEntry_timeScale(lua_State* tolua_S)
{
  spTrackEntry* self = (spTrackEntry*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'timeScale'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->timeScale);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: timeScale of class  spTrackEntry */
#ifndef TOLUA_DISABLE_tolua_set_spTrackEntry_timeScale
static int tolua_set_spTrackEntry_timeScale(lua_State* tolua_S)
{
  spTrackEntry* self = (spTrackEntry*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'timeScale'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->timeScale = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: mixTime of class  spTrackEntry */
#ifndef TOLUA_DISABLE_tolua_get_spTrackEntry_mixTime
static int tolua_get_spTrackEntry_mixTime(lua_State* tolua_S)
{
  spTrackEntry* self = (spTrackEntry*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mixTime'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->mixTime);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: mixTime of class  spTrackEntry */
#ifndef TOLUA_DISABLE_tolua_set_spTrackEntry_mixTime
static int tolua_set_spTrackEntry_mixTime(lua_State* tolua_S)
{
  spTrackEntry* self = (spTrackEntry*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mixTime'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->mixTime = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: mixDuration of class  spTrackEntry */
#ifndef TOLUA_DISABLE_tolua_get_spTrackEntry_mixDuration
static int tolua_get_spTrackEntry_mixDuration(lua_State* tolua_S)
{
  spTrackEntry* self = (spTrackEntry*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mixDuration'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->mixDuration);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: mixDuration of class  spTrackEntry */
#ifndef TOLUA_DISABLE_tolua_set_spTrackEntry_mixDuration
static int tolua_set_spTrackEntry_mixDuration(lua_State* tolua_S)
{
  spTrackEntry* self = (spTrackEntry*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mixDuration'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->mixDuration = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: mix of class  spTrackEntry */
#ifndef TOLUA_DISABLE_tolua_get_spTrackEntry_mix
static int tolua_get_spTrackEntry_mix(lua_State* tolua_S)
{
  spTrackEntry* self = (spTrackEntry*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mix'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->mix);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: mix of class  spTrackEntry */
#ifndef TOLUA_DISABLE_tolua_set_spTrackEntry_mix
static int tolua_set_spTrackEntry_mix(lua_State* tolua_S)
{
  spTrackEntry* self = (spTrackEntry*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mix'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->mix = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: timeScale of class  spAnimationState */
#ifndef TOLUA_DISABLE_tolua_get_spAnimationState_timeScale
static int tolua_get_spAnimationState_timeScale(lua_State* tolua_S)
{
  spAnimationState* self = (spAnimationState*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'timeScale'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->timeScale);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: timeScale of class  spAnimationState */
#ifndef TOLUA_DISABLE_tolua_set_spAnimationState_timeScale
static int tolua_set_spAnimationState_timeScale(lua_State* tolua_S)
{
  spAnimationState* self = (spAnimationState*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'timeScale'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->timeScale = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: tracksCount of class  spAnimationState */
#ifndef TOLUA_DISABLE_tolua_get_spAnimationState_tracksCount
static int tolua_get_spAnimationState_tracksCount(lua_State* tolua_S)
{
  spAnimationState* self = (spAnimationState*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'tracksCount'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->tracksCount);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: tracksCount of class  spAnimationState */
#ifndef TOLUA_DISABLE_tolua_set_spAnimationState_tracksCount
static int tolua_set_spAnimationState_tracksCount(lua_State* tolua_S)
{
  spAnimationState* self = (spAnimationState*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'tracksCount'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->tracksCount = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: name of class  __spEventDataForScript */
#ifndef TOLUA_DISABLE_tolua_get___spEventDataForScript_name
static int tolua_get___spEventDataForScript_name(lua_State* tolua_S)
{
  __spEventDataForScript* self = (__spEventDataForScript*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'name'",NULL);
#endif
  tolua_pushcppstring(tolua_S,(const char*)self->name);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: name of class  __spEventDataForScript */
#ifndef TOLUA_DISABLE_tolua_set___spEventDataForScript_name
static int tolua_set___spEventDataForScript_name(lua_State* tolua_S)
{
  __spEventDataForScript* self = (__spEventDataForScript*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'name'",NULL);
  if (!tolua_iscppstring(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->name = ((std::string)  tolua_tocppstring(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: intValue of class  __spEventDataForScript */
#ifndef TOLUA_DISABLE_tolua_get___spEventDataForScript_intValue
static int tolua_get___spEventDataForScript_intValue(lua_State* tolua_S)
{
  __spEventDataForScript* self = (__spEventDataForScript*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'intValue'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->intValue);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: intValue of class  __spEventDataForScript */
#ifndef TOLUA_DISABLE_tolua_set___spEventDataForScript_intValue
static int tolua_set___spEventDataForScript_intValue(lua_State* tolua_S)
{
  __spEventDataForScript* self = (__spEventDataForScript*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'intValue'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->intValue = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: floatValue of class  __spEventDataForScript */
#ifndef TOLUA_DISABLE_tolua_get___spEventDataForScript_floatValue
static int tolua_get___spEventDataForScript_floatValue(lua_State* tolua_S)
{
  __spEventDataForScript* self = (__spEventDataForScript*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'floatValue'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->floatValue);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: floatValue of class  __spEventDataForScript */
#ifndef TOLUA_DISABLE_tolua_set___spEventDataForScript_floatValue
static int tolua_set___spEventDataForScript_floatValue(lua_State* tolua_S)
{
  __spEventDataForScript* self = (__spEventDataForScript*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'floatValue'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->floatValue = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: stringValue of class  __spEventDataForScript */
#ifndef TOLUA_DISABLE_tolua_get___spEventDataForScript_stringValue
static int tolua_get___spEventDataForScript_stringValue(lua_State* tolua_S)
{
  __spEventDataForScript* self = (__spEventDataForScript*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'stringValue'",NULL);
#endif
  tolua_pushcppstring(tolua_S,(const char*)self->stringValue);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: stringValue of class  __spEventDataForScript */
#ifndef TOLUA_DISABLE_tolua_set___spEventDataForScript_stringValue
static int tolua_set___spEventDataForScript_stringValue(lua_State* tolua_S)
{
  __spEventDataForScript* self = (__spEventDataForScript*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'stringValue'",NULL);
  if (!tolua_iscppstring(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->stringValue = ((std::string)  tolua_tocppstring(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: data of class  __spEventForScript */
#ifndef TOLUA_DISABLE_tolua_get___spEventForScript_data
static int tolua_get___spEventForScript_data(lua_State* tolua_S)
{
  __spEventForScript* self = (__spEventForScript*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'data'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->data,"__spEventDataForScript");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: data of class  __spEventForScript */
#ifndef TOLUA_DISABLE_tolua_set___spEventForScript_data
static int tolua_set___spEventForScript_data(lua_State* tolua_S)
{
  __spEventForScript* self = (__spEventForScript*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'data'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"__spEventDataForScript",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->data = *((__spEventDataForScript*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: time of class  __spEventForScript */
#ifndef TOLUA_DISABLE_tolua_get___spEventForScript_time
static int tolua_get___spEventForScript_time(lua_State* tolua_S)
{
  __spEventForScript* self = (__spEventForScript*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'time'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->time);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: time of class  __spEventForScript */
#ifndef TOLUA_DISABLE_tolua_set___spEventForScript_time
static int tolua_set___spEventForScript_time(lua_State* tolua_S)
{
  __spEventForScript* self = (__spEventForScript*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'time'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->time = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: intValue of class  __spEventForScript */
#ifndef TOLUA_DISABLE_tolua_get___spEventForScript_intValue
static int tolua_get___spEventForScript_intValue(lua_State* tolua_S)
{
  __spEventForScript* self = (__spEventForScript*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'intValue'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->intValue);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: intValue of class  __spEventForScript */
#ifndef TOLUA_DISABLE_tolua_set___spEventForScript_intValue
static int tolua_set___spEventForScript_intValue(lua_State* tolua_S)
{
  __spEventForScript* self = (__spEventForScript*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'intValue'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->intValue = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: floatValue of class  __spEventForScript */
#ifndef TOLUA_DISABLE_tolua_get___spEventForScript_floatValue
static int tolua_get___spEventForScript_floatValue(lua_State* tolua_S)
{
  __spEventForScript* self = (__spEventForScript*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'floatValue'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->floatValue);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: floatValue of class  __spEventForScript */
#ifndef TOLUA_DISABLE_tolua_set___spEventForScript_floatValue
static int tolua_set___spEventForScript_floatValue(lua_State* tolua_S)
{
  __spEventForScript* self = (__spEventForScript*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'floatValue'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->floatValue = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: stringValue of class  __spEventForScript */
#ifndef TOLUA_DISABLE_tolua_get___spEventForScript_stringValue
static int tolua_get___spEventForScript_stringValue(lua_State* tolua_S)
{
  __spEventForScript* self = (__spEventForScript*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'stringValue'",NULL);
#endif
  tolua_pushcppstring(tolua_S,(const char*)self->stringValue);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: stringValue of class  __spEventForScript */
#ifndef TOLUA_DISABLE_tolua_set___spEventForScript_stringValue
static int tolua_set___spEventForScript_stringValue(lua_State* tolua_S)
{
  __spEventForScript* self = (__spEventForScript*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'stringValue'",NULL);
  if (!tolua_iscppstring(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->stringValue = ((std::string)  tolua_tocppstring(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: createWithFile of class  SkeletonAnimation */
#ifndef TOLUA_DISABLE_tolua_Spine_SkeletonAnimation_createWithFile00
static int tolua_Spine_SkeletonAnimation_createWithFile00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"SkeletonAnimation",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  char* skeletonDataFile = ((char*)  tolua_tostring(tolua_S,2,0));
  char* atlasFile = ((char*)  tolua_tostring(tolua_S,3,0));
  float scale = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   SkeletonAnimation* tolua_ret = (SkeletonAnimation*)  SkeletonAnimation::createWithFile(skeletonDataFile,atlasFile,scale);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"SkeletonAnimation");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'createWithFile'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setMix of class  SkeletonAnimation */
#ifndef TOLUA_DISABLE_tolua_Spine_SkeletonAnimation_setMix00
static int tolua_Spine_SkeletonAnimation_setMix00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SkeletonAnimation",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SkeletonAnimation* self = (SkeletonAnimation*)  tolua_tousertype(tolua_S,1,0);
  char* fromAnimation = ((char*)  tolua_tostring(tolua_S,2,0));
  char* toAnimation = ((char*)  tolua_tostring(tolua_S,3,0));
  float duration = ((float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setMix'", NULL);
#endif
  {
   self->setMix(fromAnimation,toAnimation,duration);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setMix'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setAnimation of class  SkeletonAnimation */
#ifndef TOLUA_DISABLE_tolua_Spine_SkeletonAnimation_setAnimation00
static int tolua_Spine_SkeletonAnimation_setAnimation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SkeletonAnimation",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SkeletonAnimation* self = (SkeletonAnimation*)  tolua_tousertype(tolua_S,1,0);
  int trackIndex = ((int)  tolua_tonumber(tolua_S,2,0));
  char* name = ((char*)  tolua_tostring(tolua_S,3,0));
  bool loop = ((bool)  tolua_toboolean(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setAnimation'", NULL);
#endif
  {
   spTrackEntry* tolua_ret = (spTrackEntry*)  self->setAnimation(trackIndex,name,loop);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"spTrackEntry");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setAnimation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addAnimation of class  SkeletonAnimation */
#ifndef TOLUA_DISABLE_tolua_Spine_SkeletonAnimation_addAnimation00
static int tolua_Spine_SkeletonAnimation_addAnimation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SkeletonAnimation",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SkeletonAnimation* self = (SkeletonAnimation*)  tolua_tousertype(tolua_S,1,0);
  int trackIndex = ((int)  tolua_tonumber(tolua_S,2,0));
  char* name = ((char*)  tolua_tostring(tolua_S,3,0));
  bool loop = ((bool)  tolua_toboolean(tolua_S,4,0));
  float delay = ((float)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addAnimation'", NULL);
#endif
  {
   spTrackEntry* tolua_ret = (spTrackEntry*)  self->addAnimation(trackIndex,name,loop,delay);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"spTrackEntry");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addAnimation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getCurrent of class  SkeletonAnimation */
#ifndef TOLUA_DISABLE_tolua_Spine_SkeletonAnimation_getCurrent00
static int tolua_Spine_SkeletonAnimation_getCurrent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SkeletonAnimation",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SkeletonAnimation* self = (SkeletonAnimation*)  tolua_tousertype(tolua_S,1,0);
  int trackIndex = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getCurrent'", NULL);
#endif
  {
   spTrackEntry* tolua_ret = (spTrackEntry*)  self->getCurrent(trackIndex);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"spTrackEntry");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getCurrent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: clearTracks of class  SkeletonAnimation */
#ifndef TOLUA_DISABLE_tolua_Spine_SkeletonAnimation_clearTracks00
static int tolua_Spine_SkeletonAnimation_clearTracks00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SkeletonAnimation",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SkeletonAnimation* self = (SkeletonAnimation*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'clearTracks'", NULL);
#endif
  {
   self->clearTracks();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'clearTracks'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: clearTrack of class  SkeletonAnimation */
#ifndef TOLUA_DISABLE_tolua_Spine_SkeletonAnimation_clearTrack00
static int tolua_Spine_SkeletonAnimation_clearTrack00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SkeletonAnimation",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SkeletonAnimation* self = (SkeletonAnimation*)  tolua_tousertype(tolua_S,1,0);
  int trackIndex = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'clearTrack'", NULL);
#endif
  {
   self->clearTrack(trackIndex);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'clearTrack'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setScriptHandlerForAnima of class  SkeletonAnimation */
#ifndef TOLUA_DISABLE_tolua_Spine_SkeletonAnimation_setScriptHandlerForAnima00
static int tolua_Spine_SkeletonAnimation_setScriptHandlerForAnima00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SkeletonAnimation",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !toluafix_isfunction(tolua_S,2,"LUA_FUNCTION",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SkeletonAnimation* self = (SkeletonAnimation*)  tolua_tousertype(tolua_S,1,0);
  LUA_FUNCTION funId = (  toluafix_ref_function(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setScriptHandlerForAnima'", NULL);
#endif
  {
   self->setScriptHandlerForAnima(funId);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setScriptHandlerForAnima'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: resetScriptHandlerForAnima of class  SkeletonAnimation */
#ifndef TOLUA_DISABLE_tolua_Spine_SkeletonAnimation_resetScriptHandlerForAnima00
static int tolua_Spine_SkeletonAnimation_resetScriptHandlerForAnima00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SkeletonAnimation",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SkeletonAnimation* self = (SkeletonAnimation*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'resetScriptHandlerForAnima'", NULL);
#endif
  {
   self->resetScriptHandlerForAnima();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'resetScriptHandlerForAnima'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setScriptHandlerForTrack of class  SkeletonAnimation */
#ifndef TOLUA_DISABLE_tolua_Spine_SkeletonAnimation_setScriptHandlerForTrack00
static int tolua_Spine_SkeletonAnimation_setScriptHandlerForTrack00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SkeletonAnimation",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !toluafix_isfunction(tolua_S,2,"LUA_FUNCTION",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SkeletonAnimation* self = (SkeletonAnimation*)  tolua_tousertype(tolua_S,1,0);
  LUA_FUNCTION funId = (  toluafix_ref_function(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setScriptHandlerForTrack'", NULL);
#endif
  {
   self->setScriptHandlerForTrack(funId);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setScriptHandlerForTrack'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: resetScriptHandlerForTrack of class  SkeletonAnimation */
#ifndef TOLUA_DISABLE_tolua_Spine_SkeletonAnimation_resetScriptHandlerForTrack00
static int tolua_Spine_SkeletonAnimation_resetScriptHandlerForTrack00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SkeletonAnimation",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SkeletonAnimation* self = (SkeletonAnimation*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'resetScriptHandlerForTrack'", NULL);
#endif
  {
   self->resetScriptHandlerForTrack();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'resetScriptHandlerForTrack'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_Spine_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_cclass(tolua_S,"SkeletonRenderer","SkeletonRenderer","CCNode",NULL);
  tolua_beginmodule(tolua_S,"SkeletonRenderer");
   tolua_function(tolua_S,"setSkin",tolua_Spine_SkeletonRenderer_setSkin00);
   tolua_function(tolua_S,"setAttachment",tolua_Spine_SkeletonRenderer_setAttachment00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"spAnimation","spAnimation","",NULL);
  tolua_beginmodule(tolua_S,"spAnimation");
   tolua_variable(tolua_S,"name",tolua_get_spAnimation_name,tolua_set_spAnimation_name);
   tolua_variable(tolua_S,"duration",tolua_get_spAnimation_duration,tolua_set_spAnimation_duration);
   tolua_variable(tolua_S,"timelinesCount",tolua_get_spAnimation_timelinesCount,tolua_set_spAnimation_timelinesCount);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"spTrackEntry","spTrackEntry","",NULL);
  tolua_beginmodule(tolua_S,"spTrackEntry");
   tolua_variable(tolua_S,"state",tolua_get_spTrackEntry_state_ptr,tolua_set_spTrackEntry_state_ptr);
   tolua_variable(tolua_S,"next",tolua_get_spTrackEntry_next_ptr,tolua_set_spTrackEntry_next_ptr);
   tolua_variable(tolua_S,"previous",tolua_get_spTrackEntry_previous_ptr,tolua_set_spTrackEntry_previous_ptr);
   tolua_variable(tolua_S,"animation",tolua_get_spTrackEntry_animation_ptr,tolua_set_spTrackEntry_animation_ptr);
   tolua_variable(tolua_S,"loop",tolua_get_spTrackEntry_loop,tolua_set_spTrackEntry_loop);
   tolua_variable(tolua_S,"delay",tolua_get_spTrackEntry_delay,tolua_set_spTrackEntry_delay);
   tolua_variable(tolua_S,"time",tolua_get_spTrackEntry_time,tolua_set_spTrackEntry_time);
   tolua_variable(tolua_S,"lastTime",tolua_get_spTrackEntry_lastTime,tolua_set_spTrackEntry_lastTime);
   tolua_variable(tolua_S,"endTime",tolua_get_spTrackEntry_endTime,tolua_set_spTrackEntry_endTime);
   tolua_variable(tolua_S,"timeScale",tolua_get_spTrackEntry_timeScale,tolua_set_spTrackEntry_timeScale);
   tolua_variable(tolua_S,"mixTime",tolua_get_spTrackEntry_mixTime,tolua_set_spTrackEntry_mixTime);
   tolua_variable(tolua_S,"mixDuration",tolua_get_spTrackEntry_mixDuration,tolua_set_spTrackEntry_mixDuration);
   tolua_variable(tolua_S,"mix",tolua_get_spTrackEntry_mix,tolua_set_spTrackEntry_mix);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"spAnimationState","spAnimationState","",NULL);
  tolua_beginmodule(tolua_S,"spAnimationState");
   tolua_variable(tolua_S,"timeScale",tolua_get_spAnimationState_timeScale,tolua_set_spAnimationState_timeScale);
   tolua_variable(tolua_S,"tracksCount",tolua_get_spAnimationState_tracksCount,tolua_set_spAnimationState_tracksCount);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"__spEventDataForScript","__spEventDataForScript","",NULL);
  tolua_beginmodule(tolua_S,"__spEventDataForScript");
   tolua_variable(tolua_S,"name",tolua_get___spEventDataForScript_name,tolua_set___spEventDataForScript_name);
   tolua_variable(tolua_S,"intValue",tolua_get___spEventDataForScript_intValue,tolua_set___spEventDataForScript_intValue);
   tolua_variable(tolua_S,"floatValue",tolua_get___spEventDataForScript_floatValue,tolua_set___spEventDataForScript_floatValue);
   tolua_variable(tolua_S,"stringValue",tolua_get___spEventDataForScript_stringValue,tolua_set___spEventDataForScript_stringValue);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"__spEventForScript","__spEventForScript","",NULL);
  tolua_beginmodule(tolua_S,"__spEventForScript");
   tolua_variable(tolua_S,"data",tolua_get___spEventForScript_data,tolua_set___spEventForScript_data);
   tolua_variable(tolua_S,"time",tolua_get___spEventForScript_time,tolua_set___spEventForScript_time);
   tolua_variable(tolua_S,"intValue",tolua_get___spEventForScript_intValue,tolua_set___spEventForScript_intValue);
   tolua_variable(tolua_S,"floatValue",tolua_get___spEventForScript_floatValue,tolua_set___spEventForScript_floatValue);
   tolua_variable(tolua_S,"stringValue",tolua_get___spEventForScript_stringValue,tolua_set___spEventForScript_stringValue);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"SkeletonAnimation","SkeletonAnimation","SkeletonRenderer",NULL);
  tolua_beginmodule(tolua_S,"SkeletonAnimation");
   tolua_function(tolua_S,"createWithFile",tolua_Spine_SkeletonAnimation_createWithFile00);
   tolua_function(tolua_S,"setMix",tolua_Spine_SkeletonAnimation_setMix00);
   tolua_function(tolua_S,"setAnimation",tolua_Spine_SkeletonAnimation_setAnimation00);
   tolua_function(tolua_S,"addAnimation",tolua_Spine_SkeletonAnimation_addAnimation00);
   tolua_function(tolua_S,"getCurrent",tolua_Spine_SkeletonAnimation_getCurrent00);
   tolua_function(tolua_S,"clearTracks",tolua_Spine_SkeletonAnimation_clearTracks00);
   tolua_function(tolua_S,"clearTrack",tolua_Spine_SkeletonAnimation_clearTrack00);
   tolua_function(tolua_S,"setScriptHandlerForAnima",tolua_Spine_SkeletonAnimation_setScriptHandlerForAnima00);
   tolua_function(tolua_S,"resetScriptHandlerForAnima",tolua_Spine_SkeletonAnimation_resetScriptHandlerForAnima00);
   tolua_function(tolua_S,"setScriptHandlerForTrack",tolua_Spine_SkeletonAnimation_setScriptHandlerForTrack00);
   tolua_function(tolua_S,"resetScriptHandlerForTrack",tolua_Spine_SkeletonAnimation_resetScriptHandlerForTrack00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_Spine (lua_State* tolua_S) {
 return tolua_Spine_open(tolua_S);
};
#endif

