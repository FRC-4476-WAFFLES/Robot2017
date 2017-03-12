#include <Commands/Drive/DriveOperator.h>
#include <Commands/Climber/ClimberFudge.h>
#include <Subsystems/DriveSubsystem.h>
ClimberFudge::ClimberFudge():
	CommandBase("ClimberFudge")
	{
	Requires(climber.get());
	}
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());


// Called just before this Command runs the first time
void ClimberFudge::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void ClimberFudge::Execute() {
	climber->SetPower(oi->operatorController->GetY());
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