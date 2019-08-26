#include "twMatrix3x3.h"
#include "cmath"

namespace TwistedSDK
{
	twMatrix3x3::twMatrix3x3(
		float _m00, float _m01, float _m02,
		float _m10, float _m11, float _m12,
		float _m20, float _m21, float _m22)
	{
		this->m_matrix[0][0] = _m00;
		this->m_matrix[0][1] = _m01;
		this->m_matrix[0][2] = _m02;
		this->m_matrix[1][0] = _m10;
		this->m_matrix[1][1] = _m11;
		this->m_matrix[1][2] = _m12;
		this->m_matrix[2][0] = _m20;
		this->m_matrix[2][1] = _m21;
		this->m_matrix[2][2] = _m22;
	}

	twMatrix3x3::twMatrix3x3(float _value)
	{
		this->m_matrix[0][0] = _value;
		this->m_matrix[0][1] = _value;
		this->m_matrix[0][2] = _value;
		this->m_matrix[1][0] = _value;
		this->m_matrix[1][1] = _value;
		this->m_matrix[1][2] = _value;
		this->m_matrix[2][0] = _value;
		this->m_matrix[2][1] = _value;
		this->m_matrix[2][2] = _value;
	}

	twMatrix3x3::twMatrix3x3(const twVector3D & _vec1, const twVector3D & _vec2, const twVector3D & _vec3)
	{
		this->m_matrix[0][0] = _vec1.x;
		this->m_matrix[0][1] = _vec1.y;
		this->m_matrix[0][2] = _vec1.z;
		this->m_matrix[1][0] = _vec2.x;
		this->m_matrix[1][1] = _vec2.y;
		this->m_matrix[1][2] = _vec2.z;
		this->m_matrix[2][0] = _vec3.x;
		this->m_matrix[2][1] = _vec3.y;
		this->m_matrix[2][2] = _vec3.z;
	}

	twMatrix3x3::twMatrix3x3(const twMatrix3x3 & _matrix)
	{
		*this = _matrix;
	}

	twMatrix3x3::twMatrix3x3()
	{
		this->m_matrix[0][0] = 0.f;
		this->m_matrix[0][1] = 0.f;
		this->m_matrix[0][2] = 0.f;
		this->m_matrix[1][0] = 0.f;
		this->m_matrix[1][1] = 0.f;
		this->m_matrix[1][2] = 0.f;
		this->m_matrix[2][0] = 0.f;
		this->m_matrix[2][1] = 0.f;
		this->m_matrix[2][2] = 0.f;
	}

	twMatrix3x3::~twMatrix3x3()
	{
	}

	const twMatrix3x3 twMatrix3x3::ZERO = twMatrix3x3(0.f);
	const twMatrix3x3 twMatrix3x3::IDENTITY = twMatrix3x3(1.f, 0.f, 0.f, 
														  0.f, 1.f, 0.f, 
														  0.f, 0.f, 1.f);

	void twMatrix3x3::Zero()
	{
		this->m_matrix[0][0] = 0.f;
		this->m_matrix[0][1] = 0.f;
		this->m_matrix[0][2] = 0.f;
		this->m_matrix[1][0] = 0.f;
		this->m_matrix[1][1] = 0.f;
		this->m_matrix[1][2] = 0.f;
		this->m_matrix[2][0] = 0.f;
		this->m_matrix[2][1] = 0.f;
		this->m_matrix[2][2] = 0.f;
	}

	void twMatrix3x3::Transpose()
	{
		twMatrix3x3 tempLastMatrix = *this;

		this->m_matrix[0][0] = tempLastMatrix.m_matrix[0][0];
		this->m_matrix[0][1] = tempLastMatrix.m_matrix[1][0];
		this->m_matrix[0][2] = tempLastMatrix.m_matrix[2][0];
		this->m_matrix[1][0] = tempLastMatrix.m_matrix[0][1];
		this->m_matrix[1][1] = tempLastMatrix.m_matrix[1][1];
		this->m_matrix[1][2] = tempLastMatrix.m_matrix[2][1];
		this->m_matrix[2][0] = tempLastMatrix.m_matrix[0][2];
		this->m_matrix[2][1] = tempLastMatrix.m_matrix[1][2];
		this->m_matrix[2][2] = tempLastMatrix.m_matrix[2][2];
	}

