#ifndef INC_IO_Gamepad_H_
#define INC_IO_Gamepad_H_

#include <SDL2\SDL.h>
#include "digital_button.h"
#include <map>

#define MAX_CONTROLLERS 4
#define MAX_AXIS_VALUE 32767
#define AXIS_MOUSE_MOVEMENT 500
#define AXIS_SENSIBILITY_SHOOTING 1
#define AXIS_SENSIBILITY_MOVEMENT 2
#define AXIS_ACCURACY_THRESHOLD 0.2f
#define TRIGGER_ACCURACY_THRESHOLD 0.51f

#define DH_GAMECONTROLLER_0		0x0000
#define DH_GAMECONTROLLER_1		0x0100
#define DH_GAMECONTROLLER_2		0x0200
#define DH_GAMECONTROLLER_3		0x0300

#define XBOX_A					0x0000
#define XBOX_B					0x0001
#define XBOX_X					0x0002
#define XBOX_Y					0x0003
#define XBOX_BACK				0x0004
#define XBOX_GUIDE				0x0005
#define XBOX_START				0x0006
#define XBOX_LEFTSTICK			0x0007
#define XBOX_RIGHTSTICK			0x0008
#define XBOX_LEFTSHOULDER		0x0009
#define XBOX_RIGHTSHOULDER		0x000A
#define XBOX_DPAD_UP			0x000B
#define XBOX_DPAD_DOWN			0x000C
#define XBOX_DPAD_LEFT			0x000D
#define XBOX_DPAD_RIGHT			0x000E
#define XBOX_AXIS_LEFTX			0x0010
#define XBOX_AXIS_LEFTY			0x0011
#define XBOX_AXIS_RIGHTX		0x0012
#define XBOX_AXIS_RIGHTY		0x0013
#define XBOX_AXIS_TRIGGERLEFT	0x0014
#define XBOX_AXIS_TRIGGERRIGHT	0x0015

#define PS4_X_CROSS				0x0000
#define PS4_ROUND				0x0001
#define PS4_SQUARE				0x0002
#define PS4_TRIANGLE			0x0003
#define PS4_SHARE				0x0004
#define PS4_PS					0x0005
#define PS4_OPTIONS				0x0006
#define PS4_L3					0x0007
#define PS4_R3					0x0008
#define PS4_L1					0x0009
#define PS4_R1					0x000A
#define PS4_UP					0x000B
#define PS4_DOWN				0x000C
#define PS4_LEFT				0x000D
#define PS4_RIGHT				0x000E
#define PS4_AXIS_LEFTX			0x0010
#define PS4_AXIS_LEFTY			0x0011
#define PS4_AXIS_RIGHTX			0x0012
#define PS4_AXIS_RIGHTY			0x0013
#define PS4_L2_TRIGGER			0x0014
#define PS4_R2_TRIGGER			0x0015

class TGamepad {


	SDL_GameController	*ControllerHandles[MAX_CONTROLLERS];
	std::map<int, CGameControllerButton> gamepadMapping[MAX_CONTROLLERS];
public:

	TGamepad() {};
	~TGamepad();
	void start();
	void update(float dt);

	 CGameControllerButton & operator[](short key_code);

};


#endif

