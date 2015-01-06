#include "PhoenixBase.h"

PhoenixBase::PhoenixBase()

{
	m_Bot = new PhoenixRobot();
	m_ControlBoard = new PhoenixControlBoard();
	m_OpController = new OperatorController(m_ControlBoard);
	m_Constants = Constants::GetInstance();
	//	SetPeriod(HZ(ROBOT_HZ));
//	GetWatchdog().SetEnabled(false);
//	printf("Done constructing PhoenixBase!\n");
}

void PhoenixBase::RobotInit()
{
}

void PhoenixBase::DisabledInit()
{
//	m_Constants->RestoreData();
}

void PhoenixBase::AutonomousInit()
{
//	m_Bot->GyroFinalizeCalibration();
//
//	m_AutoController->SetCommandList(AutoModes::GetInstance()->GetCommandList());
//	m_Bot->SetController(m_AutoController);
//	m_Bot->Reset();
//
//	m_Bot->SetWinchState(Winch::READY_TO_FIRE);
	//m_WinchState = Winch::READY_TO_FIRE;
}
void PhoenixBase::TeleopInit()
{
	m_Bot->SetController(m_OpController);
//	m_Bot->Reset();

	//m_Bot->SetWinchState(m_WinchState);
	//m_WinchState = Winch::READY_TO_FIRE;
}

void PhoenixBase::DisabledContinuous()
{
//	taskDelay(WAIT_FOREVER);
}

void PhoenixBase::AutonomousContinuous()
{
//	taskDelay(WAIT_FOREVER);
}

void PhoenixBase::TeleopContinuous()
{
//	taskDelay(WAIT_FOREVER);
}

void PhoenixBase::DisabledPeriodic()
{
//	m_Bot->GyroHandleCalibration();
//
//	if(m_ControlBoard->GetAutoSelectButton())
//	{
//		if(m_ControlBoard->GetDriveButton(3))
//		{
//			m_Bot->Reset();
//			m_Constants->RestoreData();
//			AutoModes::GetInstance()->NextMode();
//		}
//		else
//		{
//			m_Bot->GyroFinalizeCalibration();
//		}
//	}
//
//	m_Bot->PrintToDS();
}
void PhoenixBase::AutonomousPeriodic()
{
//	m_Bot->PrintToDS();
//	m_Bot->handle();
}
void PhoenixBase::TeleopPeriodic()
{
//	if(m_ControlBoard->GetAutoSelectButton())
//	{
//		m_Bot->Reset();
//		m_Constants->RestoreData();
//	}
//
//	m_Bot->PrintToDS();
	m_Bot->handle();
}

START_ROBOT_CLASS(PhoenixBase);
