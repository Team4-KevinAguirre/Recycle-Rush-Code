#include "Intake.h"

Intake::Intake(VictorSP* leftIntakeMotor, VictorSP* rightIntakeMotor, DoubleSolenoid* leftIntakeArm, DoubleSolenoid* rightIntakeArm){

	Constants_ = Constants::GetInstance();

	//Motors
	LeftIntakeMotor_ = leftIntakeMotor;
	RightIntakeMotor_ = rightIntakeMotor;

	//Pneumatics
	LeftIntakeArm_ = leftIntakeArm;
	RightIntakeArm_ = rightIntakeArm;

}

void Intake::SetIntakeMotors(float intakePowerLeft, float intakePowerRight){
	LeftIntakeMotor_->Set(PwmLimit(intakePowerLeft));
	RightIntakeMotor_->Set(-PwmLimit(intakePowerRight));
}

void Intake::SetIntakeMotorsLinear(float intakePower){
	SetIntakeMotors(intakePower,intakePower);
}


void Intake::SetIntakeMotorsRotate(float intakePower){
	SetIntakeMotors(-intakePower, intakePower);
}
