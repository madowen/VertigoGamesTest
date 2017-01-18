#ifndef __COMP_EQUIPMENT__
#define __COMP_EQUIPMENT__

#include "CompBase.h"
#include <vector>

class GameObject;
class Vector3;
class CCompEquipment : public CCompBase {
	int indexHead;
	int indexLeftHand;
	int indexRightHand;
	std::vector<GameObject*> headInventory;
	std::vector<GameObject*> handInventory;

public:
	CCompEquipment();
	~CCompEquipment();
	void render();
	void renderHUD();
	void renderSelection(Vector3 offset);
	void update(float elapsed);
	void changeEquip(int slot);
	void addObjectToInventory(GameObject* obj);
	void equipObject(int id_obj, int slot);
	void receiveMessage(std::vector<std::string> msg);
	std::string className() { return "CCompEquipment"; }
};

#endif