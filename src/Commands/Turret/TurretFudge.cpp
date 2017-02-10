#include <Commands/Turret/TurretFudge.h>


// Allows the driver to drive the robot by making the speed of the robot = the Y axis value

// needs the undivided attention of the drive subsystem
TurretFudge::TurretFudge():
	CommandBase("TurretFudge")
{
	Requires(turret.get());
}

// Called just before this Command runs the first time
void TurretFudge::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
//makes the speed of the robot = the Y axis value of the joysticks
void TurretFudge::Execute()
{
	//slow
	if(!OI::DriveDeadzone(oi->operatorController->GetRawAxis(0))){
		turret->SetPower((oi->operatorController->GetRawAxis(0))*0.25);
	}else if(!OI::DriveDeadzone(oi->operatorController->GetRawAxis(2))){//fast
		turret->SetPower((oi->operatorController->GetRawAxis(2))*0.5);
	}
}

// Make this return true when this Command no longer needs to run execute()
// never ends
bool TurretFudge::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
//stops the drive motor
void TurretFudge::End()
{
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
//stops the drive motors when .....see above....
void TurretFudge::Interrupted()
{

}
