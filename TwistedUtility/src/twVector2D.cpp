#include "twVector2D.h"
#include <math.h>

namespace TwistedSDK
{
	twVector2D::twVector2D(float _x = 0.f, float _y = 0.f)
	{
		this->x = _x;
		this->y = _y;
	}

	twVector2D::twVector2D(const twVector2D & _vec)
	{
		*this = _vec;
	}

	twVector2D::twVector2D()
	{
		this->x = 0.f;
		this->y = 0.f;
	}

	twVector2D::~twVector2D() {};

	const twVector2D twVector2D::ZERO = twVector2D(0.f, 0.f);
	const twVector2D twVector2D::UP = twVector2D(0.f, 1.f);
	const twVector2D twVector2D::RIGHT = twVector2D(1.f, 0.f);
	const twVector2D twVector2D::LEFT = twVector2D(-1.f, 0.f);
	const twVector2D twVector2D::DOWN = twVector2D(0.f, -1.f);

	void twVector2D::Normalize()
	{
		float tempMagnitude = this->Magnitude();
		this->x /= tempMagnitude;
		this->y /= tempMagnitude;
	}

	void twVector2D::Truncate(float _maxValue)
	{
		float i = _maxValue / this->Magnitude();
		i = i < 1.f ? i : _maxValue;

		this->x *= i;
		this->y *= i;
	}

	void twVector2D::Rotate(float _angle)
	{
		this->x = (this->x * cosf(_angle)) - (this->y * sinf(_angle));
		this->y = (this->y * cosf(_angle)) + (this->x * sinf(_angle));
	}

	void twVector2D::Zero()
	{
		x = 0.f;
		y = 0.f;
	}

	float twVector2D::Magnitude()
	{
		return sqrtf(this->x * this->x + this->y * this->y);
	}

	float twVector2D::GetAngle()
	{
		return static_cast<float>(atan2(this->y, this->x));
	}

	float twVector2D::DistanceFrom(const twVector2D& _vec)
	{
		return sqrtf((this->x - _vec.x) * (this->x - _vec.x) +
			(this->y - _vec.y) * (this->y - _vec.y));
	}

	float twVector2D::DotProduct(const twVector2D& _vec) const
	{
		return (this->x * _vec.x) + (this->y * _vec.y);
	}

	float twVector2D::CrossProduct(const twVector2D& _vec) const
	{
		return (this->x * _vec.y) - (this->y * _vec.x);
	}

	bool twVector2D::isNormilized()
	{
		float tempMagnitude = this->Magnitude();
		if (this->x / tempMagnitude == 1.f && this->y / tempMagnitude == 1.f)
		{
			return true;
		}
		return false;
	}

	twVector2D twVector2D::ProjectOn(const twVector2D& _vec)
	{
		float tempResult = this->DotProduct(_vec);
		float tempMagnitude = const_cast<twVector2D &>(_vec).Magnitude();
		tempResult /= tempMagnitude * tempMagnitude;

		return twVector2D(_vec.x * tempResult, _vec.y * tempResult);
	}

	void twVector2D::operator=(const twVector2D & _vec)
	{
		this->x = _vec.x;
		this->y = _vec.y;
	}

	void twVector2D::operator+=(const twVector2D & _vec)
	{
		this->x += _vec.x;
		this->y += _vec.y;
	}

	void twVector2D::operator-=(const twVector2D & _vec)
	{
		this->x -= _vec.x;
		this->y -= _vec.y;
	}

	void twVector2D::operator*=(float _scalar)
	{
		this->x *= _scalar;
		this->y *= _scalar;
	}

	void twVector2D::operator+=(float _scalar)
	{
		this->x += _scalar;
		this->y += _scalar;
	}

	void twVector2D::operator-=(float _scalar)
	{
		this->x -= _scalar;
		this->y -= _scalar;
	}

	bool twVector2D::operator==(const twVector2D & _vec) const
	{
		if (this->x == _vec.x && this->y == _vec.y)
		{
			return true;
		}
		return false;
	}

	bool twVector2D::operator!=(const twVector2D & _vec) const
	{
		if (this->x != _vec.x || this->y != _vec.y)
		{
			return true;
		}
		return false;
	}

	twVector2D twVector2D::operator+(const twVector2D& _vec) const
	{
		return twVector2D(this->x + _vec.x, this->y + _vec.y);
	}

	twVector2D twVector2D::operator-(const twVector2D& _vec) const
	{
		return twVector2D(this->x - _vec.x, this->y - _vec.y);
	}

	twVector2D twVector2D::operator*(float _scalar) const
	{
		return twVector2D(this->x * _scalar, this->y * _scalar);
	}
}
