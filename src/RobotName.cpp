#include <RobotName.h>

RobotName::RobotName()

{
	m_Constants = Constants::GetInstance();

	//Motors
	m_LeftDriveMotorA = new Talon(m_Constants->PWM_LEFT_DRIVE_A);
	m_RightDriveMotorA = new Talon(m_Constants->PWM_RIGHT_DRIVE_A);

	//Sensors
	m_LeftDriveEncoder = new Encoder((int)m_Constants->ENCODER_LEFT_DRIVE_A, (int)m_Constants->ENCODER_LEFT_DRIVE_B);
	m_RightDriveEncoder = new Encoder((int)m_Constants->ENCODER_RIGHT_DRIVE_A, (int)m_Constants->ENCODER_RIGHT_DRIVE_B);

	//Pneumatics


	//Joysticks
	m_DriverJoystick = new Joystick(m_Constants->JOY_PORT_DRIVE);
	m_OperatorJoystick = new Joystick(m_Constants->JOY_PORT_OPERATOR);

	//Control Board
	m_ControlBoard = new PhoenixControlBoard(m_DriverJoystick, m_OperatorJoystick);

	//Subsystems
	m_Drivebase = new DriveBase(m_LeftDriveMotorA, m_RightDriveMotorA, m_LeftDriveEncoder, m_RightDriveEncoder);
}

void RobotName::ResetMotors()
{
	m_Drivebase->SetLinearPower(0,0);
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
	m_Constants->LoadFile();
	ResetMotors();
	//m_Drivebase->ResetGyro();
	m_Drivebase->ResetEncoders();


	  prevLeftDist_ = 0.0;
	  prevRightDist_ = 0.0;
	  prevTime = 0.0;
//	  currDriver_ = teleopDriver_;
//	  currDriver_->Reset();
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
