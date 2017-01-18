#ifndef __COMP_GAMEOBJECT_GENERATOR__
#define __COMP_GAMEOBJECT_GENERATOR__

#include "GameObject.h"
#include "components\CompEquipment.h"
#include "components\CompPlayerController.h"
#include "components\CompTransform.h"
#include "components\CompHat.h"
#include "components\CompStone.h"
#include "components\CompFlashlight.h"
#include "components\CompGun.h"
#include "components\CompAmmo.h"
#include "components\CompLever.h"
#include "utils\utils.h"
#include <typeinfo>

GameObject* generatePlayer() {
	GameObject* player = new GameObject;
	CCompTransform* player_trx = new CCompTransform;
	player_trx->setOwner(player);
	player->addComponent(player_trx);
	CCompPlayerController* player_controller = new CCompPlayerController;
	player_controller->setOwner(player);
	player->addComponent(player_controller);
	CCompEquipment* player_equipment = new CCompEquipment;
	player_equipment->setOwner(player);
	player->addComponent(player_equipment);


	return player;
}

GameObject* generateItem(Vector3 p, int objectType) {
	GameObject* item = new GameObject;
	CCompTransform* item_trx = new CCompTransform;
	item_trx->setOwner(item);
	item_trx->setPosition(p);
	item->addComponent(item_trx);
	switch (objectType) {
		case HAT:
		{
			CCompHat* c_hat = new CCompHat;
			c_hat->setOwner(item);
			item->addComponent(c_hat);
			break;
		}
		case GUN:
		{
			CCompGun* c_gun = new CCompGun;
			c_gun->setOwner(item);
			item->addComponent(c_gun);
			break;
		}
		case STONE:
		{
			CCompStone* c_stone = new CCompStone;
			c_stone->setOwner(item);
			item->addComponent(c_stone);
			break;
		}
		case AMMO:
		{
			CCompAmmo* c_ammo = new CCompAmmo;
			c_ammo->setOwner(item);
			item->addComponent(c_ammo);
			break;
		}
		case FLASHLIGHT:
		{
			CCompFlashlight* c_flashlight = new CCompFlashlight;
			c_flashlight->setOwner(item);
			item->addComponent(c_flashlight);
			break;
		}
		case LEVER:
		{
			CCompLever* c_lever = new CCompLever;
			c_lever->setOwner(item);
			item->addComponent(c_lever);
			break;
		}

	}

	return item;
}
#endif