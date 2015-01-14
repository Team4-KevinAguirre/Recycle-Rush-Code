#include "RobotName.h"

RobotName::RobotName()

{
	Constants_ = Constants::GetInstance();

	//Motors

	LeftDriveMotorA_ = new Talon((int)Constants_->PWM_LEFT_DRIVE_A);
	LeftDriveMotorB_ = new Talon((int)Constants_->PWM_LEFT_DRIVE_B);
	RightDriveMotorA_ = new Talon((int)Constants_->PWM_RIGHT_DRIVE_A);
	RightDriveMotorB_ = new Talon((int)Constants_->PWM_RIGHT_DRIVE_B);

	//Sensors
	DriveGyro_ = new RelativeGyro((int)Constants_->GYRO_DRIVE);

	//Joysticks
	DriverJoystick_ = new Joystick((int)Constants_->JOY_PORT_DRIVE);
	OperatorJoystick_ = new Joystick((int)Constants_->JOY_PORT_OPERATOR);

	//Control Board
	ControlBoard_ = new PhoenixControlBoard(DriverJoystick_, OperatorJoystick_);


	//Subsystems
	Drive_ = new Drive(LeftDriveMotorA_, LeftDriveMotorB_, RightDriveMotorA_, RightDriveMotorB_, DriveGyro_);



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
	//Drive Stuff up here
	Drive_->setLinearPower(ControlBoard_->GetDriveAxis(Constants_->JOY_AXIS_LJ_Y), ControlBoard_->GetDriveAxis(Constants_->JOY_AXIS_RJ_Y));
	//Tank drive

}
