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

	//motor safety
	DriveLeft1->SetSafetyEnabled(true);
	DriveLeft2->SetSafetyEnabled(true);
	DriveLeft3->SetSafetyEnabled(true);
	DriveRight1->SetSafetyEnabled(true);
	DriveRight2->SetSafetyEnabled(true);
	DriveRight3->SetSafetyEnabled(true);

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
	double left_value = left->GetRawAxis(1);
	double right_value = right->GetRawAxis(1);
	double avg = (left_value + right_value) / 2.0;
	double test = fabs(left_value - right_value)/fabs(avg)/Preferences::GetInstance()->GetDouble("Drive_Straight_Limit", 2.7);
	if(test < 1.0) {
		left_value = left_value * test + avg * (1.0 - test);
		right_value = right_value * test + avg * (1.0 - test);
	}
	drive(curve(right_value), curve(left_value));
}

void DriveSubsystem::drive(double left, double right) {
	DriveRight1->SetSpeed(right);
	DriveRight2->SetSpeed(right);
	DriveRight3->SetSpeed(right);
	DriveLeft1->SetSpeed(-left);
	DriveLeft2->SetSpeed(-left);
	DriveLeft3->SetSpeed(-left);
}

void DriveSubsystem::auto_drive(double distanceTarget, double angleTarget, double speed) {
	// Calculate the error on the distance traveled
	double distanceError = (distance() - distanceTarget)*0.76;

	// Make sure the distance error does not exceed 100%
	if(distanceError > 1.0) {
		distanceError = 1.0;
	}
	if(distanceError < -1.0) {
		distanceError = -1.0;
	}

	// Calculate the difference between the current angle and the desired angle
	double angleError = angleTarget - angle();

	// Set the motors to run
	drive(0.01*angleError + speed*distanceError, -0.01*angleError + speed*distanceError);
}

bool DriveSubsystem::on_target(double distanceTarget, double angleTarget) {
	double distanceError = distance() - distanceTarget;
	double angleError = angleTarget - angle();
	return distanceError < 0.20 && distanceError > -0.20 && angleError < 5.0 && angleError > -5.0;
}

void DriveSubsystem::prints() {
	SmartDashboard::PutNumber("drive.angle(degrees)", angle());
	SmartDashboard::PutNumber("drive.distance(feet)", distance());
}

namespace drive_curves {
	double nocurve(double x) {
		if(fabs(x) < 0.05) {
			return 0.0;
		}
		return x;
	}

	template<int Degree>
	double exponential(double x) {
		return pow(x, Degree);
	}

	double cheesy_curve(double x) {
		if(fabs(x) < 0.05 ) {
		    return 0.0;
		} else if(x < 0.0) {
			return -cheesy_curve(-x);
		} else {
			return 4.5504 * pow(x, 4) + -5.9762 * pow(x, 3) + 2.5895 * pow(x, 2) + -0.0869 * x + 0.0913;
		}
	}

	double bezier(double t, std::vector<double> p){
		double oldT = t;
		if(p.size() == 2)
			return p[0] + (p[1] - p[0])*t;

		if(0 > t || t > 1)
			t = -t;
		if(p.size() <2)
			fprintf(stderr, "Too few points given");

		auto d = p;

		for(int i = d.size(); i > 0; i--)
			for (int j = 1; j < i; j++)
				d[j-1] = bezier(t, std::vector<double>{d[j-1], d[j]});

		if(oldT < 0){
			return -d[0];
		}else{
			return d[0];
		}
	}

	double bezier_1114(double x) {
		return drive_curves::bezier(x, std::vector<double>{0, 0.54, -0.07, 1});
	}
}
