#pragma once
#include "Point3D.h";
typedef unsigned int hash;

class Transform
{
private:
	Point3D _position;
	Point3D _rotation;
	Point3D _scale;
	Transform* _parent = NULL;
	std::vector<Transform*> _children;
	hash _hash;
	static hash last_hash;
	std::string _tag;
public:

	Point3D& Position();
	Point3D& Rotation();
	Point3D& Scale();
	void setPosition(Point3D position);
	void setRotation(Point3D rotation);
	void setScale(Point3D scale);

	void rotate(Point3D rotation);
	void rotateAround(Point3D point, Point3D rotation);	//Falta implementar
	void translate(float distance, Point3D rotation);

	void setParent(Transform* parent);
	Transform* getParent();

	void addChild(Transform* child);
	bool removeChild(Transform* child, bool cleanUp);
	bool removeChildByTag(std::string tag, bool cleanUp);
	bool removeChildByHash(hash h, bool cleanUp);
	std::vector<Transform*> getChildren();
	Transform* getChildByHash(hash h);
	Transform* getChildByTag(std::string tag);

	hash getHash();
	std::string getTag();


	Transform();
	virtual ~Transform();
};

