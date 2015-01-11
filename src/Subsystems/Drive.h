//Header File for Drive Base
//This is where we Declare Everything
#ifndef HI
#define HI

#include "WPILib.h"
#include "../PhoenixLib/PhoenixLib.h"
#include "../Config/Constants.h"


class Drive
{


public:

	Drive(Talon* leftDriveMotorA, Talon* rightDriveMotorA, Encoder* LeftDriveEncoder, Encoder* RightDriveEncoder, Gyro* Gyro); //This function is called the constructor

	//~Drive();//Destructor is the correct terminology.  This has to do with memory management.  We always need to release dynamically allocated memory.

	void DriveSpeedTurn(float speed, float turn, bool quickTurn);


	void TankDrive (float left, float right);

	void DriveLeftRight(float leftDriveValue, float rightDriveValue);

	void SetLinearPower(double leftPower, double rightPower);

	void DriveWithHeading(double heading, double speed);

	bool DriveDistanceWithHeading(double heading, double distance);

	double GetDriveDistance();

	double GetLeftEncoderDistance();

	double GetRightEncoderDistance();

	void ResetEncoders();

	void ResetGyro();





private:
	//Why put in private?

	Constants* Constants_;

	Talon* LeftDriveMotor_;
	Talon* RightDriveMotor_;

	Gyro* GyroDrive_;

	Encoder* LeftDriveEncoder_;
	Encoder* RightDriveEncoder_;

	DigitalInput* LimitSwitchMain_;

	float m_leftDriveValue;
	float m_rightDriveValue;

	//We are making sure to abide by getters and setters for all WPI objects.  This is so that we can run data validation at every setter.  We can throw an error if we want to here.
	void SetLeftMotors(float val);
	void SetRightMotors(float val);

//	PhoenixControlBoard();

//	bool GetQuickTurn();
//	bool GetAutoSelectButton();

//	float GetDriveAxis(unsigned int axis);
//	bool GetDriveButton(unsigned int button);
//
//	float GetOperatorAxis(unsigned int axis);
//	bool GetOperatorButton(unsigned int button);
//
//

};

#endif
