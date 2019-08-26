#include "twVector3D.h"
#include <math.h>


namespace TwistedSDK
{
	twVector3D::twVector3D(float _x, float _y, float _z)
	{
		this->x = _x;
		this->y = _y;
		this->z = _z;
	}

	twVector3D::twVector3D(float _scalar)
	{
		this->x = _scalar;
		this->y = _scalar;
		this->z = _scalar;
	}

	twVector3D::twVector3D(const twVector3D & _vec)
	{
		*this = _vec;
	}

	twVector3D::twVector3D()
	{
		this->x = 0.f;
		this->y = 0.f;
		this->z = 0.f;
	}

	twVector3D::~twVector3D()
	{
	}

	const twVector3D twVector3D::ZERO = twVector3D(0.f, 0.f, 0.f);
	const twVector3D twVector3D::UP = twVector3D(0.f, 1.f, 0.f);
	const twVector3D twVector3D::RIGHT = twVector3D(1.f, 0.f, 0.f);
	const twVector3D twVector3D::LEFT = twVector3D(-1.f, 0.f, 0.f);
	const twVector3D twVector3D::DOWN = twVector3D(0.f, -1.f, 0.f);

	void twVector3D::Normalize()
	{
		float tempMagnitude = this->Magnitude();
		this->x /= tempMagnitude;
		this->y /= tempMagnitude;
		this->z /= tempMagnitude;
	}

	void twVector3D::Truncate(float _maxValue)
	{
		float i = _maxValue / this->Magnitude();
		i = i < 1.f ? i : _maxValue;

		this->x *= i;
		this->y *= i;
		this->z *= i;
	}

	void twVector3D::Zero()
	{
		this->x = 0.f;
		this->y = 0.f;
		this->z = 0.f;
	}

	float twVector3D::Magnitude()
	{
		return sqrtf(this->x * this->x + this->y * this->y + this->z * this->z);
	}

	float twVector3D::DotProduct(const twVector3D & _vec) const
	{
		return (this->x * _vec.x) + (this->y * _vec.y) + (this->z * _vec.z);
	}

	float twVector3D::DistanceFrom(const twVector3D & _vec)
	{
		return sqrtf((this->x - _vec.x) * (this->x - _vec.x) +
					 (this->y - _vec.y) * (this->y - _vec.y) + 
					 (this->z - _vec.z) * (this->z - _vec.z));
	}

	bool twVector3D::isNormilized()
	{
		float tempMagnitude = this->Magnitude();
		return (this->x / tempMagnitude == 1.f &&
				this->y / tempMagnitude == 1.f &&
				this->z / tempMagnitude == 1.f ? true : false);
	}

	twVector3D twVector3D::CrossProduct(const twVector3D & _vec) const
	{
		return twVector3D((this->y * _vec.z - this->z * _vec.y),
						  (this->z * _vec.x - this->x * _vec.z),
						  (this->x * _vec.y - this->y * _vec.x));
	}

	twVector3D twVector3D::ProjectOn(const twVector3D & _vec) const
	{
		float tempResult = this->DotProduct(_vec);
		float tempMagnitude = const_cast<twVector3D &>(_vec).Magnitude();
		tempResult /= tempMagnitude * tempMagnitude;

		return twVector3D(_vec.x * tempResult, _vec.y * tempResult, _vec.z * tempResult);
	}

	void twVector3D::operator=(const twVector3D & _vec)
	{
		this->x = _vec.x;
		this->y = _vec.y;
		this->z = _vec.z;
	}

	void twVector3D::operator+=(const twVector3D & _vec)
	{
		this->x += _vec.x;
		this->y += _vec.y; 
		this->z += _vec.z;
	}

	void twVector3D::operator-=(const twVector3D & _vec)
	{
		this->x -= _vec.x;
		this->y -= _vec.y;
		this->z -= _vec.z;
	}

	void twVector3D::operator*=(float _scalar)
	{
		this->x *= _scalar;
		this->y *= _scalar;
		this->z *= _scalar;
	}

	void twVector3D::operator+=(float _scalar)
	{
		this->x += _scalar;
		this->y += _scalar;
		this->z += _scalar;
	}

	void twVector3D::operator-=(float _scalar)
	{
		this->x -= _scalar;
		this->y -= _scalar;
		this->z -= _scalar;
	}

	bool twVector3D::operator==(const twVector3D & _vec) const
	{
		return (this->x == _vec.x && this->y == _vec.y &&
				this->z == _vec.z ? true : false);
	}

	bool twVector3D::operator!=(const twVector3D & _vec) const
	{
		return (this->x != _vec.x || this->y != _vec.y ||
				this->z != _vec.z ? true : false);
	}

	twVector3D twVector3D::operator*(float _scalar) const
	{
		return twVector3D(x * _scalar, y * _scalar, z * _scalar);
	}

	twVector3D twVector3D::operator+(const twVector3D & _vec) const
	{
		return twVector3D(x + _vec.x, y + _vec.y, z + _vec.z);
	}

	twVector3D twVector3D::operator-(const twVector3D & _vec) const
	{
		return twVector3D(x - _vec.x, y - _vec.y, z - _vec.z);
	}
}
