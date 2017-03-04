#include <Commands/Intake/ConveyorAuto.h>


// Allows the driver to drive the robot by making the speed of the robot = the Y axis value

// needs the undivided attention of the drive subsystem
ConveyorAuto::ConveyorAuto(double speed, double time):
	CommandBase("ConveyorAuto")
{
	Requires(intake.get());

	this->speed = speed;
	this->time = time;
}

// Called just before this Command runs the first time
void ConveyorAuto::Initialize()
{
	done.Reset();
	done.Start();
}

// Called repeatedly when this Command is scheduled to run
//makes the speed of the robot = the Y axis value of the joysticks
void ConveyorAuto::Execute()
{
	intake->IntakeRollers->SetSpeed(0.0);
	intake->BallConveyor->Set(speed);
}

// Make this return true when this Command no longer needs to run execute()
// never ends
bool ConveyorAuto::IsFinished()
{
	return done.HasPeriodPassed(time);
}

// Called once after isFinished returns true
//stops the drive motor
void ConveyorAuto::End()
{
	intake->IntakeRollers->SetSpeed(0.0);
	intake->BallConveyor->Set(0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
//stops the drive motors when .....see above....
void ConveyorAuto::Interrupted()
{
	intake->IntakeRollers->SetSpeed(0.0);
	intake->BallConveyor->Set(0.0);
}
