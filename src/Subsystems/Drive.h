//Header File for Drive Base
//This is where we Declare Everything
#ifndef DRIVE_H_
#define DRIVE_H_

#include "WPILib.h"
#include "../Config/Constants.h"


class Drive
{


public:
	Drive(Talon* leftDriveMotorA, Talon* leftDriveMotorB, Talon* rightDriveMotorA, Talon* rightDriveMotorB);
	//Tank Drive
	void setLinearPower(double leftPower, double rightPower);



private:

	Constants* Constants_;

	//Motors
	Talon* leftDriveMotorA_;
	Talon* leftDriveMotorB_;
	Talon* rightDriveMotorA_;
	Talon* rightDriveMotorB_;



};
#endif
