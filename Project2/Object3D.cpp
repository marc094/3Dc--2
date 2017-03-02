#include "Object3D.h"



Object3D::Object3D()
{
	_mesh = NULL;
}


Object3D::Object3D(Mesh3D* mesh)
{
	_mesh = mesh;
}


Object3D::~Object3D()
{
}


void Object3D::Update(float dt) {

}
