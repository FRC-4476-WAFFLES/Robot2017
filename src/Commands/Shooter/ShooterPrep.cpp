#include <Commands/Shooter/ShooterPrep.h>


// Allows the driver to drive the robot by making the speed of the robot = the Y axis value

// needs the undivided attention of the drive subsystem
ShooterPrep::ShooterPrep():
	CommandBase("ShooterPrep")
{
	Requires(shooter.get());
}

// Called just before this Command runs the first time
void ShooterPrep::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
//makes the speed of the robot = the Y axis value of the joysticks
void ShooterPrep::Execute()
{
	shooter->Load->Set(0.0);
	shooter->Rollers->Set(-1.0);
}

// Make this return true when this Command no longer needs to run execute()
// never ends
bool ShooterPrep::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
//stops the drive motor
void ShooterPrep::End()
{
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
//stops the drive motors when .....see above....
void ShooterPrep::Interrupted()
{

}
