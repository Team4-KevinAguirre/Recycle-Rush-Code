#include <RobotName.h>

RobotName::RobotName()

{
	Constants_ = Constants::GetInstance();

	//Motors
	LeftDriveMotorA_ = new Talon(Constants_->PWM_LEFT_DRIVE_A);
	RightDriveMotorA_ = new Talon(Constants_->PWM_RIGHT_DRIVE_A);

	//Sensors
	LeftDriveEncoder_ = new Encoder((int)Constants_->ENCODER_LEFT_DRIVE_A, (int)Constants_->ENCODER_LEFT_DRIVE_B);
	RightDriveEncoder_ = new Encoder((int)Constants_->ENCODER_RIGHT_DRIVE_A, (int)Constants_->ENCODER_RIGHT_DRIVE_B);

	//Pneumatics



	//Joysticks
	DriverJoystick_ = new Joystick(Constants_->JOY_PORT_DRIVE);
	OperatorJoystick_ = new Joystick(Constants_->JOY_PORT_OPERATOR);

	//Control Board
	ControlBoard_ = new PhoenixControlBoard(DriverJoystick_, OperatorJoystick_);



	//Subsystems
	Drive_ = new Drive(LeftDriveMotorA_, RightDriveMotorA_, LeftDriveEncoder_, RightDriveEncoder_);

	// Drivers
	TeleopDriver_ = new TeleopDriver(Drive_,ControlBoard_);
	CurrDriver_ = TeleopDriver_;


	  prevLeftDist_ = 0.0;
	  prevRightDist_ = 0.0;
	  prevTime = 0.0;
}

void RobotName::ResetMotors()
{
	Drive_->SetLinearPower(0,0);
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
	Constants_->LoadFile();
	ResetMotors();
	//Drive_base->ResetGyro();
	Drive_->ResetEncoders();


	  prevLeftDist_ = 0.0;
	  prevRightDist_ = 0.0;
	  prevTime = 0.0;
	  CurrDriver_ = TeleopDriver_;
	  CurrDriver_->Reset();
//	  timer_->Reset();

	  //target_->SetUseSkew(true);
	  //lightDelay_->Start();



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
