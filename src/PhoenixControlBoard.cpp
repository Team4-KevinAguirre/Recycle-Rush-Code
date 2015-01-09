#include <PhoenixControlBoard.h>

/// Constructor for Phoenix Control Board
PhoenixControlBoard::PhoenixControlBoard(Joystick* DriveJoystick, Joystick* OperatorJoystick)
//	:
//	m_PreviousAuto(false)
{
	m_Constants = Constants::GetInstance();
	m_DriveJoystick = DriveJoystick;
	m_OperatorJoystick = OperatorJoystick;

}


float PhoenixControlBoard::GetDriveAxis(unsigned int axis){

	return (m_DriveJoystick->GetRawAxis(axis));
}

bool PhoenixControlBoard::GetDriveButton(unsigned int button){
	return (m_DriveJoystick->GetRawButton(button));
}

float PhoenixControlBoard::GetOperatorAxis(unsigned int axis){
	return (m_OperatorJoystick->GetRawAxis(axis));
}

bool PhoenixControlBoard::GetOperatorButton(unsigned int button){
	return (m_OperatorJoystick->GetRawButton(button));
}

/// Returns state of shifter switch
//float PhoenixControlBoard::GetDriveAxis(unsigned int axis)
//{
//	return m_DriveStick->GetRawAxis(axis);
//}
//
///// Returns state of autonomous select button
//bool PhoenixControlBoard::GetAutoSelectButton()
//{
//	if(GetDriveButton(AUTON_BUTTON) && !m_PreviousAuto)
//	{
//		m_PreviousAuto = GetDriveButton(AUTON_BUTTON);
//		return true;
//	}
//	m_PreviousAuto = GetDriveButton(AUTON_BUTTON);
//	return false;
//}
//
//
///// Returns the state of the quick turn
//bool PhoenixControlBoard::GetQuickTurn()
//{
//	return !GetDriveButton(8);
//}
//
//float PhoenixControlBoard::GetDriveStickY()
//{
//	return m_DriveStick->GetRawAxis(LEFT_GAMEPAD_Y);
//}
//
//float PhoenixControlBoard::GetSteeringX()
//{
//	return m_DriveWheel->GetRawAxis(STEERING_X);
//}
//
//bool PhoenixControlBoard::GetDriveButton(const int button)
//{
//	return m_DriveStick->GetRawButton(button);
//}
//
//bool PhoenixControlBoard::GetOperatorButton(const int button)
//{
//	return m_OperatorPanel->GetRawButton(button);
//}
//
//bool PhoenixControlBoard::GetSteeringButton(const int button)
//{
//	return m_DriveWheel->GetRawButton(button);
//}
