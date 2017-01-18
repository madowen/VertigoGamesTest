#ifndef __COMP_GUN__
#define __COMP_GUN__

#include "CompItemHand.h"

class Vector3;
class CCompGun : public CCompItemHand {
	int ammo;
	bool automatic;
	float shoot_rate;
	float shoot_time;
public:
	CCompGun():ammo(0), shoot_rate(.5f), shoot_time(0.f),automatic(true){}
	void render();
	void renderHUD(Vector3 offset);
	void action(std::vector<std::string>msg);
	void receiveMessage(std::vector<std::string> msg);
	void renderSymbol(Vector3 offset);
	std::string className() { return "CCompGun"; }
};
#endif