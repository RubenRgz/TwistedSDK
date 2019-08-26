/************************************************************************************/
/**
* @LC	  31/07/2019
* @file   twVector4D.h
* @Author Ruben Rodriguez (rubn2113@gmail.com)
* @date   10/02/2018
* @brief  Vector 4D class
* @bug	  No bugs known
*/
/************************************************************************************/
#pragma once

class twVector4D
{
	/********************************************************************************/
	/* Constructors & destructor												    */
	/********************************************************************************/
public:
	explicit twVector4D(float _x, float _y, 
						float _z, float _w);				/*!< Constructor with parameters */
	explicit twVector4D(float _scalar);						/*!< Constructor with one value */
	twVector4D(const twVector4D& _vec);						/*!< Constructor with a vector */
	twVector4D();											/*!< Default constructor */
	~twVector4D();											/*!< Destructor */

	/********************************************************************************/
	/* Variable declaration													        */
	/********************************************************************************/
public:
	float x;												/*!< X coordinate */
	float y;												/*!< Y coordinate */
	float z;												/*!< Z coordinate */
	float w;												/*!< W coordinate */

	static const twVector4D ZERO;                           /*!< Zero vector */
	static const twVector4D UP;								/*!< Up vector */
	static const twVector4D RIGHT;							/*!< Right vector */
	static const twVector4D LEFT;                           /*!< Left vector */
	static const twVector4D DOWN;							/*!< Down vector */

	/********************************************************************************/
	/* Functions																    */
	/********************************************************************************/
public:
	void Normalize();											/*!< Normalizes the vector */
	void Truncate(float _maxValue);								/*!< Limits the vector to the
																	current max value given */
	void Zero();												/*!< Resets the vector's
																	values to 0 */
	float Magnitude();											/*!< Returns the length
																	of this vector */

	/********************************************************************************/
	/* Operator overloading															*/
	/********************************************************************************/
public:
	void operator =	(const twVector4D& _vec);
	void operator += (const twVector4D& _vec);
	void operator -= (const twVector4D& _vec);
	void operator *= (float _scalar);
	void operator += (float _scalar);
	void operator -= (float _scalar);

	bool operator == (const twVector4D& _vec) const;
	bool operator != (const twVector4D& _vec) const;

	twVector4D operator + (const twVector4D& _vec) const;
	twVector4D operator - (const twVector4D& _vec) const;
	twVector4D operator * (float _scalar) const;
};

