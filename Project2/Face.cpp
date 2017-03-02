#include "Face.h"



Face::Face(Point3D* p1, Point3D* p2, Point3D* p3)
{
	P1 = p1;
	P2 = p2;
	P3 = p3;
	P4 = NULL;
}


Face::Face(Point3D* p1, Point3D* p2, Point3D* p3, Point3D* p4) 
{
	P1 = p1;
	P2 = p2;
	P3 = p3;
	P4 = p4;
}

Face::~Face()
{
}
