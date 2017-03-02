#include "Line.h"



Line::Line(Point3D* p1, Point3D* p2)
{
	P1 = p1;
	P2 = p2;
}


Line::~Line()
{
}


/*void Line::Render(SDL_Renderer* renderer) {
	SDL_RenderDrawLine()
}*/