#pragma once

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "CANTalon.h"

class ShooterSubsystem: public Subsystem
{
private:
public:
	ShooterSubsystem();
	void InitDefaultCommand();
	void SetSpeed(double RPM);
	void SetTurret(double TurretAngle);
	void CameraNetworkTable();
	void prints();
	CANTalon* Rollers;
	CANTalon* Rollers_Slave;
	CANTalon* Load;
	CANTalon* Turret;
	static constexpr float ShotSpeed = 100;
	std::shared_ptr<NetworkTable> table;
};


