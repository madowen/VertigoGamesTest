#include "stdafx.h"
#include "CompHat.h"
#include "utils\framework.h"

void CCompHat::render() {
	if (equiped) {
		glBegin(GL_POLYGON);
		glVertex3f(0.4f, 0.0f, 0.0f);
		glVertex3f(0.0f, -0.3f, 0.0f);
		glVertex3f(-0.4f, 0.0f, 0.0f);
		glVertex3f(0.0f, 1.0f, 0.0f);
		glEnd();
	} else {
		CCompItem::render();
		renderSymbol(Vector3(0, 0, 0));
	}
}

void CCompHat::renderSymbol(Vector3 offset) {
	// draw H //
	glBegin(GL_LINES);
	glVertex3f(offset.x + -0.4f, offset.y + 0.7f, offset.z + 0.0f);
	glVertex3f(offset.x + -0.4f, offset.y + -0.7f, offset.z + 0.0f);
	glVertex3f(offset.x + 0.4f, offset.y + 0.7f, offset.z + 0.0f);
	glVertex3f(offset.x + 0.4f, offset.y + -0.7f, offset.z + 0.0f);
	glVertex3f(offset.x + -0.4f, offset.y + 0.0f, offset.z + 0.0f);
	glVertex3f(offset.x + 0.4f, offset.y + 0.0f, offset.z + 0.0f);
	glEnd();

}

void CCompHat::receiveMessage(std::vector<std::string> msg) {
	CCompItem::receiveMessage(msg);
	if (msg[0] == "renderSymbol")
		renderSymbol(Vector3(stof(msg[1]), stof(msg[2]), stof(msg[3])));
}