#ifndef DRIVE_SUBSYSTEM_H
#define DRIVE_SUBSYSTEM_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class DriveSubsystem: public Subsystem
{
private:
	Victor* RightMotorFront;
	Victor* LeftMotorFront;
	Victor* RightMotorBack;
	Victor* LeftMotorBack;

	Encoder* DriveEncoder;
	ADXRS450_Gyro* gyro;
public:
	DriveSubsystem();
	void InitDefaultCommand();
	double GetGyro();
	void Drive (Joystick* left, Joystick* right);
	void Drive (double left, double right);
	void resetGyro();
	double driveEncoder();
	void ReZero();
};

#endif
