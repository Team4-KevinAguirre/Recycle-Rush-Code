#include "RobotName.h"

RobotName::RobotName()

{
	Constants_ = Constants::GetInstance();

	//Motors

	LeftDriveMotorA_ = new VictorSP((int)Constants_->PWM_LEFT_DRIVE_A);
	LeftDriveMotorB_ = new VictorSP((int)Constants_->PWM_LEFT_DRIVE_B);
	RightDriveMotorA_ = new VictorSP((int)Constants_->PWM_RIGHT_DRIVE_A);
	RightDriveMotorB_ = new VictorSP((int)Constants_->PWM_RIGHT_DRIVE_B);

	LeftIntakeMotor_ = new VictorSP((int)Constants_->PWM_LEFT_INTAKE);
	RightIntakeMotor_ = new VictorSP((int)Constants_->PWM_RIGHT_INTAKE);
	//Sensors
	DriveGyro_ = new RelativeGyro((int)Constants_->GYRO_DRIVE);
	LeftDriveEncoder_ = new Encoder((int)Constants_->ENCODER_LEFT_DRIVE_A, (int)Constants_->ENCODER_LEFT_DRIVE_B);
	RightDriveEncoder_ = new Encoder((int)Constants_->ENCODER_RIGHT_DRIVE_A, (int)Constants_->ENCODER_RIGHT_DRIVE_B);

	//Joysticks
	DriverJoystick_ = new Joystick((int)Constants_->JOY_PORT_DRIVE);
	OperatorJoystick_ = new Joystick((int)Constants_->JOY_PORT_OPERATOR);

	//Control Board
	ControlBoard_ = new PhoenixControlBoard(DriverJoystick_, OperatorJoystick_);


	//Subsystems
	Drive_ = new Drive(LeftDriveMotorA_, LeftDriveMotorB_, RightDriveMotorA_, RightDriveMotorB_, DriveGyro_, LeftDriveEncoder_, RightDriveEncoder_);
	Intake_ = new Intake(LeftIntakeMotor_, RightIntakeMotor_);


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
Drive_->resetAbsoluteGyro();
//Absolute Reset gyro once per teleop
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
Drive_->resetAbsoluteGyro();
//Absolute Reset Gyro periodically
}
void RobotName::AutonomousPeriodic()
{

}
void RobotName::TeleopPeriodic()
{
	Drive_->DriveSpeedTurn(ControlBoard_->GetDriveAxis(Constants_->JOY_AXIS_LJ_Y),ControlBoard_->GetDriveAxis(Constants_->JOY_AXIS_LJ_X),ControlBoard_->GetDriveButton(Constants_->JOY_BUTTON_RB));
//	//Drive Stuff up here
	//Drive_->SetLinearPower(ControlBoard_->GetDriveAxis(Constants_->JOY_AXIS_LJ_Y), ControlBoard_->GetDriveAxis(Constants_->JOY_AXIS_RJ_Y));
//	//Tank drive
//
//	Drive_->rotateDrive(ControlBoard_->GetDriveAxis(Constants_->JOY_AXIS_L_TRIGGER));
//	//TODO: Just this doesn't support using both triggers.  Make sure that L_TRIGGER works in 2015 Mapping, and if so, subtract L-R.
//
//	Drive_->rotateAbsoluteDrive(ControlBoard_->GetDrivePOV());
//	//Should take user POV (D-PAD input).  When pressed, the robot will rotate to where it was absolutely zero'd.
//
//	Intake_->SetIntakeMotorsLinear(ControlBoard_->GetOperatorAxis(Constants_->JOY_AXIS_LJ_Y));
//
//	Intake_->SetIntakeMotorsRotate(ControlBoard_->GetOperatorAxis(Constants_->JOY_AXIS_RJ_X));
}
