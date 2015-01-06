//Declaration File for Drive Base
//This is where we define everything.
#include "DriveBase.h"

DriveBase::DriveBase(){

	m_Constants = Constants::GetInstance();

	m_RightDriveMotor = new Talon(m_Constants->PWM_RIGHT_DRIVE_A);
	m_LeftDriveMotor = new Talon(m_Constants->PWM_LEFT_DRIVE_A);

	m_leftDriveValue = 0.0;
	m_rightDriveValue = 0.0;
}


DriveBase::~DriveBase(){
	delete m_RightDriveMotor;
	delete m_LeftDriveMotor;
}

void DriveBase::DriveSpeedTurn(float speed, float turn, bool quickTurn){
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

void DriveBase::SetLeftMotors(float val){

	if(val < -1.0)
		val = -1.0;
	else if(val > 1.0)
		val = 1.0;

	m_LeftDriveMotor->Set(-val);
}
void DriveBase::SetRightMotors(float val){

	if(val < -1.0)
		val = -1.0;
	else if(val > 1.0)
		val = 1.0;

	m_RightDriveMotor->Set(val);
}

void DriveBase::DriveLeftRight(float leftDriveValue, float rightDriveValue){

	if(leftDriveValue > -1.0 && leftDriveValue < 1.0)
			if((rightDriveValue > -1.0 && rightDriveValue < 1.0)){
				m_leftDriveValue = leftDriveValue;
				m_rightDriveValue = rightDriveValue;
			}
}



void DriveBase::DriveWithHeading(double heading, double speed);

bool DriveBase::DriveDistanceWithHeading(double heading, double distance);

double DriveBase::GetDriveDistance();

