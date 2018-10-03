/************************************************************************/
/**
* @LC	  10/03/2018
* @file   twPlatform.h
* @Author Ruben Rodriguez (rubn2113@gmail.com)
* @date   09/02/2018
* @brief  Set the platform type
* @bug	  No know Bugs
*/
/************************************************************************/
#pragma once

/************************************************************************************************************************/
/* Platform config			                                               												*/
/************************************************************************************************************************/
#define WINDOWS
//#define IOS
//#define LINUX
//#define PLAY_STATION
//#define XBOX

//Operating System
#ifdef WINDOWS
#define DIRECTX
#define BIG_ENDIAN
#endif // WINDOWS

#ifdef IOS
#define OPENGL
#define LITTLE_ENDIAN
#endif // IOS

#ifdef LINUX
#define OPENGL
#define LITTLE_ENDIAN
#endif // LINUX

//Endianness
#ifdef BIG_ENDIAN
#define BIG_ENDIAN_USAGE
#endif // BIG_ENDIAN

#ifdef LITTLE_ENDIAN
#define LITTLE_ENDIAN_USAGE
#endif // LITTLE_ENDIAN

//System
#ifdef _WIN64
#define SYSTEM_64BITS
#else
#define SYSTEM_32BITS
#endif // x86 or x64
