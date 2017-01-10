#pragma once

#include "Commands/Subsystem.h"
#include "WPILib.h"

class ShooterSubsystem: public Subsystem
{
private:
	Victor* Rollers;
	Victor* Turret;
public:
	ShooterSubsystem();
	void InitDefaultCommand();


};


