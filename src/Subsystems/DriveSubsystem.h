#ifndef DRIVE_SUBSYSTEM_H
#define DRIVE_SUBSYSTEM_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "CustomSensors/ADIS16448_IMU.h"

class DriveSubsystem: public Subsystem
{
private:
	Encoder* DriveEncoder;
	Encoder* DriveEncoder2;
	ADIS16448_IMU* gyro;
	Victor* DriveRight1;
	Victor* DriveRight2;
	Victor* DriveRight3;
	Victor* DriveLeft1;
	Victor* DriveLeft2;
	Victor* DriveLeft3;

	double last_left;
	double last_right;

//	double lastSpeed;
public:
	DriveSubsystem();
	void InitDefaultCommand();
	double distance();
	double angle();
	void auto_drive(double distance, double angle, double speed);
	bool on_target(double distance, double angle);
	void zero_sensors();
	void drive(Joystick* left, Joystick* right);
	void drive(double left, double right, bool ramp);
	void prints();
};

namespace drive_curves {
	double nocurve(double x);
	template<int Degree>
	double exponential(double x);
	double cheesy_curve(double x);
	double bezier_1114(double x);
}

#endif
