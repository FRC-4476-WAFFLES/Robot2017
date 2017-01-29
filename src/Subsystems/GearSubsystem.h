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
	Servo* GearLeft;
	Servo*GearRight;
};


