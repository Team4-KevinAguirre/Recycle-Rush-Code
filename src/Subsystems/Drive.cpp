//Declaration File for Drive Base
//This is where we define everything.
#include "Drive.h"

Drive::Drive(VictorSP* leftDriveMotorA, VictorSP* leftDriveMotorB, VictorSP* rightDriveMotorA, VictorSP* rightDriveMotorB, RelativeGyro* driveGyro, Encoder* leftDriveEncoder, Encoder* rightDriveEncoder){

	Constants_ = Constants::GetInstance();

	//Motors
	LeftDriveMotorA_ = leftDriveMotorA;
	LeftDriveMotorB_ = leftDriveMotorB;

	RightDriveMotorA_ = rightDriveMotorA;
	RightDriveMotorB_ = rightDriveMotorB;

	//Sensors
	DriveGyro_ = driveGyro;
	DriveGyro_->ResetAbsolute();
	LeftDriveEncoder_ = leftDriveEncoder;
	RightDriveEncoder_ = rightDriveEncoder;


	DrivePid_ = new Pid(&Constants_->PID_DRIVE_SPEED_KP, &Constants_->PID_DRIVE_SPEED_KI, &Constants_->PID_DRIVE_SPEED_KD);
	TurnPid_ = new Pid(&Constants_->PID_DRIVE_TURN_KP,&Constants_->PID_DRIVE_TURN_KI, &Constants_->PID_DRIVE_TURN_KD);

	m_PreviousGyroError = 0;
	m_PreviousDriveError = 0;
	m_PrevDistance = 0;

	old_wheel_ = 0;
	quickStopAccumulator_ = 0.0;

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

		if(quickTurn) {
			sensitivity = 1;
			speed = 0;
		}
		else
			sensitivity = 0.4;

		turn *= sensitivity;
		turn = -turn;

		float left_power = speed + turn;
		float right_power = speed - turn;

		SmartDashboard::PutNumber("Drive Left",left_power);
		SmartDashboard::PutNumber("Drive Right", right_power);

		SetLinearPower(left_power, right_power);

}

//void Drive::rotateDrive(float turnIncrement){
//	//TODO: Remove newLeft/newRight because memory waste.  Put in here for ease of reading.
//	float sens = .01;
//	float newLeft = ((LeftDriveMotorA_->Get())+turnIncrement*sens);
//	float newRight = ((RightDriveMotorA_->Get())+turnIncrement*sens);
//	SetLinearPower(newLeft,newRight);
//}

//void Drive::rotateAbsoluteDrive(float rotationAngle){
//	float currAngle = DriveGyro_->GetAngle();
//	float setpointAngle = rotationAngle;
//
//	double power = TurnPid_->Update(setpointAngle, currAngle);
//	SetLinearPower(-power, power);
//}

double Drive::GetLeftEncoderDistance() {

	double leftEncoderDist = LeftDriveEncoder_->GetDistance();
	SmartDashboard::PutNumber("LeftEncoder",leftEncoderDist);
	return(leftEncoderDist);

}

double Drive::GetRightEncoderDistance() {

	double rightEncoderDist = RightDriveEncoder_->GetDistance();
	SmartDashboard::PutNumber("RightEncoder",rightEncoderDist);
	return(rightEncoderDist);
}

double Drive::GetGyroAngle() {
	double angleTurn = DriveGyro_->GetAngle();
	SmartDashboard::PutNumber("Gyro Angle", angleTurn);
	return angleTurn;


}

void Drive::ResetGyro(){
	DriveGyro_->Reset();
}

void Drive::resetAbsoluteGyro(){
	DriveGyro_->ResetAbsolute();
}

void Drive::ResetEncoders() {
	LeftDriveEncoder_->Reset();
	RightDriveEncoder_->Reset();
}

void Drive::SetLinearPower(double leftPower, double rightPower){
	SmartDashboard::PutNumber("Drive_Motor_Left_Power", leftPower);
	SmartDashboard::PutNumber("Drive_Motor_Right_Power", rightPower);

	LeftDriveMotorA_->Set(PwmLimit(-leftPower));
	LeftDriveMotorB_->Set(PwmLimit(-leftPower));
	RightDriveMotorA_->Set(PwmLimit(rightPower));
	RightDriveMotorB_->Set(PwmLimit(rightPower));

}

