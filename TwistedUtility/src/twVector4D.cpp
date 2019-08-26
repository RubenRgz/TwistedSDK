#include "twVector4D.h"
#include <math.h>

twVector4D::twVector4D(float _x, float _y, float _z, float _w)
{
	this->x = _x;
	this->y = _y;
	this->z = _z;
	this->w = _w;
}

twVector4D::twVector4D(float _scalar)
{
	this->x = _scalar;
	this->y = _scalar;
	this->z = _scalar;
	this->w = _scalar;
}

twVector4D::twVector4D(const twVector4D & _vec)
{
	*this = _vec;
}

twVector4D::twVector4D()
{
	this->x = 0.f;
	this->y = 0.f;
	this->z = 0.f;
	this->w = 0.f;
}

twVector4D::~twVector4D()
{
}

const twVector4D twVector4D::ZERO = twVector4D(0.f, 0.f, 0.f, 0.f);
const twVector4D twVector4D::UP = twVector4D(0.f, 1.f, 0.f, 0.f);
const twVector4D twVector4D::RIGHT = twVector4D(1.f, 0.f, 0.f, 0.f);
const twVector4D twVector4D::LEFT = twVector4D(-1.f, 0.f, 0.f, 0.f);
const twVector4D twVector4D::DOWN = twVector4D(0.f, -1.f, 0.f, 0.f);

void twVector4D::Normalize()
{
	float tempMagnitude = this->Magnitude();
	this->x /= tempMagnitude;
	this->y /= tempMagnitude;
	this->z /= tempMagnitude;
	this->w /= tempMagnitude;
}

void twVector4D::Truncate(float _maxValue)
{
	float i = _maxValue / this->Magnitude();
	i = i < 1.f ? i : _maxValue;

	this->x *= i;
	this->y *= i;
	this->z *= i;
	this->w *= i;
}

void twVector4D::Zero()
{
	this->x = 0.f;
	this->y = 0.f;
	this->z = 0.f;
	this->w = 0.f;
}

float twVector4D::Magnitude()
{
	return sqrtf(this->x * this->x + this->y * this->y + 
				 this->z * this->z + this->w * this->w);
}

void twVector4D::operator=(const twVector4D & _vec)
{
	this->x = _vec.x;
	this->y = _vec.y;
	this->z = _vec.z;
	this->w = _vec.w;
}

void twVector4D::operator+=(const twVector4D & _vec)
{
	this->x += _vec.x;
	this->y += _vec.y;
	this->z += _vec.z;
	this->w += _vec.w;
}

void twVector4D::operator-=(const twVector4D & _vec)
{
	this->x -= _vec.x;
	this->y -= _vec.y;
	this->z -= _vec.z;
	this->w -= _vec.w;
}

void twVector4D::operator*=(float _scalar)
{
	this->x *= _scalar;
	this->y *= _scalar;
	this->z *= _scalar;
	this->w *= _scalar;
}

void twVector4D::operator+=(float _scalar)
{
	this->x += _scalar;
	this->y += _scalar;
	this->z += _scalar;
	this->w += _scalar;
}

void twVector4D::operator-=(float _scalar)
{
	this->x -= _scalar;
	this->y -= _scalar;
	this->z -= _scalar;
	this->w -= _scalar;
}

bool twVector4D::operator==(const twVector4D & _vec) const
{
	return (this->x == _vec.x && this->y == _vec.y &&
			this->z == _vec.z && this->w == _vec.w ? true : false);
}

bool twVector4D::operator!=(const twVector4D & _vec) const
{
	return (this->x != _vec.x || this->y != _vec.y ||
			this->z != _vec.z || this->w != _vec.w ? true : false);
}

twVector4D twVector4D::operator*(float _scalar) const
{
	return twVector4D(this->x * _scalar, this->y * _scalar, 
					  this->z * _scalar, this->w * _scalar);
}

twVector4D twVector4D::operator+(const twVector4D & _vec) const
{
	return twVector4D(this->x + _vec.x, this->y + _vec.y, 
					  this->z + _vec.z, this->w + _vec.w);
}

twVector4D twVector4D::operator-(const twVector4D & _vec) const
{
	return twVector4D(this->x - _vec.x, this->y - _vec.y, 
					  this->z - _vec.z, this->w - _vec.w);
}
