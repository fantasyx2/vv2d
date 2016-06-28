/*
** Lua binding: Gif
** Generated automatically by tolua++-1.0.92 on Tue Jun 28 23:24:12 2016.
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
#include "CCZipFile.h"

using namespace cocos2d;
using namespace CocosDenshion;

/* Exported function */
TOLUA_API int  tolua_Gif_open (lua_State* tolua_S);

#include "CacheGif.h"
#include "InstantGif.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_InstantGif (lua_State* tolua_S)
{
 InstantGif* self = (InstantGif*) tolua_tousertype(tolua_S,1,0);
    Mtolua_delete(self);
    return 0;
}

static int tolua_collect_CacheGif (lua_State* tolua_S)
{
 CacheGif* self = (CacheGif*) tolua_tousertype(tolua_S,1,0);
    Mtolua_delete(self);
    return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"InstantGif");
 toluafix_add_type_mapping(CLASS_HASH_CODE(typeid(InstantGif)), "InstantGif");
 tolua_usertype(tolua_S,"CacheGif");
 toluafix_add_type_mapping(CLASS_HASH_CODE(typeid(CacheGif)), "CacheGif");
 tolua_usertype(tolua_S,"CCShaderSprite");
 toluafix_add_type_mapping(CLASS_HASH_CODE(typeid(CCShaderSprite)), "CCShaderSprite");
 tolua_usertype(tolua_S,"GifBase");
 toluafix_add_type_mapping(CLASS_HASH_CODE(typeid(GifBase)), "GifBase");
}

