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
	_matrix = Matrix(1, 4);
	x(0);
	y(0);
	z(0);
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
	updateMatrix();
}

void Point3D::updateMatrix() {
	Point2D::updateMatrix();
	_matrix[0][2] = _z;
}

void Point3D::updatePoint() {
	Point2D::updatePoint();
	_z = _matrix[0][2];
}

Point3D Point3D::operator +(Point3D p) {
	Point3D res(x() + p.x(), y() + p.y(), z() + p.z());
	return res;
}

Point3D Point3D::operator -(Point3D p) {
	Point3D res(x() - p.x(), y() - p.y(), z() - p.z());
	return res;
}

void Point3D::operator +=(Point3D p) {
	x(x() + p.x());
	y(y() + p.y());
	z(z() + p.z());
}

void Point3D::operator -=(Point3D p) {
	x(x() - p.x());
	y(y() - p.y());
	z(z() - p.z());
}

Point3D Point3D::operator *(float f) {
	Point2D::operator*(f);
	z(f*z());
	return *this;
}