//Header File for Drive Base
//This is where we Declare Everything
#ifndef DRIVE_H_
#define DRIVE_H_

#include "WPILib.h"
#include "../Config/Constants.h"
#include "../Util/RelativeGyro.h"
#include "Subsystems/Pid.h"


class Drive
{


public:
	Drive(VictorSP* leftDriveMotorA, VictorSP* leftDriveMotorB, VictorSP* rightDriveMotorA, VictorSP* rightDriveMotorB, RelativeGyro* driveGyro, Encoder* leftDriveEncoder, Encoder* rightDriveEncoder);
	//Tank Drive
	void SetLinearPower(double leftPower, double rightPower);
	//Adjusted st. positive is forward.

	//Relative Reset of Gyro.  Simply offsets the absolute angle, so we still have absolute control.
	//Need to perform this when we want to hold relative to a certain location.
	void resetGyro();

	void resetAbsoluteGyro();
	//Absolute reset of gyro.  Because of calibration errors, do not perform this on a periodic basis.  Perform this
	//at Init states.

	void rotateDrive(float turnIncrement);
	//Used with "analog" joystick inputs (triggers, etc...) to rotate robot finely.
	//TODO: Create a global rotation sensitivity constant.

	void rotateAbsoluteDrive(float angle);

	void DriveSpeedTurn(float throttle, float turn, bool quickturn);

private:

	Constants* Constants_;

	//Motors
	VictorSP* LeftDriveMotorA_;
	VictorSP* LeftDriveMotorB_;
	VictorSP* RightDriveMotorA_;
	VictorSP* RightDriveMotorB_;

	//Sensors
	RelativeGyro* DriveGyro_;
	Encoder* LeftDriveEncoder_;
	Encoder* RightDriveEncoder_;


	Pid* TurnPid_;

};
#endif
