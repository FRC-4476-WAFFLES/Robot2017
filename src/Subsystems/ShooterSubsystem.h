#pragma once

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "CANTalon.h"

class ShooterSubsystem: public Subsystem
{
private:
public:
	ShooterSubsystem();
	void InitDefaultCommand();
	void SetSpeed(double RPM);
	CANTalon* Rollers;
	CANTalon* Rollers_Slave;
	CANTalon* Load;
	static constexpr float ShotSpeed = 100;
};


