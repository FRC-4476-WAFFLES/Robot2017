#pragma once

#include "Commands/Subsystem.h"
#include "WPILib.h"

class ShooterSubsystem: public Subsystem
{
private:
	TalonSRX* Rollers;
	Victor* Turret;
public:
	ShooterSubsystem();
	void InitDefaultCommand();
};


