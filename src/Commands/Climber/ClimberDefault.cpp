#include "Commands/Climber/ClimberDefault.h"
#include "Subsystems/ClimberSubsystem.h"

ClimberDefault::ClimberDefault():
	CommandBase("ClimberDefault")
	{
	Requires(climber.get());
	}
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());


// Called just before this Command runs the first time
void ClimberDefault::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void ClimberDefault::Execute() {
//	climber->Climber->SetPI
}

// Make this return true when this Command no longer needs to run execute()
bool ClimberDefault::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ClimberDefault::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ClimberDefault::Interrupted() {

}
