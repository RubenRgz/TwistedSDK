/************************************************************************************/
/**
* @LC	  17/07/2019
* @file   twDataTypes.h
* @Author Ruben Rodriguez (rubn2113@gmail.com)
* @date   09/02/2018
* @brief  Set the system data we going to use
* @bug	  No bugs known
*/
/************************************************************************************/
#pragma once

/************************************************************************************/
/* Includes					                                                        */
/************************************************************************************/
#include"twPlatform.h"

#ifdef SYSTEM_32BITS //32 bits system

const auto MAX_UINT8 = 0xffffffff;
const auto MIN_UINT8 = 0x00000000;

typedef unsigned char		  tw_uint8;			/*!< 8 bits  unsigned. */
typedef unsigned short int    tw_uint16;		/*!< 16 bits unsigned. */
typedef unsigned int          tw_uint32;		/*!< 32 bits unsigned. */
typedef unsigned long long    tw_uint64;		/*!< 64 bits unsigned. */
typedef unsigned int*	      tw_uintptr;		/*!< Unsigned integer of size
							 						equal to a pointer. */
							 
typedef	signed char		      tw_int8;			/*!< 8 bits  signed. */
typedef signed short int      tw_int16;			/*!< 16 bits signed. */
typedef signed int	 	      tw_int32;			/*!< 32 bits signed. */
typedef signed long long      tw_int64;			/*!< 64 bits signed. */
typedef signed int*		      tw_intptr;		/*!< Signed integer of size 
							 						equal to a pointer. */
						     
typedef char			      ANSICHAR;			/*!< ANSI char normally is a signed type. */
typedef wchar_t			      UNICHAR;			/*!< UNICODE normally is a unsigned type. */

#else // 64 bits system

const auto MAX_UINT8 = 0xffffffff;
const auto MIN_UINT8 = 0x00000000;

typedef unsigned char         tw_uint8;			/*!< 8 bits  unsigned. */
typedef unsigned short int    tw_uint16;		/*!< 16 bits unsigned. */
typedef unsigned int          tw_uint32;		/*!< 32 bits unsigned. */
typedef unsigned long long    tw_uint64;		/*!< 64 bits unsigned. */
typedef unsigned int*		  tw_uintptr;		/*!< Unsigned integer of size 
													equal to a pointer. */

typedef	signed char			  tw_int8;			/*!< 8 bits  signed. */
typedef signed short int	  tw_int16;			/*!< 16 bits signed. */
typedef signed int	 		  tw_int32;			/*!< 32 bits signed. */
typedef signed long long	  tw_int64;			/*!< 64 bits signed. */
typedef signed int*			  tw_intptr;		/*!< Signed integer of size
													equal to a pointer. */

typedef char				  ANSICHAR;			/*!< ANSI char normally is a signed type. */
typedef wchar_t				  UNICHAR;			/*!< UNICODE normally is a unsigned type. */

#endif 

