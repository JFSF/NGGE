/** @file:      Platforms.h
 *
 *  @author:    João Ferreira
 *  @date:      2023.Oct.18
 *
 */
#ifndef PLATFORMS_H_INCLUDED
#define PLATFORMS_H_INCLUDED

#ifdef _WIN32
    #ifdef _WIN64
        #define NG_PLATFORM_WINDOWS64
    #else
        #define NG_PLATFORM_WINDOWS32
    #endif
#elif defined(__APPLE__) || defined(__MACH__)
    #include <TargetCondicionals.h>
    #if TARGET_IPHONE_SIMULATOR == 1
        #define NG_PLATFORM_IOSSIMULATOR
    #elif TARGET_OS_IPHONE == 1
        #define NG_PLATFORM_IPHONE
    #elif TARGET_OS_MAC == 1
        #define NG_PLATFORM_MACOS
    #else
        #error "Unknown Apple platform..."
    #endif
#elif defined(__ANDROID__)
    #define NG_PLATFORM_ANDROID
#elif defined(__LINUX__)
    #define NG_PLATFORM_LINUX
#else
    #error "Unknown platform..."
#endif


#endif // PLATFORMS_H_INCLUDED
