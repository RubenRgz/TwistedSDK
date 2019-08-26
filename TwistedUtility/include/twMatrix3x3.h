/************************************************************************************/
/**
* @LC	  26/07/2018
* @file   twMatrix3x3.h
* @Author Ruben Rodriguez (rubn2113@gmail.com)
* @date   10/02/2018
* @brief  Matrix 3x3 class
* @bug	  No bugs known
*/
/************************************************************************************/
#pragma once

/************************************************************************************/
/* Includes																			*/
/************************************************************************************/
#include "twVector3D.h"

namespace TwistedSDK
{
	/********************************************************************************/
	/* Matrix 3x3 class								                                */
	/********************************************************************************/
	class twMatrix3x3
	{
		/****************************************************************************/
		/* Constructors & destructor		                                        */
		/****************************************************************************/
	public:
		explicit twMatrix3x3(float _m00, float _m01, float _m02,
							float _m10, float _m11, float _m12,
							float _m20, float _m21, float _m22);
		explicit twMatrix3x3(float _value);
		twMatrix3x3(const twVector3D& _vec1,
			const twVector3D& _vec2,
			const twVector3D& _vec3);
		twMatrix3x3(const twMatrix3x3& _matrix);
		twMatrix3x3();												/*!< Default constructor */
		~twMatrix3x3();												/*!< Destructor */

		/****************************************************************************/
		/* Variable declaration														*/
		/****************************************************************************/
	public:
		float m_matrix[3][3];

		static const twMatrix3x3 ZERO;								/*!< Zero matrix */
		static const twMatrix3x3 IDENTITY;                          /*!< Identity matrix */	
		
		/****************************************************************************/
		/* Functions											                    */
		/****************************************************************************/
	public:
		void Zero();								/*!< Converts this matrix to zero matrix */
		void Transpose();							/*!< Transposes this matrix */
		void Inverse();								/*!< Inverts this matrix */

		float Determinant() const;					/*!< Returns matrix determinant */
		
		void Rotate(float _angle);									/*!< Rotates this matrix */
		void Rotate(float _angleX, float _angleY, float _angleZ);	/*!< Rotates this matrix */
		void Scale(float _scale);									/*!< Scales this matrix */
		void Scale(float _scaleX, float _scaleY, float _scaleZ);	/*!< Scales this matrix */

		/****************************************************************************/
		/* Operator overloading												        */
		/****************************************************************************/
	public:
		void operator = (const twMatrix3x3& _matrix);

		bool operator == (const twMatrix3x3& _matrix);
		bool operator != (const twMatrix3x3& _matrix);

		twMatrix3x3 operator + (const twMatrix3x3& _matrix);
		twMatrix3x3 operator - (const twMatrix3x3& _matrix);
		twMatrix3x3 operator * (const twMatrix3x3& _matrix);
		twVector3D  operator * (const twVector3D & _vector);
		twMatrix3x3 operator * (float _scalar);
	};
}
