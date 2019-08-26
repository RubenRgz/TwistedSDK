/************************************************************************************/
/**
* @LC	  28/07/2019
* @file   twDegrees.h
* @Author Ruben Rodriguez (rubn2113@gmail.com)
* @date   27/07/2019
* @brief  Degrees class
* @bug	  No bugs known
*/
/************************************************************************************/
#pragma once

/************************************************************************************/
/* Includes															                */
/************************************************************************************/
#include "twRadians.h"

namespace TwistedSDK
{
	/********************************************************************************/
	/* Degrees class												                */
	/********************************************************************************/
	class twDegrees
	{
		/****************************************************************************/
		/* Constructors & destructor		                                        */
		/****************************************************************************/
	public:
		explicit twDegrees(float _value);				/*!< Constructor with value */
		twDegrees(const twDegrees& _degrees);			/*!< Constructor with degrees */
		twDegrees(const twRadians& _radians);			/*!< Constructor with radians */
		twDegrees();									/*!< Default constructor */
		virtual ~twDegrees();							/*!< Destructor */

		/****************************************************************************/
		/* Variable declaration								                        */
		/****************************************************************************/
	public:
		float m_degrees;								/*!< Current degrees */

		/****************************************************************************/
		/* Public functions                                                         */
		/****************************************************************************/
	public:
		void Unwind();									/*!< Returns current degrees in
															0 - 360 scale */
		
		twRadians ToRadians();							/*!< Convert to radians */

		float ToFloatRadians();							/*!< Convert to radians and retunrs 
															the value in float */
	};
}
