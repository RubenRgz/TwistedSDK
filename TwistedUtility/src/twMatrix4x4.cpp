#include "twMatrix4x4.h"
#include "twDataTypes.h"

twMatrix4x4::twMatrix4x4(float _m00, float _m01, float _m02, float _m03, 
						 float _m10, float _m11, float _m12, float _m13, 
						 float _m20, float _m21, float _m22, float _m23, 
						 float _m30, float _m31, float _m32, float _m33)
{
	m00 = _m00;
	m01 = _m01;
	m02 = _m02;
	m03 = _m03;
	m10 = _m10;
	m11 = _m11;
	m12 = _m12;
	m13 = _m13;
	m20 = _m20;
	m21 = _m21;
	m22 = _m22;
	m23 = _m23;
	m30 = _m30;
	m31 = _m31;
	m32 = _m32;
	m33 = _m33;
}

twMatrix4x4::twMatrix4x4(const twVector4D & _vec1, const twVector4D & _vec2, 
						 const twVector4D & _vec3, const twVector4D & _vec4)
{
	m00 = _vec1.x;
	m01 = _vec1.y;
	m02 = _vec1.z;
	m03 = _vec1.w;
	m10 = _vec2.x;
	m11 = _vec2.y;
	m12 = _vec2.z;
	m13 = _vec2.w;
	m20 = _vec3.x;
	m21 = _vec3.y;
	m22 = _vec3.z;
	m23 = _vec3.w;
	m30 = _vec4.x;
	m31 = _vec4.y;
	m32 = _vec4.z;
	m33 = _vec4.w;
}

twMatrix4x4::twMatrix4x4(const twMatrix4x4 & _matrix)
{
	*this = _matrix;
}

twMatrix4x4::~twMatrix4x4()
{
}

void twMatrix4x4::Zero()
{
	m00 = 0.f;
	m01 = 0.f;
	m02 = 0.f;
	m03 = 0.f;
	m10 = 0.f;
	m11 = 0.f;
	m12 = 0.f;
	m13 = 0.f;
	m20 = 0.f;
	m21 = 0.f;
	m22 = 0.f;
	m23 = 0.f;
	m30 = 0.f;
	m31 = 0.f;
	m32 = 0.f;
	m33 = 0.f;
}

void twMatrix4x4::Transpose()
{
	twMatrix4x4 tempLastMatrix = *this;

	m00 = tempLastMatrix.m00;
	m01 = tempLastMatrix.m10;
	m02 = tempLastMatrix.m20;
	m03 = tempLastMatrix.m30;
	m10 = tempLastMatrix.m01;
	m11 = tempLastMatrix.m11;
	m12 = tempLastMatrix.m21;
	m13 = tempLastMatrix.m31;
	m20 = tempLastMatrix.m02;
	m21 = tempLastMatrix.m12;
	m22 = tempLastMatrix.m22;
	m23 = tempLastMatrix.m32;
	m30 = tempLastMatrix.m03;
	m31 = tempLastMatrix.m13;
	m32 = tempLastMatrix.m23;
	m33 = tempLastMatrix.m33;
}

void twMatrix4x4::Identity()
{
	m00 = 1.f;
	m11 = 1.f;
	m22 = 1.f;
	m33 = 1.f;
}

void twMatrix4x4::operator=(const twMatrix4x4 & _matrix)
{
	m00 = _matrix.m00;
	m01 = _matrix.m10;
	m02 = _matrix.m20;
	m03 = _matrix.m30;
	m10 = _matrix.m01;
	m11 = _matrix.m11;
	m12 = _matrix.m21;
	m13 = _matrix.m31;
	m20 = _matrix.m02;
	m21 = _matrix.m12;
	m22 = _matrix.m22;
	m23 = _matrix.m32;
	m30 = _matrix.m03;
	m31 = _matrix.m13;
	m32 = _matrix.m23;
	m33 = _matrix.m33;
}

bool twMatrix4x4::operator==(const twMatrix4x4 & _matrix)
{
	return (m00 == _matrix.m00 &&
			m01 == _matrix.m10 &&
			m02 == _matrix.m20 &&
			m03 == _matrix.m30 &&
			m10 == _matrix.m01 &&
			m11 == _matrix.m11 &&
			m12 == _matrix.m21 &&
			m13 == _matrix.m31 &&
			m20 == _matrix.m02 &&
			m21 == _matrix.m12 &&
			m22 == _matrix.m22 &&
			m23 == _matrix.m32 &&
			m30 == _matrix.m03 &&
			m31 == _matrix.m13 &&
			m32 == _matrix.m23 &&
			m33 == _matrix.m33 ? true : false);		
}