/* method: getGifFrameName of class  GifBase */
#ifndef TOLUA_DISABLE_tolua_Gif_GifBase_getGifFrameName00
static int tolua_Gif_GifBase_getGifFrameName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GifBase",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GifBase* self = (GifBase*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getGifFrameName'", NULL);
#endif
  {
   std::string tolua_ret = (std::string)  self->getGifFrameName(index);
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getGifFrameName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: pause of class  GifBase */
#ifndef TOLUA_DISABLE_tolua_Gif_GifBase_pause00
static int tolua_Gif_GifBase_pause00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GifBase",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GifBase* self = (GifBase*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'pause'", NULL);
#endif
  {
   self->pause();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'pause'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: play of class  GifBase */
#ifndef TOLUA_DISABLE_tolua_Gif_GifBase_play00
static int tolua_Gif_GifBase_play00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GifBase",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GifBase* self = (GifBase*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'play'", NULL);
#endif
  {
   self->play();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'play'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isplaying of class  GifBase */
#ifndef TOLUA_DISABLE_tolua_Gif_GifBase_isplaying00
static int tolua_Gif_GifBase_isplaying00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GifBase",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GifBase* self = (GifBase*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isplaying'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isplaying();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isplaying'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setloop of class  GifBase */
#ifndef TOLUA_DISABLE_tolua_Gif_GifBase_setloop00
static int tolua_Gif_GifBase_setloop00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GifBase",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GifBase* self = (GifBase*)  tolua_tousertype(tolua_S,1,0);
  bool lp = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setloop'", NULL);
#endif
  {
   self->setloop(lp);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setloop'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  CacheGif */
#ifndef TOLUA_DISABLE_tolua_Gif_CacheGif_create00
static int tolua_Gif_CacheGif_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CacheGif",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  char* name = ((char*)  tolua_tostring(tolua_S,2,0));
  {
   CacheGif* tolua_ret = (CacheGif*)  CacheGif::create(name);
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CacheGif");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  CacheGif */
#ifndef TOLUA_DISABLE_tolua_Gif_CacheGif_new00
static int tolua_Gif_CacheGif_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CacheGif",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CacheGif* tolua_ret = (CacheGif*)  Mtolua_new((CacheGif)());
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CacheGif");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  CacheGif */
#ifndef TOLUA_DISABLE_tolua_Gif_CacheGif_new00_local
static int tolua_Gif_CacheGif_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CacheGif",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CacheGif* tolua_ret = (CacheGif*)  Mtolua_new((CacheGif)());
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CacheGif");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  CacheGif */
#ifndef TOLUA_DISABLE_tolua_Gif_CacheGif_delete00
static int tolua_Gif_CacheGif_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CacheGif",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CacheGif* self = (CacheGif*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  InstantGif */
#ifndef TOLUA_DISABLE_tolua_Gif_InstantGif_create00
static int tolua_Gif_InstantGif_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"InstantGif",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* name = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   InstantGif* tolua_ret = (InstantGif*)  InstantGif::create(name);
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"InstantGif");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  InstantGif */
#ifndef TOLUA_DISABLE_tolua_Gif_InstantGif_new00
static int tolua_Gif_InstantGif_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"InstantGif",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   InstantGif* tolua_ret = (InstantGif*)  Mtolua_new((InstantGif)());
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"InstantGif");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  InstantGif */
#ifndef TOLUA_DISABLE_tolua_Gif_InstantGif_new00_local
static int tolua_Gif_InstantGif_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"InstantGif",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   InstantGif* tolua_ret = (InstantGif*)  Mtolua_new((InstantGif)());
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"InstantGif");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  InstantGif */
#ifndef TOLUA_DISABLE_tolua_Gif_InstantGif_delete00
static int tolua_Gif_InstantGif_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"InstantGif",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  InstantGif* self = (InstantGif*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getGifFrameName of class  InstantGif */
#ifndef TOLUA_DISABLE_tolua_Gif_InstantGif_getGifFrameName00
static int tolua_Gif_InstantGif_getGifFrameName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"InstantGif",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  InstantGif* self = (InstantGif*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getGifFrameName'", NULL);
#endif
  {
   std::string tolua_ret = (std::string)  self->getGifFrameName(index);
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getGifFrameName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_Gif_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_cclass(tolua_S,"GifBase","GifBase","CCShaderSprite",NULL);
  tolua_beginmodule(tolua_S,"GifBase");
   tolua_function(tolua_S,"getGifFrameName",tolua_Gif_GifBase_getGifFrameName00);
   tolua_function(tolua_S,"pause",tolua_Gif_GifBase_pause00);
   tolua_function(tolua_S,"play",tolua_Gif_GifBase_play00);
   tolua_function(tolua_S,"isplaying",tolua_Gif_GifBase_isplaying00);
   tolua_function(tolua_S,"setloop",tolua_Gif_GifBase_setloop00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"CacheGif","CacheGif","GifBase",tolua_collect_CacheGif);
  #else
  tolua_cclass(tolua_S,"CacheGif","CacheGif","GifBase",NULL);
  #endif
  tolua_beginmodule(tolua_S,"CacheGif");
   tolua_function(tolua_S,"create",tolua_Gif_CacheGif_create00);
   tolua_function(tolua_S,"new",tolua_Gif_CacheGif_new00);
   tolua_function(tolua_S,"new_local",tolua_Gif_CacheGif_new00_local);
   tolua_function(tolua_S,".call",tolua_Gif_CacheGif_new00_local);
   tolua_function(tolua_S,"delete",tolua_Gif_CacheGif_delete00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"InstantGif","InstantGif","GifBase",tolua_collect_InstantGif);
  #else
  tolua_cclass(tolua_S,"InstantGif","InstantGif","GifBase",NULL);
  #endif
  tolua_beginmodule(tolua_S,"InstantGif");
   tolua_function(tolua_S,"create",tolua_Gif_InstantGif_create00);
   tolua_function(tolua_S,"new",tolua_Gif_InstantGif_new00);
   tolua_function(tolua_S,"new_local",tolua_Gif_InstantGif_new00_local);
   tolua_function(tolua_S,".call",tolua_Gif_InstantGif_new00_local);
   tolua_function(tolua_S,"delete",tolua_Gif_InstantGif_delete00);
   tolua_function(tolua_S,"getGifFrameName",tolua_Gif_InstantGif_getGifFrameName00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_Gif (lua_State* tolua_S) {
 return tolua_Gif_open(tolua_S);
};
#endif

