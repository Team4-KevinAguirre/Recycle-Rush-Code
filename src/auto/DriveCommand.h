#ifndef AUTO_DRIVE_COMMAND_H_
#define AUTO_DRIVE_COMMAND_H_

#include "auto/AutoCommand.h"


//class Drive;
//class Pid;
//
class DriveCommand : public AutoCommand {

public:
	DriveCommand(Drive* drive, double distance, double angle, double timeout, double maxSpeed, double maxAcceleration, double maxAlpha, double maxOmega);



private:
	Drive* drive_;


};
























