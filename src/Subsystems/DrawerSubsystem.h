#pragma once

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "CANTalon.h"

class DrawerSubsystem: public Subsystem
{
private:

public:
	DrawerSubsystem();
	void InitDefaultCommand();
	void ContinuosIntake();
	CANTalon* Drawer;
};


