#pragma once

#include "Commands/Subsystem.h"
#include "WPILib.h"

class TurretSubsystem: public Subsystem
{
private:

public:
	TurretSubsystem();
	void InitDefaultCommand();
	void AngleIntrepreter();
	void SetAngle(double angle);
	void SetPower(double power);
	void prints();
	CANTalon* Turret;
	std::shared_ptr<NetworkTable> table;

};


