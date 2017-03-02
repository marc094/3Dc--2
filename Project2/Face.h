#pragma once
#include "Point3D.h"
#include <vector>

class Face
{
private:
	Point3D *P1, *P2, *P3, *P4;
public:
	Face(Point3D*, Point3D*, Point3D*);
	Face(Point3D*, Point3D*, Point3D*, Point3D*);
	virtual ~Face();
};

