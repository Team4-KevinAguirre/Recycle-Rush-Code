//==================================================
// Copyright (C) 2014 Team 1538 / The Holy Phoenixs
//==================================================

#ifndef __Phoenix_BASE_H__
#define __Phoenix_BASE_H__

//#include <hostLib.h>
#include <WPILib.h>
#include "PhoenixControlBoard.h"
#include "Controllers/OperatorController.h"
#include "Config/Constants.h"
//#include "Controllers/AutoModeController.h"
//#include "Autonomous/AutoModes.h"
//#include "PhoenixLib/PhoenixLib.h"


class PhoenixBase : public IterativeRobot
{
private:
	PhoenixRobot* m_Bot;
	PhoenixControlBoard* m_ControlBoard;
	OperatorController* m_OpController;
	Constants* m_Constants;
	//AutoModeController* m_AutoController;
	//PhoenixConstants* m_Constants;
	//Winch::e_WinchState m_WinchState;
public:
	PhoenixBase();
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
};

#endif

