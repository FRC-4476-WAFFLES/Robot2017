#pragma once

#include "Commands/Subsystem.h"
#include "CANTalon.h"

class GearSubsystem: public Subsystem
{
private:

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
//	Servo* GearLeft;
//	Servo*GearRight;
	bool is_open = false;
};


