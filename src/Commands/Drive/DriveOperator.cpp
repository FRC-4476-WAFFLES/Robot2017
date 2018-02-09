// Allows the driver to drive the robot by making the speed of the robot = the Y axis value

#include "Commands/Drive/DriveOperator.h"
#include "Subsystems/DriveSubsystem.h"
#include "OI.h"

// needs the undivided attention of the drive subsystem
DriveOperator::DriveOperator():
	CommandBase("DriveAuto")
{
	Requires(drive.get());
}

// Called just before this Command runs the first time
void DriveOperator::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
//makes the speed of the robot = the Y axis value of the joysticks
void DriveOperator::Execute()
{
	drive->drive(oi.get()->joystickLeft, oi.get()->joystickRight);
}

// Make this return true when this Command no longer needs to run execute()
// never ends
bool DriveOperator::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
//stops the drive motor
void DriveOperator::End()
{
	drive->drive(0.0, 0.0, false);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
//stops the drive motors when .....see above....
void DriveOperator::Interrupted()
{
	drive->drive(0.0, 0.0, false);
}
