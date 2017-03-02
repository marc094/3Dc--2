#pragma once
#include "Transform.h"

class Object2D
{
protected:
	Transform _transform;
	//Sprite

public:
	Object2D();
	virtual ~Object2D();
};

