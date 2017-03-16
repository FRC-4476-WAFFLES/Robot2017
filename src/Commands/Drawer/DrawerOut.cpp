#include "Commands/Drawer/DrawerOut.h"
#include "Subsystems/DrawerSubsystem.h"

DrawerOut::DrawerOut():
	CommandBase("DrawerOut")
{
	Requires(drawer.get());
}

// Called just before this Command runs the first time
void DrawerOut::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void DrawerOut::Execute() {
	//TODO real numbers
	drawer->Drawer->SetSetpoint(3910.0);
}

// Make this return true when this Command no longer needs to run execute()
bool DrawerOut::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void DrawerOut::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DrawerOut::Interrupted() {

}
