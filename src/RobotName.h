//==================================================
// Copyright (C) 2014 Team 1538 / The Holy Phoenixs
//==================================================

#ifndef __ROBOT_NAME_H__
#define __ROBOT_NAME_H__

//#include <hostLib.h>
#include "Subsystems/Drive.h"
#include "Subsystems/Conveyor.h"
#include "Subsystems/Intake.h"
#include <WPILib.h>

#include "Config/Constants.h"
#include "PhoenixControlBoard.h"


class RobotName : public IterativeRobot
{
private:

public:
	RobotName();
	void ResetMotors();
	void RobotInit();
	void DisabledInit();
	void AutonomousInit();
	void TeleopInit();
	void DisabledContinuous();
	void AutonomousContinuous();
	void TeleopContinuous();
	void DisabledPeriodic();
	void AutonomousPeriodic();
	void TeleopPeriodic();


private:

	//Constants
	Constants* Constants_;



};

START_ROBOT_CLASS(RobotName);

#endif

