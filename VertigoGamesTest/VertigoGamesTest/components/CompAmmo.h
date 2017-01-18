#ifndef __COMP_AMMO__
#define __COMP_AMMO__

#include "CompItemHand.h"

class Vector3;
class CCompAmmo : public CCompItemHand {
public:
	void render();
	void action(std::vector<std::string>msg);
	void receiveMessage(std::vector<std::string> msg);
	void renderSymbol(Vector3 offset);
	std::string className() { return "CCompAmmo"; }
};
#endif