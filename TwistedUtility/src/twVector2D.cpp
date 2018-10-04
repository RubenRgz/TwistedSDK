#include "twVector2D.h"
#include <math.h>

twVector2D::twVector2D(float _x, float _y)
{
	x = _x;
	y = _y;
}

twVector2D::twVector2D(const twVector2D & _vec)
{
	*this = _vec;
}

twVector2D::~twVector2D() {};

twVector2D twVector2D::operator*(float _scalar) const
{
	return twVector2D(x * _scalar, y * _scalar);
}

twVector2D twVector2D::operator*(const twVector2D& _vec) const
{
	return twVector2D(x * _vec.x, y * _vec.y);
}

twVector2D twVector2D::operator+(const twVector2D& _vec) const
{
	return twVector2D(x + _vec.x, y + _vec.y);
}

twVector2D twVector2D::operator-(const twVector2D& _vec) const
{
	return twVector2D(x - _vec.x, y - _vec.y);
}

void twVector2D::SetDirection(const VectorDirection& _direction)
{
	switch (_direction)
	{
	case VD_UP:
		x = 0.f;
		y = 1.f;
		break;
	case VD_DOWN:
		x = 0.f;
		y = -1.f;
		break;
	case VD_RIGHT:
		x = 1.f;
		y = 0.f;
		break;
	case VD_LEFT:
		x = -1.f;
		y = 0.f;
		break;
	default:
		break;
	}
}

void twVector2D::Rotate(float _angle)
{
	float xt = (x * cosf(_angle)) - (y * sinf(_angle));
	float yt = (y * cosf(_angle)) + (x * sinf(_angle));
	x = xt;
	y = yt;
}

float twVector2D::CrossProduct(const twVector2D& _vec) const
{
	return (this->x * _vec.y) - (this->y * _vec.x);
}

float twVector2D::Magnitude()
{
	return sqrtf(x * x + y * y);
}

void twVector2D::Normalize()
{
	float mag = this->Magnitude();
	this->x = x / mag;
	this->y = y / mag;
}

float twVector2D::DotProduct(const twVector2D& _vec) const
{
	return (x * _vec.x) + (y * _vec.y);
}

void twVector2D::Truncate(float _max)
{
	float i;

	i = _max / this->Magnitude();
	i = i < 1.f ? i : _max;

	this->x *= i;
	this->y *= i;
}

float twVector2D::GetAngle()
{
	return static_cast<float>(atan2(this->y, this->x));
}

void twVector2D::ScaleBy(float _scale)
{
	this->x *= _scale;
	this->y *= _scale;
}

void twVector2D::Zero()
{
	x = 0.f;
	y = 0.f;
}

float twVector2D::DistanceFrom(const twVector2D& _vec)
{
	return sqrtf((this->x - _vec.x) * (this->x - _vec.x) +
		(this->y - _vec.y) * (this->y - _vec.y));
}

bool twVector2D::isNormilized()
{
	if (sqrtf(x * x + y * y) == 1.f)
		return true;

	return false;
}

twVector2D twVector2D::ProjectOn(const twVector2D& _vec)
{
	float result = this->DotProduct(_vec);
	float mag = sqrtf(_vec.x * _vec.x + _vec.y * _vec.y);
	result = result / (mag * mag);

	return twVector2D(_vec.x * result, _vec.y * result);
}