	float twMatrix3x3::Determinant() const
	{
		return ((this->m_matrix[0][0] * ((this->m_matrix[1][1] * this->m_matrix[2][2]) - 
				(this->m_matrix[1][2] * this->m_matrix[2][1]))) -
				(this->m_matrix[0][1] * ((this->m_matrix[1][0] * this->m_matrix[2][2]) - 
				(this->m_matrix[1][2] * this->m_matrix[2][0]))) +
				(this->m_matrix[0][2] * ((this->m_matrix[1][0] * this->m_matrix[2][1]) - 
				(this->m_matrix[1][1] * this->m_matrix[2][0]))));
	}

	void twMatrix3x3::Rotate(float _angle)
	{
		// X rotation
		this->m_matrix[1][1] * std::cos(_angle);
		this->m_matrix[1][2] * std::sin(_angle);
		this->m_matrix[2][2] * -std::sin(_angle);
		this->m_matrix[2][2] * std::cos(_angle);

		// Y rotation
		this->m_matrix[0][0] * std::cos(_angle);
		this->m_matrix[0][2] * -std::sin(_angle);
		this->m_matrix[2][0] * std::sin(_angle);
		this->m_matrix[2][2] * std::cos(_angle);

		// Z rotation
		this->m_matrix[0][0] * std::cos(_angle);
		this->m_matrix[0][1] * std::sin(_angle);
		this->m_matrix[1][0] * -std::sin(_angle);
		this->m_matrix[1][1] * std::cos(_angle);
	}

	void twMatrix3x3::Rotate(float _angleX, float _angleY, float _angleZ)
	{
		// X rotation
		this->m_matrix[1][1] * std::cos(_angleX);
		this->m_matrix[1][2] * std::sin(_angleX);
		this->m_matrix[2][2] * -std::sin(_angleX);
		this->m_matrix[2][2] * std::cos(_angleX);

		// Y rotation
		this->m_matrix[0][0] * std::cos(_angleY);
		this->m_matrix[0][2] * -std::sin(_angleY);
		this->m_matrix[2][0] * std::sin(_angleY);
		this->m_matrix[2][2] * std::cos(_angleY);

		// Z rotation
		this->m_matrix[0][0] * std::cos(_angleZ);
		this->m_matrix[0][1] * std::sin(_angleZ);
		this->m_matrix[1][0] * -std::sin(_angleZ);
		this->m_matrix[1][1] * std::cos(_angleZ);
	}

	void twMatrix3x3::Scale(float _scale)
	{
		this->m_matrix[0][0] * _scale;
		this->m_matrix[1][1] * _scale;
		this->m_matrix[2][2] * _scale;
	}

	void twMatrix3x3::Scale(float _scaleX, float _scaleY, float _scaleZ)
	{
		this->m_matrix[0][0] * _scaleX;
		this->m_matrix[1][1] * _scaleY;
		this->m_matrix[2][2] * _scaleZ;
	}

