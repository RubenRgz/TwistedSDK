/************************************************************************************/
/**
* @LC	  31/07/2019
* @file   Point.h
* @Author Rubén Rodríguez Serrano (rubn2113@gmail.com)
* @date   2017/10/16
* @brief  It´s a simple 2D point
* @bug	  No bugs known
*/
/************************************************************************************/
#pragma once

namespace TwistedSDK
{
	/********************************************************************************/
	/* Point Class											                        */
	/********************************************************************************/
	class twPoint
	{
		/****************************************************************************/
		/* Constructors & destructor		                                        */
		/****************************************************************************/
	public:
		explicit twPoint(float _x, float _y);				/*!< Constructor with parameters */
		explicit twPoint(float _value);						/*!< Constructor with one value */
		twPoint(const twPoint& _point);						/*!< Constructor with a point */
		twPoint();											/*!< Default constructor */
		~twPoint();											/*!< Destructor */

		/****************************************************************************/
		/* Variable declaration								                        */
		/****************************************************************************/
	public:
		float x;											/*!< X coordinate */
		float y;											/*!< Y coordinate */

		/****************************************************************************/
		/* Operator overloading                                                     */
		/****************************************************************************/
	public:
		void operator =	(const twPoint& _point);
		void operator += (const twPoint& _point);
		void operator -= (const twPoint& _point);
		void operator *= (const twPoint& _point);
		void operator /= (const twPoint& _point);
		void operator += (float _value);
		void operator -= (float _value);
		void operator *= (float _value);
		void operator /= (float _value);

		bool operator == (const twPoint& _point) const;
		bool operator != (const twPoint& _point) const;

		twPoint operator + (const twPoint& _point) const;
		twPoint operator - (const twPoint& _point) const;
		twPoint operator * (const twPoint& _point) const;
		twPoint operator / (const twPoint& _point) const;
	};
}
