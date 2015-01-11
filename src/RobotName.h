//==================================================
// Copyright (C) 2014 Team 1538 / The Holy Phoenixs
//==================================================

#ifndef __ROBOT_NAME_H__
#define __ROBOT_NAME_H__

//#include <hostLib.h>
#include <Subsystems/Drive.h>
#include <WPILib.h>

#include "Config/Constants.h"
#include "PhoenixControlBoard.h"

#include "drivers/Driver.h"
#include "drivers/TeleopDriver.h"
//#include "Controllers/AutoModeController.h"
//#include "Autonomous/AutoModes.h"
//#include "PhoenixLib/PhoenixLib.h"


class RobotName : public IterativeRobot
{
private:
	//OperatorController* m_OpController;
	//AutoModeController* m_AutoController;
	//PhoenixConstants* m_Constants;
	//Winch::e_WinchState m_WinchState;
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

	//Vision

	//Subsystems
	Drive* Drive_;

	//Drivers
	Driver* CurrDriver_;
	TeleopDriver* TeleopDriver_;

	//Joysticks
	Joystick* DriverJoystick_;
	Joystick* OperatorJoystick_;

	//Control Board
	PhoenixControlBoard* ControlBoard_;


	//Motors
	Talon* LeftDriveMotorA_;
	Talon* RightDriveMotorA_;


	//Sensors
	Encoder* LeftDriveEncoder_;
	Encoder* RightDriveEncoder_;

	Gyro* GyroDrive_;

	DigitalInput* LimitSwitchMain_;

	//DigitalInput* LimitA_;

	//Pneumatics

	//DriverStation* lcd;


};

START_ROBOT_CLASS(RobotName);

#endif

