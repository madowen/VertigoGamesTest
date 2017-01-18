#include "io.h"
#include <windowsx.h>

extern CIOModule* io = nullptr;

bool CIOModule::start() {
	gamepad.start();
	//mouse.capture();
	return true;
}

void CIOModule::stop() {

}

void CIOModule::update(float dt) {
	keys.update(dt);
	gamepad.update(dt);
}

void CIOModule::onKeydown(unsigned char key, int x, int y) {
	keys.sysSysStatus(key, true);
}
void CIOModule::onKeyup(unsigned char key, int x, int y) {
	keys.sysSysStatus(key, false);
}

