#include "Intake.h"

Intake::Intake(VictorSP* leftIntakeMotor, VictorSP* rightIntakeMotor){

	Constants_ = Constants::GetInstance();

	//Motors
	LeftIntakeMotor_ = leftIntakeMotor;
	RightIntakeMotor_ = rightIntakeMotor;

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
