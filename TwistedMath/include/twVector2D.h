/************************************************************************/
/**
* @LC	  09/23/2018
* @file   twVector2D.h
* @Author Ruben Rodriguez (rubn2113@gmail.com)
* @date   09/02/2018
* @brief  Vector class
* @bug	  No know Bugs
*/
/************************************************************************/
#pragma once

/************************************************************************/
/* Includes											                    */
/************************************************************************/
#include <math.h>

/************************************************************************/
/* Enums											                    */
/************************************************************************/
enum VectorDirection
{
	VD_UP = 0,
	VD_DOWN,
	VD_RIGHT,
	VD_LEFT
};

class twVector2D
{
	/************************************************************************/
	/* Constructors & destructor		                                    */
	/************************************************************************/
public:
	explicit twVector2D(float _x = 0, float _y = 0);
	twVector2D(const twVector2D& _vec);

	~twVector2D();

	/************************************************************************/
	/* Variable declaration								                    */
	/************************************************************************/
public:
	
	float x;																		/*!< X value of the vector */
	float y;																		/*!< Y value of the vector */

	/************************************************************************/
	/* Operator overloading                                                 */
	/************************************************************************/
	twVector2D operator * (float _scalar) const;
	twVector2D operator * (const twVector2D& _vect) const;
	twVector2D operator + (const twVector2D& _vect) const;
	twVector2D operator - (const twVector2D& _vect) const;

	/************************************************************************/
	/* Functions                                                            */
	/************************************************************************/
	void setDirection(VectorDirection _direction);
	void rotate(float _angle);
	void normalize();
	void truncate(float _max);
	void scaleBy(float _scale);

	float crossproduct(const twVector2D& _vect) const;
	float magnitude();
	float dotproduct(const twVector2D& _vect) const;
	float getAngle();
	float distanceFrom(const twVector2D& _vec);

	twVector2D projectOn(const twVector2D& _vec);
};