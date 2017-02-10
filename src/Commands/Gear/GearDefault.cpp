#include "GearDefault.h"


GearDefault::GearDefault():
	CommandBase("GearDeafault")
{

	Requires(gear.get());
}

// Called just before this Command runs the first time
void GearDefault::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void GearDefault::Execute() {

	if(Toggle == 0 && oi->Start){
		gear->Closed();
		Toggle = 1;
	}
}

// Make this return true when this Command no longer needs to run execute()
bool GearDefault::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void GearDefault::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void GearDefault::Interrupted() {

}
