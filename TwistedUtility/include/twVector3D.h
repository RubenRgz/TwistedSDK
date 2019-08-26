/************************************************************************************/
/**
* @LC	  31/07/2019
* @file   twVector3D.h
* @Author Ruben Rodriguez (rubn2113@gmail.com)
* @date   09/02/2018
* @brief  Vector 3D class
* @bug	 No bugs known
*/
/************************************************************************************/
#pragma once

namespace TwistedSDK
{
	/********************************************************************************/
	/* Vector 3D Class										                        */
	/********************************************************************************/
	class twVector3D
	{
		/************************************************************************/
		/* Constructors & destructor		                                    */
		/************************************************************************/
	public:
		explicit twVector3D(float _x, float _y, float _z);		/*!< Constructor
																	with parameters */
		explicit twVector3D(float _scalar);						/*!< Constructor with 
																	one value */
		twVector3D(const twVector3D& _vec);						/*!< Constructor
																	with vector */
		twVector3D();											/*!< Default constructor */
		~twVector3D();											/*!< Destructor */

		/************************************************************************/
		/* Variable declaration								                    */
		/************************************************************************/
	public:
		float x;												/*!< X coordinate */
		float y;												/*!< Y coordinate */
		float z;												/*!< Z coordinate */

		static const twVector3D ZERO;                           /*!< Zero vector */
		static const twVector3D UP;								/*!< Up vector */
		static const twVector3D RIGHT;							/*!< Right vector */
		static const twVector3D LEFT;                           /*!< Left vector */
		static const twVector3D DOWN;							/*!< Down vector */

		/****************************************************************************/
		/* Functions															    */
		/****************************************************************************/
	public:
		void Normalize();											/*!< Normalizes the 
																		vector */
		void Truncate(float _maxValue);								/*!< Limits the vector 
																		to the current max 
																		value given */
		void Zero();												/*!< Resets the vector's 
																		values to 0 */

		
		float Magnitude();											/*!< Returns the length
																		of this vector */
		float DotProduct(const twVector3D& _vec) const;				/*!< Returns a scalar 
																		between two vectors.
																		If the result is 0 the 
																		vectors are orthogonal,
																		if the result is > 0 
																		the angle between the 
																		two vectors is less 
																		than 90°, and if the 
																		result is < 0 the angle
																		between this vectors is
																		greater than 90° */
		float DistanceFrom(const twVector3D& _vec);					/*!< Returns the distance
																		between 2 vectors */

		bool isNormilized();										/*!< Verifies if this vector
																		is already normalized */

		twVector3D CrossProduct(const twVector3D& _vec) const;		/*!< Returns the orthogonal
																		vector between 
																		two vectors */
		twVector3D ProjectOn(const twVector3D& _vec) const;				/*!< Returns the projection
																		of this vector on the
																		given one */

		/****************************************************************************/
		/* Operator overloading													    */
		/****************************************************************************/
	public:
		void operator =	(const twVector3D& _vec);
		void operator += (const twVector3D& _vec);
		void operator -= (const twVector3D& _vec);
		void operator *= (float _scalar);
		void operator += (float _scalar);
		void operator -= (float _scalar);

		bool operator == (const twVector3D& _vec) const;
		bool operator != (const twVector3D& _vec) const;

		twVector3D operator + (const twVector3D& _vec) const;
		twVector3D operator - (const twVector3D& _vec) const;
		twVector3D operator * (float _scalar) const;
	};
}
