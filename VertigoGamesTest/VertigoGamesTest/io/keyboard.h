#ifndef INC_IO_KEYBOARD_H_
#define INC_IO_KEYBOARD_H_

#include "stdafx.h"
#include "digital_button.h"
#include <map>

class TKeyBoard {
	std::map< int, CDigitalButton > active_keys;
public:
	void update(float dt);
	void sysSysStatus(int key_code, bool is_pressed);
	const CDigitalButton &operator[](int key_code);
};


#endif

