//Header File for Drive Base
//This is where we Declare Everything
#ifndef DRIVE_H_
#define DRIVE_H_

#include "WPILib.h"
#include "../Config/Constants.h"
#include "../Util/RelativeGyro.h"


class Drive
{


public:
	Drive(Talon* leftDriveMotorA, Talon* leftDriveMotorB, Talon* rightDriveMotorA, Talon* rightDriveMotorB, RelativeGyro* driveGyro);
	//Tank Drive
	void setLinearPower(double leftPower, double rightPower);

	void resetGyro();
	//Relative Reset of Gyro.  Simply offsets the absolute angle, so we still have absolute control.
	//Need to perform this when we want to hold relative to a certain location.

	void resetAbsoluteGyro();
	//Absolute reset of gyro.  Because of calibration errors, do not perform this on a periodic basis.  Perform this
	//at Init states.

	void rotateDrive(float turnIncrement);
	//Used with "analog" joystick inputs (triggers, etc...) to rotate robot finely.
	//TODO: Create a global rotation sensitivity constant.



private:

	Constants* Constants_;

	//Motors
	Talon* LeftDriveMotorA_;
	Talon* LeftDriveMotorB_;
	Talon* RightDriveMotorA_;
	Talon* RightDriveMotorB_;

	RelativeGyro* DriveGyro_;

};
#endif
