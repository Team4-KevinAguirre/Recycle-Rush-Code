//Declaration File for Drive Base
//This is where we define everything.
#include "Drive.h"

Drive::Drive(Talon* leftDriveMotorA, Talon* leftDriveMotorB, Talon* rightDriveMotorA, Talon* rightDriveMotorB, RelativeGyro* driveGyro){

	Constants_ = Constants::GetInstance();

	//Motors
	LeftDriveMotorA_ = leftDriveMotorA;
	LeftDriveMotorB_ = leftDriveMotorB;

	RightDriveMotorA_ = rightDriveMotorA;
	RightDriveMotorB_ = rightDriveMotorB;

	DriveGyro_ = driveGyro;

}

void Drive::setLinearPower(double leftPower, double rightPower){
	LeftDriveMotorA_->Set(PwmLimit(leftPower));
	LeftDriveMotorB_->Set(PwmLimit(leftPower));
	RightDriveMotorA_->Set(PwmLimit(rightPower));
	RightDriveMotorB_->Set(PwmLimit(rightPower));

}

