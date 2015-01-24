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

	/*
	 * Constructor
	 * All electronics are passed into the Intake Subsystem for use.
	 */
	Intake(VictorSP* leftIntakeMotor, VictorSP* rightIntakeMotor, DoubleSolenoid* leftIntakeArm, DoubleSolenoid* rightIntakeArm, Compressor* compressor);

	/**
	 * Function to directly interface with the motors.
	 * Positive Value Intakes, which a negative value Spits out.
	 * TODO: Make sure the correct motor is set negative.
	 */
	void SetIntakeMotors(float intakePowerLeft, float intakePowerRight);

	/**
	 * Convenience function to intake/expel objects.
	 */

	void SetIntakeMotorsLinear(float intakePower);

	/**
	 * Convenience function to rotate objects.
	 */
	void SetIntakeMotorsRotate(float intakePower);

	/**
	 * If pressure in system is too low, command will not function.
	 * bool off - If true, solenoids turned off.  (Does that mean they go limp?)  This overrides left/right
	 * bool left/right - If true, Arm switches in.  If false, Arm goes out.
	 *
	 */
	void SetIntakeArm(bool left, bool right, bool off);

private:

	Constants* Constants_;

	VictorSP* LeftIntakeMotor_;
	VictorSP* RightIntakeMotor_;

	DoubleSolenoid* LeftIntakeArm_;
	DoubleSolenoid* RightIntakeArm_;
	Compressor* Compressor_;

};

#endif
