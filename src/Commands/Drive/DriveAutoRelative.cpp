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
	// Calculate the error on the distance traveled
		double distanceError = (drive->distance() - distance)*0.01;

		// Make sure the distance error does not exceed 100%
		if(distanceError > 1.0) {
			distanceError = 1.0;
		}
		if(distanceError < -1.0) {
			distanceError = -1.0;
		}

		// Calculate the difference between the current angle and the desired angle
		double angleError = angle - drive->angle();

		// Set the motors to run
		drive->drive(0.01*angleError + speed*distanceError, -0.01*angleError + speed*distanceError);
}

// Returns true when the distance is within 200 and the angle is within 5 degrees
bool DriveAutoRelative::IsFinished() {
	double distanceError = drive->distance() - distance;
	double angleError = angle - drive->angle();
	return distanceError < 20 && distanceError > -20 && angleError < 5.0 && angleError > -5.0;
}

// Stop the motors when this command ends
void DriveAutoRelative::End() {
	drive->drive(0.0, 0.0);
}

// Stop the motors when this command is interrupted by another
void DriveAutoRelative::Interrupted() {
	drive->drive(0.0, 0.0);
}
