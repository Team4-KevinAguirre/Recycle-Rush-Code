#ifndef DRIVERS_TELEOP_DRIVER_H
#define DRIVERS_TELEOP_DRIVER_H

#include "drivers/Driver.h"
#include "subsystems/Drive.h"
#include "config/Constants.h"
#include "PhoenixControlBoard.h"

class Constants;
class PhoenixControlBoard;

/**
 * @author Eric Bakan
 *
 * A teleop drive controller
 * Primarily translate control board inputs into drive outputs
 */
class TeleopDriver : public Driver {
 public:

  /**
   * Only needs a drive and control board inputs
   */
  TeleopDriver(Drive* drive, PhoenixControlBoard* controlBoard);

  /**
   * Updates the driver
   * Controls ALL the logic
   */
  virtual bool UpdateDriver();

  /**
   * Resets some toggles and such like pizza wheels, etc.
   */
  virtual void Reset();

  /**
   * Clean up clean up, everybody everywhere!
   * Clean up clean up, everybody do your share!
   */
  virtual ~TeleopDriver();

 private:
  Constants* Constants_;
  PhoenixControlBoard* ControlBoard_;

//
//
//  //initial joystick vals
//  double startLeftJoystick_;
//  double startRightJoystick_;
};

#endif // DRIVERS_TELEOP_DRIVER_H
