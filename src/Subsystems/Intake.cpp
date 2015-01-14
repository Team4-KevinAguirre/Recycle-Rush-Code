#include "Intake.h"

Intake::Intake(Victor* leftIntakeMotor, Victor* rightIntakeMotor){

	Constants_ = Constants::GetInstance();

	//Motors
	LeftIntakeMotor_ = leftIntakeMotor;
	RightIntakeMotor_ = rightIntakeMotor;

}
