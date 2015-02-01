//==================================================
// Copyright (C) 2014 Team 1538 / The Holy PHOENIXs
//==================================================

#ifndef __PHOENIX_CONTROL_BOARD_H__
#define __PHOENIX_CONTROL_BOARD_H__

#include <WPILib.h>
#include "Config/Constants.h"

class PhoenixControlBoard
{

public:
	/**
	 * Constructor for the ControlBoard.  This is used to wrap all joystick functionality.  Able to easily switch
	 * commands between Driver and Operator Joysticks.
	 */
	PhoenixControlBoard(Joystick* DriveJoystick, Joystick* OperatorJoystick);

	/**
	 * Used in conjunction with the Constants class to easily access an Axis on the Driver's Controller.
	 * Note: This is a raw reading.  To apply a filter to this Drive Axis, use filter commands.
	 */
	float GetDriveAxis(int axis);

	/**
	 * This function allows user to trim percentage from the bottom and top ranges of the axis.  The output is then
	 * linear between these two "modified" bounds.
	 * TODO: @ Return | ___________.
	 */
	float GetDriveAxisFilterTopBottomTrim(int axis, double botTrim, double topTrim);

	/**
	 * Cubic Filter to change sensitivity at all Joystick Input Ranges.  The tuning parameter 'a', should be set between
	 * 0 and 1.  This function will be less sensitive to lower ranges, but is more sensitive at higher ranges.
	 *  Credits to Ether:
	 *  http://www.chiefdelphi.com/media/papers/2421?	 *
	 */

	float GetDriveAxisFilterCubic(int axis, double a);

	/**
	 * Used in conjunction with the Constants class to easily access a Button on the Driver's Controller.
	 */
	bool GetDriveButton(int button);

	/**
	 * This is used to access the Driver's POV.  Not exactly sure what should be returned.  Therefore, this is
	 * going to be left alone, and a TODO will be created.
	 * @Return | The degree starting at up and going clockwise.
	 * TODO: Do we need to fix s.t. zero'd somewhere else?
	 */
	float GetDrivePOV(int button);

	/**
	 * Used in conjunction with the Constants class to easily access an Axis on the Operator's Controller.
	 * Note: This is a raw reading.  To apply a filter to this Drive Axis, use filter commands.
	 */
	float GetOperatorAxis(int axis);

	/**
	 * This function allows user to trim percentage from the bottom and top ranges of the axis.  The output is then
	 * linear between these two "modified" bounds.
	 * TODO: @ Return | ___________.
	 */
	float GetOperatorAxisFilterTopBottomTrim(int axis, double botTrim, double topTrim);

	/**
	 * Cubic Filter to change sensitivity at all Joystick Input Ranges.  The tuning parameter 'a', should be set between
	 * 0 and 1.  This function will be less sensitive to lower ranges, but is more sensitive at higher ranges.
	 *  Credits to Ether:
	 *  http://www.chiefdelphi.com/media/papers/2421?	 *
	 */

	float GetOperatorAxisFilterCubic(int axis, double a);

	/**
	 * Used in conjunction with the Constants class to easily access a Button on the Operator's Controller.
	 */
	bool GetOperatorButton(int button);

	/**
	 * This is used to access the Operator's POV.  Not exactly sure what should be returned.  Therefore, this is
	 * going to be left alone, and a TODO will be created.
	 * @Return | The degree starting at up and going clockwise.
	 * TODO: Do we need to fix s.t. zero'd somewhere else?
	 */
	float GetOperatorPOV(int button);
private:
	Joystick* DriveJoystick_;
	Joystick* OperatorJoystick_;
	Constants* Constants_;


};

#endif
