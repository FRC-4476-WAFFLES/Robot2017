#include "GearToggle.h"


GearToggle::GearToggle():
	CommandBase("GearToggle")
{

	Requires(gear.get());
}

// Called just before this Command runs the first time
void GearToggle::Initialize() {
	gear->Toggle();
}

// Called repeatedly when this Command is scheduled to run
void GearToggle::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool GearToggle::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void GearToggle::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void GearToggle::Interrupted() {

}
