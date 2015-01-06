//Header File for Drive Base
//This is where we Declare Everything
#ifndef HI
#define HI

#include "WPILib.h"
#include "../PhoenixLib/PhoenixLib.h"
#include "../Config/Constants.h"


class DriveBase
{


public:

	DriveBase(); //This function is called the constructor

	//~DriveBase();//Destructor is the correct terminology.  This has to do with memory management.  We always need to release dynamically allocated memory.

	void DriveSpeedTurn(float speed, float turn, bool quickTurn);

	void DriveLeftRight(float leftDriveValue, float rightDriveValue);

	void DriveWithHeading(double heading, double speed);

	bool DriveDistanceWithHeading(double heading, double distance);

	double GetDriveDistance();

	double GetLeftEncoderDistance();

	double GetRightEncoderDistance();

	void ResetEncoders();





private:
	//Why put in private?

	Constants* m_Constants;

	Talon* m_LeftDriveMotor;
	Talon* m_RightDriveMotor;

	Encoder* m_LeftDriveEncoder;
	Encoder* m_RightDriveEncoder;

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
