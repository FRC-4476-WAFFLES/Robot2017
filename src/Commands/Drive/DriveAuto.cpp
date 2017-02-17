/**
 * Drives in a direction for a certain number of encoder tick
 */

#include "DriveAuto.h"

DriveAuto::DriveAuto(double distance, double angle):
	CommandBase("DriveAuto")
{
	// We need the drive subsystem to not be doing anything else
	Requires(drive.get());

	// Remember distance and angle for later
	this->distance = distance;
	this->angle = angle;
	this->speed = 0.5;
}

DriveAuto::DriveAuto(double distance, double angle, double speed):
			CommandBase("DriveAuto")
{
	// We need the drive subsystem to not be doing anything else
	Requires(drive.get());

	// Remember distance and angle for later
	this->distance = distance;
	this->angle = angle;
	this->speed = speed;
}

void DriveAuto::Initialize() {
	done.Reset();
	done.Start();
}

void DriveAuto::Execute() {
	drive->auto_drive(distance, angle, speed);
	if(!drive->on_target(distance, angle)) {
		done.Reset();
		done.Start();
	}
}

bool DriveAuto::IsFinished() {
	return done.HasPeriodPassed(0.1);
}

// Stop the motors when this command ends
void DriveAuto::End() {
	drive->drive(0.0, 0.0, false);
}

// Stop the motors when this command is interrupted by another
void DriveAuto::Interrupted() {
	drive->drive(0.0, 0.0, false);
}
