/**
 * Drives in a direction for a certain number of encoder tick
 */

#include "DriveHalf.h"

DriveHalf::DriveHalf(double angle, int side):
	CommandBase("DriveAuto")
{
	// We need the drive subsystem to not be doing anything else
	Requires(drive.get());

	// Remember distance and angle for later
	this->angle = angle;
	this->speed = 0.5;
	this->side = side;
}

DriveHalf::DriveHalf(double angle, double speed, int side):
			CommandBase("DriveAuto")
{
	// We need the drive subsystem to not be doing anything else
	Requires(drive.get());

	// Remember distance and angle for later
	this->angle = angle;
	this->speed = speed;
	this->side = side;
}

void DriveHalf::Initialize() {

}

void DriveHalf::Execute() {

	// Calculate the difference between the current angle and the desired angle
	double angleError = angle - drive->angle();

	//1=right, 2=left
	if(side == 1){
		drive->drive(0.0, -0.01*angleError, false);
	}else if(side == 2){
		drive->drive(0.01*angleError, 0.0, false);
	}else{
		drive->drive(0.0, 0.0, false);
	}


	// Calculate the difference between the current angle and the desired angle


	// Set the motors to run
//	drive->drive(0.01*angleError, -0.01*angleError);
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
