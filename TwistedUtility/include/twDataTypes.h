/************************************************************************/
/**
* @LC	  10/03/2018
* @file   twDataTypes.h
* @Author Ruben Rodriguez (rubn2113@gmail.com)
* @date   09/02/2018
* @brief  Set the platform type
* @bug	  No know Bugs
*/
/************************************************************************/
#pragma once

/************************************************************************************************************************/
/* Includes					                                               												*/
/************************************************************************************************************************/
#include"twPlatform.h"

#ifdef SYSTEM_32BITS //32 bits system

constexpr auto MAX_UINT8 = 0xffffffff;
constexpr auto MIN_UINT8 = 0x00000000;

typedef unsigned char         tw_uint8;		/*!< 8-bit  unsigned. */
typedef unsigned short int    tw_uint16;	/*!< 16-bit unsigned. */
typedef unsigned int          tw_uint32;	/*!< 32-bit unsigned. */
typedef unsigned long long    tw_uint64;	/*!< 64-bit unsigned. */
typedef unsigned int*		  tw_uintptr;   /*!< Unsigned integer of size equal to a pointer. */

typedef	signed char			  tw_int8;		/*!< 8-bit  signed. */
typedef signed short int	  tw_int16;		/*!< 16-bit signed. */
typedef signed int	 		  tw_int32;		/*!< 32-bit signed. */
typedef signed long long	  tw_int64;		/*!< 64-bit signed. */
typedef signed int*			  tw_intptr;    /*!< Signed integer of size equal to a pointer. */

typedef char				  ANSICHAR;		/*!< ANSI char normally is a signed type. */
typedef wchar_t				  UNICHAR;		/*!< UNICODE normally is a unsigned type. */

#else // 64 bits system

constexpr auto MAX_UINT8 = 0xffffffff;
constexpr auto MIN_UINT8 = 0x00000000;

typedef unsigned char         tw_uint8;		/*!< 8-bit  unsigned. */
typedef unsigned short int    tw_uint16;	/*!< 16-bit unsigned. */
typedef unsigned int          tw_uint32;	/*!< 32-bit unsigned. */
typedef unsigned long long    tw_uint64;	/*!< 64-bit unsigned. */
typedef unsigned int*		  tw_uintptr;   /*!< Unsigned integer of size equal to a pointer. */

typedef	signed char			  tw_int8;		/*!< 8-bit  signed. */
typedef signed short int	  tw_int16;		/*!< 16-bit signed. */
typedef signed int	 		  tw_int32;		/*!< 32-bit signed. */
typedef signed long long	  tw_int64;		/*!< 64-bit signed. */
typedef signed int*			  tw_intptr;    /*!< Signed integer of size equal to a pointer. */

typedef char				  ANSICHAR;		/*!< ANSI char normally is a signed type. */
typedef wchar_t				  UNICHAR;		/*!< UNICODE normally is a unsigned type. */

#endif 

