#ifndef __LUASPINE_H_
#define __LUASPINE_H_

#ifdef __cplusplus
extern "C" {
#endif
#include "tolua++.h"
#ifdef __cplusplus
}
#endif

TOLUA_API int luaopen_Spine(lua_State* tolua_S);

#endif // __LUACOCOS2D_H_
