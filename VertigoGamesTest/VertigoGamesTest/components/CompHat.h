#ifndef __COMP_HAT__
#define __COMP_HAT__

#include "CompItemHead.h"

class Vector3;
class CCompHat : public CCompItemHead {
public:
	void render();
	void renderSymbol(Vector3 offset);
	void receiveMessage(std::vector<std::string> msg);
	std::string className() { return "CCompHat"; }
};
#endif