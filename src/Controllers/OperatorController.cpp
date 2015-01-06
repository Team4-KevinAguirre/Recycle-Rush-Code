#include "OperatorController.h"

OperatorController::OperatorController(PhoenixControlBoard* controlboard)
//	:
//	m_PreviousFire(false),
//	m_PreviousFullBack(false),
//	m_PreviousHalfBack(false)
{
	m_CB = new PhoenixControlBoard();
	m_Constants = Constants::GetInstance();
}

void OperatorController::handle(PhoenixRobot* bot)
{

	if(m_CB->GetDriveAxis(m_Constants->JOY_BUTTON_A))
		bot->DriveSpeedTurn(m_CB->GetDriveAxis(m_Constants->JOY_AXIS_LJ_Y),m_CB->GetDriveAxis(m_Constants->JOY_AXIS_RJ_X),m_CB->GetDriveButton(m_Constants->JOY_BUTTON_RB));


	//printf("Controlling...\n");
//	bot->DriveSpeedTurn(m_CB->GetDriveStickY(), m_CB->GetSteeringX(), m_CB->GetSteeringButton(FAST_TURN));
//
//	double frontIntakeSpeed = 0;
//	if(m_CB->GetOperatorButton(INTAKE_FRONT)) //Intake front
//	{
//		frontIntakeSpeed = -CONSTANT("IntakeSpeed");
//	}
//	else if(m_CB->GetOperatorButton(EXHAUST_FRONT))
//	{
//		frontIntakeSpeed = CONSTANT("IntakeSpeed");
//	}
//	bot->FrontIntake(-frontIntakeSpeed, m_CB->GetOperatorButton(9));
//
//	double rearIntakeSpeed = 0;
//	if(m_CB->GetOperatorButton(INTAKE_REAR))
//	{
//		bot->WinchHoldVoltage(CONSTANT("ExhaustSetpoint"));
//		rearIntakeSpeed = -CONSTANT("IntakeSpeed");https://
//	}
//	else if(m_CB->GetOperatorButton(EXHAUST_REAR)) //Exhaust rear
//	{
//		rearIntakeSpeed = CONSTANT("IntakeSpeed");
//	}
//	bot->RearIntake(-rearIntakeSpeed, m_CB->GetOperatorButton(7));
//
//	if(m_CB->GetOperatorButton(6) && !m_PreviousFire)
//	{
//		bot->ForceFire();
//	}
//	m_PreviousFire = m_CB->GetOperatorButton(6);
//
//	if(m_CB->GetOperatorButton(8) && !m_PreviousHalfBack)
//	{
//		bot->ChangeWinchSetpoint(CONSTANT("HalfBackSetpoint"));
//	}
//	m_PreviousHalfBack = m_CB->GetOperatorButton(8);
//
//	if(m_CB->GetOperatorButton(FAR) && !m_PreviousFullBack)
//	{
//		bot->AutoSettle();
//		//bot->ChangeWinchSetpoint(CONSTANT("FullBackSetpoint"));
//	}
//	m_PreviousFullBack = m_CB->GetOperatorButton(FAR);
//
//	if(m_CB->GetDriveButton(1))
//	{
//		bot->WinchDespring();
//	}
}

