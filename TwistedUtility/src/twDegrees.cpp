#include "twDegrees.h"
#define _USE_MATH_DEFINES
#include <cmath>

namespace TwistedSDK
{
	twDegrees::twDegrees(float _value)
	{
		this->m_degrees =_value;
	}

	twDegrees::twDegrees(const twDegrees & _degrees)
	{
		*this = _degrees;
	}

	twDegrees::twDegrees(const twRadians & _radians)
	{
		this->m_degrees = _radians.m_radians * (180.f / M_PI);
	}

	twDegrees::twDegrees()
	{
		this->m_degrees = 0;
	}

	twDegrees::~twDegrees()
	{
	}

	void twDegrees::Unwind()
	{
		while (this->m_degrees >= 360.f)
		{
			this->m_degrees -= 360.f;
		}
	}

	twRadians twDegrees::ToRadians()
	{
		return twRadians(this->m_degrees * (M_PI / 180.f));
	}

	float twDegrees::ToFloatRadians()
	{
		return this->m_degrees * (M_PI / 180.f);
	}
}
