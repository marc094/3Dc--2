#pragma once
#include "Point3D.h"
#include "SDL.h"
class Line
{
private:
	Point3D *P1, *P2;

public:
	//void Render(SDL_Renderer*);
	Line(Point3D*, Point3D*);
	virtual ~Line();
};