	void twMatrix3x3::Inverse()
	{
		twMatrix3x3 tempMatrixOfMinors;

		tempMatrixOfMinors.m_matrix[0][0] = (this->m_matrix[1][1] * this->m_matrix[2][2]) - 
											(this->m_matrix[1][2] * this->m_matrix[2][1]);
		tempMatrixOfMinors.m_matrix[0][1] = (this->m_matrix[1][0] * this->m_matrix[2][2]) - 
											(this->m_matrix[1][2] * this->m_matrix[2][0]);
		tempMatrixOfMinors.m_matrix[0][2] = (this->m_matrix[1][0] * this->m_matrix[2][1]) - 
											(this->m_matrix[1][1] * this->m_matrix[2][0]);
		tempMatrixOfMinors.m_matrix[1][0] = (this->m_matrix[0][1] * this->m_matrix[2][2]) - 
											(this->m_matrix[0][2] * this->m_matrix[2][1]);
		tempMatrixOfMinors.m_matrix[1][1] = (this->m_matrix[0][0] * this->m_matrix[2][2]) - 
											(this->m_matrix[0][2] * this->m_matrix[2][0]);
		tempMatrixOfMinors.m_matrix[1][2] = (this->m_matrix[0][0] * this->m_matrix[2][1]) - 
											(this->m_matrix[0][1] * this->m_matrix[2][0]);
		tempMatrixOfMinors.m_matrix[2][0] = (this->m_matrix[0][1] * this->m_matrix[1][2]) - 
											(this->m_matrix[0][2] * this->m_matrix[1][1]);
		tempMatrixOfMinors.m_matrix[2][1] = (this->m_matrix[0][0] * this->m_matrix[1][2]) - 
											(this->m_matrix[0][2] * this->m_matrix[1][0]);
		tempMatrixOfMinors.m_matrix[2][2] = (this->m_matrix[0][0] * this->m_matrix[1][1]) - 
											(this->m_matrix[0][1] * this->m_matrix[1][0]);

		twMatrix3x3 tempMatrixOfCofactors;

		tempMatrixOfCofactors.m_matrix[0][0] = tempMatrixOfMinors.m_matrix[0][0];
		tempMatrixOfCofactors.m_matrix[0][1] = -1 * tempMatrixOfMinors.m_matrix[0][1];
		tempMatrixOfCofactors.m_matrix[0][2] = tempMatrixOfMinors.m_matrix[0][2];
		tempMatrixOfCofactors.m_matrix[1][0] = -1 * tempMatrixOfMinors.m_matrix[1][0];
		tempMatrixOfCofactors.m_matrix[1][1] = tempMatrixOfMinors.m_matrix[1][1];
		tempMatrixOfCofactors.m_matrix[1][2] = -1 * tempMatrixOfMinors.m_matrix[1][2];
		tempMatrixOfCofactors.m_matrix[2][0] = tempMatrixOfMinors.m_matrix[2][0];
		tempMatrixOfCofactors.m_matrix[2][1] = -1 * tempMatrixOfMinors.m_matrix[2][1];
		tempMatrixOfCofactors.m_matrix[2][2] = tempMatrixOfMinors.m_matrix[2][2];

		tempMatrixOfCofactors.Transpose();

		float tempDeterminant = this->Determinant();
		float tempScalar = 1 / tempDeterminant;

		this->m_matrix[0][0] = tempMatrixOfCofactors.m_matrix[0][0] * tempScalar;
		this->m_matrix[0][1] = tempMatrixOfCofactors.m_matrix[0][1] * tempScalar;
		this->m_matrix[0][2] = tempMatrixOfCofactors.m_matrix[0][2] * tempScalar;
		this->m_matrix[1][0] = tempMatrixOfCofactors.m_matrix[1][0] * tempScalar;
		this->m_matrix[1][1] = tempMatrixOfCofactors.m_matrix[1][1] * tempScalar;
		this->m_matrix[1][2] = tempMatrixOfCofactors.m_matrix[1][2] * tempScalar;
		this->m_matrix[2][0] = tempMatrixOfCofactors.m_matrix[2][0] * tempScalar;
		this->m_matrix[2][1] = tempMatrixOfCofactors.m_matrix[2][1] * tempScalar;
		this->m_matrix[2][2] = tempMatrixOfCofactors.m_matrix[2][2] * tempScalar;
	}

	void twMatrix3x3::operator=(const twMatrix3x3 & _matrix)
	{
		this->m_matrix[0][0] = _matrix.m_matrix[0][0];
		this->m_matrix[0][1] = _matrix.m_matrix[1][0];
		this->m_matrix[0][2] = _matrix.m_matrix[2][0];
		this->m_matrix[1][0] = _matrix.m_matrix[0][1];
		this->m_matrix[1][1] = _matrix.m_matrix[1][1];
		this->m_matrix[1][2] = _matrix.m_matrix[2][1];
		this->m_matrix[2][0] = _matrix.m_matrix[0][2];
		this->m_matrix[2][1] = _matrix.m_matrix[1][2];
		this->m_matrix[2][2] = _matrix.m_matrix[2][2];
	}

	bool twMatrix3x3::operator==(const twMatrix3x3 & _matrix)
	{
		return (this->m_matrix[0][0] == _matrix.m_matrix[0][0] &&
				this->m_matrix[0][1] == _matrix.m_matrix[1][0] &&
				this->m_matrix[0][2] == _matrix.m_matrix[2][0] &&
				this->m_matrix[1][0] == _matrix.m_matrix[0][1] &&
				this->m_matrix[1][1] == _matrix.m_matrix[1][1] &&
				this->m_matrix[1][2] == _matrix.m_matrix[2][1] &&
				this->m_matrix[2][0] == _matrix.m_matrix[0][2] &&
				this->m_matrix[2][1] == _matrix.m_matrix[1][2] &&
				this->m_matrix[2][2] == _matrix.m_matrix[2][2] ? true : false);
	}

	bool twMatrix3x3::operator!=(const twMatrix3x3 & _matrix)
	{
		return (this->m_matrix[0][0] != _matrix.m_matrix[0][0] ||
				this->m_matrix[0][1] != _matrix.m_matrix[1][0] ||
				this->m_matrix[0][2] != _matrix.m_matrix[2][0] ||
				this->m_matrix[1][0] != _matrix.m_matrix[0][1] ||
				this->m_matrix[1][1] != _matrix.m_matrix[1][1] ||
				this->m_matrix[1][2] != _matrix.m_matrix[2][1] ||
				this->m_matrix[2][0] != _matrix.m_matrix[0][2] ||
				this->m_matrix[2][1] != _matrix.m_matrix[1][2] ||
				this->m_matrix[2][2] != _matrix.m_matrix[2][2] ? true : false);
	}

