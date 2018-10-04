/************************************************************************/
/**
* @LC	  10/02/2018
* @file   twMatrix3x3.h
* @Author Ruben Rodriguez (rubn2113@gmail.com)
* @date   10/02/2018
* @brief  Matrix 4x4 class
* @bug	  No bugs known
*/
/************************************************************************/
#pragma once

class twVector4D
{
	/************************************************************************/
	/* Constructors & destructor		                                    */
	/************************************************************************/
public:
	explicit twVector4D(float _x = 0.f, float _y = 0.f, 
						float _z = 0.f, float _w = 0.f);											/*!< Default constructor */
	twVector4D(const twVector4D& _vec);																/*!< Object constructor */

	~twVector4D();

	/************************************************************************/
	/* Variable declaration								                    */
	/************************************************************************/
public:
	float x;																		/*!< X value of the vector */
	float y;																		/*!< Y value of the vector */
	float z;																		/*!< Z value of the vector */
	float w;																		/*!< w value of the vector */

	/************************************************************************/
	/* Functions                                                            */
	/************************************************************************/
public:

	/************************************************************************/
	/* Operator overloading                                                 */
	/************************************************************************/
public:
	void operator =	(const twVector4D& _vec);

	twVector4D operator * (float _scalar) const;
	twVector4D operator + (const twVector4D& _vec) const;
	twVector4D operator - (const twVector4D& _vec) const;
};

