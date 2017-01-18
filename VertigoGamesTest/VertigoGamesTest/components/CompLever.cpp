#include "stdafx.h"
#include "CompLever.h"
#include "base\Game.h"
#include "base\GameObject.h"
#include "CompTransform.h"
#include "io\io.h"

void CCompLever::render() {
	glBegin(GL_LINES);
	glVertex3f(-1.f, 0.f, 0.f);
	glVertex3f(1.f, 0.f, 0.f);
	glVertex3f(0.f, 0.f, 0.f);
	if (open)
		glVertex3f(.75f, 0.5f, 0.f);
	else
		glVertex3f(-.75f, 0.5f, 0.f);
	glEnd();
}

void CCompLever::activate(){
	GameObject* p = game->getPlayer();
	GameObject* o = owner;
	CCompTransform* p_trx = static_cast<CCompTransform*>(p->getComponent("CCompTransform"));
	CCompTransform* o_trx = static_cast<CCompTransform*>(owner->getComponent("CCompTransform"));
	Vector3 p_pos = p_trx->getPosition();
	Vector3 o_pos = o_trx->getPosition();
	if (o_pos.distance(p_pos) < 1.5)
		open = !open;
}

void CCompLever::update(float elapsed) {
	// ACTIVATE //
	if (io->keys['E'].becomesPressed() || io->gamepad[DH_GAMECONTROLLER_0 | PS4_X_CROSS].becomesPressed())
		activate();

}