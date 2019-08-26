/************************************************************************************/
/**
* @LC	  28/07/2019
* @file   twRadians.h
* @Author Ruben Rodriguez (rubn2113@gmail.com)
* @date   27/07/2019
* @brief  Radians class
* @bug	  No bugs known
*/
/************************************************************************************/
#pragma once

/************************************************************************************/
/* Includes															                */
/************************************************************************************/
#include "twDegrees.h"

namespace TwistedSDK
{
	/********************************************************************************/
	/* Radians class												                */
	/********************************************************************************/
	class twRadians
	{
		/****************************************************************************/
		/* Constructors & destructor		                                        */
		/****************************************************************************/
	public:
		explicit twRadians(float _value);				/*!< Constructor with value */
		twRadians(const twRadians& _radians);			/*!< Constructor with radians */
		twRadians(const twDegrees& _degrees);			/*!< Constructor with degrees */
		twRadians();									/*!< Default constructor */
		virtual ~twRadians();							/*!< Destructor */

		/****************************************************************************/
		/* Variable declaration								                        */
		/****************************************************************************/
	public:
		float m_radians;								/*!< Current radians */

		/****************************************************************************/
		/* Public functions                                                         */
		/****************************************************************************/
	public:
		void Unwind();									/*!< Returns current radians in
															0 - 2 PI scale */

		twDegrees ToDegrees();							/*!< Convert to degrees */

		float ToFloatDegrees();							/*!< Convert to degrees and retunrs 
															the value in float */
	};
}

