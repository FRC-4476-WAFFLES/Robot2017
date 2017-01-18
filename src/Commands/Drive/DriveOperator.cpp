#include "DriveOperator.h"


// Allows the driver to drive the robot by making the speed of the robot = the Y axis value

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
	double controllerLeft = Preferences::GetInstance()->GetDouble("Speed",0.0); //+ oi.get()->operatorController->GetRawAxis(1) / 3.7;
	//double controllerRight = oi.get()->joystickRight->GetY(); // + oi.get()->operatorController->GetRawAxis(3) / 3.7;
	if (oi.get()->joystickLeft->GetRawButton(1)){
		drive->Drive(controllerLeft,controllerLeft);
	}else{
		drive->Drive(0.0,0.0);
	}
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
	drive->drive(0.0, 0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
//stops the drive motors when .....see above....
void DriveOperator::Interrupted()
{
	drive->drive(0.0, 0.0);
}
