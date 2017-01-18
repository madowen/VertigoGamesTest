#ifndef __COMP_STONE__
#define __COMP_STONE__

#include "CompItemHand.h"
class Vector3;
class CCompStone : public CCompItemHand {
public:
	void render();
	void action(std::vector<std::string>msg);
	void receiveMessage(std::vector<std::string> msg);
	void renderSymbol(Vector3 offset);
	std::string className() { return "CCompStone"; }
};

#endif