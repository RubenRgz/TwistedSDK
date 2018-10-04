#include "twMatrix3x3.h"
#include "twDataTypes.h"

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

twMatrix3x3::twMatrix3x3(const twVector3D & _vec1, const twVector3D & _vec2, const twVector3D & _vec3)
{
	m00 = _vec1.x;
	m01 = _vec1.y;
	m02 = _vec1.z;
	m10 = _vec2.x;
	m11 = _vec2.y;
	m12 = _vec2.z;
	m20 = _vec3.x;
	m21 = _vec3.y;
	m22 = _vec3.z;
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

void twMatrix3x3::Transpose()
{
	twMatrix3x3 tempLastMatrix = *this;

	m00 = tempLastMatrix.m00;
	m01 = tempLastMatrix.m10;
	m02 = tempLastMatrix.m20;
	m10 = tempLastMatrix.m01;
	m11 = tempLastMatrix.m11;
	m12 = tempLastMatrix.m21;
	m20 = tempLastMatrix.m02;
	m21 = tempLastMatrix.m12;
	m22 = tempLastMatrix.m22;
}

void twMatrix3x3::Identity()
{
	m00 = 1.f;
	m11 = 1.f;
	m22 = 1.f;

}

float twMatrix3x3::Determinant() const
{
	return ((m00 * ((m11 * m22) - (m12 * m21))) - 
			(m01 * ((m10 * m22) - (m12 * m20))) + 
			(m02 * ((m10 * m21) - (m11 * m20))));
}

void twMatrix3x3::Inverse()
{
	twMatrix3x3 tempMatrixOfMinors;

	tempMatrixOfMinors.m00 = (m11 * m22) - (m12 * m21);
	tempMatrixOfMinors.m01 = (m10 * m22) - (m12 * m20);
	tempMatrixOfMinors.m02 = (m10 * m21) - (m11 * m20);
	tempMatrixOfMinors.m10 = (m01 * m22) - (m02 * m21);
	tempMatrixOfMinors.m11 = (m00 * m22) - (m02 * m20);
	tempMatrixOfMinors.m12 = (m00 * m21) - (m01 * m20);
	tempMatrixOfMinors.m20 = (m01 * m12) - (m02 * m11);
	tempMatrixOfMinors.m21 = (m00 * m12) - (m02 * m10);
	tempMatrixOfMinors.m22 = (m00 * m11) - (m01 * m10);

	twMatrix3x3 tempMatrixOfCofactors;

	tempMatrixOfCofactors.m00 = tempMatrixOfMinors.m00;
	tempMatrixOfCofactors.m01 = -1 * tempMatrixOfMinors.m01;
	tempMatrixOfCofactors.m02 = tempMatrixOfMinors.m02;
	tempMatrixOfCofactors.m10 = -1 * tempMatrixOfMinors.m10;
	tempMatrixOfCofactors.m11 = tempMatrixOfMinors.m11;
	tempMatrixOfCofactors.m12 = -1 * tempMatrixOfMinors.m12;
	tempMatrixOfCofactors.m20 = tempMatrixOfMinors.m20;
	tempMatrixOfCofactors.m21 = -1 * tempMatrixOfMinors.m21;
	tempMatrixOfCofactors.m22 = tempMatrixOfMinors.m22;

	tempMatrixOfCofactors.Transpose();

	float tempDeterminant = this->Determinant();
	float tempScalar = 1 / tempDeterminant;

	m00 = tempMatrixOfCofactors.m00 * tempScalar;
	m01 = tempMatrixOfCofactors.m01 * tempScalar;
	m02 = tempMatrixOfCofactors.m02 * tempScalar;
	m10 = tempMatrixOfCofactors.m10 * tempScalar;
	m11 = tempMatrixOfCofactors.m11 * tempScalar;
	m12 = tempMatrixOfCofactors.m12 * tempScalar;
	m20 = tempMatrixOfCofactors.m20 * tempScalar;
	m21 = tempMatrixOfCofactors.m21 * tempScalar;
	m22 = tempMatrixOfCofactors.m22 * tempScalar;
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
	twMatrix3x3 tempMatrixMultiplication;

	for (tw_uint32 i = 0; i < 3; ++i)
	{
		for (tw_uint32 j = 0; j < 3; ++j)
		{
			for (tw_uint32 k = 0; k < 3; ++k)
			{
				tempMatrixMultiplication.Line[i][j] += (Line[i][k] * _matrix.Line[k][j]);
			}
		}
	}
	return tempMatrixMultiplication;
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


