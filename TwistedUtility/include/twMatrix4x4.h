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

/************************************************************************/
/* Includes											                    */
/************************************************************************/
#include "twVector4D.h"

class twMatrix4x4
{
	/************************************************************************/
	/* Constructors & destructor		                                    */
	/************************************************************************/
public:
	explicit twMatrix4x4(float _m00 = 0.f, float _m01 = 0.f, float _m02 = 0.f, float _m03 = 0.f,
						 float _m10 = 0.f, float _m11 = 0.f, float _m12 = 0.f, float _m13 = 0.f,
						 float _m20 = 0.f, float _m21 = 0.f, float _m22 = 0.f, float _m23 = 0.f,
						 float _m30 = 0.f, float _m31 = 0.f, float _m32 = 0.f, float _m33 = 0.f);

	twMatrix4x4(const twVector4D& _vec1, const twVector4D& _vec2,
				const twVector4D& _vec3, const twVector4D& _vec4);

	twMatrix4x4(const twMatrix4x4& _matrix);

	~twMatrix4x4();

	/************************************************************************/
	/* Variable declaration								                    */
	/************************************************************************/
public:
	union
	{
		struct
		{
			float m00, m01, m02, m03,
				  m10, m11, m12, m13,
				  m20, m21, m22, m23,
				  m30, m31, m32, m33;
		};
		float Line[4][4];
		float fMatrix[16];
	};

	/************************************************************************/
	/* Functions                                                            */
	/************************************************************************/
public:
	void Zero();																	/*!< Converts the matrix to zero matrix */
	void Transpose();																/*!< Transposes the matrix */
	void Identity();																/*!< Converts the matrix to identity matrix */
	void Inverse();																	/*!< Inverts the matrix */

	float Determinant() const;														/*!< Gives us the matrix determinant */

	/************************************************************************/
	/* Operator overloading                                                 */
	/************************************************************************/
public:
	void operator=          (const twMatrix4x4& _matrix);							/*!< Matrix assignation */

	bool operator==			(const twMatrix4x4& _matrix);							/*!< Positive comparison */
	bool operator!=			(const twMatrix4x4& _matrix);							/*!< Negative comparison */

	twMatrix4x4 operator+	(const twMatrix4x4& _matrix);							/*!< Matrix addition */
	twMatrix4x4 operator-	(const twMatrix4x4& _matrix);							/*!< Matrix substraction */
	twMatrix4x4 operator*	(const twMatrix4x4& _matrix);							/*!< Matrix multiplication */
	twMatrix4x4 operator*	(float _scalar);										/*!< Scalar multiplication */

};

