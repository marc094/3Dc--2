#pragma once
#include "Point2D.h"

class Point3D : public Point2D
{
protected:

	float _z;
	void updateMatrix();
	void updatePoint();
public:
	float z();
	void z(float z );

	Point3D operator +(Point3D);
	Point3D operator -(Point3D);
	void operator +=(Point3D);
	void operator -=(Point3D);
	Point3D operator *(float);

	Point3D(float, float, float);
	Point3D();
	virtual ~Point3D();
};