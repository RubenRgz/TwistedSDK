#pragma once
#include"twPlatform.h"

#ifdef SYSTEM_32BITS

constexpr auto MAX_UINT8 = 0xffffffff;
constexpr auto MIN_UINT8 = 0x00000000;

typedef unsigned char tw_uint8;
typedef unsigned int tw_uint32;
typedef char tw_int8;
typedef int tw_int32;


#else


#endif // SYSTEM_32BITS


