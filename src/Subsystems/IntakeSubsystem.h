#pragma once

#include "Commands/Subsystem.h"
#include "WPILib.h"

class IntakeSubsystem: public Subsystem
{
private:

public:
	IntakeSubsystem();
	void InitDefaultCommand();
	VictorSP* IntakeRollers;
	TalonSRX* BallConveyor;
};


