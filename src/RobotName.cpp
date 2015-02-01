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

	//Pneumatics
	LeftIntakeArm_ = new DoubleSolenoid((int)Constants_->SOLENOID_LEFT_ARM_FWD,(int)Constants_->SOLENOID_LEFT_ARM_REV);
	RightIntakeArm_ = new DoubleSolenoid((int)Constants_->SOLENOID_RIGHT_ARM_FWD,(int)Constants_->SOLENOID_RIGHT_ARM_REV);
	Compressor_ = new Compressor((int)Constants_->COMPRESSOR_CAN_PORT);
	Compressor_->Start(); //This will keep the compressor fully charged at all points in time.

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
	Intake_ = new Intake(LeftIntakeMotor_, RightIntakeMotor_, LeftIntakeArm_, RightIntakeArm_, Compressor_);

	isTankDrive = false;

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
	//Drive Commands
	if(ControlBoard_->GetDriveButton(Constants_->JOY_BUTTON_START))
	{
		if(isTankDrive)
			isTankDrive = false;
		else
			isTankDrive = true;
	}
	if(isTankDrive)
		Drive_->SetPower(ControlBoard_->GetDriveAxis(Constants_->JOY_AXIS_LJ_Y), ControlBoard_->GetDriveAxis(Constants_->JOY_AXIS_RJ_Y));
	else
		Drive_->DriveSpeedTurn(ControlBoard_->GetDriveAxis(Constants_->JOY_AXIS_LJ_Y),ControlBoard_->GetDriveAxis(Constants_->JOY_AXIS_RJ_X),ControlBoard_->GetDriveButton(Constants_->JOY_BUTTON_RB));
	//Drive_->DriveSpeedTurn(ControlBoard_->GetDriveAxis(Constants_->JOY_AXIS_LJ_Y),ControlBoard_->GetDriveAxis(Constants_->JOY_AXIS_RJ_X),ControlBoard_->GetDriveButton(Constants_->JOY_BUTTON_RB));
	//	Drive_->SetPower(ControlBoard_->GetDriveAxis(Constants_->JOY_AXIS_LJ_Y), ControlBoard_->GetDriveAxis(Constants_->JOY_AXIS_RJ_Y));
//	Drive_->rotateDrive(ControlBoard_->GetDriveAxis(Constants_->JOY_AXIS_L_TRIGGER)); ////TODO: Just this doesn't support using both triggers.  Make sure that L_TRIGGER works in 2015 Mapping, and if so, subtract L-R.
//	Drive_->rotateAbsoluteDrive(ControlBoard_->GetDriveAxis(Constants_->JOY_AXIS_R_TRIGGER)); //TODO: Just this doesn't support using both triggers.  Make sure that L_TRIGGER works in 2015 Mapping, and if so, subtract L-R.
//	Drive_->GetLeftEncoderDistance(); //Need to use smartdashboard.
//	Drive_->GetRightEncoderDistance(); //"       "
//	Drive_->GetGyroAngle(); //Use Smartdashboard
//	Drive_->ResetGyro(); //Use SmartDashboard
//	Drive_->resetAbsoluteGyro(); //Use SmartDashboard
//	Drive_->ResetEncoders(); //Use SmartDashboard
//
//	Intake_->SetIntakeMotors(ControlBoard_->GetDriveButton(Constants_->JOY_BUTTON_X),ControlBoard_->GetDriveButton(Constants_->JOY_BUTTON_B));
//	Intake_->SetIntakeMotorsLinear(ControlBoard_->GetDriveAxis(Constants_->JOY_AXIS_RJ_Y));
//	Intake_->SetIntakeMotorsRotate(ControlBoard_->GetDriveAxis(Constants_->JOY_AXIS_RJ_X));
//	Intake_->SetIntakeArm(ControlBoard_->GetDrivePOV(Constants_->JOY_DPAD_LEFT),ControlBoard_->GetDrivePOV(Constants_->JOY_DPAD_RIGHT),ControlBoard_->GetDriveButton(Constants_->JOY_BUTTON_RB));
}
