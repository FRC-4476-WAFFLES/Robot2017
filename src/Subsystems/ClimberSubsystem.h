#pragma once

#include <Commands/Subsystem.h>
#include <Encoder.h>
#include <ctre/phoenix/MotorControl/CAN/TalonSRX.h>
#include <ctre/Phoenix.h>
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
	TalonSRX* Climber;
	TalonSRX* Climber_Slave;
	Encoder* ClimbEncoder;
	PowerDistributionPanel ClimberPower;
};
