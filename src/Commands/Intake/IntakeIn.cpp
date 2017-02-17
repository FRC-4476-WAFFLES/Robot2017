#include <Commands/Intake/IntakeIn.h>
#include "IntakeDefault.h"


// Allows the driver to drive the robot by making the speed of the robot = the Y axis value

// needs the undivided attention of the drive subsystem
IntakeIn::IntakeIn():
	CommandBase("IntakeIn")
{

	Requires(intake.get());
}

// Called just before this Command runs the first time
void IntakeIn::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
//makes the speed of the robot = the Y axis value of the joysticks
void IntakeIn::Execute()
{
	intake->IntakeRollers->SetSpeed(-1.0);
	intake->BallConveyor->Set(-1.0);
	//TODO add button
	if(false){
		Scheduler::GetInstance()->AddCommand(new IntakeDefault);
	}
}

// Make this return true when this Command no longer needs to run execute()
// never ends
bool IntakeIn::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
//stops the drive motor
void IntakeIn::End()
{
	intake->IntakeRollers->SetSpeed(0.0);
	intake->BallConveyor->Set(0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
//stops the drive motors when .....see above....
void IntakeIn::Interrupted()
{

}
