/** @file:      Base.h
 *
 *  @author:    João Ferreira
 *  @date:      2023.Oct.18
 *
 */

#ifndef BASE_H_INCLUDED
#define BASE_H_INCLUDED

#include "Platforms.h"
#include <memory>

#ifdef NG_MODE_DEBUG
    #if defined(NG_PLATFORM_WINDOWS64) || defined(NG_PLATFORM_WINDOWS32)
        #define NG_DEBUGBREAK() __debugbreak()
    #elif defined(NG_PLATFORM_LINUX)
        #define NG_DEBUGBREAK() raise(SIGTRAP)
    #elif defined(NG_PLATFORM_MACOS)
        #define NG_DEBUBREAK() __builtin_trap
    #elif defined(NG_PLATFORM_IOS) || defined(NG_PLATFORM_ANDROID)
        #define NG_DEBUGBREAK() __debugbreak()
    #else
        #error "Platform doesn't support __debugbreak()"
    #endif
    #define NG_ENABLE_ASSERTS
#else
    #define NG_DEBUGBREAK()
#endif



#endif // BASE_H_INCLUDED
