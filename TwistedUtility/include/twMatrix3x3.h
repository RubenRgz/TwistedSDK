/************************************************************************/
/**
* @LC	  10/02/2018
* @file   twMatrix3x3.h
* @Author Ruben Rodriguez (rubn2113@gmail.com)
* @date   10/02/2018
* @brief  Matrix 3x3 class
* @bug	  No know Bugs
*/
/************************************************************************/
#pragma once

/************************************************************************/
/* Includes											                    */
/************************************************************************/
#include "twVector3D.h"

class twMatrix3x3
{
	/************************************************************************/
	/* Constructors & destructor		                                    */
	/************************************************************************/
public:
	explicit twMatrix3x3(float _m00 = 0.f, float _m01 = 0.f, float _m02 = 0.f,
		float _m10 = 0.f, float _m11 = 0.f, float _m12 = 0.f,
		float _m20 = 0.f, float _m21 = 0.f, float _m22 = 0.f);

	twMatrix3x3(const twVector3D& _vec1, const twVector3D& _vec2, const twVector3D& _vec3);

	twMatrix3x3(const twMatrix3x3& _matrix);

	~twMatrix3x3();

	/************************************************************************/
	/* Variable declaration								                    */
	/************************************************************************/
public:
	union
	{
		struct
		{
			float	m00, m01, m02,
					m10, m11, m12,
					m20, m21, m22;
		};

		float Line[3][3];
		float fMatrix[9];
	};

	/************************************************************************/
	/* Functions                                                            */
	/************************************************************************/
public:
	void Zero();																	/*!< Converts the matrix to zero matrix */
	void Transpose();																/*!< Transposes the matrix */
	void Identity();																/*!< Converts the matrix to identity matrix */
	float Determinant() const;														/*!< Gives us the matrix determinant */
	void Inverse();																	/*!< Inverts the matrix */

	/************************************************************************/
	/* Operator overloading                                                 */
	/************************************************************************/
public:
	void operator=          (const twMatrix3x3& _matrix);							/*!< Matrix assignation */
	
	bool operator==			(const twMatrix3x3& _matrix);							/*!< Positive comparison */
	bool operator!=			(const twMatrix3x3& _matrix);							/*!< Negative comparison */

	twMatrix3x3 operator+	(const twMatrix3x3& _matrix);							/*!< Matrix addition */
	twMatrix3x3 operator-	(const twMatrix3x3& _matrix);							/*!< Matrix substraction */
	twMatrix3x3 operator*	(const twMatrix3x3& _matrix);							/*!< Matrix multiplication */
	twMatrix3x3 operator*	(float _scalar);										/*!< Scalar multiplication */

};
