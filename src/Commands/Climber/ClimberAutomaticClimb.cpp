#include "Commands/Climber/ClimberAutomaticClimb.h"
#include "Subsystems/ClimberSubsystem.h"

ClimberAutomaticClimb::ClimberAutomaticClimb():
	CommandBase("ClimberAutomaticClimb")
	{
	Requires(climber.get());
	}



// Called just before this Command runs the first time
void ClimberAutomaticClimb::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void ClimberAutomaticClimb::Execute() {
	climber->AutomaticClimb();
}

// Make this return true when this Command no longer needs to run execute()
bool ClimberAutomaticClimb::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ClimberAutomaticClimb::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ClimberAutomaticClimb::Interrupted() {

}
