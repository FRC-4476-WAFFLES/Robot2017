#pragma once

#include "Commands/Subsystem.h"
#include "WPILib.h"

class GearSubsystem: public Subsystem
{
private:

public:
	GearSubsystem();
	void InitDefaultCommand();
	Servo* Gear;

};


