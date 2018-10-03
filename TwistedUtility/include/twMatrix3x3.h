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

class twMatrix3x3
{
	/************************************************************************/
	/* Constructors & destructor		                                    */
	/************************************************************************/
public:
	explicit twMatrix3x3(float _m00 = 0.f, float _m01 = 0.f, float _m02 = 0.f,
		float _m10 = 0.f, float _m11 = 0.f, float _m12 = 0.f,
		float _m20 = 0.f, float _m21 = 0.f, float _m22 = 0.f);

	twMatrix3x3(const twMatrix3x3& _matrix);

	~twMatrix3x3();

	/************************************************************************/
	/* Variable declaration								                    */
	/************************************************************************/
public:
	float m00;
	float m01;
	float m02;
	float m10;
	float m11;
	float m12;
	float m20;
	float m21;
	float m22;

	/************************************************************************/
	/* Functions                                                            */
	/************************************************************************/
public:
	void Zero();

	/************************************************************************/
	/* Operator overloading                                                 */
	/************************************************************************/
public:
	void operator=          (const twMatrix3x3& _matrix);				/*!< Matrix assignation */
	
	bool operator==			(const twMatrix3x3& _matrix);				/*!< Positive comparison */
	bool operator!=			(const twMatrix3x3& _matrix);				/*!< Negative comparison */

	twMatrix3x3 operator+	(const twMatrix3x3& _matrix);				/*!< Matrix addition */
	twMatrix3x3 operator-	(const twMatrix3x3& _matrix);				/*!< Matrix substraction */
	twMatrix3x3 operator*	(const twMatrix3x3& _matrix);				/*!< Matrix multiplication */
	twMatrix3x3 operator*	(float _scalar);							/*!< Scalar multiplication */

};
