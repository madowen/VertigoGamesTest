#include "stdafx.h"
#include "CompTransform.h"

CCompTransform::CCompTransform() {
	model = new Matrix44;
}

CCompTransform::~CCompTransform() {
	delete model;
}

void CCompTransform::modelSet() {
	model->set();
}

Vector3 CCompTransform::getPosition() {
	return Vector3(
		this->model->m[12],
		this->model->m[13],
		this->model->m[14]
	);
}

Vector3 CCompTransform::getForward() {
	return model->topVector();
}

Vector3 CCompTransform::getRight() {
	return model->rightVector();
}

void CCompTransform::setPosition(Vector3 p) {
	this->model->m[12] = p.x;
	this->model->m[13] = p.y;
	this->model->m[14] = p.z;

}

Matrix44 CCompTransform::getModelValue() {
	return *model;
}

void CCompTransform::setModel(Matrix44 m) {
	*model = m;
}