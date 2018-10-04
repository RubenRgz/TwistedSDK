#include "twPoint.h"

twPoint::twPoint(const tw_int32& _x, const tw_int32& _y)
{
	x = _x;
	y = _y;
}

twPoint::twPoint(const twPoint & _point)
{
	*this = _point;
}

twPoint::~twPoint(){}

void twPoint::operator=(const twPoint & _point)
{
	this->x = _point.x;
	this->y = _point.y;
}

bool twPoint::operator==(const twPoint & _point) const
{
	if (x == _point.x && y == _point.y)
	{
		return true;
	}
	return false;
}

bool twPoint::operator!=(const twPoint & _point) const
{
	if (x != _point.x || y != _point.y)
	{
		return true;
	}
	return false;
}
