#include <Commands/Gear/GearAutoUltrasonic.h>

GearAutoUltrasonic::GearAutoUltrasonic() :
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	CommandBase("GearAutoUltrasonic")
{
	Requires(drive.get());
	Requires(gear.get());
	pos = drive->angle();
}



// Called just before this Command runs the first time
void GearAutoUltrasonic::Initialize() {
	t.Reset();
	t.Start();
	pos = drive->angle();
}

// Called repeatedly when this Command is scheduled to run
void GearAutoUltrasonic::Execute() {
	drive->DriveToGearWall(pos);
	gear->is_open = true;
	gear->Persist();
}

// Make this return true when this Command no longer needs to run execute()
bool GearAutoUltrasonic::IsFinished() {
	return t.HasPeriodPassed(0.4);
}

// Called once after isFinished returns true
void GearAutoUltrasonic::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void GearAutoUltrasonic::Interrupted() {

}
