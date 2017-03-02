#pragma once
#include "Mesh3D.h"
#include "Transform.h"
class Object3D
{
protected:
	Transform _transform;
	Mesh3D* _mesh;

public:
	virtual void Update(float dt);

	Object3D();
	Object3D(Mesh3D*);
	virtual ~Object3D();
};

