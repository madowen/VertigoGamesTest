#include "stdafx.h"
#include "CompFlashlight.h"
#include "utils\utils.h"
#include "utils\framework.h"

void CCompFlashlight::render() {
	if (equiped) {
		float side = 0.0f;
		if (equiped == RIGHTHAND)
			side = 0.5f;
		if (equiped == LEFTHAND)
			side = -0.5f;
		if (light) {
			glBegin(GL_POLYGON);
			glVertex3f(side, 0.f, 0.f);
			glVertex3f(side - 1.f, 1.f, 0.f);
			glVertex3f(side + 1.f, 1.f, 0.f);
			glEnd();
		} else {
			glBegin(GL_LINE_LOOP);
			glVertex3f(side, 0.f, 0.f);
			glVertex3f(side - .3f, .3f, 0.f);
			glVertex3f(side + .3f, .3f, 0.f);
			glEnd();
		}
	} else {
		CCompItem::render();
		renderSymbol(Vector3(0, 0, 0));

	}
}

void CCompFlashlight::action(std::vector<std::string>msg) {
	// Switch Light //
	if (msg[2] == "becomesPressed")
		light = !light;
}

void CCompFlashlight::receiveMessage(std::vector<std::string>msg) {
	CCompItem::receiveMessage(msg);
	if (msg[0] == "action")
		action(msg);
	else if (msg[0] == "renderSymbol")
		renderSymbol(Vector3(stof(msg[1]), stof(msg[2]), stof(msg[3])));
}

void CCompFlashlight::renderSymbol(Vector3 offset) {
	// draw F //
	glBegin(GL_LINES);
	glVertex3f(offset.x + 0.4f, offset.y + 0.7f, offset.z + 0.0f);
	glVertex3f(offset.x + -0.4f, offset.y + 0.7f, offset.z + 0.0f);
	glVertex3f(offset.x + 0.4f, offset.y + 0.0f, offset.z + 0.0f);
	glVertex3f(offset.x + -0.4f, offset.y + 0.0f, offset.z + 0.0f);
	glVertex3f(offset.x + -0.4f, offset.y + 0.7f, offset.z + 0.0f);
	glVertex3f(offset.x + -0.4f, offset.y + -0.7f, offset.z + 0.0f);
	glEnd();
}
