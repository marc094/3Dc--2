#include "Point3D.h"

Point3D::Point3D(float x, float y, float z)
{
	_matrix = Matrix(1, 4);
	this->x(x);
	this->y(y);
	this->z(z);
	updateMatrix();
}


Point3D::Point3D()
{
}


Point3D::~Point3D()
{
}

//Accessors
float Point3D::z() {
	return _z;
}
void Point3D::z(float z) {
	_z = z;
}

void Point3D::updateMatrix() {
	Point2D::updateMatrix();
	_matrix[0][2] = _z;
}

void Point3D::updatePoint() {
	Point2D::updatePoint();
	_z = _matrix[0][2];
}