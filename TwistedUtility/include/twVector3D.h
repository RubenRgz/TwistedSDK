/************************************************************************/
/**
* @LC	  10/02/2018
* @file   twVector3D.h
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


class twVector3D
{
/************************************************************************/
/* Constructors & destructor		                                    */
/************************************************************************/
public:
	explicit twVector3D(float _x = 0.f, float _y = 0.f, float _z = 0.f);			/*!< Default constructor */
	twVector3D(const twVector3D& _vec);												/*!< Object constructor */

	~twVector3D();																	/*!< Destructor */

	/************************************************************************/
	/* Variable declaration								                    */
	/************************************************************************/
public:

	float x;																		/*!< X value of the vector */
	float y;																		/*!< Y value of the vector */
	float z;																		/*!< Z value of the vector */

	/************************************************************************/
	/* Functions                                                            */
	/************************************************************************/
public:
	void Normalize();																/*!< This function normalize the vector */
	void ScaleBy(float _scale);														/*!< This function scales the vector magnitud */
	void Zero();																	/*!< Resets the vector's values to 0 */

	twVector3D CrossProduct(const twVector3D& _vec) const;							/*!< Gives us the orthogonal vector between 2 vectors */
	float Magnitude();																/*!< Gives us the length of the current vector */
	float DotProduct(const twVector3D& _vec) const;									/*!< If the result is 0 the vectors are orthogonal, 
																					if the result > 0 the angle between the two vectors is less than 90°,
																					and if the result < 0 the angle between this vectors is greater than 90° */
	float DistanceFrom(const twVector3D& _vec);										/*!< Gives us the distance between 2 vectors */

	bool isNormilized();															/*!< Verifies if the current vector is already normalized */

	twVector3D ProjectOn(const twVector3D& _vec);									/*!< Gives us the projection of the current vector on the given one */

	/************************************************************************/
	/* Operator overloading                                                 */
	/************************************************************************/
public:
	twVector3D operator * (float _scalar) const;
	twVector3D operator * (const twVector3D& _vec) const;
	twVector3D operator + (const twVector3D& _vec) const;
	twVector3D operator - (const twVector3D& _vec) const;

};

