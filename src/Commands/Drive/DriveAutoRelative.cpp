/**
 * Drives in a direction for a certain number of encoder tick
 */

#include "DriveAutoRelative.h"

DriveAutoRelative::DriveAutoRelative(double distance, double angle):
	CommandBase("DriveAutoRelative")
{
	// We need the drive subsystem to not be doing anything else
	Requires(drive.get());

	// Remember distance and angle for later
	this->distanceRelative = distance;
	this->distance = 0;
	this->angle = 0;
	this->angleRelative = angle;
	this->speed = 0.5;
}

DriveAutoRelative::DriveAutoRelative(double distance, double angle, double speed):
			CommandBase("DriveAutoRelative")
{
	// We need the drive subsystem to not be doing anything else
	Requires(drive.get());

	// Remember distance and angle for later
	this->distanceRelative = distance;
	this->angle = 0;
	this->distance = 0;
	this->angleRelative = angle;
	this->speed = speed;
}

void DriveAutoRelative::Initialize() {
	distance = drive->distance() + distanceRelative;
	angle = drive->angle() + angleRelative;
}

void DriveAutoRelative::Execute() {
	drive->auto_drive(distance, angle, speed);
}

bool DriveAutoRelative::IsFinished() {
	return drive->on_target(distance, angle);
}

// Stop the motors when this command ends
void DriveAutoRelative::End() {
	drive->drive(0.0, 0.0, false);
}

// Stop the motors when this command is interrupted by another
void DriveAutoRelative::Interrupted() {
	drive->drive(0.0, 0.0, false);
}
