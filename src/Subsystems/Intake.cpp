#include "Intake.h"

Intake::Intake(VictorSP* leftIntakeMotor, VictorSP* rightIntakeMotor, DoubleSolenoid* leftIntakeArm, DoubleSolenoid* rightIntakeArm, Compressor* compressor){

	Constants_ = Constants::GetInstance();

	//Motors
	LeftIntakeMotor_ = leftIntakeMotor;
	RightIntakeMotor_ = rightIntakeMotor;

	//Pneumatics
	LeftIntakeArm_ = leftIntakeArm;
	RightIntakeArm_ = rightIntakeArm;
	Compressor_ = compressor;

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

void Intake::SetIntakeArm(bool left, bool right, bool off) {
	if(Compressor_->GetPressureSwitchValue())//If pressure is low
		return;
	if(off)
	{
		LeftIntakeArm_->Set(LeftIntakeArm_->kOff);
		RightIntakeArm_->Set(RightIntakeArm_->kOff);
		return;
	}
	if(left)
		LeftIntakeArm_->Set(LeftIntakeArm_->kForward);
	else
		LeftIntakeArm_->Set(LeftIntakeArm_->kReverse);
	if(right)
		RightIntakeArm_->Set(RightIntakeArm_->kForward);
	else
		RightIntakeArm_->Set(RightIntakeArm_->kReverse);
	return;
}
