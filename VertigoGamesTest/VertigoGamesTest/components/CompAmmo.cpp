#include "stdafx.h"
#include "CompAmmo.h"
#include "utils\utils.h"
#include "utils\framework.h"
#include "base\Game.h"
#include "base\GameObject.h"

void CCompAmmo::render() {
	if (equiped) {
	} else {
		CCompItem::render();
		renderSymbol(Vector3(0, 0, 0));

	}
}

void CCompAmmo::action(std::vector<std::string>msg) {
	// Recharge gun //
	game->getPlayer()->sendMessage({ "rechargeGun",msg[1] });
}

void CCompAmmo::receiveMessage(std::vector<std::string>msg) {
	CCompItem::receiveMessage(msg);
	if (msg[0] == "action")
		action(msg);
	else if (msg[0] == "renderSymbol")
		renderSymbol(Vector3(stof(msg[1]), stof(msg[2]), stof(msg[3])));	
}

void CCompAmmo::renderSymbol(Vector3 offset) {
	// draw A //
	glBegin(GL_LINES);
	glVertex3f(offset.x + -0.4f, offset.y + -0.7f, offset.z + 0.0f);
	glVertex3f(offset.x + 0.0f, offset.y + 0.7f, offset.z + 0.0f);
	glVertex3f(offset.x + 0.4f, offset.y + -0.7f, offset.z + 0.0f);
	glVertex3f(offset.x + 0.0f, offset.y + 0.7f, offset.z + 0.0f);
	glVertex3f(offset.x + -0.2f, offset.y + 0.0f, offset.z + 0.0f);
	glVertex3f(offset.x + 0.2f, offset.y + 0.0f, offset.z + 0.0f);
	glEnd();


}
