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
