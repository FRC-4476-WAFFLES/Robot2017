#include "Commands/Drawer/DrawerBumper.h"
#include "Subsystems/DrawerSubsystem.h"

DrawerBumper::DrawerBumper():
	CommandBase("DrawerBumper")
{
	Requires(drawer.get());
}

// Called just before this Command runs the first time
void DrawerBumper::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void DrawerBumper::Execute() {
	//TODO real numbers
	drawer->Drawer->SetSetpoint(1140.0);
}

// Make this return true when this Command no longer needs to run execute()
bool DrawerBumper::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void DrawerBumper::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DrawerBumper::Interrupted() {

}
