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

