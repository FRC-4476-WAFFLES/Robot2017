#include "IntakeDefault.h"
#include "IntakeIn.h"



// Allows the driver to drive the robot by making the speed of the robot = the Y axis value

// needs the undivided attention of the drive subsystem
IntakeDefault::IntakeDefault():
	CommandBase("IntakeDefault")
{
	Requires(intake.get());
}

// Called just before this Command runs the first time
void IntakeDefault::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
//makes the speed of the robot = the Y axis value of the joysticks
void IntakeDefault::Execute()
{
	intake->IntakeRollers->SetSpeed(0.0);
	intake->BallConveyor->SetSpeed(0.0);
	//TODO add button
	if(false){
		Scheduler::GetInstance()->AddCommand(new IntakeIn);
	}

}

// Make this return true when this Command no longer needs to run execute()
// never ends
bool IntakeDefault::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
//stops the drive motor
void IntakeDefault::End()
{
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
//stops the drive motors when .....see above....
void IntakeDefault::Interrupted()
{
	intake->IntakeRollers->SetSpeed(0.0);
	intake->BallConveyor->SetSpeed(0.0);

}
