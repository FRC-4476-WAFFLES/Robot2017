#pragma once

#include "Commands/Subsystem.h"
#include "WPILib.h"

class IntakeSubsystem: public Subsystem
{
private:

public:
	IntakeSubsystem();
	void InitDefaultCommand();
	void ContinuosIntake();
	VictorSP* IntakeRollers;
	CANTalon* BallConveyor;
};


