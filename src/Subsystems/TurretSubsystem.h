#pragma once

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "CANTalon.h"

class TurretSubsystem: public Subsystem
{
private:
	void UpdateRollersPID();

public:
	TurretSubsystem();
	void InitDefaultCommand();
	void AngleIntrepreter();
	void SetAngle(double angle);
	void SetPower(double power);
	void TurretHome();
	void prints();
	CANTalon* Turret;
	std::shared_ptr<NetworkTable> table;
	double Determined_Speed;

};


