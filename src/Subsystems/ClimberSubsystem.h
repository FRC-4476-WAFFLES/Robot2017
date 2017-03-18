#pragma once

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "CANTalon.h"

class ClimberSubsystem: public Subsystem
{
private:

public:
	ClimberSubsystem();
	void InitDefaultCommand();
	void SetPower(double power);
	void SetPosition(double position);
	double GetSetpoint();
	double GetPosition();
	CANTalon* Climber;
	CANTalon* Climber_Slave;
	Encoder* ClimbEncoder;
};
