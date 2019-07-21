#include "twPoint.h"

namespace TwistedSDK
{
	twPoint::twPoint(float _x = 0.f, float _y = 0.f)
	{
		this->x = _x;
		this->y = _y;
	}

	twPoint::twPoint(const twPoint & _point)
	{
		*this = _point;
	}

	twPoint::twPoint()
	{
		this->x = 0.f;
		this->y = 0.f;
	}

	twPoint::~twPoint() {}

	void twPoint::operator=(const twPoint & _point)
	{
		this->x = _point.x;
		this->y = _point.y;
	}

	void twPoint::operator+=(const twPoint & _point)
	{
		this->x += _point.x;
		this->y += _point.y;
	}

	void twPoint::operator-=(const twPoint & _point)
	{
		this->x -= _point.x;
		this->y -= _point.y;
	}

	void twPoint::operator*=(const twPoint & _point)
	{
		this->x *= _point.x;
		this->y *= _point.y;
	}

	void twPoint::operator/=(const twPoint & _point)
	{
		this->x /= _point.x;
		this->y /= _point.y;
	}

	void twPoint::operator+=(float _value)
	{
		this->x += _value;
		this->y += _value;
	}

	void twPoint::operator-=(float _value)
	{
		this->x -= _value;
		this->y -= _value;
	}

	void twPoint::operator*=(float _value)
	{
		this->x *= _value;
		this->y *= _value;
	}

	void twPoint::operator/=(float _value)
	{
		this->x /= _value;
		this->y /= _value;
	}

	bool twPoint::operator==(const twPoint & _point) const
	{
		if (this->x == _point.x && this->y == _point.y)
		{
			return true;
		}
		return false;
	}

	bool twPoint::operator!=(const twPoint & _point) const
	{
		if (this->x != _point.x || this->y != _point.y)
		{
			return true;
		}
		return false;
	}

	twPoint twPoint::operator+(const twPoint & _point) const
	{
		return twPoint(this->x + _point.x, this->y + _point.y);
	}

	twPoint twPoint::operator-(const twPoint & _point) const
	{
		return twPoint(this->x - _point.x, this->y - _point.y);
	}

	twPoint twPoint::operator*(const twPoint & _point) const
	{
		return twPoint(this->x * _point.x, this->y * _point.y);
	}

	twPoint twPoint::operator/(const twPoint & _point) const
	{
		return twPoint(this->x / _point.x, this->y / _point.y);
	}
}
