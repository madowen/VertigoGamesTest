#ifndef __COMP_LEVER__
#define __COMP_LEVER__

#include "CompBase.h"

class CCompLever : public CCompBase {
	bool open;
public:
	CCompLever():open(false){}
	void render();
	void activate();
	void update(float elapsed);
	std::string className() { return "CCompLever"; }
};

#endif