bool twMatrix4x4::operator!=(const twMatrix4x4 & _matrix)
{
	return (m00 != _matrix.m00 ||
			m01 != _matrix.m10 ||
			m02 != _matrix.m20 ||
			m03 != _matrix.m30 ||
			m10 != _matrix.m01 ||
			m11 != _matrix.m11 ||
			m12 != _matrix.m21 ||
			m13 != _matrix.m31 ||
			m20 != _matrix.m02 ||
			m21 != _matrix.m12 ||
			m22 != _matrix.m22 ||
			m23 != _matrix.m32 ||
			m30 != _matrix.m03 ||
			m31 != _matrix.m13 ||
			m32 != _matrix.m23 ||
			m33 != _matrix.m33 ? true : false);
}

twMatrix4x4 twMatrix4x4::operator+(const twMatrix4x4 & _matrix)
{
	twMatrix4x4 tempAddition;

	tempAddition.m00 = m00 + _matrix.m00;
	tempAddition.m01 = m01 + _matrix.m10;
	tempAddition.m02 = m02 + _matrix.m20;
	tempAddition.m03 = m03 + _matrix.m30;
	tempAddition.m10 = m10 + _matrix.m01;
	tempAddition.m11 = m11 + _matrix.m11;
	tempAddition.m12 = m12 + _matrix.m21;
	tempAddition.m13 = m13 + _matrix.m31;
	tempAddition.m20 = m20 + _matrix.m02;
	tempAddition.m21 = m21 + _matrix.m12;
	tempAddition.m22 = m22 + _matrix.m22;
	tempAddition.m23 = m23 + _matrix.m32;
	tempAddition.m30 = m30 + _matrix.m03;
	tempAddition.m31 = m31 + _matrix.m13;
	tempAddition.m32 = m32 + _matrix.m23;
	tempAddition.m33 = m33 + _matrix.m33;

	return tempAddition;
}

twMatrix4x4 twMatrix4x4::operator-(const twMatrix4x4 & _matrix)
{
	twMatrix4x4 tempSubstraction;

	tempSubstraction.m00 = m00 - _matrix.m00;
	tempSubstraction.m01 = m01 - _matrix.m10;
	tempSubstraction.m02 = m02 - _matrix.m20;
	tempSubstraction.m03 = m03 - _matrix.m30;
	tempSubstraction.m10 = m10 - _matrix.m01;
	tempSubstraction.m11 = m11 - _matrix.m11;
	tempSubstraction.m12 = m12 - _matrix.m21;
	tempSubstraction.m13 = m13 - _matrix.m31;
	tempSubstraction.m20 = m20 - _matrix.m02;
	tempSubstraction.m21 = m21 - _matrix.m12;
	tempSubstraction.m22 = m22 - _matrix.m22;
	tempSubstraction.m23 = m23 - _matrix.m32;
	tempSubstraction.m30 = m30 - _matrix.m03;
	tempSubstraction.m31 = m31 - _matrix.m13;
	tempSubstraction.m32 = m32 - _matrix.m23;
	tempSubstraction.m33 = m33 - _matrix.m33;

	return tempSubstraction;
}

twMatrix4x4 twMatrix4x4::operator*(const twMatrix4x4 & _matrix)
{
	twMatrix4x4 tempMatrixMultiplication;

	for (tw_uint32 i = 0; i < 4; ++i)
	{
		for (tw_uint32 j = 0; j < 4; ++j)
		{
			for (tw_uint32 k = 0; k < 4; ++k)
			{
				tempMatrixMultiplication.Line[i][j] += (Line[i][k] * _matrix.Line[k][j]);
			}
		}
	}

	return tempMatrixMultiplication;
}

twMatrix4x4 twMatrix4x4::operator*(float _scalar)
{
	twMatrix4x4 tempMultiplication;

	tempMultiplication.m00 = m00 * _scalar;
	tempMultiplication.m01 = m01 * _scalar;
	tempMultiplication.m02 = m02 * _scalar;
	tempMultiplication.m03 = m03 * _scalar;
	tempMultiplication.m10 = m10 * _scalar;
	tempMultiplication.m11 = m11 * _scalar;
	tempMultiplication.m12 = m12 * _scalar;
	tempMultiplication.m13 = m13 * _scalar;
	tempMultiplication.m20 = m20 * _scalar;
	tempMultiplication.m21 = m21 * _scalar;
	tempMultiplication.m22 = m22 * _scalar;
	tempMultiplication.m23 = m23 * _scalar;
	tempMultiplication.m30 = m30 * _scalar;
	tempMultiplication.m31 = m31 * _scalar;
	tempMultiplication.m32 = m32 * _scalar;
	tempMultiplication.m33 = m33 * _scalar;

	return tempMultiplication;
}
