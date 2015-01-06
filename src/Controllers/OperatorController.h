//==================================================
// Copyright (C) 2014 Team 1538 / The Holy Phoenixs
//==================================================

#ifndef __OPERATOR_CONTROLLER_H__
#define __OPERATOR_CONTROLLER_H__

#include <math.h>
#include <WPILib.h>
#include "../PhoenixRobot.h"
#include "../PhoenixControlBoard.h"
#include "GenericController.h"
#include "../Config/Constants.h"
//#include "../PhoenixLib/PhoenixLib.h"

class OperatorController: public GenericController
{	
private:
	OperatorController();
	PhoenixControlBoard* m_CB;
	Constants* m_Constants;
//	bool m_PreviousFire;
//	bool m_PreviousFullBack;
//	bool m_PreviousHalfBack;
public:
	OperatorController(PhoenixControlBoard* controlboard);
	void handle(PhoenixRobot* bot);
};

#endif
