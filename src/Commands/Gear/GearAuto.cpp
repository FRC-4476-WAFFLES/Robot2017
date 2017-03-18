#include "Commands/Gear/GearAuto.h"
#include "Subsystems/GearSubsystem.h"

GearAuto::GearAuto() :
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	CommandBase("GearAuto")
{
	Requires(gear.get());
}



// Called just before this Command runs the first time
void GearAuto::Initialize() {
	t.Reset();
	t.Start();
}

// Called repeatedly when this Command is scheduled to run
void GearAuto::Execute() {
	gear->is_open = true;
	gear->Persist();
}

// Make this return true when this Command no longer needs to run execute()
bool GearAuto::IsFinished() {
	return t.HasPeriodPassed(0.4);

}

// Called once after isFinished returns true
void GearAuto::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void GearAuto::Interrupted() {

}
