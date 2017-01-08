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

}

void DriveAuto::Execute() {
	// Calculate the error on the distance traveled
	double distanceError = drive->driveEncoder() - distance;

	// Make sure the distance error does not exceed 100%
	if(distanceError > 1.0) {
		distanceError = 1.0;
	}
	if(distanceError < -1.0) {
		distanceError = -1.0;
	}

	// Calculate the difference between the current angle and the desired angle
	double angleError = angle - drive->GetGyro();

	// Set the motors to run
	drive->Drive(0.1*angleError - speed*distanceError, 0.1*angleError - speed*distanceError);
}

// Returns true when the distance is within 200 and the angle is within 5 degrees
bool DriveAuto::IsFinished() {
	double distanceError = drive->driveEncoder() - distance;
	double angleError = angle - drive->GetGyro();
	return distanceError < 200 && distanceError > -200 && angleError < 5.0 && angleError > -5.0;
}

// Stop the motors when this command ends
void DriveAuto::End() {
	drive->Drive(0.0, 0.0);
}

// Stop the motors when this command is interrupted by another
void DriveAuto::Interrupted() {
	drive->Drive(0.0, 0.0);
}
