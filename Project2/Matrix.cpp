#include "Matrix.h"

Matrix::Matrix(int x, int y)
{
	dimX = x;
	dimY = y;

	for (int i = 0; i < dimX; i++) {
		std::vector<float> v;
		_values.push_back(v);
		_values[i].resize(y);
	}
}

Matrix::Matrix()
{
	dimX = 0;
	dimY = 0;
}

Matrix::~Matrix()
{
}

std::vector<float>& Matrix::at(int i) {
	return _values[i];
}

std::vector<float>& Matrix::operator[](int i) {
	return _values[i];
}

int Matrix::getDimensionX() {
	return dimX;
}
int Matrix::getDimensionY() {
	return dimY;
}

Matrix Matrix::operator *(Matrix a) {
	int x = a.dimX;
	int y = dimY;
	int m = a.dimY;
	Matrix result(x, y);

	if (dimX != a.dimY)
	{
		printf("Can't multiply two matrices of different Y and X dimension\n");
		return a;
	}

	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			for (int k = 0; k < m; k++) {
				float aa, b, c;
				aa = result[i][j];
				b = _values[k][j];
				c = a[i][k];
				result[i][j] += _values[k][j] * a[i][k];
			}
		}
	}

	/*printf("Success multiplying!\n");
	result.print();*/
	return result;
}

Matrix Matrix::operator +(Matrix a) {
	int x = dimX;
	int y = dimY;

	if (x != a.dimX)
	{
		printf("Can't add two matrices of different dimension\n");
		return *this;
	}

	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			_values[i][j] += a[i][j];
		}
	}

	return *this;
}

Matrix Matrix::operator -(Matrix a) {
	int x = dimX;
	int y = dimY;

	if (x != a.dimX)
	{
		printf("Can't subtract two matrices of different dimension\n");
		return *this;
	}

	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			_values[i][j] -= a[i][j];
		}
	}

	return *this;
}

void Matrix::print() {
	for (int i = 0; i < dimX; i++) {
		for (int j = 0; j < dimY; j++) {
			printf("%f ", _values[i][j]);
		}
		printf("\n");
	}
}
