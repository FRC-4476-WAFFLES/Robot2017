#ifndef DRIVE_SUBSYSTEM_H
#define DRIVE_SUBSYSTEM_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class DriveSubsystem: public Subsystem
{
private:
	RobotDrive* DriveBase;

	Encoder* DriveEncoder;
	Encoder* DriveEncoder2;
	ADXRS450_Gyro* gyro;
public:
	DriveSubsystem();
	void InitDefaultCommand();
	double distance();
	double angle();
	void zero_sensors();

	void drive(Joystick* left, Joystick* right);
	void drive(double left, double right);
	void prints();
};

namespace drive_curves {
	double nocurve(double x);
	template<int Degree>
	double exponential(double x);
	double cheesy_curve(double x);
}

#endif
