/**
 * Drives in a direction for a certain number of encoder tick
 */

#include "Commands/Drive/DriveAutoTolerant.h"
#include "Subsystems/DriveSubsystem.h"

DriveAutoTolerant::DriveAutoTolerant(double distance, double angle):
	CommandBase("DriveAutoTolerant")
{
	// We need the drive subsystem to not be doing anything else
	Requires(drive.get());

	// Remember distance and angle for later
	this->distance = distance;
	this->angle = angle;
	this->speed = 0.3;
}

DriveAutoTolerant::DriveAutoTolerant(double distance, double angle, double speed):
			CommandBase("DriveAutoTolerant")
{
	// We need the drive subsystem to not be doing anything else
	Requires(drive.get());

	// Remember distance and angle for later
	this->distance = distance;
	this->angle = angle;
	this->speed = speed;
}

void DriveAutoTolerant::Initialize() {
	done.Reset();
	done.Start();
}

void DriveAutoTolerant::Execute() {
	drive->auto_drive(distance, angle, speed);
	if(!drive->on_target(distance, angle)) {
		done.Reset();
		done.Start();
	}
}

bool DriveAutoTolerant::IsFinished() {
	double distanceError = drive->distance() - distance;
	double angleError = angle - drive->angle();
	return distanceError < 0.5 && distanceError > -0.5 && angleError < 5.0 && angleError > -5.0;
}

// Stop the motors when this command ends
void DriveAutoTolerant::End() {
	drive->drive(0.0, 0.0, false);
}

// Stop the motors when this command is interrupted by another
void DriveAutoTolerant::Interrupted() {
	drive->drive(0.0, 0.0, false);
}
