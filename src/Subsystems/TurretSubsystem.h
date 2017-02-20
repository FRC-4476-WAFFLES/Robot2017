#pragma once

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "CANTalon.h"

class TurretSubsystem: public Subsystem
{
private:
	void UpdateRollersPID();
	double last_vision;
	double last_gyro;
	double last_angle;
	double vision_history[100];
	int vision_index = 0;
	Timer last_pid_time;
	double* LookupHistory(int delta, bool increment);
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


