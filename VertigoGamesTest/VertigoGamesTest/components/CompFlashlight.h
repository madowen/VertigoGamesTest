#ifndef __COMP_FLASHLIGHT__
#define __COMP_FLASHLIGHT__

#include "CompItemHand.h"
class Vector3;
class CCompFlashlight : public CCompItemHand {
	bool light;
public:
	CCompFlashlight() :light(false) {}
	void render();
	void action(std::vector<std::string>msg);
	void receiveMessage(std::vector<std::string> msg);
	void renderSymbol(Vector3 offset);
	std::string className() { return "CCompFlashlight"; }
};

#endif