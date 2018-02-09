#pragma once

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include <ctre/Phoenix.h>
#include <ctre/phoenix/MotorControl/CAN/TalonSRX.h>

class IntakeSubsystem: public Subsystem
{
private:

public:
	IntakeSubsystem();
	void InitDefaultCommand();
	void ContinuosIntake();
	VictorSP* IntakeRollers;
	TalonSRX* BallConveyor;
};


