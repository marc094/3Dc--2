#include "Mesh3D.h"



Mesh3D::Mesh3D(Point3D p, std::vector<Triangle3D> edges)
{
	_transform.setPosition(p);
	polygons = edges;
	//_edges = edges;
	for (int i = 0; i < polygons.size(); i++) {

		polygons[i].centerAround(&_transform);
	}
}


Mesh3D::~Mesh3D()
{
}

void Mesh3D::rotate(Point3D p) {
	_transform.rotate(p);
	for (int i = 0; i < polygons.size(); i++) {
		polygons[i].rotate(p);
	}
}

void Mesh3D::renderLines(SDL_Renderer* renderer) {
	for (int i = 0; i < polygons.size(); i++) {
		polygons[i].renderLines(renderer);
	}
}

