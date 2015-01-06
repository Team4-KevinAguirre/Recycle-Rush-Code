//==================================================
// Copyright (C) 2014 Team 1538 / The Holy Cows
//==================================================

#ifndef __PHOENIX_ROBOT_H__
#define __PHOENIX_ROBOT_H__


#include <WPILib.h>
#include "Controllers/GenericController.h"
#include "Config/Constants.h"
#include "PhoenixLib/PhoenixLib.h"
#include "Subsystems/DriveBase.h"
//#include "Subsystems/Intake.h"
//#include "Subsystems/Winch.h"
//#include "CowLib/CowLib.h"
//#include "CowControlBoard.h"
//#include "CounterBase.h"
//#include "CowConstants.h"

class PhoenixRobot
{

private:
//	int m_DSUpdateCount;

	GenericController* m_Controller;

	Constants* m_Constants;
	//Drive Motors
	Talon* m_RightDriveA;
	Talon* m_LeftDriveA;
	DriveBase* m_Drive;

	float m_leftDriveValue;
	float m_rightDriveValue;
//
//	Relay* m_Compressor;
//	DigitalInput* m_PressureSwitch;
//
//	Intake* m_FrontIntake;
//
//	Intake* m_RearIntake;
//	Winch* m_Winch;
//
//	CowLib::CowGyro* m_Gyro;
//	Encoder* m_DriveEncoder;
//	AnalogChannel* m_FrontIR; //  // TODO: front and rear are named backwards, fix
//	AnalogChannel* m_RearIR;
//
//	KinectStick* m_KinectLeftArm;
//	KinectStick* m_KinectRightArm;
//
//	float m_LeftDriveValue;
//	float m_RightDriveValue;
//
//	double m_FrontIntakeSpeed;
//	bool m_FrontIntakeState;
//	double m_RearIntakeSpeed;
//	bool m_RearIntakeState;
//
//	double m_BallAdjustTime;
//	e_FiringState m_FiringState;
//	e_SettlingState m_SettlingState;
//	double m_BallSettledTime;
//
//	double m_PreviousGyroError;
//	double m_PreviousDriveError;
//
	void SetLeftMotors(float val);
	void SetRightMotors(float val);
public:
	PhoenixRobot();
//	void Reset();
//	void GyroHandleCalibration();
//	void GyroFinalizeCalibration();
	void SetController(GenericController* controller);
//	void PrintToDS();
//	double GetDriveDistance();
//	bool DriveDistanceWithHeading(double heading, double distance);
//	bool DriveWithHeading(double heading, double speed);
//	void SetFrontIntakeState(bool state);
//	void SetRearIntakeState(bool State);
//	void FrontIntake(double speed, bool state);
//	void RearIntake(double speed, bool state);
//	void SetWinchState(Winch::e_WinchState state);
//	void AskForFire();
//	void ForceFire();
//	bool ReadyToFire();
//	bool Reloading();
//	bool ChangeWinchSetpoint(double setpoint);
//	void WinchHoldVoltage(double setpoint);
//	void WinchDespring();
	void DriveSpeedTurn(float speed, float turn, bool quickTurn);
	void DriveLeftRight(float leftDriveValue, float rightDriveValue);
//	void QuickTurn(float turn);
//	double KinectLeftRight();
//	double GetFrontIR();
//	double GetRearIR();
//	void AutoSettle();
//	e_SettlingState GetSettledState();
//
	void handle();
};

#endif
