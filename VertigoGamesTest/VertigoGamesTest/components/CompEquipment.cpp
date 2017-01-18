#include "stdafx.h"
#include "CompEquipment.h"
#include "io\io.h"
#include "utils\utils.h"
#include "utils\framework.h"
#include "base\GameObject.h"
#include "base\Game.h"

CCompEquipment::CCompEquipment() {
	indexHead = -1;
	indexLeftHand = -1;
	indexRightHand = -1;
}

CCompEquipment::~CCompEquipment() {
	headInventory.clear();
	handInventory.clear();
}

void CCompEquipment::render() {
	if (indexHead > -1) headInventory[indexHead]->render();
	if (indexLeftHand > -1) handInventory[indexLeftHand]->render();
	if (indexRightHand > -1) handInventory[indexRightHand]->render();
}

void CCompEquipment::renderHUD() {
	int y = 0;
	{
		// head //
		print_bitmap_string(GLUT_BITMAP_HELVETICA_18, "HEAD:", -(UNIT_SIZE - 1), -(UNIT_SIZE - 1) + y * 2);
		int x = 0;
		Vector3 pos_selection = Vector3(-(UNIT_SIZE - 6) + x, -(UNIT_SIZE - 1.5) + y * 2, 0);
		if (indexHead == -1) {
			glColor3f(50.f / 255.f, 205.f / 255.f, 50.f / 255.f);
			renderSelection(pos_selection);
			glColor3f(1, 1, 1);
		}
		for (int i = 0; i < headInventory.size(); i++) {
			GameObject* obj = headInventory[i];
			x++;
			Vector3 pos_obj = Vector3(-(UNIT_SIZE - 6) + x * 2, -(UNIT_SIZE - 1.5) + y * 2, 0);
			if (indexHead == i) {
				glColor3f(50.f / 255.f, 205.f / 255.f, 50.f / 255.f);
				renderSelection(pos_obj);
				glColor3f(1, 1, 1);
			}
			obj->sendMessage({ "renderSymbol",std::to_string(pos_obj.x),std::to_string((pos_obj.y)),std::to_string(pos_obj.z) });
		}

	}
	y++;
	{
		// right hand //
		print_bitmap_string(GLUT_BITMAP_HELVETICA_18, "RIGHT:", -(UNIT_SIZE - 1), -(UNIT_SIZE - 1) + y * 2);
		int x = 0;
		Vector3 pos_selection = Vector3(-(UNIT_SIZE - 6) + x, -(UNIT_SIZE - 1.5) + y * 2, 0);
		if (indexRightHand == -1) {
			glColor3f(255.f / 255.f, 69.f / 255.f, 0.f / 255.f);
			renderSelection(pos_selection);
			glColor3f(1, 1, 1);
		}
		for (int i = 0; i < handInventory.size(); i++) {
			GameObject* obj = handInventory[i];
			x++;
			Vector3 pos_obj = Vector3(-(UNIT_SIZE - 6) + x * 2, -(UNIT_SIZE - 1.5) + y * 2, 0);
			if (indexRightHand == i) {
				glColor3f(255.f / 255.f, 69.f / 255.f, 0.f / 255.f);
				renderSelection(pos_obj);
				Vector3 pos_hud = Vector3((UNIT_SIZE - 1.5), -(UNIT_SIZE - 1.5), 0);
				obj->sendMessage({ "renderHUD",std::to_string(pos_hud.x),std::to_string((pos_hud.y)),std::to_string(pos_hud.z) });
				glColor3f(1, 1, 1);
			}
			obj->sendMessage({ "renderSymbol",std::to_string(pos_obj.x),std::to_string((pos_obj.y)),std::to_string(pos_obj.z) });
		}

	}
	y++;
	{
		// left hand //
		print_bitmap_string(GLUT_BITMAP_HELVETICA_18, "LEFT:", -(UNIT_SIZE - 1), -(UNIT_SIZE - 1) + y * 2);
		int x = 0;
		Vector3 pos_selection = Vector3(-(UNIT_SIZE - 6) + x, -(UNIT_SIZE - 1.5) + y * 2, 0);
		if (indexLeftHand == -1) {
			glColor3f(255.f/255.f, 105.f / 255.f, 180.f / 255.f);
			renderSelection(pos_selection);
			glColor3f(1, 1, 1);
		}
		for (int i = 0; i < handInventory.size(); i++) {
			GameObject* obj = handInventory[i];
			x++;
			Vector3 pos_obj = Vector3(-(UNIT_SIZE - 6) + x * 2, -(UNIT_SIZE - 1.5) + y * 2, 0);
			if (indexLeftHand == i) {
				glColor3f(255.f / 255.f, 105.f / 255.f, 180.f / 255.f);
				renderSelection(pos_obj);
				Vector3 pos_hud = Vector3((UNIT_SIZE - 1.5)-2, -(UNIT_SIZE - 1.5), 0);
				obj->sendMessage({ "renderHUD",std::to_string(pos_hud.x),std::to_string((pos_hud.y)),std::to_string(pos_hud.z) });
				glColor3f(1, 1, 1);
			}
			obj->sendMessage({ "renderSymbol",std::to_string(pos_obj.x),std::to_string((pos_obj.y)),std::to_string(pos_obj.z) });
		}
	}

}

