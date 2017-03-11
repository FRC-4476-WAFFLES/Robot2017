#pragma once

#include "Commands/Subsystem.h"
#include "WPILib.h"

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
//	Servo* GearLeft;
//	Servo*GearRight;
	bool is_open = false;
};


