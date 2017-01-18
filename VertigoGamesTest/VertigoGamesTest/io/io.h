#ifndef INC_MODULE_IO_H_
#define INC_MODULE_IO_H_


#include "keyboard.h"
#include "gamepad.h"

class CIOModule {
public:
	bool start() ;
	void stop() ;
	void update(float dt) ;
	void onKeydown(unsigned char key, int x, int y);
	void onKeyup(unsigned char key, int x, int y);
	const char* getName() const {
		return "io";
	}

	TKeyBoard keys;
	TGamepad  gamepad;

};

extern CIOModule* io;

#endif
