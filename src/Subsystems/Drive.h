//Header File for Drive Base
//This is where we Declare Everything
#ifndef DRIVE_H_
#define DRIVE_H_

#include "WPILib.h"
#include "../Config/Constants.h"
#include "../Util/RelativeGyro.h"
#include "Subsystems/Pid.h"


class Drive
{


public:
	/**
	 * Constructor
	 * Accepts all the electronic components associated with the drive base.
	 */
	Drive(VictorSP* leftDriveMotorA, VictorSP* leftDriveMotorB, VictorSP* rightDriveMotorA, VictorSP* rightDriveMotorB, RelativeGyro* driveGyro, Encoder* leftDriveEncoder, Encoder* rightDriveEncoder);


private:

	Constants* Constants_;

};
#endif
