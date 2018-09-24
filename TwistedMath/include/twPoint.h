/********************************************************************/
/**
* @LC	  09/23/2018
* @file   Point.h
* @Author Rubén Rodríguez Serrano (rubn2113@gmail.com)
* @date   2017/10/16
* @brief  It´s a simple 2D point
* @bug	  No known bugs.
*/
/********************************************************************/
#pragma once

/************************************************************************/
/* Includes											                    */
/************************************************************************/
#include <twDataTypes.h>

/************************************************************************/
/* Point Class											                */
/************************************************************************/
class twPoint
{
	/************************************************************************/
	/* Constructors & destructor		                                    */
	/************************************************************************/
public:
	explicit twPoint(const tw_int32& _x = 0, const tw_int32& _y = 0);				/*!< Constructor with variables */
	twPoint(const twPoint& _point);													/*!< Constructor with Point */
	~twPoint();																		/*!< Destructor */

	/************************************************************************/
	/* Variable declaration								                    */
	/************************************************************************/
public:
	tw_int32 x;																		/*!< X value of the point */
	tw_int32 y;																		/*!< Y value of the point */

	/************************************************************************/
	/* Operator overloading                                                 */
	/************************************************************************/
public:
	bool operator == (const twPoint& _point) const;
	bool operator != (const twPoint& _point) const;
};


