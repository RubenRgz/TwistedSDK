#include "twMatrix3x3.h"

twMatrix3x3::twMatrix3x3(
	float _m00, float _m01, float _m02, 
	float _m10, float _m11, float _m12, 
	float _m20, float _m21, float _m22)
{
	m00 = _m00;
	m01 = _m01;
	m02 = _m02;
	m10 = _m10;
	m11 = _m11;
	m12 = _m12;
	m20 = _m20;
	m21 = _m21;
	m22 = _m22;
}

twMatrix3x3::twMatrix3x3(const twMatrix3x3 & _matrix)
{
	*this = _matrix;
}

twMatrix3x3::~twMatrix3x3()
{
}

void twMatrix3x3::Zero()
{
	m00 = 0.f;
	m01 = 0.f;
	m02 = 0.f;
	m10 = 0.f;
	m11 = 0.f;
	m12 = 0.f;
	m20 = 0.f;
	m21 = 0.f;
	m22 = 0.f;
}

void twMatrix3x3::operator=(const twMatrix3x3 & _matrix)
{
	m00 = _matrix.m00;
	m01 = _matrix.m01;
	m02 = _matrix.m02;
	m10 = _matrix.m10;
	m11 = _matrix.m11;
	m12 = _matrix.m12;
	m20 = _matrix.m20;
	m21 = _matrix.m21;
	m22 = _matrix.m22;
}

bool twMatrix3x3::operator==(const twMatrix3x3 & _matrix)
{
	return (m00 == _matrix.m00 &&
			m01 == _matrix.m01 &&
			m02 == _matrix.m02 &&
			m10 == _matrix.m10 &&
			m11 == _matrix.m11 &&
			m12 == _matrix.m12 &&
			m20 == _matrix.m20 &&
			m21 == _matrix.m21 &&
			m22 == _matrix.m22 ? true : false);
}

bool twMatrix3x3::operator!=(const twMatrix3x3 & _matrix)
{
	return (m00 != _matrix.m00 ||
			m01 != _matrix.m01 ||
			m02 != _matrix.m02 ||
			m10 != _matrix.m10 ||
			m11 != _matrix.m11 ||
			m12 != _matrix.m12 ||
			m20 != _matrix.m20 ||
			m21 != _matrix.m21 ||
			m22 != _matrix.m22 ? true : false);
}

twMatrix3x3 twMatrix3x3::operator+(const twMatrix3x3 & _matrix)
{
	twMatrix3x3 tempAddition;

	tempAddition.m00 = m00 + _matrix.m00;
	tempAddition.m01 = m01 + _matrix.m01;
	tempAddition.m02 = m02 + _matrix.m02;
	tempAddition.m10 = m10 + _matrix.m10;
	tempAddition.m11 = m11 + _matrix.m11;
	tempAddition.m12 = m12 + _matrix.m12;
	tempAddition.m20 = m20 + _matrix.m20;
	tempAddition.m21 = m21 + _matrix.m21;
	tempAddition.m22 = m22 + _matrix.m22;

	return tempAddition;
}

twMatrix3x3 twMatrix3x3::operator-(const twMatrix3x3 & _matrix)
{
	twMatrix3x3 tempSubstraction;

	tempSubstraction.m00 = m00 - _matrix.m00;
	tempSubstraction.m01 = m01 - _matrix.m01;
	tempSubstraction.m02 = m02 - _matrix.m02;
	tempSubstraction.m10 = m10 - _matrix.m10;
	tempSubstraction.m11 = m11 - _matrix.m11;
	tempSubstraction.m12 = m12 - _matrix.m12;
	tempSubstraction.m20 = m20 - _matrix.m20;
	tempSubstraction.m21 = m21 - _matrix.m21;
	tempSubstraction.m22 = m22 - _matrix.m22;

	return tempSubstraction;
}

twMatrix3x3 twMatrix3x3::operator*(const twMatrix3x3 & _matrix)
{
	return twMatrix3x3();
}

twMatrix3x3 twMatrix3x3::operator*(float _scalar)
{
	twMatrix3x3 tempMultiplication;

	tempMultiplication.m00 = m00 * _scalar;
	tempMultiplication.m01 = m01 * _scalar;
	tempMultiplication.m02 = m02 * _scalar;
	tempMultiplication.m10 = m10 * _scalar;
	tempMultiplication.m11 = m11 * _scalar;
	tempMultiplication.m12 = m12 * _scalar;
	tempMultiplication.m20 = m20 * _scalar;
	tempMultiplication.m21 = m21 * _scalar;
	tempMultiplication.m22 = m22 * _scalar;

	return tempMultiplication;
}


