#include "stdafx.h"
#include "CompItem.h"
#include "utils\utils.h"
#include "base\GameObject.h"
#include "CompTransform.h"
#include "base\Game.h"

void CCompItem::render() {
	drawHollowCircle(0.f, 0.f, 1.f);
}

void CCompItem::receiveMessage(std::vector<std::string> msg) {

	if (msg[0] == "equipObject") {
		equiped = std::stoi(msg[1]);
	}
	if (msg[0] == "unequipObject") {
		equiped = 0;
	}
}

void CCompItem::update(float elapsed) {
	if (!equiped) {
		GameObject* o = this->owner;
		CCompTransform* o_trx = static_cast<CCompTransform*>(o->getComponent("CCompTransform"));
		Vector3 o_pos = o_trx->getPosition();

		GameObject* player = game->getPlayer();
		CCompTransform* player_trx = static_cast<CCompTransform*>(player->getComponent("CCompTransform"));
		Vector3 player_pos = player_trx->getPosition();

		float dist = o_pos.distance(player_pos);
		if (dist < 1.5) {
			player->sendMessage({ "addObjectToInventory",std::to_string(o->getID()) });
			game->quitObject(o->getID());
			o_trx->setModel(Matrix44());
		}
	}
}