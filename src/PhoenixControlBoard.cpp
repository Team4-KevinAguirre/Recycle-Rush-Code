#include <PhoenixControlBoard.h>

/// Constructor for Phoenix Control Board
PhoenixControlBoard::PhoenixControlBoard(Joystick* DriveJoystick, Joystick* OperatorJoystick)
//	:
//	m_PreviousAuto(false)
{
	Constants_ = Constants::GetInstance();
	DriveJoystick_ = DriveJoystick;
	OperatorJoystick_ = OperatorJoystick;

}


float PhoenixControlBoard::GetDriveAxis(unsigned int axis){

	return (DriveJoystick_->GetRawAxis(axis));
}

bool PhoenixControlBoard::GetDriveButton(unsigned int button){
	return (DriveJoystick_->GetRawButton(button));
}

float PhoenixControlBoard::GetOperatorAxis(unsigned int axis){
	return (OperatorJoystick_->GetRawAxis(axis));
}

bool PhoenixControlBoard::GetOperatorButton(unsigned int button){
	return (OperatorJoystick_->GetRawButton(button));
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
