/************************************************************************/
/**
* @LC	  10/03/2018
* @file   twVector2D.h
* @Author Ruben Rodriguez (rubn2113@gmail.com)
* @date   09/02/2018
* @brief  Vector class
* @bug	  No bugs known
*/
/************************************************************************/
#pragma once

/************************************************************************/
/* Enums											                    */
/************************************************************************/
enum VectorDirection
{
	VD_UP = 0,
	VD_DOWN,
	VD_RIGHT,
	VD_LEFT,
	VD_TOTAL
};

class twVector2D
{
	/************************************************************************/
	/* Constructors & destructor		                                    */
	/************************************************************************/
public:
	explicit twVector2D(float _x = 0.f, float _y = 0.f);							/*!< Default constructor */
	twVector2D(const twVector2D& _vec);												/*!< Object constructor */

	~twVector2D();																	/*!< Destructor */

	/************************************************************************/
	/* Variable declaration								                    */
	/************************************************************************/
public:
	
	float x;																		/*!< X value of the vector */
	float y;																		/*!< Y value of the vector */

	/************************************************************************/
	/* Functions                                                            */
	/************************************************************************/
public:
	void SetDirection(const VectorDirection& _direction);							/*!< Sets the initial vector direction */
	void Rotate(float _angle);														/*!< Rotates the vector */
	void Normalize();																/*!< This function normalize the vector */
	void Truncate(float _max);														/*!< This function truncates the vector to a max value given */
	void ScaleBy(float _scale);														/*!< This function scales the vector magnitud */
	void Zero();																	/*!< Resets the vector's values to 0 */

	float CrossProduct(const twVector2D& _vec) const;								/*!< If the result is 0 the vectors are orthogonal */
	float Magnitude();																/*!< Gives us the length of the current vector */	
	float DotProduct(const twVector2D& _vec) const;									/*!< If the result is 0 the vectors are orthogonal, 
																					if the result > 0 the angle between the two vectors is less than 90°,
																					and if the result < 0 the angle between this vectors is greater than 90° */
	float GetAngle();																/*!< Gives us the angle of the current vector */
	float DistanceFrom(const twVector2D& _vec);										/*!< Gives us the distance between2 vectors */

	bool isNormilized();															/*!< Verifies if the current vector is already normalized */

	twVector2D ProjectOn(const twVector2D& _vec);									/*!< Gives us the projection of the current vector on the given one */

	/************************************************************************/
	/* Operator overloading                                                 */
	/************************************************************************/
public:
	void operator =	(const twVector2D& _vec);

	twVector2D operator * (float _scalar) const;
	twVector2D operator + (const twVector2D& _vec) const;
	twVector2D operator - (const twVector2D& _vec) const;
};