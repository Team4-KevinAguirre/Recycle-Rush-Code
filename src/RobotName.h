//==================================================
// Copyright (C) 2014 Team 1538 / The Holy Phoenixs
//==================================================

#ifndef __ROBOT_NAME_H__
#define __ROBOT_NAME_H__

//#include <hostLib.h>
#include <WPILib.h>

#include "Controllers/OperatorController.h"

#include "Config/Constants.h"
#include "Subsystems/DriveBase.h"
#include "PhoenixControlBoard.h"
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
	Constants* m_Constants;

	//Vision

	//Subsystems
	DriveBase* m_Drivebase;

	//Drivers

	//Joysticks
	Joystick* m_DriverJoystick;
	Joystick* m_OperatorJoystick;

	//Control Board
	PhoenixControlBoard m_ControlBoard;


	//Motors
	Talon* m_LeftDriveMotorA;
	Talon* m_RightDriveMotorA;


	//Sensors
	Encoder* m_LeftDriveEncoder;
	Encoder* m_RightDriveEncoder;

	//Pneumatics

	//DriverStation* lcd;

	  double prevLeftDist_;
	  double prevRightDist_;
	  double prevTime;

};

START_ROBOT_CLASS(RobotName);

#endif

