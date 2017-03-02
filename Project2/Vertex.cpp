#include "Vertex.h"



Vertex::Vertex(Point3D p)
{
	_transform.setPosition(p);
}


Vertex::~Vertex()
{
}


Point3D Vertex::getRelativePosition() {
	return _transform.Position();
}

Point3D Vertex::getAbsolutePosition() {
	Point3D abs_pos = _transform.Position();
	for (Transform* p = _transform.getParent(); p != NULL; p = p->getParent()) {
		abs_pos += p->Position();
	}
	return abs_pos;
}

void Vertex::setRelativePosition(Point3D p) {
	_transform.setPosition(p);
}

void Vertex::setAbsolutePosition(Point3D p) {
	for (Transform* parent = _transform.getParent(); parent != NULL; parent = parent->getParent()) {
		p -= parent->Position();
	}
	_transform.setPosition(p);
}


/*float Vertex::x() {
	return _relPosition.x();
}

void Vertex::x(float f) {
	_relPosition.x(f);
}

float Vertex::y() {
	return _relPosition.y();
}

void Vertex::y(float f) {
	_relPosition.y(f);
}

float Vertex::z() {
	return _relPosition.z();
}

void Vertex::z(float f) {
	_relPosition.z(f);
}*/

void Vertex::bind(Transform* mesh) {
	_transform.setParent(mesh);
}

Matrix Vertex::getMatrix() {
	return _transform.Position().getMatrix();
}

void Vertex::applyMatrix(Matrix m) {
	_transform.Position().applyMatrix(m);
}