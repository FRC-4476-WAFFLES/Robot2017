#pragma once

#include "Commands/Subsystem.h"
#include "Joystick.h"
#include "Encoder.h"
#include "Timer.h"
#include "Victor.h"
#include "Ultrasonic.h"
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
	Ultrasonic* ultrasonic_sensor;

	double last_left = 0;
	double last_right = 0;

	double last_distance_error = 0;
	double last_angle_error = 0;
	Timer last_pid_time;
public:
	DriveSubsystem();
	void InitDefaultCommand();
	void DriveToGearWall(double InputAngle);
	bool IsAtWall();
	double distance_to_wall();
	double distance();
	double angle();
	double angle_rate();
	void auto_drive(double distance, double angle, double speed);
	bool on_target(double distance, double angle);
	bool on_target(double distanceTarget, double distanceTolerence, double angleTarget, double angleTolerence);
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
