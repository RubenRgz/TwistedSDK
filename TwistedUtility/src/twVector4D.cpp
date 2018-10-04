#include "twVector4D.h"

twVector4D::twVector4D(float _x, float _y, float _z, float _w)
{
	x = _x;
	y = _y;
	z = _z;
	w = _w;
}

twVector4D::twVector4D(const twVector4D & _vec)
{
	*this = _vec;
}

twVector4D::~twVector4D()
{
}

void twVector4D::operator=(const twVector4D & _vec)
{
	this->x = _vec.x;
	this->y = _vec.y;
	this->z = _vec.z;
	this->w = _vec.w;
}

twVector4D twVector4D::operator*(float _scalar) const
{
	return twVector4D(x * _scalar, y * _scalar, z * _scalar, w * _scalar);
}

twVector4D twVector4D::operator+(const twVector4D & _vec) const
{
	return twVector4D(x + _vec.x, y + _vec.y, z + _vec.z, w + _vec.w);
}

twVector4D twVector4D::operator-(const twVector4D & _vec) const
{
	return twVector4D(x - _vec.x, y - _vec.y, z - _vec.z, w - _vec.w);
}
