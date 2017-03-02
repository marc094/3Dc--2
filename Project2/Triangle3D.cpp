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

void Triangle3D::rotate(Point3D angle) {
	/*if (pow(vector.x(), 2) + pow(vector.y(), 2) + pow(vector.z(), 2) != 1) {
		printf("Error: cant rotate around this axis");
		return;
	}
	else {*/	
	Matrix mT(4, 4);
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

	for (int i = 0; i < vertex.size(); i++) {
		Matrix m = vertex[i].getMatrix();

		m = mT * m;

		vertex[i].applyMatrix(m);
	}
	//}
}

void Triangle3D::translate(Point3D dist) {
	for (int i = 0; i < vertex.size(); i++) {
		vertex[i].setRelativePosition(vertex[i].getRelativePosition() + dist);
	}
}


void Triangle3D::renderLines(SDL_Renderer* renderer) {
	int size = vertex.size();
	SDL_Point* points = (SDL_Point*)malloc((size + 1) * sizeof(SDL_Point));
	
	for (int i = 0; i < size; i++) {
		points[i].x = vertex[i].getAbsolutePosition().x();
		points[i].y = vertex[i].getAbsolutePosition().y();
	}
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderDrawLines(renderer, points, size);
	SDL_RenderDrawLine(renderer, points[size-1].x, points[size-1].y, points[0].x, points[0].y);
	//SDL_RenderDrawPoint(renderer, points[0]->x, points[0]->y);
	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
}

void Triangle3D::centerAround(Transform* mesh) {
	for (int i = 0; i < vertex.size(); i++) {
		vertex[i].bind(mesh);
	}
}
