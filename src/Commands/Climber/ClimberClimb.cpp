#include "Commands/Climber/ClimberClimb.h"
#include "Subsystems/ClimberSubsystem.h"
#include <WPILib.h>

ClimberClimb::ClimberClimb():
	CommandBase("ClimberClimb")
	{
	Requires(climber.get());
	}
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());


// Called just before this Command runs the first time
void ClimberClimb::Initialize() {
	t.Reset();
	t.Start();
}

// Called repeatedly when this Command is scheduled to run
void ClimberClimb::Execute() {
	climber->SetPower(1.0);
}

// Make this return true when this Command no longer needs to run execute()
bool ClimberClimb::IsFinished() {
	return t.HasPeriodPassed(1);
}

// Called once after isFinished returns true
void ClimberClimb::End() {
	climber->SetPower(0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ClimberClimb::Interrupted() {
	climber->SetPower(0.0);
}
