/**
 * Drives in a direction for a certain number of encoder tick
 */

#include "DriveHalfRelative.h"

DriveHalfRelative::DriveHalfRelative(double angle, int side):
	CommandBase("DriveAuto")
{
	// We need the drive subsystem to not be doing anything else
	Requires(drive.get());

	// Remember distance and angle for later
	this->angleRelative = angle;
	this->angle = 0;
	this->speed = 0.5;
	this->side = side;
}

DriveHalfRelative::DriveHalfRelative(double angle, double speed, int side):
			CommandBase("DriveAuto")
{
	// We need the drive subsystem to not be doing anything else
	Requires(drive.get());

	// Remember distance and angle for later
	this->angleRelative = angle;
	this->angle = angle;
	this->speed = speed;
	this->side = side;
}

void DriveHalfRelative::Initialize() {
	angle = drive->angle() + angleRelative;
}

void DriveHalfRelative::Execute() {

	// Calculate the difference between the current angle and the desired angle
	double angleError = angle - drive->angle();

	//1=right, 2=left
	if(side == 1){
		drive->drive(0.0, -0.01*angleError);
	}else if(side == 2){
		drive->drive(0.01*angleError, 0.0);
	}else{
		drive->drive(0.0, 0.0);
	}


	// Calculate the difference between the current angle and the desired angle


	// Set the motors to run
//	drive->drive(0.01*angleError, -0.01*angleError);
}

// Returns true when the distance is within 200 and the angle is within 5 degrees
bool DriveHalfRelative::IsFinished() {
	double angleError = angle - drive->angle();
	return angleError < 5.0 && angleError > -5.0;
}

// Stop the motors when this command ends
void DriveHalfRelative::End() {
	drive->drive(0.0, 0.0);
}

// Stop the motors when this command is interrupted by another
void DriveHalfRelative::Interrupted() {
	drive->drive(0.0, 0.0);
}
