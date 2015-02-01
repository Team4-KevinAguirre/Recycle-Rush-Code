#include <PhoenixControlBoard.h>

/// Constructor for Phoenix Control Board
PhoenixControlBoard::PhoenixControlBoard(Joystick* DriveJoystick, Joystick* OperatorJoystick)

{
	Constants_ = Constants::GetInstance();
	DriveJoystick_ = DriveJoystick;
	OperatorJoystick_ = OperatorJoystick;

}


float PhoenixControlBoard::GetDriveAxis(int axis){
	return DriveJoystick_->GetRawAxis(axis);
}

float PhoenixControlBoard::GetDriveAxisFilterTopBottomTrim(int axis, double botTrim, double topTrim){
	float rawInput = DriveJoystick_->GetRawAxis(axis);

	if(botTrim == 1 || topTrim == 1 || (1-botTrim-topTrim) == 0 || (botTrim + topTrim) >= 1)
		return rawInput;
	else
		return(1/(1-botTrim-topTrim)*(rawInput - botTrim));

}

float PhoenixControlBoard::GetDriveAxisFilterCubic(int axis, double a) {
	float rawInput = DriveJoystick_->GetRawAxis(axis);
	if(a < 0 || a > 1)
		return rawInput;

	float rawInputCubed = rawInput * rawInput * rawInput;
	return a*rawInputCubed + (1-a)*rawInput;
}

bool PhoenixControlBoard::GetDriveButton(int button){

	return (DriveJoystick_->GetRawButton(button));
}

float PhoenixControlBoard::GetDrivePOV(int button){
	return (DriveJoystick_->GetPOV(button));
}

float PhoenixControlBoard::GetOperatorAxis(int axis){
	return (OperatorJoystick_->GetRawAxis(axis));
}

float PhoenixControlBoard::GetOperatorAxisFilterTopBottomTrim(int axis, double botTrim, double topTrim){
	float rawInput = OperatorJoystick_->GetRawAxis(axis);

	if(botTrim == 1 || topTrim == 1 || (1-botTrim-topTrim) == 0 || (botTrim + topTrim) >= 1)
		return rawInput;
	else
		return(1/(1-botTrim-topTrim)*(rawInput - botTrim));

}

float PhoenixControlBoard::GetOperatorAxisFilterCubic(int axis, double a) {
	float rawInput = OperatorJoystick_->GetRawAxis(axis);
	if(a < 0 || a > 1)
		return rawInput;

	float rawInputCubed = rawInput * rawInput * rawInput;
	return a*rawInputCubed + (1-a)*rawInput;
}

bool PhoenixControlBoard::GetOperatorButton(int button){
	return (OperatorJoystick_->GetRawButton(button));
}

float PhoenixControlBoard::GetOperatorPOV(int button){
	return (OperatorJoystick_->GetPOV(button));
	}
