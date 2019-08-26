#include "twRadians.h"
#define _USE_MATH_DEFINES
#include <cmath>

namespace TwistedSDK
{
	twRadians::twRadians(float _value)
	{
		this->m_radians = _value;
	}

	twRadians::twRadians(const twRadians & _radians)
	{
		*this = _radians;
	}

	TwistedSDK::twRadians::twRadians(const twDegrees & _degrees)
	{
		this->m_radians = _degrees.m_degrees * (M_PI / 180.f);
	}

	twRadians::twRadians()
	{
		this->m_radians = 0.f;
	}


	twRadians::~twRadians()
	{
	}

	void twRadians::Unwind()
	{
		while (this->m_radians >= 2 * M_PI)
		{
			this->m_radians -= 2 * M_PI;
		}
	}
	twDegrees twRadians::ToDegrees()
	{

		return twDegrees(this->m_radians * (180.f / M_PI));
	}
	float twRadians::ToFloatDegrees()
	{
		return this->m_radians * (180.f / M_PI);
	}
}
