#include <Commands/Shooter/ShooterShoot.h>


// Allows the driver to drive the robot by making the speed of the robot = the Y axis value

// needs the undivided attention of the drive subsystem
ShooterShoot::ShooterShoot():
	CommandBase("ShooterShoot")
{
	Requires(shooter.get());
}

// Called just before this Command runs the first time
void ShooterShoot::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
//makes the speed of the robot = the Y axis value of the joysticks
void ShooterShoot::Execute()
{
	shooter->RunLoad();
	shooter->SetPower(-Preferences::GetInstance()->GetDouble("Shot_Speed", 1.0));
}

// Make this return true when this Command no longer needs to run execute()
// never ends
bool ShooterShoot::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
//stops the drive motor
void ShooterShoot::End()
{
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
//stops the drive motors when .....see above....
void ShooterShoot::Interrupted()
{

}
