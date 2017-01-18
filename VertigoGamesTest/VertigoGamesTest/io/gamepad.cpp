#include "gamepad.h"
#include "stdafx.h"
#include "io.h"
#include "utils\utils.h"


void TGamepad::update(float dt) {
	SDL_GameControllerUpdate();
	for (int ControllerIndex = 0;
		 ControllerIndex < MAX_CONTROLLERS;
		 ++ControllerIndex) {
		if (ControllerHandles[ControllerIndex] != 0 && SDL_GameControllerGetAttached(ControllerHandles[ControllerIndex])) {
			// NOTE: We have a controller with index ControllerIndex.
			gamepadMapping[ControllerIndex][XBOX_A].setCurrentStatus(SDL_GameControllerGetButton(ControllerHandles[ControllerIndex], SDL_CONTROLLER_BUTTON_A));
			gamepadMapping[ControllerIndex][XBOX_B].setCurrentStatus(SDL_GameControllerGetButton(ControllerHandles[ControllerIndex], SDL_CONTROLLER_BUTTON_B));
			gamepadMapping[ControllerIndex][XBOX_X].setCurrentStatus(SDL_GameControllerGetButton(ControllerHandles[ControllerIndex], SDL_CONTROLLER_BUTTON_X));
			gamepadMapping[ControllerIndex][XBOX_Y].setCurrentStatus(SDL_GameControllerGetButton(ControllerHandles[ControllerIndex], SDL_CONTROLLER_BUTTON_Y));
			gamepadMapping[ControllerIndex][XBOX_BACK].setCurrentStatus(SDL_GameControllerGetButton(ControllerHandles[ControllerIndex], SDL_CONTROLLER_BUTTON_BACK));
			gamepadMapping[ControllerIndex][XBOX_GUIDE].setCurrentStatus(SDL_GameControllerGetButton(ControllerHandles[ControllerIndex], SDL_CONTROLLER_BUTTON_GUIDE));
			gamepadMapping[ControllerIndex][XBOX_START].setCurrentStatus(SDL_GameControllerGetButton(ControllerHandles[ControllerIndex], SDL_CONTROLLER_BUTTON_START));
			gamepadMapping[ControllerIndex][XBOX_LEFTSTICK].setCurrentStatus(SDL_GameControllerGetButton(ControllerHandles[ControllerIndex], SDL_CONTROLLER_BUTTON_LEFTSTICK));
			gamepadMapping[ControllerIndex][XBOX_RIGHTSTICK].setCurrentStatus(SDL_GameControllerGetButton(ControllerHandles[ControllerIndex], SDL_CONTROLLER_BUTTON_RIGHTSTICK));
			gamepadMapping[ControllerIndex][XBOX_LEFTSHOULDER].setCurrentStatus(SDL_GameControllerGetButton(ControllerHandles[ControllerIndex], SDL_CONTROLLER_BUTTON_LEFTSHOULDER));
			gamepadMapping[ControllerIndex][XBOX_RIGHTSHOULDER].setCurrentStatus(SDL_GameControllerGetButton(ControllerHandles[ControllerIndex], SDL_CONTROLLER_BUTTON_RIGHTSHOULDER));
			gamepadMapping[ControllerIndex][XBOX_DPAD_UP].setCurrentStatus(SDL_GameControllerGetButton(ControllerHandles[ControllerIndex], SDL_CONTROLLER_BUTTON_DPAD_UP));
			gamepadMapping[ControllerIndex][XBOX_DPAD_DOWN].setCurrentStatus(SDL_GameControllerGetButton(ControllerHandles[ControllerIndex], SDL_CONTROLLER_BUTTON_DPAD_DOWN));
			gamepadMapping[ControllerIndex][XBOX_DPAD_LEFT].setCurrentStatus(SDL_GameControllerGetButton(ControllerHandles[ControllerIndex], SDL_CONTROLLER_BUTTON_DPAD_LEFT));
			gamepadMapping[ControllerIndex][XBOX_DPAD_RIGHT].setCurrentStatus(SDL_GameControllerGetButton(ControllerHandles[ControllerIndex], SDL_CONTROLLER_BUTTON_DPAD_RIGHT));
			gamepadMapping[ControllerIndex][XBOX_AXIS_LEFTX].setCurrentStatus((float)((float)SDL_GameControllerGetAxis(ControllerHandles[ControllerIndex], SDL_CONTROLLER_AXIS_LEFTX) / (float)MAX_AXIS_VALUE), AXIS_ACCURACY_THRESHOLD);
			gamepadMapping[ControllerIndex][XBOX_AXIS_LEFTY].setCurrentStatus((float)((float)SDL_GameControllerGetAxis(ControllerHandles[ControllerIndex], SDL_CONTROLLER_AXIS_LEFTY) / (float)MAX_AXIS_VALUE), AXIS_ACCURACY_THRESHOLD);
			gamepadMapping[ControllerIndex][XBOX_AXIS_RIGHTX].setCurrentStatus((float)((float)SDL_GameControllerGetAxis(ControllerHandles[ControllerIndex], SDL_CONTROLLER_AXIS_RIGHTX) / (float)MAX_AXIS_VALUE), AXIS_ACCURACY_THRESHOLD);
			gamepadMapping[ControllerIndex][XBOX_AXIS_RIGHTY].setCurrentStatus((float)((float)SDL_GameControllerGetAxis(ControllerHandles[ControllerIndex], SDL_CONTROLLER_AXIS_RIGHTY) / (float)MAX_AXIS_VALUE), AXIS_ACCURACY_THRESHOLD);
			gamepadMapping[ControllerIndex][XBOX_AXIS_TRIGGERLEFT].setCurrentStatus((float)((float)SDL_GameControllerGetAxis(ControllerHandles[ControllerIndex], SDL_CONTROLLER_AXIS_TRIGGERLEFT) / (float)MAX_AXIS_VALUE), TRIGGER_ACCURACY_THRESHOLD);
			gamepadMapping[ControllerIndex][XBOX_AXIS_TRIGGERRIGHT].setCurrentStatus((float)((float)SDL_GameControllerGetAxis(ControllerHandles[ControllerIndex], SDL_CONTROLLER_AXIS_TRIGGERRIGHT) / (float)MAX_AXIS_VALUE), TRIGGER_ACCURACY_THRESHOLD);

		} else {
			// TODO: This controller is note plugged in.
		}
	}
}


 CGameControllerButton & TGamepad::operator[](short key_code) {
	int high = Hi(key_code);
	int low = Lo(key_code);
	return gamepadMapping[high][low];
}

