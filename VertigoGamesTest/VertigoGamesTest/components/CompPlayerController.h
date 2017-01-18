#ifndef __COMP_PLAYER_CONTROLLER__
#define __COMP_PLAYER_CONTROLLER__

#include "CompBase.h"

class CCompPlayerController : public CCompBase {
	float speedMovement = 5;
	float speedRotation = 100;
public:
	void render();
	void update(float elapsed);

	std::string className() { return "CCompPlayerController"; }
};

#endif