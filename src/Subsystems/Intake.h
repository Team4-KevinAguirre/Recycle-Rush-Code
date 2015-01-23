//Header File for Drive Base
//This is where we Declare Everything
#ifndef INTAKE_H_
#define INTAKE_H_

#include "WPILib.h"
#include "../PhoenixLib/PhoenixLib.h"
#include "../Config/Constants.h"


class Intake
{


public:

	Intake(VictorSP* leftIntakeMotor, VictorSP* rightIntakeMotor); //This function is called the constructor

	void SetIntakeMotors(float intakePowerLeft, float intakePowerRight);
	//Make positive value intake inwards, while negative value intake outwards.  Therefore, one of the motors need to be neg.

	void SetIntakeMotorsLinear(float intakePower);

	void SetIntakeMotorsRotate(float intakePower);
private:

	Constants* Constants_;

	VictorSP* LeftIntakeMotor_;
	VictorSP* RightIntakeMotor_;



};

#endif
