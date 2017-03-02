#pragma once
#ifndef _P2D_
#define _P2D_
#include "Matrix.h"

class Point2D
{
protected:

	float _x, _y;
	Matrix _matrix;
	virtual void updateMatrix();
	virtual void updatePoint();
public:
	float x();
	float y();
	void x(float x);
	void y(float y);

	Matrix getMatrix();
	void applyMatrix(Matrix);

	Point2D operator +(Point2D);
	Point2D operator -(Point2D);
	void operator +=(Point2D);
	void operator -=(Point2D);
	Point2D operator *(float);

	Point2D(float, float);
	Point2D();
	virtual ~Point2D();
};

#endif // !_P2D_