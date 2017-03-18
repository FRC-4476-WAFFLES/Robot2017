/**
 * Drives in a direction for a certain number of encoder tick
 */

#include "Commands/Drive/DriveHalf.h"
#include "Subsystems/DriveSubsystem.h"

DriveHalf::DriveHalf(double angle, double percent_right):
	CommandBase("DriveAuto")
{
	// We need the drive subsystem to not be doing anything else
	Requires(drive.get());

	// Remember distance and angle for later
	this->angle = angle;
	this->speed = 0.5;
	this->percent_right = percent_right;
}

DriveHalf::DriveHalf(double angle, double speed, double percent_right):
			CommandBase("DriveAuto")
{
	// We need the drive subsystem to not be doing anything else
	Requires(drive.get());

	// Remember distance and angle for later
	this->angle = angle;
	this->speed = speed;
	this->percent_right = percent_right;
}

void DriveHalf::Initialize() {

}

void DriveHalf::Execute() {

	// Calculate the difference between the current angle and the desired angle
	double angleError = angle - drive->angle();

	drive->drive((speed * 0.1) * angleError * (1.0 - percent_right), -(speed * 1.0) * angleError * percent_right, true);
}

// Returns true when the distance is within 200 and the angle is within 5 degrees
bool DriveHalf::IsFinished() {
	double angleError = angle - drive->angle();
	return angleError < 5.0 && angleError > -5.0;
}

// Stop the motors when this command ends
void DriveHalf::End() {
	drive->drive(0.0, 0.0, false);
}

// Stop the motors when this command is interrupted by another
void DriveHalf::Interrupted() {
	drive->drive(0.0, 0.0, false);
}
