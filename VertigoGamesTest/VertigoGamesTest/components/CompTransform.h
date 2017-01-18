#ifndef __COMP_TRANSFORM__
#define __COMP_TRANSFORM__

#include "CompBase.h"
#include "utils\framework.h"

class CCompTransform: public CCompBase {
	Matrix44* model;
public:
	CCompTransform();
	~CCompTransform();
	std::string className() { return "CCompTransform"; }
	void modelSet();
	Vector3 getPosition();
	Vector3 getForward();
	Vector3 getRight();
	void setPosition(Vector3 p);
	Matrix44 getModelValue();
	void setModel(Matrix44 m);
};

#endif