#include "drivers/TeleopDriver.h"





TeleopDriver::TeleopDriver(Drive* drive, PhoenixControlBoard* controlBoard) : Driver(drive) {
  m_Constants = Constants::GetInstance();
  m_ControlBoard = controlBoard;

  Reset();
}

bool TeleopDriver::UpdateDriver() {
  // Operator drive control
//  bool wantHighGear = !leftJoystick_->GetRawButton((int)constants_->highGearPort);
//  bool quickTurning = rightJoystick_->GetRawButton((int)constants_->quickTurnPort);
//  drive_->SetHighGear(wantHighGear);
//  // Add the starting position to the deadband just so we never get any stupid crap
//  double straightPower = -leftJoystick_->GetY();
//  double turnPower = rightJoystick_->GetX();
//
//  // If the switch has toggled, flip the pizza wheels.
//  bool currPizzaWheelsButton = rightJoystick_->GetRawButton((int)constants_->pizzaSwitchPort);
//  if (currPizzaWheelsButton != oldPizzaWheelsButton_) {
//    pizzaWheelsDown_ = !pizzaWheelsDown_;
//  }
//  oldPizzaWheelsButton_ = currPizzaWheelsButton;
//
//  // Retract the pizza wheels if the sensor has detected the bump.
//  drive_->SetPizzaWheelDown(pizzaWheelsDown_);
//
//  // Brake
//  drive_->SetBrakeOn(askForBrake_ || operatorControl_->GetBrakeSwitch());
//
//  // Drive
//  DriverStationLCD::GetInstance()->PrintfLine(DriverStationLCD::kUser_Line1, "l:%0.3f r:%0.3f", straightPower, turnPower);
//  drive_->CheesyDrive(straightPower, turnPower, quickTurning);

  return true;
}

void TeleopDriver::Reset() {
  // Reset pizza wheels.
//  oldPizzaWheelsButton_ = rightJoystick_->GetRawButton((int)constants_->pizzaSwitchPort);
//  pizzaWheelsDown_= false;
//  drive_->SetPizzaWheelDown(pizzaWheelsDown_);
//  startLeftJoystick_ = leftJoystick_->GetY();
//  startRightJoystick_ = rightJoystick_->GetX();
//  AskForBrake(false);
}
}

TeleopDriver::~TeleopDriver() {
}
