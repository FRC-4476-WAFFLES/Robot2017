#include "Commands/Drawer/DrawerIn.h"
#include "Subsystems/DrawerSubsystem.h"

DrawerIn::DrawerIn():
	CommandBase("DrawerIn")
{
	Requires(drawer.get());
}

// Called just before this Command runs the first time
void DrawerIn::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void DrawerIn::Execute() {
	drawer->Drawer->SetSetpoint(0.0);
}

// Make this return true when this Command no longer needs to run execute()
bool DrawerIn::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void DrawerIn::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DrawerIn::Interrupted() {

}
