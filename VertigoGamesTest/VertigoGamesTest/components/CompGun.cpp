#include "stdafx.h"
#include "CompGun.h"
#include "utils\utils.h"
#include "utils\framework.h"
#include "base\Game.h"
#include "base\GameObject.h"
void CCompGun::render() {
	if (equiped) {
		float side = 0.0f;
		if (equiped == RIGHTHAND)
			side = 0.5f;
		if (equiped == LEFTHAND)
			side = -0.5f;
		glBegin(GL_POLYGON);
		glVertex3f(side - .1f, 0.f, 0.f);
		glVertex3f(side + .1f, 0.f, 0.f);
		glVertex3f(side - .1f, .3f, 0.f);
		glVertex3f(side + .1f, .3f, 0.f);
		glEnd();
	} else {
		CCompItem::render();
		renderSymbol(Vector3(0, 0, 0));

	}
}

void CCompGun::renderHUD(Vector3 offset) {
	if (equiped) {
		for (int i = 0; i < 10; i++) {
			if (i < ammo)
				glBegin(GL_POLYGON);
			else
				glBegin(GL_LINE_LOOP);
			glVertex3f(offset.x + -.8f, offset.y + -.8f + .5f*i, offset.z + 0.f);
			glVertex3f(offset.x + .8f, offset.y + -.8f + .5f*i, offset.z + 0.f);
			glVertex3f(offset.x + .8f, offset.y + -.4f + .5f*i, offset.z + 0.f);
			glVertex3f(offset.x + -.8f, offset.y + -.4f + .5f*i, offset.z + 0.f);
			glEnd();
		}
	}
}

void CCompGun::action(std::vector<std::string>msg) {
	// Shoot //
	if (!automatic) {
		if (msg[2] == "becomesPressed")	ammo--;
	} else {
		if (msg[2] == "becomesPressed") {
			shoot_time = shoot_rate;
			ammo--;
		} else if (msg[2] == "isPressed") {
			shoot_time -= stof(msg[3]);
			if (shoot_time <= 0) {
				ammo--;
				shoot_time += shoot_rate;
			}
		}
	}
}

void CCompGun::receiveMessage(std::vector<std::string>msg) {
	CCompItem::receiveMessage(msg);
	if (msg[0] == "action")
		action(msg);
	else if (msg[0] == "renderSymbol")
		renderSymbol(Vector3(stof(msg[1]), stof(msg[2]), stof(msg[3])));
	else if (msg[0] == "renderHUD")
		renderHUD(Vector3(stof(msg[1]), stof(msg[2]), stof(msg[3])));
	else if (msg[0] == "rechargeGun") {
		ammo = 10;
		game->getPlayer()->sendMessage({ "deleteAmmo",msg[1] });
	} else if (msg[0] == "mode") {
		automatic = !automatic;
	}
}

void CCompGun::renderSymbol(Vector3 offset) {
	// draw G //
	glBegin(GL_LINES);
	glVertex3f(offset.x + 0.4f, offset.y + 0.7f, offset.z + 0.0f);
	glVertex3f(offset.x + -0.4f, offset.y + 0.7f, offset.z + 0.0f);
	glVertex3f(offset.x + -0.4f, offset.y + 0.7f, offset.z + 0.0f);
	glVertex3f(offset.x + -0.4f, offset.y + -0.7f, offset.z + 0.0f);
	glVertex3f(offset.x + -0.4f, offset.y + -0.7f, offset.z + 0.0f);
	glVertex3f(offset.x + 0.4f, offset.y + -0.7f, offset.z + 0.0f);
	glVertex3f(offset.x + 0.4f, offset.y + -0.7f, offset.z + 0.0f);
	glVertex3f(offset.x + 0.4f, offset.y + 0.f, offset.z + 0.0f);
	glVertex3f(offset.x + 0.4f, offset.y + 0.f, offset.z + 0.0f);
	glVertex3f(offset.x + 0.f, offset.y + 0.f, offset.z + 0.0f);
	glVertex3f(offset.x + 0.f, offset.y + 0.f, offset.z + 0.0f);
	glVertex3f(offset.x + 0.f, offset.y + -0.2f, offset.z + 0.0f);
	glEnd();

}