	twMatrix3x3 twMatrix3x3::operator+(const twMatrix3x3 & _matrix)
	{
		return twMatrix3x3(this->m_matrix[0][0] + _matrix.m_matrix[0][0],
						   this->m_matrix[0][1] + _matrix.m_matrix[0][1],
						   this->m_matrix[0][2] + _matrix.m_matrix[0][2],
						   this->m_matrix[1][0] + _matrix.m_matrix[1][0],
						   this->m_matrix[1][1] + _matrix.m_matrix[1][1],
						   this->m_matrix[1][2] + _matrix.m_matrix[1][2],
						   this->m_matrix[2][0] + _matrix.m_matrix[2][0],
						   this->m_matrix[2][1] + _matrix.m_matrix[2][1],
						   this->m_matrix[2][2] + _matrix.m_matrix[2][2]);
	}

	twMatrix3x3 twMatrix3x3::operator-(const twMatrix3x3 & _matrix)
	{
		return twMatrix3x3(this->m_matrix[0][0] - _matrix.m_matrix[0][0],
						   this->m_matrix[0][1] - _matrix.m_matrix[0][1],
						   this->m_matrix[0][2] - _matrix.m_matrix[0][2],
						   this->m_matrix[1][0] - _matrix.m_matrix[1][0],
						   this->m_matrix[1][1] - _matrix.m_matrix[1][1],
						   this->m_matrix[1][2] - _matrix.m_matrix[1][2],
						   this->m_matrix[2][0] - _matrix.m_matrix[2][0],
						   this->m_matrix[2][1] - _matrix.m_matrix[2][1],
						   this->m_matrix[2][2] - _matrix.m_matrix[2][2]);
	}

	twMatrix3x3 twMatrix3x3::operator*(const twMatrix3x3 & _matrix)
	{
		twVector3D tempVec1(this->m_matrix[0][0], this->m_matrix[0][1], this->m_matrix[0][2]);
		twVector3D tempVec2(this->m_matrix[1][0], this->m_matrix[1][1], this->m_matrix[1][2]);
		twVector3D tempVec3(this->m_matrix[2][0], this->m_matrix[2][1], this->m_matrix[2][2]);

		twVector3D newVec1(_matrix.m_matrix[0][0], _matrix.m_matrix[1][0], _matrix.m_matrix[2][0]);
		twVector3D newVec2(_matrix.m_matrix[0][1], _matrix.m_matrix[1][1], _matrix.m_matrix[2][1]);
		twVector3D newVec3(_matrix.m_matrix[0][2], _matrix.m_matrix[1][2], _matrix.m_matrix[2][2]);

		return twMatrix3x3(tempVec1.DotProduct(newVec1),
						   tempVec1.DotProduct(newVec2),
						   tempVec1.DotProduct(newVec3),
						   tempVec2.DotProduct(newVec1),
						   tempVec2.DotProduct(newVec2),
						   tempVec2.DotProduct(newVec3),
						   tempVec3.DotProduct(newVec1),
						   tempVec3.DotProduct(newVec2),
						   tempVec3.DotProduct(newVec3));
	}

	twVector3D twMatrix3x3::operator*(const twVector3D & _vector)
	{
		twVector3D tempVec1(this->m_matrix[0][0], this->m_matrix[1][0], this->m_matrix[2][0]);
		twVector3D tempVec2(this->m_matrix[0][1], this->m_matrix[1][1], this->m_matrix[2][1]);
		twVector3D tempVec3(this->m_matrix[0][2], this->m_matrix[1][2], this->m_matrix[2][2]);

		return twVector3D(_vector.DotProduct(tempVec1),
						  _vector.DotProduct(tempVec2),
						  _vector.DotProduct(tempVec3));
	}

	twMatrix3x3 twMatrix3x3::operator*(float _scalar)
	{
		return twMatrix3x3(this->m_matrix[0][0] * _scalar,
						   this->m_matrix[0][1] * _scalar,
						   this->m_matrix[0][2] * _scalar,
						   this->m_matrix[1][0] * _scalar,
						   this->m_matrix[1][1] * _scalar,
						   this->m_matrix[1][2] * _scalar,
						   this->m_matrix[2][0] * _scalar,
						   this->m_matrix[2][1] * _scalar,
						   this->m_matrix[2][2] * _scalar);
	}
}
