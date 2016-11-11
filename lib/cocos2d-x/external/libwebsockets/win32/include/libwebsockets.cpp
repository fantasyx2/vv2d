
#include "platform/CCPlatformMacros.h"
#include "ExtensionMacros.h"
#include "cocos2d.h"

#ifdef __cplusplus
extern "C" {
#include <cstddef>
#include <cstdarg>
#endif
#include <stdarg.h>
#if _MSC_VER >= 1900
#pragma comment(lib,"legacy_stdio_definitions.lib")
FILE * __cdecl __iob_func(void)
{
	FILE __libwebsocket_std_redef_arr[] = { stdin, stdout, stderr };
	return &(__libwebsocket_std_redef_arr[0]);
}
#endif

#ifdef __cplusplus
}
#endif
