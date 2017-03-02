#pragma once
#include <vector>
#include "Vertex.h"
#include <math.h>
#include "SDL.h"
class Triangle3D
{
protected:
	std::vector<Vertex> vertex;
	Transform* mesh;
public:
	Triangle3D(Point3D, Point3D, Point3D);
	Triangle3D(std::vector<Point3D>);
	virtual ~Triangle3D();

	void rotate(Point3D angle);
	void translate(Point3D dist);
	void renderLines(SDL_Renderer*);
	void centerAround(Transform*);
};

