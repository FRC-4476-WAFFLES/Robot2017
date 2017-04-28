#pragma once

#include <Commands/Subsystem.h>
#include <Encoder.h>
#include <CANTalon.h>
#include <PowerDistributionPanel.h>

class ClimberSubsystem: public Subsystem
{
private:

public:
	ClimberSubsystem();
	void InitDefaultCommand();
	void SetPower(double power);
	void SetPosition(double position);
	void AutomaticClimb();
	double GetSetpoint();
	double GetPosition();
	void prints();
	double hold = 0.0;
	CANTalon* Climber;
	CANTalon* Climber_Slave;
	Encoder* ClimbEncoder;
	PowerDistributionPanel ClimberPower;
};
