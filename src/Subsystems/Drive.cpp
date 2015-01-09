//Declaration File for Drive Base
//This is where we define everything.
#include <Subsystems/Drive.h>

Drive::Drive(Talon* LeftDriveMotorA, Talon* RightDriveMotorA, Encoder* LeftDriveEncoder, Encoder* RightDriveEncoder){

	m_Constants = Constants::GetInstance();

	m_LeftDriveMotor = LeftDriveMotorA;
	m_RightDriveMotor = RightDriveMotorA;

	m_LeftDriveEncoder = LeftDriveEncoder;
	m_RightDriveEncoder = RightDriveEncoder;

	m_leftDriveValue = 0.0;
	m_rightDriveValue = 0.0;
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

		DriveLeftRight(left_power, right_power);
}

void Drive::SetLeftMotors(float val){

	if(val < -1.0)
		val = -1.0;
	else if(val > 1.0)
		val = 1.0;

	m_LeftDriveMotor->Set(-val);
}

void Drive::SetRightMotors(float val){

	if(val < -1.0)
		val = -1.0;
	else if(val > 1.0)
		val = 1.0;

	m_RightDriveMotor->Set(val);
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

	return (m_LeftDriveEncoder->Get()/ clicksPerRotation /gearRatioToWheel * wheelSize * m_Constants->PI);
}

double Drive::GetRightEncoderDistance(){
	  // Number of clicks read by encoder / number of clicks per rotation * gear ratio from encoder to wheel *
	  // wheel circumference
	//TODO: Make sure this is correct
	double clicksPerRotation = 256.0;
	double gearRatioToWheel = 3.5;
	double wheelSize = 6.0;

	return (-m_RightDriveEncoder->Get()/ clicksPerRotation /gearRatioToWheel * wheelSize * m_Constants->PI);
}

void Drive::ResetEncoders() {
	m_LeftDriveEncoder->Reset();
	m_RightDriveEncoder->Reset();
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
