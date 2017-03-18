#pragma once

#include "Commands/Subsystem.h"
#include "CANTalon.h"

class DrawerSubsystem: public Subsystem
{
private:

public:
	DrawerSubsystem();
	CANTalon* Drawer;
	void InitDefaultCommand();
	double GetSetpoint();
	void SetSetpoint(double);
	void prints();
};


