/**
 * DriveSubsystem is a class that keeps references to each of the
 * drive motors and drive encoder.
 */


#include "DriveSubsystem.h"
#include <math.h>
#include <SmartDashboard/SmartDashboard.h>
#include <Preferences.h>
#include "Commands/Drive/DriveOperator.h"
#include "Commands/Drive/DriveAuto.h"
#include "CustomSensors/ADIS16448_IMU.h"
#include "OI.h"
#include "RobotMap.h"

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

	ultrasonic_sensor = new Ultrasonic(SONAR_OUT, SONAR_IN);
	ultrasonic_sensor->SetAutomaticMode(true);
}

void DriveSubsystem::InitDefaultCommand() {
	// When no other commands are running, we do operator control
	SetDefaultCommand(new DriveOperator());
}

double DriveSubsystem::distance_to_wall() {
	return (ultrasonic_sensor->GetRangeInches())/12;
}

void DriveSubsystem::DriveToGearWall(double InputAngle)
{
	auto_drive(distance() + distance_to_wall() - 0.3, InputAngle,0.3);
}

bool DriveSubsystem::IsAtWall() {
	return distance_to_wall() - 0.35 < 0.0;
}

double DriveSubsystem::distance() {
	return ((DriveEncoder->Get() - DriveEncoder2->Get())/2.0)/76.83333333;
}

double DriveSubsystem::angle() {
	return gyro->GetAngleZ();
}

double DriveSubsystem::angle_rate() {
	return gyro->GetRateZ();
}

void DriveSubsystem::zero_sensors() {
	gyro->Reset();
	DriveEncoder->Reset();
	DriveEncoder2->Reset();
}

void DriveSubsystem::drive(Joystick* left, Joystick* right) {
	auto curve = drive_curves::nocurve;
	double left_value = left->GetRawAxis(1);
	double right_value = right->GetRawAxis(1);
	double avg = (left_value + right_value) / 2.0;
	double test = fabs(left_value - right_value)/fabs(avg)/Preferences::GetInstance()->GetDouble("Drive_Straight_Limit", 1.7);
	if(test < 1.0) {
		left_value = left_value * test + avg * (1.0 - test);
		right_value = right_value * test + avg * (1.0 - test);
	}
	drive(curve(right_value), curve(left_value), false);
}

double ramp(double last, double target) {
//	const double step = 0.1;
	if(last < 0 && target < 0 && target > last)
		return target;
	if(last > 0 && target > 0 && target < last)
		return target;
	if(!((last > 100.0) ^ (last < 100.0)))
		return 0.0;
	return last * (1-0.1) + target * 0.1;
}

void DriveSubsystem::drive(double left, double right, bool do_ramp) {
	double new_left = left;
	double new_right = right;
//	if(do_ramp) {
//		new_left = ramp(last_left, left);
//		new_right = ramp(last_right, right);
//	}
	DriveRight1->SetSpeed(new_right);
	DriveRight2->SetSpeed(new_right);
	DriveRight3->SetSpeed(new_right);
	DriveLeft1->SetSpeed(-new_left);
	DriveLeft2->SetSpeed(-new_left);
	DriveLeft3->SetSpeed(-new_left);
	last_right = new_right;
	last_left = new_left;
}

void DriveSubsystem::auto_drive(double distanceTarget, double angleTarget, double speed) {
	double drive_kP = 5.0;
	double drive_kD = 0.3;

	// Calculate the error on the distance traveled
	double distance_error = (distance() - distanceTarget);
	double distance_out = drive_kP * distance_error + drive_kD * (distance_error - last_distance_error) / last_pid_time.Get();
	last_distance_error = distance_error;

	// Make sure the distance error does not exceed 100%
	if(distance_out > 0.9) {
		distance_out = 0.9;
	} else if(distance_out < -0.9) {
		distance_out = -0.9;
	}

	double angle_kP = 0.1;
	double angle_kD = 0.00;

	// Calculate the difference between the current angle and the desired angle
	double angle_error = (angle() - angleTarget);
	double angle_out = angle_kP * angle_error + angle_kD * (angle_error - last_angle_error) / last_pid_time.Get();
	last_angle_error = angle_error;

	if(angle_out > 0.5) {
		angle_out = 0.5;
	} else if(angle_out < -0.5) {
		angle_out = -0.5;
	}

	last_pid_time.Reset();
	last_pid_time.Start();


	// Set the motors to run
	drive(-angle_out + speed*distance_out, angle_out + speed*distance_out, true);
}

bool DriveSubsystem::on_target(double distanceTarget, double angleTarget) {
	double distanceError = distance() - distanceTarget;
	double angleError = angleTarget - angle();
	return distanceError < 0.05 && distanceError > -0.05 && angleError < 1.0 && angleError > -1.0;
}

bool DriveSubsystem::on_target(double distanceTarget, double distanceTolerence, double angleTarget, double angleTolerence) {
	double distanceError = distance() - distanceTarget;
	double angleError = angleTarget - angle();
	return
			distanceError < distanceTolerence && distanceError > -distanceTolerence &&
			angleError < angleTolerence && angleError > -angleTolerence;
}

void DriveSubsystem::prints() {
	SmartDashboard::PutNumber("drive.angle(degrees)", angle());
	SmartDashboard::PutNumber("drive.distance(feet)", distance());
	SmartDashboard::PutNumber("drive.ultrasonic(feet)", distance_to_wall());
	SmartDashboard::PutNumber("Drive Speed", ((DriveEncoder->GetRate() - DriveEncoder2->GetRate())/2.0)/76.83333333);
}

namespace drive_curves {
	double nocurve(double x) {
		if(OI::DriveDeadzone(x)) {
			return 0.0;
		}
		return x;
	}

	template<int Degree>
	double exponential(double x) {
		return pow(x, Degree);
	}

	double cheesy_curve(double x) {
		if(OI::DriveDeadzone(x)) {
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
