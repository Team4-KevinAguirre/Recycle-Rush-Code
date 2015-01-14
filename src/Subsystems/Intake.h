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

	Intake(Victor* leftIntakeMotor, Victor* rightIntakeMotor); //This function is called the constructor


private:

	Constants* Constants_;

	Victor* LeftIntakeMotor_;
	Victor* RightIntakeMotor_;



};

#endif
