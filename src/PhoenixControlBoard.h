//==================================================
// Copyright (C) 2014 Team 1538 / The Holy PHOENIXs
//==================================================

#ifndef __PHOENIX_CONTROL_BOARD_H__
#define __PHOENIX_CONTROL_BOARD_H__

#include <WPILib.h>
#include "Config/Constants.h"

//#define SHIFTER_BUTTON			4
//#define AUTON_BUTTON			1
//#define PID_BUTTON				3
//
//#define LEFT_GAMEPAD_X			1
//#define LEFT_GAMEPAD_Y			2
//#define RIGHT_GAMEPAD_X			3
//#define RIGHT_GAMEPAD_Y			4
//#define STEERING_X				1
//
//#define FAST_TURN				6

/// This class offers access to the 2010 specific PHOENIX Control Board
///
class PhoenixControlBoard
{

public:
	PhoenixControlBoard(Joystick* DriveJoystick, Joystick* OperatorJoystick);
	
//	bool GetQuickTurn();
//	bool GetAutoSelectButton();

	float GetDriveAxis(unsigned int axis);
	bool GetDriveButton(unsigned int button);

	float GetOperatorAxis(unsigned int axis);
	bool GetOperatorButton(unsigned int button);

private:
	Joystick* DriveJoystick_;
	Joystick* OperatorJoystick_;
	Constants* Constants_;

};

#endif
