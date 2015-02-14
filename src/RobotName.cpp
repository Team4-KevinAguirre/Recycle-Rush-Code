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
	Compressor_ = new Compressor(); //(int)Constants_->COMPRESSOR_CAN_PORT

	//Sensors
	DriveGyro_ = new RelativeGyro((int)Constants_->GYRO_DRIVE);
	LeftDriveEncoder_ = new Encoder((int)Constants_->ENCODER_LEFT_DRIVE_A, (int)Constants_->ENCODER_LEFT_DRIVE_B);
	RightDriveEncoder_ = new Encoder((int)Constants_->ENCODER_RIGHT_DRIVE_A, (int)Constants_->ENCODER_RIGHT_DRIVE_B);
	//LeftDriveEncoder_ = new Encoder(0, 1, false, Encoder::k4X);
	//RightDriveEncoder_ = new Encoder(2, 3, false, Encoder::k4X);

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
	Drive_->ResetEncoders();
	Drive_->resetAbsoluteGyro();

}

void RobotName::AutonomousInit()
{

}
void RobotName::TeleopInit()
{
	Drive_->ResetGyro();
	Drive_->ResetEncoders();
	Compressor_->Start(); //This will keep the compressor fully charged at all points in time.
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

if(ControlBoard_->GetDriveButton(Constants_->JOY_BUTTON_Y)){
//	Drive_->ResetEncoders();
	Drive_->ResetGyro();
}

//	//Drive Commands
	if(ControlBoard_->GetDriveButton(Constants_->JOY_BUTTON_START))
		isTankDrive = !isTankDrive;
	if(isTankDrive)
		Drive_->SetLinearPower(ControlBoard_->GetDriveAxisFilterTopBottomTrim(Constants_->JOY_AXIS_LJ_Y,0.05,0.05), ControlBoard_->GetDriveAxisFilterTopBottomTrim(Constants_->JOY_AXIS_RJ_Y, 0.05, 0.05));
	else
		Drive_->DriveSpeedTurn(ControlBoard_->GetDriveAxisFilterCubic(Constants_->JOY_AXIS_LJ_Y, 0.5),ControlBoard_->GetDriveAxisFilterCubic(Constants_->JOY_AXIS_RJ_X, 0.75),ControlBoard_->GetDriveButton(Constants_->JOY_BUTTON_RB));
		Drive_->GetGyroAngle();
	if(ControlBoard_->GetDriveButton(Constants_->JOY_BUTTON_A))
		Drive_->DriveWithHeading(0,0);
//	SmartDashboard::PutNumber("R:get",RightDriveEncoder_->Get());
//SmartDashboard::PutNumber("R:raw",RightDriveEncoder_->GetRaw());
//SmartDashboard::PutNumber("R:dist",RightDriveEncoder_->GetDistance());
//SmartDashboard::PutNumber("R:period",RightDriveEncoder_->GetPeriod());
//SmartDashboard::PutNumber("R:rate",RightDriveEncoder_->GetRate());
//SmartDashboard::PutBoolean("R:Dir", RightDriveEncoder_->GetDirection());
	//SmartDashboard::PutNumber("l:", Drive_->GetLeftEncoderDistance());
//SmartDashboard::PutNumber("r:", Drive_->GetRightEncoderDistance());

/**
 * Every robot function shall be placed here for convenience sake, so we have a comprehensive list of all robot functions.
 */

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
