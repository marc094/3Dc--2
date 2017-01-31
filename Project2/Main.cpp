#include "Triangle3D.h"

void main() {

	Point3D p1(0, 0, 0);
	Point3D p2(20, 15, 43);
	Point3D p3(11, 52, 35);

	Triangle3D triangle(p1, p2, p3);
	triangle.Rotate(p3);
	getchar();

}