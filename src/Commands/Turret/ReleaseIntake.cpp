#include <Commands/Turret/ReleaseIntake.h>


// Allows the driver to drive the robot by making the speed of the robot = the Y axis value

// needs the undivided attention of the drive subsystem
ReleaseIntake::ReleaseIntake():
	CommandBase("ReleaseIntake")
{
	Requires(turret.get());
}

// Called just before this Command runs the first time
void ReleaseIntake::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
//makes the speed of the robot = the Y axis value of the joysticks
void ReleaseIntake::Execute()
{
	turret->SetPower(0.45);
}

// Make this return true when this Command no longer needs to run execute()
// never ends
bool ReleaseIntake::IsFinished()
{
	return turret->GetAngle() < 130;
}

// Called once after isFinished returns true
//stops the drive motor
void ReleaseIntake::End()
{
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
//stops the drive motors when .....see above....
void ReleaseIntake::Interrupted()
{

}
