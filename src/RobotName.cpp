#include "RobotName.h"

RobotName::RobotName()

{
	Constants_ = Constants::GetInstance();

	//Motors

	LeftIntakeMotor_ = new VictorSP((int)Constants_->PWM_LEFT_INTAKE);
	RightIntakeMotor_ = new VictorSP((int)Constants_->PWM_RIGHT_INTAKE);

	//Pneumatics
	LeftIntakeArm_ = new DoubleSolenoid((int)Constants_->SOLENOID_LEFT_ARM_FWD,(int)Constants_->SOLENOID_LEFT_ARM_REV);
	RightIntakeArm_ = new DoubleSolenoid((int)Constants_->SOLENOID_RIGHT_ARM_FWD,(int)Constants_->SOLENOID_RIGHT_ARM_REV);
	Compressor_ = new Compressor((int)Constants_->COMPRESSOR_CAN_PORT);
	Compressor_->Start(); //This will keep the compressor fully charged at all points in time.

	//Sensors

	//Joysticks
	DriverJoystick_ = new Joystick((int)Constants_->JOY_PORT_DRIVE);
	OperatorJoystick_ = new Joystick((int)Constants_->JOY_PORT_OPERATOR);

	//Control Board
	ControlBoard_ = new PhoenixControlBoard(DriverJoystick_, OperatorJoystick_);

	//Subsystems
	Intake_ = new Intake(LeftIntakeMotor_, RightIntakeMotor_, LeftIntakeArm_, RightIntakeArm_, Compressor_);


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
//	Intake_->SetIntakeMotorsLinear(ControlBoard_->GetOperatorAxis(Constants_->JOY_AXIS_LJ_Y));
//
//	Intake_->SetIntakeMotorsRotate(ControlBoard_->GetOperatorAxis(Constants_->JOY_AXIS_RJ_X));
}
