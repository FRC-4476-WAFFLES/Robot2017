#pragma once

#include "Commands/Subsystem.h"
#include "Timer.h"
#include "CANTalon.h"

class GearSubsystem: public Subsystem
{
private:
	bool IsSensorWorking(double setpoint);
	void SetAngle(double setpoint, double override_speed);
	Timer *stuck_timer;
	double last_error = 0;
public:
	GearSubsystem();
	void InitDefaultCommand();
	void Open();
	void Closed();
	void Toggle();
	void Persist();
	void prints();
	CANTalon* Gear;
	float starting_angle = 0;
	bool is_open = false;
	bool cancel = false;
	double vclosed = 0.686;
	double vopen = 0.575;
	double fmodGearEnc;
};


