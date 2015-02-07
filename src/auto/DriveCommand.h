#ifndef AUTO_DRIVE_COMMAND_H_
#define AUTO_DRIVE_COMMAND_H_

#include "auto/AutoCommand.h"
#include "Subsystems/Drive.h"
#include "Config/Constants.h"


class Drive;
//class Pid;
//
class DriveCommand : public AutoCommand {

public:


	/**
	 * Constructor. Accepts drivetrain pointer and goal in terms of distance in inches
	 */
	DriveCommand(Drive* drive, double distance, double angle, double timeout);

	/*
	 * Resets encoders and gyro
	 */
	void Initialize();

	/*
	 * Uses PID Updated Values to set motors and reach distance goal with acceptable error.
	 */
	bool Run();

private:
	//Subsystems
	Drive* Drive_;

	//Goals
	double angleGoal_;
	double distanceGoal_;


};

#endif






















