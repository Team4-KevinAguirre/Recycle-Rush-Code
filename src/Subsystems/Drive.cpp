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

void Drive::resetGyro(){
	DriveGyro_->Reset();
}

void Drive::resetAbsoluteGyro(){
	DriveGyro_->ResetAbsolute();
}

void Drive::rotateDrive(float turnIncrement){
	//TODO: Remove newLeft/newRight because memory waste.  Put in here for ease of reading.
	float sens = .01;
	float newLeft = ((LeftDriveMotorA_->Get)+turnIncrement*sens);
	float newRight = ((RightDriveMotorA_->Get)+turnIncrement*sens);
	setLinearPower(newLeft,newRight);
}


