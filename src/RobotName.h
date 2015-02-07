
#ifndef __ROBOT_NAME_H__
#define __ROBOT_NAME_H__

//#include <hostLib.h>
#include "Subsystems/Drive.h"
#include "Subsystems/Intake.h"
#include "Util/RelativeGyro.h"
#include <WPILib.h>
#include "Config/Constants.h"
#include "PhoenixControlBoard.h"


class RobotName : public IterativeRobot
{
private:

public:
	RobotName();
	void ResetMotors();
	void RobotInit();
	void DisabledInit();
	void AutonomousInit();
	void TeleopInit();
	void DisabledContinuous();
	void AutonomousContinuous();
	void TeleopContinuous();
	void DisabledPeriodic();
	void AutonomousPeriodic();
	void TeleopPeriodic();


private:

	//Constants
	Constants* Constants_;

	VictorSP* LeftDriveMotorA_;
	VictorSP* LeftDriveMotorB_;
	VictorSP* RightDriveMotorA_;
	VictorSP* RightDriveMotorB_;

	VictorSP* LeftIntakeMotor_;
	VictorSP* RightIntakeMotor_;


	//Pneumatics
	DoubleSolenoid* LeftIntakeArm_;
	DoubleSolenoid* RightIntakeArm_;
	Compressor* Compressor_;

	//Sensors
	RelativeGyro* DriveGyro_;
	Encoder* LeftDriveEncoder_;
	Encoder* RightDriveEncoder_;

	//Joysticks
	Joystick* DriverJoystick_;
	Joystick* OperatorJoystick_;

	//Control Board
	PhoenixControlBoard* ControlBoard_;

	//Subsystems
	Drive* Drive_;
	Intake* Intake_;

	bool isTankDrive;
};

START_ROBOT_CLASS(RobotName);

#endif

