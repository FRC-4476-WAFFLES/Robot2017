#include "Commands/Climber/ClimberGrabReverse.h"
#include "Subsystems/ClimberSubsystem.h"

ClimberGrabReverse::ClimberGrabReverse():
	CommandBase("ClimberGrabReverse")
	{
	Requires(climber.get());
	}
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());


// Called just before this Command runs the first time
void ClimberGrabReverse::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void ClimberGrabReverse::Execute() {
	climber->SetPower(0.2);
}

// Make this return true when this Command no longer needs to run execute()
bool ClimberGrabReverse::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ClimberGrabReverse::End() {
	climber->SetPower(0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ClimberGrabReverse::Interrupted() {
	climber->SetPower(0.0);
}
