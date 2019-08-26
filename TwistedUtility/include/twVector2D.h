/************************************************************************************/
/**
* @LC	  31/07/2019
* @file   twVector2D.h
* @Author Ruben Rodriguez (rubn2113@gmail.com)
* @date   09/02/2018
* @brief  Vector 2D class
* @bug	  No bugs known
*/
/************************************************************************************/
#pragma once

namespace TwistedSDK
{
	/********************************************************************************/
	/* Vector 2D Class								                                */
	/********************************************************************************/
	class twVector2D
	{
		/****************************************************************************/
		/* Constructors & destructor		                                        */
		/****************************************************************************/
	public:
		explicit twVector2D(float _x, float _y);			 /*!< Constructor with parameters */
		explicit twVector2D(float _scalar);					 /*!< Constructor with one value */
		twVector2D(const twVector2D& _vec);					 /*!< Constructor with a vector */
		twVector2D();                                        /*!< Default constructor */
		~twVector2D();										 /*!< Destructor */

		/****************************************************************************/
		/* Variable declaration								                        */
		/****************************************************************************/
	public:
		float x;												/*!< X coordinate */
		float y;												/*!< Y coordinate */

		static const twVector2D ZERO;                           /*!< Zero vector */
		static const twVector2D UP;								/*!< Up vector */
		static const twVector2D RIGHT;							/*!< Right vector */
		static const twVector2D LEFT;                           /*!< Left vector */
		static const twVector2D DOWN;							/*!< Down vector */

		/****************************************************************************/
		/* Public functions                                                         */
		/****************************************************************************/
	public:
		void Normalize();									/*!< Normalizes the vector */
		void Truncate(float _maxValue);						/*!< Limits the vector to the
																current max value given */
		void Rotate(float _angle);							/*!< Rotates the vector */
		void Zero();										/*!< Resets these vector's 
																values to 0 */

		float Magnitude();									/*!< Returns the length 
																of this vector */
		float GetAngle();									/*!< Returns the angle 
																of this vector */
		float DistanceFrom(const twVector2D& _vec);			/*!< Returns the distance 
																between two vectors */
		float DotProduct(const twVector2D& _vec) const;		/*!< Returns a scalar between 
															two vectors. If the result is 0 
															the vectors are orthogonal,
															if the result > 0 the angle between
															the two vectors is less than 90°,
															and if the result < 0 the angle 
															between this vectors is greater 
															than 90° */
	
		bool isNormilized();								/*!< Verifies if this vector
																is already normalized */

		twVector2D CrossProduct(const twVector2D& _vec) const;	/*!< Returns the orthogonal
																	vector between 
																	two vectors */
		twVector2D ProjectOn(const twVector2D& _vec) const;		/*!< Returns the normalized 
																	projection of this vector 
																	on the given one */

		/****************************************************************************/
		/* Operator overloading                                                     */
		/****************************************************************************/
	public:
		void operator =	(const twVector2D& _vec);
		void operator += (const twVector2D& _vec);
		void operator -= (const twVector2D& _vec);
		void operator *= (float _scalar);
		void operator += (float _scalar);
		void operator -= (float _scalar);

		bool operator == (const twVector2D& _vec) const;
		bool operator != (const twVector2D& _vec) const;

		twVector2D operator + (const twVector2D& _vec) const;
		twVector2D operator - (const twVector2D& _vec) const;
		twVector2D operator * (float _scalar) const;
	};
}
