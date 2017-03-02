#pragma once
#include "Triangle3D.h"
#include "Transform.h"
#include "Line.h"
#include "Face.h"

class Mesh3D
{
private:
	std::vector<Triangle3D> polygons;
	std::vector<Point3D> _vertexes;
	std::vector<Line> _edges;
	//std::vector<Face> _faces;
	Transform _transform;
public:
	void rotate(Point3D);
	void renderLines(SDL_Renderer*);

	Mesh3D(Point3D, std::vector<Triangle3D>);
	virtual ~Mesh3D();
};

