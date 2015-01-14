#include "RobotName.h"

RobotName::RobotName()

{
	Constants_ = Constants::GetInstance();

	//Motors
	leftDriveMotorA_ = new Talon((int)Constants_->PWM_LEFT_DRIVE_A);
	leftDriveMotorB_ = new Talon((int)Constants_->PWM_LEFT_DRIVE_B);
	rightDriveMotorA_ = new Talon((int)Constants_->PWM_RIGHT_DRIVE_A);
	rightDriveMotorB_ = new Talon((int)Constants_->PWM_RIGHT_DRIVE_B);

	//Joysticks
	DriverJoystick_ = new Joystick((int)Constants_->JOY_PORT_DRIVE);
	OperatorJoystick_ = new Joystick((int)Constants_->JOY_PORT_OPERATOR);

	//Control Board
	ControlBoard_ = new PhoenixControlBoard(DriverJoystick_, OperatorJoystick_);


	//Subsystems
	Drive_ = new Drive(leftDriveMotorA_, leftDriveMotorB_, rightDriveMotorA_, rightDriveMotorB_);



}

void RobotName::ResetMotors()
{

}

void RobotName::RobotInit()
{
}

void RobotName::DisabledInit()
{

}

void RobotName::AutonomousInit()
{

}
void RobotName::TeleopInit()
{

}

void RobotName::DisabledContinuous()
{

}

void RobotName::AutonomousContinuous()
{

}

void RobotName::TeleopContinuous()
{

}

void RobotName::DisabledPeriodic()
{

}
void RobotName::AutonomousPeriodic()
{

}
void RobotName::TeleopPeriodic()
{


}
