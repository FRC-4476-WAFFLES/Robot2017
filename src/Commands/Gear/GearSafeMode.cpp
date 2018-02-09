#include "Commands/Gear/GearSafeMode.h"
#include "Subsystems/GearSubsystem.h"


GearSafeMode::GearSafeMode():
	CommandBase("GearSafeMode")
{

	Requires(gear.get());
}

// Called just before this Command runs the first time
void GearSafeMode::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void GearSafeMode::Execute() {
	gear->SafeMode = true;
}

// Make this return true when this Command no longer needs to run execute()
bool GearSafeMode::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void GearSafeMode::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void GearSafeMode::Interrupted() {
	gear->SafeMode = true;
}
