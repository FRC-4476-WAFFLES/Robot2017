#include "Commands/Climber/ClimberFudge.h"
#include "Subsystems/ClimberSubsystem.h"
#include "OI.h"

ClimberFudge::ClimberFudge():
	CommandBase("ClimberFudge")
{
	Requires(climber.get());
	hold = climber->Climber->GetPosition();
}
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());


// Called just before this Command runs the first time
void ClimberFudge::Initialize() {
	hold = climber->Climber->GetPosition();
}

// Called repeatedly when this Command is scheduled to run
void ClimberFudge::Execute() {
	if(!oi->DriveDeadzone(oi->operatorController->GetY())){
		climber->SetPosition(climber->GetPosition() + oi->operatorController->GetY());
		hold = climber->GetSetpoint();
	} else {
		climber->SetPosition(hold);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool ClimberFudge::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ClimberFudge::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ClimberFudge::Interrupted() {

}
