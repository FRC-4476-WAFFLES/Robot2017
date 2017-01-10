#pragma once

#include "Commands/Subsystem.h"
#include "WPILib.h"

class IntakeSubsystem: public Subsystem
{
private:
	Victor* IntakeRollers;
public:
	IntakeSubsystem();
	void InitDefaultCommand();


};