void TGamepad::start() {
	SDL_Init(SDL_INIT_JOYSTICK | SDL_INIT_GAMECONTROLLER);
	SDL_GameControllerEventState(SDL_QUERY);

	int MaxJoysticks = SDL_NumJoysticks();
	int ControllerIndex = 0;
	for (int JoystickIndex = 0; JoystickIndex < MaxJoysticks; ++JoystickIndex) {
		if (!SDL_IsGameController(JoystickIndex)) {
			continue;
		}
		if (ControllerIndex >= MAX_CONTROLLERS) {
			break;
		}
		ControllerHandles[ControllerIndex] = SDL_GameControllerOpen(JoystickIndex);
		if (SDL_GameControllerAddMappingsFromFile("gamecontroller.db") == -1)
			std::cerr << "GameController mapping file error: " << SDL_GetError() << std::endl;
		ControllerIndex++;
	}
	for (int i = 0; i < 4; i++) {
		gamepadMapping[i][PS4_X_CROSS].setCurrentStatus(0);
		gamepadMapping[i][PS4_ROUND].setCurrentStatus(0);
		gamepadMapping[i][PS4_SQUARE].setCurrentStatus(0);
		gamepadMapping[i][PS4_TRIANGLE].setCurrentStatus(0);
		gamepadMapping[i][PS4_SHARE].setCurrentStatus(0);
		gamepadMapping[i][PS4_PS].setCurrentStatus(0);
		gamepadMapping[i][PS4_OPTIONS].setCurrentStatus(0);
		gamepadMapping[i][PS4_L3].setCurrentStatus(0);
		gamepadMapping[i][PS4_R3].setCurrentStatus(0);
		gamepadMapping[i][PS4_L1].setCurrentStatus(0);
		gamepadMapping[i][PS4_R1].setCurrentStatus(0);
		gamepadMapping[i][PS4_UP].setCurrentStatus(0);
		gamepadMapping[i][PS4_DOWN].setCurrentStatus(0);
		gamepadMapping[i][PS4_LEFT].setCurrentStatus(0);
		gamepadMapping[i][PS4_RIGHT].setCurrentStatus(0);
		gamepadMapping[i][PS4_AXIS_LEFTX].setCurrentStatus(0);
		gamepadMapping[i][PS4_AXIS_LEFTY].setCurrentStatus(0);
		gamepadMapping[i][PS4_AXIS_RIGHTX].setCurrentStatus(0);
		gamepadMapping[i][PS4_AXIS_RIGHTY].setCurrentStatus(0);
		gamepadMapping[i][PS4_L2_TRIGGER].setCurrentStatus(0);
		gamepadMapping[i][PS4_R2_TRIGGER].setCurrentStatus(0);
	}					  
}

TGamepad::~TGamepad() {
	for (int ControllerIndex = 0; ControllerIndex < MAX_CONTROLLERS; ++ControllerIndex) {
		if (ControllerHandles[ControllerIndex]) {
			SDL_GameControllerClose(ControllerHandles[ControllerIndex]);
		}
	}
}


