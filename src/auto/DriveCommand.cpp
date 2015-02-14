#include "auto/DriveCommand.h"

DriveCommand::DriveCommand(Drive* drive, double distance, double angle, double timeout) {

	SetTimeout(timeout);
	Drive_ = drive;
	distanceGoal_ = distance;
	angleGoal_ = angle;

	Constants* constants = Constants::GetInstance();
}

void DriveCommand::Initialize() {

	Drive_->ResetEncoders();
	Drive_->ResetGyro();

}

bool DriveCommand::Run() {


	return(Drive_->DriveDistanceWithHeading(distanceGoal_,angleGoal_));

}
