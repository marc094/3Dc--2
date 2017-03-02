#include "Point2D.h"

Point2D::Point2D(float x, float y)
{
	_matrix = Matrix(1, 3);
	this->x(x);
	this->y(y);
	updateMatrix();
}


Point2D::Point2D()
{
}



Point2D::~Point2D()
{
}

//Accessors
float Point2D::x() {
	return _x;
}
float Point2D::y() {
	return _y;
}
void Point2D::x(float x) {
	_x = x;
	updateMatrix();
}
void Point2D::y(float y) {
	_y = y;
	updateMatrix();
}

Matrix Point2D::getMatrix() {
	return _matrix;
}

void Point2D::updateMatrix() {
	_matrix[0][0] = _x;
	_matrix[0][1] = _y;
}

void Point2D::applyMatrix(Matrix m) {
	_matrix = m;
	updatePoint();
}

void Point2D::updatePoint() {
	_x = _matrix[0][0];
	_y = _matrix[0][1];
}

Point2D Point2D::operator +(Point2D p) {
	Point2D res(x() + p.x(), y() + p.y());
	return res;
}

Point2D Point2D::operator -(Point2D p) {
	Point2D res(x() - p.x(), y() - p.y());
	return res;
}

void Point2D::operator +=(Point2D p) {
	x(x() + p.x());
	y(y() + p.y());
}

void Point2D::operator -=(Point2D p) {
	x(x() - p.x());
	y(y() - p.y());
}

Point2D Point2D::operator *(float f) {
	x(f*x());
	y(f*y());
	return *this;
}