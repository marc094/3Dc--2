#pragma once
#include <vector>
#include "Point3D.h"
#include <math.h>
class Triangle3D
{
protected:
	std::vector<Point3D> vertex;
public:
	Triangle3D(Point3D, Point3D, Point3D);
	Triangle3D(std::vector<Point3D>);
	virtual ~Triangle3D();

	void Rotate(Point3D angle);
};

