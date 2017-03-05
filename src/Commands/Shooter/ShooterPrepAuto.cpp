#include <Commands/Shooter/ShooterPrepAuto.h>


// Allows the driver to drive the robot by making the speed of the robot = the Y axis value

// needs the undivided attention of the drive subsystem
ShooterPrepAuto::ShooterPrepAuto():
	CommandBase("ShooterPrepAuto")
{
	Requires(shooter.get());
}

// Called just before this Command runs the first time
void ShooterPrepAuto::Initialize()
{
	t.Reset();
	t.Start();
}

// Called repeatedly when this Command is scheduled to run
//makes the speed of the robot = the Y axis value of the joysticks
void ShooterPrepAuto::Execute()
{
	shooter->StopLoad();
	shooter->SetSpeed(turret->Determined_Speed);
}

// Make this return true when this Command no longer needs to run execute()
// never ends
bool ShooterPrepAuto::IsFinished()
{
	return t.HasPeriodPassed(1.0);
}

// Called once after isFinished returns true
//stops the drive motor
void ShooterPrepAuto::End()
{
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
//stops the drive motors when .....see above....
void ShooterPrepAuto::Interrupted()
{

}
