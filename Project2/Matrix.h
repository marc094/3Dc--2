#pragma once
#ifndef _MATRIX_
#define _MATRIX_

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <math.h>

class Matrix
{
protected:
	std::vector<std::vector<float>> _values;
	std::vector<float>& at(int);
	int dimX, dimY;
public:
	Matrix(int, int);
	Matrix();
	virtual Matrix operator *(Matrix);
	virtual Matrix operator +(Matrix);
	virtual Matrix operator -(Matrix);
	std::vector<float>& operator[](int);
	virtual ~Matrix();

	int getDimensionX();
	int getDimensionY();

	void print();
};

#endif // !_MATRIX_