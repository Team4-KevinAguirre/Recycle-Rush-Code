//Declaration File for Drive Base
//This is where we define everything.
#include "Drive.h"

Drive::Drive(VictorSP* leftDriveMotorA, VictorSP* leftDriveMotorB, VictorSP* rightDriveMotorA, VictorSP* rightDriveMotorB, RelativeGyro* driveGyro, Encoder* leftDriveEncoder, Encoder* rightDriveEncoder){

	Constants_ = Constants::GetInstance();


}

