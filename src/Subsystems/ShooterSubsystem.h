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
	void SetPower(double power);
	void RunLoad();
	void StopLoad();
	CANTalon* Rollers;
	CANTalon* Rollers_Slave;
	VictorSP* Load;
	static constexpr float ShotSpeed = 100;
};


