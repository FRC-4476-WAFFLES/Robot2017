/**
 * Drives in a direction for a certain number of encoder tick
 */

#include "DriveHalfRelative.h"

DriveHalfRelative::DriveHalfRelative(double angle, double percent_right):
	CommandBase("DriveAuto")
{
	// We need the drive subsystem to not be doing anything else
	Requires(drive.get());

	// Remember distance and angle for later
	this->angleRelative = angle;
	this->angle = 0;
	this->speed = 1.0;
	this->percent_right = percent_right;
}

DriveHalfRelative::DriveHalfRelative(double angle, double percent_right, double speed):
			CommandBase("DriveAuto")
{
	// We need the drive subsystem to not be doing anything else
	Requires(drive.get());

	// Remember distance and angle for later
	this->angleRelative = angle;
	this->angle = angle;
	this->speed = speed;
	this->percent_right = percent_right;
}

void DriveHalfRelative::Initialize() {
	angle = drive->angle() + angleRelative;
}

void DriveHalfRelative::Execute() {
	// Calculate the difference between the current angle and the desired angle
	double angleError = (angle - drive->angle()) * 0.1;

	if(angleError > 0.9)
		angleError = 0.9;
	else if(angleError < -0.9)
		angleError = 0.9;

	drive->drive(speed * angleError * (1.0 - percent_right), -speed * angleError * percent_right, true);
}

// Returns true when the distance is within 200 and the angle is within 5 degrees
bool DriveHalfRelative::IsFinished() {
	double angleError = angle - drive->angle();
	return angleError < 5.0 && angleError > -5.0;
}

// Stop the motors when this command ends
void DriveHalfRelative::End() {
	drive->drive(0.0, 0.0, false);
}

// Stop the motors when this command is interrupted by another
void DriveHalfRelative::Interrupted() {
	drive->drive(0.0, 0.0, false);
}
