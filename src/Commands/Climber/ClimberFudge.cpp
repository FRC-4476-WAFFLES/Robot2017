#include "Commands/Climber/ClimberFudge.h"
#include "Subsystems/ClimberSubsystem.h"
#include "OI.h"

ClimberFudge::ClimberFudge():
	CommandBase("ClimberFudge")
{
	Requires(climber.get());
}
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());


// Called just before this Command runs the first time
void ClimberFudge::Initialize() {
	climber->hold = climber->Climber->GetSelectedSensorPosition(0);
}

// Called repeatedly when this Command is scheduled to run
void ClimberFudge::Execute() {
//	climber->SetPower(oi->operatorController->GetY());
	if(!oi->DriveDeadzone(oi->operatorController->GetY())) {
		climber->SetPosition(climber->GetPosition() + oi->operatorController->GetY());
		climber->hold = climber->GetPosition();
	} else if(!oi->DriveDeadzone(oi->operatorController->GetRawAxis(3))) {
		climber->SetPosition(climber->GetPosition() + oi->operatorController->GetRawAxis(3)*0.075);
		climber->hold = climber->GetPosition();
	} else {
		climber->SetPosition(climber->hold);
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
