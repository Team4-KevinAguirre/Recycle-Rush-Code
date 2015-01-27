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

	/**
	 * Used to drive robot if throttle and turning rate is wanted.  Used extensively by great teams because allows for
	 * maximum precision.
	 */
	void DriveSpeedTurn(float throttle, float turn, bool quickturn);

	/**
	 * TODO: Used to just control turning.  Not sure yet to keep in or not.
	 * Used with "analog" joystick inputs (triggers, etc...) to rotate robot finely.
	 * TODO: Create a global rotation sensitivity constant.
	 */
	void rotateDrive(float turnIncrement);

	/**
	 * Given an angle, we can use gyro to rotate to a field-centric angle.
	 * TODO: Do not know if driver wants this, but needs gyro.
	 */
	void rotateAbsoluteDrive(float angle);

	/**
	 * Gets the distance traveled by the left side of the Robot.
	 * Uses wheel radius, gear ratio, and encoder return value to obtain distance
	 */
	double GetLeftEncoderDistance();

	/**
	 * Gets the distance traveled by the right side of the Robot.
	 * Uses wheel radius, gear ratio, and encoder return value to obtain distance
	 */
	double GetRightEncoderDistance();

	/**
	 * Returns current gyro angle.
	 * @returns gyro angle in degrees.
	 */
	double GetGyroAngle();

	/**
	 * Resets RelativeGyro so current angle is now 0 degrees.  This makes sequential turning easier.
	 * Also, needed to make sensor values accurate after noise is encountered.
	 */
	void ResetGyro();

	/**
	 * Resets AbsoluteGyro which is a hardware reset.  Be careful, because it undergoes a zeroing routine which requires
	 * Drive to be motionless.  Do not perform on a periodic basis.  Perform at Init states.
	 */
	void resetAbsoluteGyro();

	/**
	 * Resets the Encoder values back to zero.  Done at beginning of match or when a hard zero is wanted.
	 */
	void ResetEncoders();

	/**
	 * Interface used to set the speeds of the motors.  This is created for readability and to obscure minus signs.
	 * A positive value is forward while a negative Value is backwards.
	 */
	void SetPower(double leftPower, double rightPower);

private:

	Constants* Constants_;

	//Motors
	VictorSP* LeftDriveMotorA_;
	VictorSP* LeftDriveMotorB_;
	VictorSP* RightDriveMotorA_;
	VictorSP* RightDriveMotorB_;

	//Sensors
	RelativeGyro* DriveGyro_;
	Encoder* LeftDriveEncoder_;
	Encoder* RightDriveEncoder_;


	Pid* TurnPid_;

};
#endif
