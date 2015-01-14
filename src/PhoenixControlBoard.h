//==================================================
// Copyright (C) 2014 Team 1538 / The Holy PHOENIXs
//==================================================

#ifndef __PHOENIX_CONTROL_BOARD_H__
#define __PHOENIX_CONTROL_BOARD_H__

#include <WPILib.h>
#include "Config/Constants.h"

class PhoenixControlBoard
{

public:
	PhoenixControlBoard(Joystick* DriveJoystick, Joystick* OperatorJoystick);

	float GetDriveAxis(int axis);
	bool GetDriveButton(int button);
	float GetDrivePOV();
	//Returns the degree starting at up and going clockwise.
	//TODO: Do we need to fix s.t. zero'd somewhere else?

	float GetOperatorAxis(int axis);
	bool GetOperatorButton(int button);
	float GetOperatorPOV();
	//Returns the degree starting at up and going clockwise.
	//TODO: Do we need to fix s.t. zero'd somewhere else?
private:
	Joystick* DriveJoystick_;
	Joystick* OperatorJoystick_;
	Constants* Constants_;


};

#endif
