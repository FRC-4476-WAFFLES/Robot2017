#include <Commands/Drive/DriveOperator.h>
#include <Commands/Climber/ClimberStop.h>
#include <Subsystems/DriveSubsystem.h>
#include <WPILib.h>
#include <math.h>
ClimberStop::ClimberStop():
	CommandBase("ClimberStop")
	{
	Requires(climber.get());
	}
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());


// Called just before this Command runs the first time
void ClimberStop::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void ClimberStop::Execute() {
	if (int(climber->distance()) % 128 < 10){
	climber->SetPower(0.0);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool ClimberStop::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ClimberStop::End() {
	climber->SetPower(0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ClimberStop::Interrupted() {
	climber->SetPower(0.0);
}
