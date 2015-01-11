//Declaration File for Drive Base
//This is where we define everything.
#include <Subsystems/Drive.h>

Drive::Drive(Talon* LeftDriveMotorA, Talon* RightDriveMotorA, Encoder* LeftDriveEncoder, Encoder* RightDriveEncoder, Gyro* Gyro, DigitalInput* LimitSwitchMain){

	Constants_ = Constants::GetInstance();

	LeftDriveMotor_ = LeftDriveMotorA;
	RightDriveMotor_ = RightDriveMotorA;

	LeftDriveEncoder_ = LeftDriveEncoder;
	RightDriveEncoder_ = RightDriveEncoder;

	GyroDrive_ = Gyro;

	LimitSwitchMain_ = LimitSwitchMain;

	m_leftDriveValue = 0.0;
	m_rightDriveValue = 0.0;
}



void Drive::TankDrive(float left, float right, float joyValue) {
	LeftDriveMotor_->Set(-left);
	RightDriveMotor_->Set(right);

	if (LimitSwitchMain_->Get()){
		(Constants_->JOY_PORT_DRIVE);
	}
}

void Drive::DriveSpeedTurn(float speed, float turn, bool quickTurn){
	float temp_vel = speed;
		float sensitivity = 0;
		//float unscaled_turn = 0;
		if (temp_vel < 0)
			temp_vel = -temp_vel;

		//printf("Velocity: %f, stick: %f\r\n", velocity, temp_vel);

		if(speed < 0.10 && speed > -0.10)
			speed = 0;
		if ((turn < 0.10 && turn > -0.10) || (speed == 0 && !quickTurn))
			turn = 0;

		//unscaled_turn = turn;

		if(quickTurn)
			sensitivity = 1;
		else
			sensitivity = 0.4;

		turn *= sensitivity;
		turn = -turn;

		float left_power = PhoenixLib::LimitMix(speed + turn);
		float right_power = PhoenixLib::LimitMix(speed - turn);
		SmartDashboard::PutNumber("GyroNum", GyroDrive_->GetAngle());

		SetLinearPower(left_power, right_power);
}

void Drive::SetLeftMotors(float val){

	if(val < -1.0)
		val = -1.0;
	else if(val > 1.0)
		val = 1.0;

	LeftDriveMotor_->Set(-val);
}

void Drive::SetRightMotors(float val){

	if(val < -1.0)
		val = -1.0;
	else if(val > 1.0)
		val = 1.0;

	RightDriveMotor_->Set(val);
}

void Drive::DriveLeftRight(float leftDriveValue, float rightDriveValue){

	if(leftDriveValue > -1.0 && leftDriveValue < 1.0)
			if((rightDriveValue > -1.0 && rightDriveValue < 1.0)){
				m_leftDriveValue = leftDriveValue;
				m_rightDriveValue = rightDriveValue;
			}
}

double Drive::GetLeftEncoderDistance(){
	  // Number of clicks read by encoder / number of clicks per rotation * gear ratio from encoder to wheel *
	  // wheel circumference
	//TODO: Make sure this is correct
	double clicksPerRotation = 256.0;
	double gearRatioToWheel = 3.5;
	double wheelSize = 6.0;

	return (LeftDriveEncoder_->Get()/ clicksPerRotation /gearRatioToWheel * wheelSize * Constants_->PI);
}

double Drive::GetRightEncoderDistance(){
	  // Number of clicks read by encoder / number of clicks per rotation * gear ratio from encoder to wheel *
	  // wheel circumference
	//TODO: Make sure this is correct
	double clicksPerRotation = 256.0;
	double gearRatioToWheel = 3.5;
	double wheelSize = 6.0;

	return (-RightDriveEncoder_->Get()/ clicksPerRotation /gearRatioToWheel * wheelSize * Constants_->PI);
}

void Drive::ResetEncoders() {
	LeftDriveEncoder_->Reset();
	RightDriveEncoder_->Reset();
}

void Drive::ResetGyro() {
	GyroDrive_->Reset();
}

void Drive::SetLinearPower(double leftPower, double rightPower){
	SetLeftMotors(leftPower);
	SetRightMotors(rightPower);
}

void Drive::DriveWithHeading(double heading, double speed){
return;
}

bool Drive::DriveDistanceWithHeading(double heading, double distance){
return true;
}

double Drive::GetDriveDistance(){
return 1.0;
}
