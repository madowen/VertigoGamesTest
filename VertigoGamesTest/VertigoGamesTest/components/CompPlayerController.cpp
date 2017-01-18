#include "stdafx.h"
#include "CompPlayerController.h"
#include "base\GameObject.h"
#include "base\Game.h"
#include "CompTransform.h"
#include "io\io.h"
#include "utils\framework.h"

void CCompPlayerController::render() {
	glBegin(GL_LINE_LOOP);
	glVertex3f(0.8f, -1.0f, 0.0f);
	glVertex3f(0.0f, -0.3f, 0.0f);
	glVertex3f(-0.8f, -1.0f, 0.0f);
	glVertex3f(0.0f, 1.0f, 0.0f);
	glEnd();
}

void CCompPlayerController::update(float elapsed) {
	GameObject* o = this->owner;
	CCompTransform* o_trx = static_cast<CCompTransform*>(o->getComponent("CCompTransform"));
	Vector3 direction = Vector3(0, 0, 0);
	float rotate = 0;
	// FORWARD // 
	if (io->keys['W'].isPressed())
		direction = direction + o_trx->getForward();
	if (io->gamepad[DH_GAMECONTROLLER_0 | PS4_AXIS_LEFTY].getValue() < -AXIS_ACCURACY_THRESHOLD)
		direction = direction - o_trx->getForward() * io->gamepad[DH_GAMECONTROLLER_0 | PS4_AXIS_LEFTY].getValue();
	// BACKWARD //
	if (io->keys['S'].isPressed())
		direction = direction - o_trx->getForward();
	if (io->gamepad[DH_GAMECONTROLLER_0 | PS4_AXIS_LEFTY].getValue() > AXIS_ACCURACY_THRESHOLD)
		direction = direction - o_trx->getForward() * io->gamepad[DH_GAMECONTROLLER_0 | PS4_AXIS_LEFTY].getValue();
	// LEFT // 
	if (io->keys['A'].isPressed())
		direction = direction - o_trx->getRight();
	if (io->gamepad[DH_GAMECONTROLLER_0 | PS4_AXIS_LEFTX].getValue() < -AXIS_ACCURACY_THRESHOLD)
		direction = direction + o_trx->getRight()*io->gamepad[DH_GAMECONTROLLER_0 | PS4_AXIS_LEFTX].getValue();
	// RIGHT //
	if (io->keys['D'].isPressed())
		direction = direction + o_trx->getRight();
	if (io->gamepad[DH_GAMECONTROLLER_0 | PS4_AXIS_LEFTX].getValue() > AXIS_ACCURACY_THRESHOLD)
		direction = direction + o_trx->getRight()*io->gamepad[DH_GAMECONTROLLER_0 | PS4_AXIS_LEFTX].getValue();

	// ROTATE //
	if (io->keys['J'].isPressed())
		rotate -= 1;
	if (io->gamepad[DH_GAMECONTROLLER_0 | PS4_AXIS_RIGHTX].getValue() < -AXIS_ACCURACY_THRESHOLD)
		rotate += io->gamepad[DH_GAMECONTROLLER_0 | PS4_AXIS_RIGHTX].getValue();
	if (io->keys['L'].isPressed())
		rotate += 1;
	if (io->gamepad[DH_GAMECONTROLLER_0 | PS4_AXIS_RIGHTX].getValue() > AXIS_ACCURACY_THRESHOLD)
		rotate += io->gamepad[DH_GAMECONTROLLER_0 | PS4_AXIS_RIGHTX].getValue();



	if (direction.x != 0 || direction.y != 0) {
		Vector2 v = Vector2(direction.x, direction.y);
		if (v.length() > 1) v = v.normalize();
		direction = Vector3(v.x, v.y, 0);
	}
	Matrix44 m = o_trx->getModelValue();
	m.traslate(direction*speedMovement*elapsed);
	m.rotateLocal(speedRotation * rotate * DEG2RAD*elapsed, Vector3(0, 0, 1));
	o_trx->setModel(m);


}
