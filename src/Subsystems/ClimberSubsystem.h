#pragma once

#include <Commands/Subsystem.h>
#include <Encoder.h>
#include <CANTalon.h>

class ClimberSubsystem: public Subsystem
{
private:

public:
	ClimberSubsystem();
	void InitDefaultCommand();
	void SetPower(double power);
	CANTalon* Climber;
	CANTalon* Climber_Slave;
	Encoder* ClimbEncoder;
	double distance();
};