void Drive::CheesyDrive(double throttle, double wheel, bool quickTurn) {

	  bool isQuickTurn = quickTurn;

	  double wheelNonLinearity;

	  double neg_inertia = wheel - old_wheel_;
	  old_wheel_ = wheel;

	  double m_PI = 3.141592;

	    wheelNonLinearity = Constants_->turnNonlinHigh;
	    // Apply a sin function that's scaled to make the turning feel better.
	    wheel = sin(m_PI / 2.0 * wheelNonLinearity * wheel) / sin(M_PI / 2.0 * wheelNonLinearity);
	    wheel = sin(m_PI / 2.0 * wheelNonLinearity * wheel) / sin(M_PI / 2.0 * wheelNonLinearity);

	  double left_pwm, right_pwm, overPower;
	  float sensitivity = 1.7;

	  float angular_power;
	  float linear_power;

	  // Negative inertia!
	  static double neg_inertia_accumulator = 0.0;
	  double neg_inertia_scalar;

	  neg_inertia_scalar = Constants_->negInertia;

	    sensitivity = Constants_->sensitivity;

	    if (fabs(throttle) > Constants_->senseCutoff) {
	      sensitivity = 1 - (1 - sensitivity) / fabs(throttle);
	    }
	  double neg_inertia_power = neg_inertia * neg_inertia_scalar;
	  neg_inertia_accumulator += neg_inertia_power;

	  wheel = wheel + neg_inertia_accumulator;
	  if(neg_inertia_accumulator > 1)
	    neg_inertia_accumulator -= 1;
	  else if (neg_inertia_accumulator < -1)
	    neg_inertia_accumulator += 1;
	  else
	    neg_inertia_accumulator = 0;

	  linear_power = throttle;

	  // Quickturn!
	  if (isQuickTurn) {
	    if (fabs(linear_power) < 0.2) {
	      double alpha = Constants_->quickStopTimeConstant;
	      quickStopAccumulator_ = (1 - alpha) * quickStopAccumulator_ + alpha * PwmLimit(wheel) * Constants_->quickStopStickScalar;
	    }
	    overPower = 1.0;
	    sensitivity = 1.0;
	    angular_power = wheel;
	  } else {
	    overPower = 0.0;
	    angular_power = fabs(throttle) * wheel * sensitivity - quickStopAccumulator_;
	    if (quickStopAccumulator_ > 1) {
	      quickStopAccumulator_ -= 1;
	    } else if (quickStopAccumulator_ < -1) {
	      quickStopAccumulator_ += 1;
	    } else {
	      quickStopAccumulator_ = 0.0;
	    }
	  }

	  right_pwm = left_pwm = linear_power;
	  left_pwm += angular_power;
	  right_pwm -= angular_power;

	  if (left_pwm > 1.0) {
	    right_pwm -= overPower * (left_pwm - 1.0);
	    left_pwm = 1.0;
	  } else if (right_pwm > 1.0) {
	    left_pwm -= overPower * (right_pwm - 1.0);
	    right_pwm = 1.0;
	  } else if (left_pwm < -1.0) {
	    right_pwm += overPower * (-1.0 - left_pwm);
	    left_pwm = -1.0;
	  } else if (right_pwm < -1.0) {
	    left_pwm += overPower * (-1.0 - right_pwm);
	    right_pwm = -1.0;
	  }
	  SetLinearPower(left_pwm, right_pwm);

}

//bool Drive::DriveWithHeading(double heading, double speed) {
//	double PID_P = Constants_->PID_DRIVE_TURN_KD;
//	double PID_D = Constants_->PID_DRIVE_TURN_KD;
//	double error = heading - GetGyroAngle();
//	double dError = error - m_PreviousGyroError;
//	double output = PID_P*error + PID_D*dError;
//
//	SetLinearPower(speed - output, speed + output);
//
//	m_PreviousGyroError = error;
//
//	return (fabs(error) < 4);
//}

//bool Drive::DriveDistanceWithHeading(double heading, double distance) {
//
//	double PID_P = Constants_->PID_DRIVE_SPEED_KP;
//	double PID_D = Constants_->PID_DRIVE_SPEED_KD;
//	double error = distance - LeftDriveEncoder_->GetDistance();
//	double dError = error - m_PreviousDriveError;
//	double output = PID_P * error + PID_D * dError;
//
//	bool headingResult = DriveWithHeading(heading, LimitMix(output,Constants_->PID_DRIVE_MAX_SPEED));
//
//	m_PreviousDriveError = error;
//
//	return(fabs(error) < 4);
//
//}

bool Drive::DriveDistanceWithHeading (double heading, double distance) {

	double LinearSpeed = DrivePid_->Update(distance,GetLeftEncoderDistance());

	bool headingResult = DriveWithHeading(heading, LimitMix(LinearSpeed,Constants_->DRIVE_MAX_SPEED));

	return (fabs(DrivePid_->lastError_) < 4 && headingResult);
}

//bool Drive::DriveWithHeading(double heading, double speed) {
//
//
//	double AngularSpeed = TurnPid_->Update(heading, GetGyroAngle());
//
//	SetLinearPower(speed - AngularSpeed, speed + AngularSpeed);
//
//	return(fabs(TurnPid_->lastError_) < 1);
//
//}

bool Drive::DriveWithHeading(double heading, double speed)
{
	speed *= -1;
	double PID_P = 0.1;
	double PID_D = 0.2;
	double error = heading - DriveGyro_->GetAngle();
	double dError = error - m_PreviousGyroError;
	double output = PID_P*error + PID_D*dError;

	SmartDashboard::PutNumber("Heading Error", error);
	SmartDashboard::PutNumber("Heading D Error", dError);
	SmartDashboard::PutNumber("Heading Output", output);

	//SetLinearPower(speed-output, speed+output);

	m_PreviousGyroError = error;

	return (fabs(error) < 1 && (400 * fabs(dError)) < 0.5);
}

void Drive::ResetDistance() {
	m_PrevDistance = 0;
}

