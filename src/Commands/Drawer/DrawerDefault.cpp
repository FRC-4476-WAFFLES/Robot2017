#include "Commands/Drawer/DrawerDefault.h"
#include "Subsystems/DrawerSubsystem.h"

DrawerDefault::DrawerDefault():
	CommandBase("DrawerDefault")
{
	Requires(drawer.get());
}

// Called just before this Command runs the first time
void DrawerDefault::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void DrawerDefault::Execute() {
	drawer->Drawer->Set(ControlMode::PercentOutput,0.0);

}

// Make this return true when this Command no longer needs to run execute()
bool DrawerDefault::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void DrawerDefault::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DrawerDefault::Interrupted() {

}
