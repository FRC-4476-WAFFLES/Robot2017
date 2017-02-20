#pragma once

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "CANTalon.h"

class ShooterSubsystem: public Subsystem
{
private:
	double last_dip = 0.0;
	double last_gyro = 0.0;
public:
	ShooterSubsystem();
	void InitDefaultCommand();
	void SetSpeed(double RPM);
	void SetPower(double power);
	void RunLoad();
	void StopLoad();
	bool AtSpeed();
	double ramp(double Target);
	void prints();
	CANTalon* Rollers;
	CANTalon* Rollers_Slave;
	VictorSP* Load;
	static constexpr float ShotSpeed = 100;
};


