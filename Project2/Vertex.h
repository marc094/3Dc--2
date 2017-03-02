#pragma once
#include "Transform.h"
class Vertex
{
private:
	Transform _transform;

public:
	Point3D getRelativePosition();
	Point3D getAbsolutePosition();
	void setRelativePosition(Point3D);
	void setAbsolutePosition(Point3D);
	/*float x();
	void x(float);
	float y();
	void y(float);
	float z();
	void z(float);*/

	Matrix getMatrix();
	void applyMatrix(Matrix);

	void bind(Transform*);

	Vertex(Point3D);
	virtual ~Vertex();
};

