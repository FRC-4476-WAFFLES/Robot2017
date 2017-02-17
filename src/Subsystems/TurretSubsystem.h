#pragma once

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "CANTalon.h"

class TurretSubsystem: public Subsystem
{
private:
	void UpdateRollersPID();
	double last_vision;
	Timer last_pid_time;
public:
	TurretSubsystem();
	void InitDefaultCommand();
	void AngleIntrepreter();
	double GetAngle();
	void SetAngle(double angle);
	void SetAngleSlow(double angle);
	void SetPower(double power);
	void AimVision();
	void TurretHome();
	void prints();
	CANTalon* Turret;
	std::shared_ptr<NetworkTable> table;
	double Determined_Speed;


};


