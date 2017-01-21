#include <Commands/Intake/IntakeOut.h>


// Allows the driver to drive the robot by making the speed of the robot = the Y axis value

// needs the undivided attention of the drive subsystem
IntakeOut::IntakeOut():
	CommandBase("IntakeOut")
{
	Requires(intake.get());
}

// Called just before this Command runs the first time
void IntakeOut::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
//makes the speed of the robot = the Y axis value of the joysticks
void IntakeOut::Execute()
{
	intake->IntakeRollers->SetSpeed(-0.7258);
	intake->BallConveyor->SetSpeed(-0.85);
}

// Make this return true when this Command no longer needs to run execute()
// never ends
bool IntakeOut::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
//stops the drive motor
void IntakeOut::End()
{
	intake->IntakeRollers->SetSpeed(0.0);
	intake->BallConveyor->SetSpeed(0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
//stops the drive motors when .....see above....
void IntakeOut::Interrupted()
{

}
