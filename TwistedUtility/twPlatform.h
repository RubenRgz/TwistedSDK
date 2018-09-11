#pragma once

/* Platform config*/

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
#define MEMORY_WORK_BG
#endif // BIG_ENDIAN

#ifdef LITTLE_ENDIAN
#define MEMORY_WORK_LE
#endif // LITTLE_ENDIAN

//System
#ifdef _WIN64
#define SYSTEM_64BITS
#else
#define SYSTEM_32BITS
#endif // x86 or x64
