#include "auto/DriveCommand.h"

#include "Subsystems/Drive.h"
#include "Config/Constants.h"

DriveCommand::DriveCommand(Drive* drive, double distance, double angle, double timeout, double maxSpeed, double maxAcceleration, double maxAlpha, double maxOmega) {
	drive_ = drive;

	Constants* constants = Constants::GetInstance();
}
