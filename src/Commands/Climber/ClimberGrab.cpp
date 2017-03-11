#include <Commands/Drive/DriveOperator.h>
#include <Commands/Climber/ClimberGrab.h>
#include <Subsystems/DriveSubsystem.h>
ClimberGrab::ClimberGrab():
	CommandBase("ClimberGrab")
	{
	Requires(climber.get());
	}
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());


// Called just before this Command runs the first time
void ClimberGrab::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void ClimberGrab::Execute() {
	climber->SetPower(0.2);
}

// Make this return true when this Command no longer needs to run execute()
bool ClimberGrab::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ClimberGrab::End() {
	climber->SetPower(0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ClimberGrab::Interrupted() {
	climber->SetPower(0.0);
}
