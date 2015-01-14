#include "drivers/TeleopDriver.h"





TeleopDriver::TeleopDriver(Drive* drive, PhoenixControlBoard* controlBoard) : Driver(drive) {
  Constants_ = Constants::GetInstance();
  ControlBoard_ = controlBoard;

  Reset();
}

bool TeleopDriver::UpdateDriver() {
//	//SmartDashboard::PutNumber("UpdateDriver init",1);
//	//std::cout<<"UpdateDriveroutside";
////	if(ControlBoard_->GetDriveButton(Constants_->JOY_BUTTON_A))
////	{
//	SmartDashboard::PutNumber("UpdateDriver inside Button",1);
////		std::cout<<"UpdateDriverinside";
//		//drive_->DriveSpeedTurn(ControlBoard_->GetDriveAxis(Constants_->JOY_AXIS_LJ_Y),ControlBoard_->GetDriveAxis(Constants_->JOY_AXIS_RJ_X), ControlBoard_->GetDriveButton(Constants_->JOY_BUTTON_RB));
//
//	//drive_->DriveSpeedTurn(ControlBoard_->GetDriveAxis(Constants_->JOY_AXIS_RJ_Y), ControlBoard_->GetDriveAxis(Constants_->JOY_AXIS_LJ_X), ControlBoard_->GetDriveButton(Constants_->JOY_BUTTON_RJPRESS));
//
//
//	//SmartDashboard::PutBoolean("Limit", drive_->LimitSwitch());
//		//	} else
////	{
////		drive_->SetLinearPower(0,0);
////	}
//  // Operator drive control
////  bool wantHighGear = !leftJoystick_->GetRawButton((int)constants_->highGearPort);
////  bool quickTurning = rightJoystick_->GetRawButton((int)constants_->quickTurnPort);
////  drive_->SetHighGear(wantHighGear);
////  // Add the starting position to the deadband just so we never get any stupid crap
////  double straightPower = -leftJoystick_->GetY();
////  double turnPower = rightJoystick_->GetX();
////
////  // If the switch has toggled, flip the pizza wheels.
////  bool currPizzaWheelsButton = rightJoystick_->GetRawButton((int)constants_->pizzaSwitchPort);
////  if (currPizzaWheelsButton != oldPizzaWheelsButton_) {
////    pizzaWheelsDown_ = !pizzaWheelsDown_;
////  }
////  oldPizzaWheelsButton_ = currPizzaWheelsButton;
////
////  // Retract the pizza wheels if the sensor has detected the bump.
////  drive_->SetPizzaWheelDown(pizzaWheelsDown_);
////
////  // Brake
////  drive_->SetBrakeOn(askForBrake_ || operatorControl_->GetBrakeSwitch());
////
////  // Drive
////  DriverStationLCD::GetInstance()->PrintfLine(DriverStationLCD::kUser_Line1, "l:%0.3f r:%0.3f", straightPower, turnPower);
////  drive_->CheesyDrive(straightPower, turnPower, quickTurning);

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


TeleopDriver::~TeleopDriver() {
}
