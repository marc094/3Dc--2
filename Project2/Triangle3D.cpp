#include "Triangle3D.h"



Triangle3D::Triangle3D(Point3D p1, Point3D p2, Point3D p3)
{
	vertex.push_back(p1);
	vertex.push_back(p2);
	vertex.push_back(p3);
}

Triangle3D::Triangle3D(std::vector<Point3D> pV)
{
	for (int i = 0; i < 3; i++) {
		vertex.push_back(pV[i]);
	}
}


Triangle3D::~Triangle3D()
{
}

void Triangle3D::Rotate(Point3D angle) {
	/*if (pow(vector.x(), 2) + pow(vector.y(), 2) + pow(vector.z(), 2) != 1) {
		printf("Error: cant rotate around this axis");
		return;
	}
	else {*/
	/*Matrix mX(4, 4);
	mX[0][0] = 1;
	mX[0][1] = 0;
	mX[0][2] = 0;
	mX[0][3] = 0;

	mX[1][0] = 0;
	mX[1][1] = cos(angle.x());
	mX[1][2] = -sin(angle.x());
	mX[1][3] = 0;

	mX[2][0] = 0;
	mX[2][1] = sin(angle.x());
	mX[2][2] = cos(angle.x());
	mX[2][3] = 0;

	mX[3][0] = 0;
	mX[3][1] = 0;
	mX[3][2] = 0;
	mX[3][3] = 1;

	Matrix mY(4, 4);
	mY[0][0] = cos(angle.y());
	mY[0][1] = 0;
	mY[0][2] = sin(angle.y());
	mY[0][3] = 0;

	mY[1][0] = 0;
	mY[1][1] = 1;
	mY[1][2] = 0;
	mY[1][3] = 0;

	mY[2][0] = -sin(angle.y());
	mY[2][1] = 0;
	mY[2][2] = cos(angle.y());
	mY[2][3] = 0;

	mY[3][0] = 0;
	mY[3][1] = 0;
	mY[3][2] = 0;
	mY[3][3] = 1;

	Matrix mZ(4, 4);
	mZ[0][0] = cos(angle.z());
	mZ[0][1] = -sin(angle.z());
	mZ[0][2] = 0;
	mZ[0][3] = 0;

	mZ[1][0] = sin(angle.z());
	mZ[1][1] = cos(angle.z());
	mZ[1][2] = 0;
	mZ[1][3] = 0;

	mZ[2][0] = 0;
	mZ[2][1] = 0;
	mZ[2][2] = 1;
	mZ[2][3] = 0;

	mZ[3][0] = 0;
	mZ[3][1] = 0;
	mZ[3][2] = 0;
	mZ[3][3] = 1;*/
	
	Matrix mT(4, 4);
	float aux = cos(angle.y())*cos(angle.z());
	mT[0][0] = cos(angle.y())*cos(angle.z());
	mT[0][1] = cos(angle.z())*sin(angle.x())*sin(angle.y())-cos(angle.x())*sin(angle.z());
	mT[0][2] = cos(angle.x())*cos(angle.z())*sin(angle.y())+sin(angle.x())*sin(angle.z());
	mT[0][3] = 0;

	mT[1][0] = cos(angle.y())*sin(angle.z());
	mT[1][1] = cos(angle.x())*cos(angle.z())+sin(angle.x())*sin(angle.y())*sin(angle.z());
	mT[1][2] = -cos(angle.z())*sin(angle.x())+cos(angle.x())*sin(angle.y())*sin(angle.z());
	mT[1][3] = 0;

	mT[2][0] = -sin(angle.y());
	mT[2][1] = cos(angle.y())*sin(angle.x());
	mT[2][2] = cos(angle.x())*cos(angle.y());
	mT[2][3] = 0;

	mT[3][0] = 0;
	mT[3][1] = 0;
	mT[3][2] = 0;
	mT[3][3] = 1;

	for each(Point3D p in vertex) {
		Matrix m = p.getMatrix();

		m = mT * m;

		p.applyMatrix(m);
	}
	//}
}