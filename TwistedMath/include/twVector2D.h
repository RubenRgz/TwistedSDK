/************************************************************************/
/**
* @LC	  09/22/2018
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
public:
	/************************************************************************/
	/* Variable declaration								                    */
	/************************************************************************/
	float x, y;

	/************************************************************************/
	/* Constructor & destructor		                                        */
	/************************************************************************/
	twVector2D(float X=0, float Y=0)	
	{
		x = X;
		y = Y;
	};

	~twVector2D(){};					

	/************************************************************************/
	/* Operators                                                            */
	/************************************************************************/
	twVector2D operator*(float scalar) const
	{
		return twVector2D(x*scalar, y*scalar);
	}

	twVector2D operator*(const twVector2D& vect) const
	{
		return twVector2D(x*vect.x, y * vect.y);
	}

	twVector2D operator+(const twVector2D &vect) const
	{
		return twVector2D(x+vect.x, y+vect.y);
	}

	twVector2D operator-(const twVector2D &vect) const
	{
		return twVector2D(x-vect.x, y-vect.y);
	}

	/************************************************************************/
	/* Functions                                                            */
	/************************************************************************/
	void setDirection(VectorDirection _direction)
	{
		switch (_direction)
		{
		case VD_UP:
			x = 0;
			y = 1;
			break;
		case VD_DOWN:
			x = 0;
			y = -1;
			break;
		case VD_RIGHT:
			x = 1;
			y = 0;
			break;
		case VD_LEFT:
			x = -1;
			y = 0;
			break;
		default:
			break;
		}
	}

	void rotate(float angle)
	{
		float xt = (x * cosf(angle)) - (y * sinf(angle));
		float yt = (y * cosf(angle)) + (x * sinf(angle));
		x = xt;
		y = yt;
	}

	float crossproduct(const twVector2D &vect2) const
	{
		return (this->x*vect2.y) - (this->y*vect2.x);
	}

	float magnitude()
	{
		return sqrtf(x*x + y*y);
	}

	void normalize()
	{
		float mag = sqrtf(x*x + y*y);
		this->x = x/mag;
		this->y = y/mag;
	}

	float dotproduct(const twVector2D &vect) const
	{
		return (x*vect.x) + (y*vect.y);
	}

	void truncate(float max)
	{
		float i;

		i = max / this->magnitude();
		i = i < 1.0f ? i : max;

		this->x *= i;
		this->y *= i;
	}

	float getAngle()
	{
		return static_cast<float>(atan2(this->y, this->x));
	}

	void scaleBy(float _scale)
	{
		this->x *= _scale;
		this->y *= _scale;
	}

	float distanceFrom(const twVector2D& _vec)
	{
		return sqrtf((this->x - _vec.x) *(this->x - _vec.x) + 
			(this->y - _vec.y) * (this->y - _vec.y));
	}
};