void CCompEquipment::renderSelection(Vector3 offset) {
	glBegin(GL_POLYGON);
	glVertex3f(offset.x + -0.9f, offset.y + 0.9f, offset.z + 0.0f);
	glVertex3f(offset.x + 0.9f, offset.y + 0.9f, offset.z + 0.0f);
	glVertex3f(offset.x + 0.9f, offset.y + -0.9f, offset.z + 0.0f);
	glVertex3f(offset.x + -0.9f, offset.y + -0.9f, offset.z + 0.0f);
	glEnd();
}

void CCompEquipment::update(float elapsed) {
	// Action Left //
	if (io->keys['C'].becomesPressed() || io->gamepad[DH_GAMECONTROLLER_0 | PS4_L2_TRIGGER].becomesPressed()) {
		if (indexLeftHand > -1) {
			GameObject* leftObj = handInventory[indexLeftHand];
			leftObj->sendMessage({ "action","left","becomesPressed",std::to_string(elapsed) });
		}
	}else if (io->keys['C'].isPressed() || io->gamepad[DH_GAMECONTROLLER_0 | PS4_L2_TRIGGER].isPressed()) {
		if (indexLeftHand > -1) {
			GameObject* leftObj = handInventory[indexLeftHand];
			leftObj->sendMessage({ "action","left","isPressed",std::to_string(elapsed) });
		}
	}

	// Action Right //
	if (io->keys['N'].becomesPressed() || io->gamepad[DH_GAMECONTROLLER_0 | PS4_R2_TRIGGER].becomesPressed()) {
		if (indexRightHand > -1) {
			GameObject* rightObj = handInventory[indexRightHand];
			rightObj->sendMessage({ "action","right","becomesPressed",std::to_string(elapsed) });
		}
	}else if (io->keys['N'].isPressed() || io->gamepad[DH_GAMECONTROLLER_0 | PS4_R2_TRIGGER].isPressed()) {
		if (indexRightHand > -1) {
			GameObject* rightObj = handInventory[indexRightHand];
			rightObj->sendMessage({ "action","right","isPressed",std::to_string(elapsed) });
		}
	}


	// Switch Mode Left //
	if (io->keys['X'].becomesPressed() || io->gamepad[DH_GAMECONTROLLER_0 | PS4_L1].becomesPressed()) {
		if (indexLeftHand > -1) {
			GameObject* leftObj = handInventory[indexLeftHand];
			leftObj->sendMessage({ "mode","left" });
		}
	}
	// Action Right //
	if (io->keys['M'].becomesPressed() || io->gamepad[DH_GAMECONTROLLER_0 | PS4_R1].becomesPressed()) {
		if (indexRightHand > -1) {
			GameObject* rightObj = handInventory[indexRightHand];
			rightObj->sendMessage({ "mode","right" });
		}
	}

	// Change Head //
	if (io->keys['T'].becomesPressed() || io->gamepad[DH_GAMECONTROLLER_0 | PS4_TRIANGLE].becomesPressed()) {
		changeEquip(HEAD);
	}
	// Change Left //
	if (io->keys['R'].becomesPressed() || io->gamepad[DH_GAMECONTROLLER_0 | PS4_SQUARE].becomesPressed()) {
		changeEquip(LEFTHAND);
	}
	// Change Right //
	if (io->keys['Y'].becomesPressed() || io->gamepad[DH_GAMECONTROLLER_0 | PS4_ROUND].becomesPressed()) {
		changeEquip(RIGHTHAND);
	}
}

