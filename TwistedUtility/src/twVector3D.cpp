#include "twVector3D.h"
#include <math.h>



twVector3D::twVector3D(float _x, float _y, float _z)
{
	x = _x;
	y = _y;
	z = _z;
}

twVector3D::twVector3D(const twVector3D & _vec)
{
	*this = _vec;
}

twVector3D::~twVector3D()
{
}

twVector3D twVector3D::operator*(float _scalar) const
{
	return twVector3D(x * _scalar, y * _scalar, z * _scalar);
}

twVector3D twVector3D::operator*(const twVector3D & _vec) const
{
	return twVector3D(x * _vec.x, y * _vec.y, z * _vec.z);
}

twVector3D twVector3D::operator+(const twVector3D & _vec) const
{
	return twVector3D(x + _vec.x, y + _vec.y, z + _vec.z);
}

twVector3D twVector3D::operator-(const twVector3D & _vec) const
{
	return twVector3D(x - _vec.x, y - _vec.y, z - _vec.z);
}

void twVector3D::Normalize()
{
	float mag = this->Magnitude();
	this->x = x / mag;
	this->y = y / mag;
	this->z = z / mag;
}

void twVector3D::ScaleBy(float _scale)
{
	this->x *= _scale;
	this->y *= _scale;
	this->z *= _scale;
}

void twVector3D::Zero()
{
	x = 0.f;
	y = 0.f;
	z = 0.f;
}

twVector3D twVector3D::CrossProduct(const twVector3D & _vec) const
{
	return twVector3D((this->y * _vec.z - this->z * _vec.y), 
					  (this->z * _vec.x - this->x * _vec.z), 
					  (this->x * _vec.y - this->y * _vec.x));
}

float twVector3D::Magnitude()
{
	return sqrtf(x * x + y * y + z * z);
}

float twVector3D::DotProduct(const twVector3D & _vec) const
{
	return (x * _vec.x) + (y * _vec.y) + (z * _vec.z);
}

float twVector3D::DistanceFrom(const twVector3D & _vec)
{
	return sqrtf((this->x - _vec.x) * (this->x - _vec.x) +
		(this->y - _vec.y) * (this->y - _vec.y) + (this->z - _vec.z) * (this->z - _vec.z));
}

bool twVector3D::isNormilized()
{
	if (sqrtf(x * x + y * y + z * z) == 1.f)
		return true;

	return false;
}
