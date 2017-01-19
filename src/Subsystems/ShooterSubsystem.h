#pragma once

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "CANTalon.h"

class ShooterSubsystem: public Subsystem
{
private:
	CANTalon* Rollers;
	Victor* Turret;
public:
	ShooterSubsystem();
	void InitDefaultCommand();
	void SetSpeed(double RPM);
};


