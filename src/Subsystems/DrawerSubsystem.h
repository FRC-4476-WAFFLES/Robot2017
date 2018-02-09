#pragma once

#include "Commands/Subsystem.h"
#include <ctre/phoenix/MotorControl/CAN/TalonSRX.h>
#include <ctre/Phoenix.h>

class DrawerSubsystem: public Subsystem
{
private:

public:
	DrawerSubsystem();
	TalonSRX* Drawer;
	void InitDefaultCommand();
	double GetSetpoint();
	void SetSetpoint(double);
	void prints();
};