void CCompEquipment::changeEquip(int slot) {
	if (slot == HEAD) {
		if (headInventory.size()) {
			if (indexHead == headInventory.size() - 1) equipObject(-1, HEAD);
			else equipObject(indexHead + 1, HEAD);
		}
	}
	if (slot == RIGHTHAND) {
		if (handInventory.size()) {
			if (indexRightHand == handInventory.size() - 1) 
				equipObject(-1, RIGHTHAND);
			else {
				if (indexRightHand + 1 == indexLeftHand) {
					if (indexRightHand+2 > handInventory.size()-1)
						equipObject(-1, RIGHTHAND);
					else
						equipObject(indexRightHand + 2, RIGHTHAND);
				}else
					equipObject(indexRightHand + 1, RIGHTHAND);
			}
		}
	}
	if (slot == LEFTHAND) {
		if (handInventory.size()) {
			if (indexLeftHand == handInventory.size() - 1)
				equipObject(-1, LEFTHAND);
			else {
				if (indexLeftHand + 1 == indexRightHand) {
					if (indexLeftHand + 2 > handInventory.size()-1)
						equipObject(-1, LEFTHAND);
					else
						equipObject(indexLeftHand + 2, LEFTHAND);
				} else
					equipObject(indexLeftHand + 1, LEFTHAND);
			}
		}
	}
}

void CCompEquipment::addObjectToInventory(GameObject * obj) {
	if (obj->slotToEquip() == HEAD)
		headInventory.push_back(obj);
	else
		handInventory.push_back(obj);
}

void CCompEquipment::equipObject(int id_obj, int slot) {
	int previous_obj = -1;
	switch (slot) {
		case HEAD:
		{
			previous_obj = indexHead;
			indexHead = id_obj;
			if (previous_obj != -1) {
				GameObject* objToUnequip = headInventory[previous_obj];
				objToUnequip->sendMessage({ "unequipObject" });
			}
			if (id_obj != -1) {
				GameObject* objToEquip = headInventory[id_obj];
				objToEquip->sendMessage({ "equipObject", std::to_string(slot) });
			}
			break;
		}
		case LEFTHAND:
		{
			previous_obj = indexLeftHand;
			indexLeftHand = id_obj;
			if (previous_obj != -1) {
				GameObject* objToUnequip = handInventory[previous_obj];
				objToUnequip->sendMessage({ "unequipObject" });
			}
			if (id_obj != -1) {
				GameObject* objToEquip = handInventory[id_obj];
				objToEquip->sendMessage({ "equipObject", std::to_string(slot) });
			}
			break;
		}
		case RIGHTHAND:
		{
			previous_obj = indexRightHand;
			indexRightHand = id_obj;
			if (previous_obj != -1) {
				GameObject* objToUnequip = handInventory[previous_obj];
				objToUnequip->sendMessage({ "unequipObject" });
			}
			if (id_obj != -1) {
				GameObject* objToEquip = handInventory[id_obj];
				objToEquip->sendMessage({ "equipObject", std::to_string(slot) });
			}
			break;
		}
	}
}

void CCompEquipment::receiveMessage(std::vector<std::string> msg) {
	if (msg[0] == "addObjectToInventory") {
		GameObject* obj = game->getObject(stoi(msg[1]));
		addObjectToInventory(obj);
	} else if (msg[0] == "rechargeGun") {
		if (msg[1] == "right") { //the ammo clip is on the right, so we have to recharge left gun //
			GameObject* obj = handInventory[indexLeftHand];
			obj->sendMessage(msg);
		} else if (msg[1] == "left") {
			GameObject* obj = handInventory[indexRightHand];
			obj->sendMessage(msg);
		}
	} else if (msg[0] == "deleteAmmo") {
		if (msg[1] == "right") {
			game->deleteObject(handInventory[indexRightHand]);
			handInventory.erase(handInventory.begin() + indexRightHand);
			indexRightHand = -1;
		}else if (msg[1] == "left") {
			game->deleteObject(handInventory[indexLeftHand]);
			handInventory.erase(handInventory.begin() + indexLeftHand);
			indexLeftHand = -1;
		}
	} else if (msg[0] == "dropStone") {
		if (msg[1] == "right") {
			handInventory.erase(handInventory.begin() + indexRightHand);
			indexRightHand = -1;
		} else if (msg[1] == "left") {
			handInventory.erase(handInventory.begin() + indexLeftHand);
			indexLeftHand = -1;
		}
	}
}