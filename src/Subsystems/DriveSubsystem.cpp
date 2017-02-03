/**
 * DriveSubsystem is a class that keeps references to each of the
 * drive motors and drive encoder.
 */


#include <Commands/Drive/DriveOperator.h>
#include "Commands/Drive/DriveAuto.h"
#include "DriveSubsystem.h"
#include "../RobotMap.h"
#include <math.h>
#include "CustomSensors/ADIS16448_IMU.h"

DriveSubsystem::DriveSubsystem():
		Subsystem("DriveSubsystem")
{
	DriveLeft1 = new Victor(DRIVE_LEFT_1);
	DriveLeft2 = new Victor(DRIVE_LEFT_2);
	DriveLeft3 = new Victor(DRIVE_LEFT_3);
	DriveRight1 = new Victor(DRIVE_RIGHT_1);
	DriveRight2 = new Victor(DRIVE_RIGHT_2);
	DriveRight3 = new Victor(DRIVE_RIGHT_3);

	gyro = new ADIS16448_IMU;
	DriveEncoder = new Encoder(DRIVE_ENCODER_A , DRIVE_ENCODER_B);
	DriveEncoder2 = new Encoder(DRIVE_ENCODER_C, DRIVE_ENCODER_D);
}

void DriveSubsystem::InitDefaultCommand() {
	// When no other commands are running, we do operator control
	SetDefaultCommand(new DriveOperator());
}

double DriveSubsystem::distance() {
	return ((DriveEncoder->Get() - DriveEncoder2->Get())/2.0)/76.83333333;
}

double DriveSubsystem::angle() {
	return gyro->GetAngleZ();
}

void DriveSubsystem::zero_sensors() {
	gyro->Reset();
	DriveEncoder->Reset();
}

void DriveSubsystem::drive(Joystick* left, Joystick* right) {
	auto curve = drive_curves::nocurve;
	drive(curve(left->GetRawAxis(1)), curve(right->GetRawAxis(1)));
}

void DriveSubsystem::drive(double left, double right) {
	DriveRight1->SetSpeed(right);
	DriveRight2->SetSpeed(right);
	DriveRight3->SetSpeed(right);
	DriveLeft1->SetSpeed(-left);
	DriveLeft2->SetSpeed(-left);
	DriveLeft3->SetSpeed(-left);
}

void DriveSubsystem::prints() {
	SmartDashboard::PutNumber("drive.angle(degrees)", angle());
	SmartDashboard::PutNumber("drive.distance(feet)", distance());
}

namespace drive_curves {
	double nocurve(double x) {
		if(fabs(x) < 0.1) {
			return 0.0;
		}
		return x;
	}

	template<int Degree>
	double exponential(double x) {
		return pow(x, Degree);
	}

	double cheesy_curve(double x) {
		if(fabs(x) < 0.01 ) {
		    return 0.0;
		} else if(x < 0.0) {
			return cheesy_curve(-x);
		} else {
			return 4.5504 * pow(x, 4) + -5.9762 * pow(x, 3) + 2.5895 * pow(x, 2) + -0.0869 * x + 0.0913;
		}
	}
}
