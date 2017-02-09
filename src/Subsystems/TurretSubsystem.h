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
	void SetTurret(float Angle);
	void prints();
	CANTalon* Turret;
	std::shared_ptr<NetworkTable> table;

};


