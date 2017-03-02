#include "Transform.h"
hash Transform::last_hash = 0;


Transform::Transform()
{
	Point3D p(0, 0, 0);
	setPosition(p);
	setRotation(p);
	Point3D u(1, 1, 1);
	setScale(u);
	_hash = ++last_hash;
}


Transform::~Transform()
{
}


Point3D& Transform::Position() {
	return _position;
}

Point3D& Transform::Rotation() {
	return _rotation;
}

Point3D& Transform::Scale() {
	return _scale;
}

void Transform::setPosition(Point3D position) {
	_position = position;
}

void Transform::setRotation(Point3D rotation) {
	_rotation = rotation;
}

void Transform::setScale(Point3D scale) {
	_scale = scale;
}

void Transform::rotate(Point3D rotation) {
	_rotation += rotation;
}

void Transform::rotateAround(Point3D point, Point3D rotation) {
	//Falta implementar
}

void Transform::translate(float distance, Point3D rotation) {
	_position += rotation * distance;
}

void Transform::setParent(Transform* t) {
	if (_parent != NULL)
		_parent->removeChild(this, false);
	t->addChild(this);
}

Transform* Transform::getParent() {
	return _parent;
}

void Transform::addChild(Transform* t) {
	t->_parent = this;
	for (int i = 0; i < _children.size(); i++) {
		if (_children[i] == t) {
			printf("Error! Cannot add child twice!");
			return;
		}
	}
	_children.push_back(t);
}

std::vector<Transform*> Transform::getChildren() {
	return _children;
}

Transform* Transform::getChildByHash(hash h) {
	for (int i = 0; i < _children.size(); i++) {
		if (_children[i] != NULL)
			if (_children[i]->getHash() == h)
				return _children[i];
	}
	return NULL;
}

Transform* Transform::getChildByTag(std::string tag) {
	for (int i = 0; i < _children.size(); i++) {
		if (_children[i] != NULL)
			if (_children[i]->getTag() == tag)
				return _children[i];
	}
	return NULL;
}

hash Transform::getHash() {
	return _hash;
}

std::string Transform::getTag() {
	return _tag;
}

bool Transform::removeChild(Transform* child, bool cleanUp) {
	for (int i = 0; i < _children.size(); i++) {
		if (_children[i] == child) {
			_children[i] = NULL;
			delete child;
			return true;
		}
	}
	return false;
}

bool Transform::removeChildByTag(std::string tag, bool cleanUp) {
	for (int i = 0; i < _children.size(); i++) {
		if (_children[i] != NULL) {
			if (_children[i]->getTag() == tag) {
				delete _children[i];
				_children[i] = NULL;
				return true;
			}
		}
	}
	return false;
}

bool Transform::removeChildByHash(hash h, bool cleanUp) {
	for (int i = 0; i < _children.size(); i++) {
		if (_children[i] != NULL) {
			if (_children[i]->getHash() == h) {
				delete _children[i];
				_children[i] = NULL;
				return true;
			}
		}
	}
	return false;
}