#include "stdafx.h"
#include "CompStone.h"
#include "utils\utils.h"
#include "utils\framework.h"
#include "base\Game.h"
#include "base\GameObject.h"
#include "CompTransform.h"

void CCompStone::render() {
	if (equiped) {
		if (equiped == RIGHTHAND)
			drawFilledCircle(0.5f, 0.5f, 0.2f);
		if (equiped == LEFTHAND)
			drawFilledCircle(-0.5f, 0.5f, 0.2f);
	} else {
		CCompItem::render();
		renderSymbol(Vector3(0, 0, 0));
	}
}

void CCompStone::action(std::vector<std::string>msg) {
	// Trhow Stone //
	GameObject* p = game->getPlayer();
	CCompTransform* p_trx = static_cast<CCompTransform*>(p->getComponent("CCompTransform"));
	CCompTransform* o_trx = static_cast<CCompTransform*>(owner->getComponent("CCompTransform"));
	Vector3 p_front = p_trx->getForward();
	Vector3 p_pos = p_trx->getPosition();
	Vector3 new_o_pos = p_pos + p_front * 5;
	o_trx->setPosition(new_o_pos);
	equiped = false;
	game->addObject(owner);
	game->getPlayer()->sendMessage({ "dropStone",msg[1] });
}

void CCompStone::receiveMessage(std::vector<std::string>msg) {
	CCompItem::receiveMessage(msg);
	if (msg[0] == "action")
		action(msg);
	else if (msg[0] == "renderSymbol")
		renderSymbol(Vector3(stof(msg[1]), stof(msg[2]), stof(msg[3])));
}

void CCompStone::renderSymbol(Vector3 offset) {
	// draw H //
	glBegin(GL_LINE_STRIP);
	glVertex3f(offset.x + 0.4f, offset.y + 0.7f, offset.z + 0.0f);
	glVertex3f(offset.x + -0.4f, offset.y + 0.7f, offset.z + 0.0f);
	glVertex3f(offset.x + -0.4f, offset.y + 0.0f, offset.z + 0.0f);
	glVertex3f(offset.x + 0.4f, offset.y + 0.0f, offset.z + 0.0f);
	glVertex3f(offset.x + 0.4f, offset.y + -0.7f, offset.z + 0.0f);
	glVertex3f(offset.x + -0.4f, offset.y + -0.7f, offset.z + 0.0f);
	glEnd();

}
