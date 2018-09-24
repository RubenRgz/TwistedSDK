#include "twVector2D.h"

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

twVector2D twVector2D::operator*(const twVector2D& _vect) const
{
	return twVector2D(x * _vect.x, y * _vect.y);
}

twVector2D twVector2D::operator+(const twVector2D& _vect) const
{
	return twVector2D(x + _vect.x, y + _vect.y);
}

twVector2D twVector2D::operator-(const twVector2D& _vect) const
{
	return twVector2D(x - _vect.x, y - _vect.y);
}

void twVector2D::setDirection(VectorDirection _direction)
{
	switch (_direction)
	{
	case VD_UP:
		x = 0;
		y = 1;
		break;
	case VD_DOWN:
		x = 0;
		y = -1;
		break;
	case VD_RIGHT:
		x = 1;
		y = 0;
		break;
	case VD_LEFT:
		x = -1;
		y = 0;
		break;
	default:
		break;
	}
}

void twVector2D::rotate(float _angle)
{
	float xt = (x * cosf(_angle)) - (y * sinf(_angle));
	float yt = (y * cosf(_angle)) + (x * sinf(_angle));
	x = xt;
	y = yt;
}

float twVector2D::crossproduct(const twVector2D& _vect) const
{
	return (this->x * _vect.y) - (this->y * _vect.x);
}

float twVector2D::magnitude()
{
	return sqrtf(x * x + y * y);
}

void twVector2D::normalize()
{
	float mag = this->magnitude();
	this->x = x / mag;
	this->y = y / mag;
}

float twVector2D::dotproduct(const twVector2D& _vect) const
{
	return (x * _vect.x) + (y * _vect.y);
}

void twVector2D::truncate(float _max)
{
	float i;

	i = _max / this->magnitude();
	i = i < 1.0f ? i : _max;

	this->x *= i;
	this->y *= i;
}

float twVector2D::getAngle()
{
	return static_cast<float>(atan2(this->y, this->x));
}

void twVector2D::scaleBy(float _scale)
{
	this->x *= _scale;
	this->y *= _scale;
}

float twVector2D::distanceFrom(const twVector2D& _vec)
{
	return sqrtf((this->x - _vec.x) * (this->x - _vec.x) +
		(this->y - _vec.y) * (this->y - _vec.y));
}

twVector2D twVector2D::projectOn(const twVector2D& _vec)
{
	float result = this->dotproduct(_vec);
	float mag = sqrtf(_vec.x * _vec.x + _vec.y * _vec.y);
	result = result / (mag * mag);

	return twVector2D(_vec.x * result, _vec.y * result);
}