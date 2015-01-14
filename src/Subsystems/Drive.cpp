//Declaration File for Drive Base
//This is where we define everything.
#include "Drive.h"

Drive::Drive(Talon* leftDriveMotorA, Talon* leftDriveMotorB, Talon* rightDriveMotorA, Talon* rightDriveMotorB){

	Constants_ = Constants::GetInstance();

	//Motors
	leftDriveMotorA_ = leftDriveMotorA;
	leftDriveMotorB_ = leftDriveMotorB;

	rightDriveMotorA_ = rightDriveMotorA;
	rightDriveMotorB_ = rightDriveMotorB;

}

void Drive::setLinearPower(double leftPower, double rightPower){
	leftDriveMotorA_->Set(PwmLimit(leftPower));
	leftDriveMotorB_->Set(PwmLimit(leftPower));
	rightDriveMotorA_->Set(PwmLimit(rightPower));
	rightDriveMotorB_->Set(PwmLimit(rightPower));

}
