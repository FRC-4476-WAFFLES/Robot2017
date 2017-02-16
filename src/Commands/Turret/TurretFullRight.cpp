#include <Commands/Turret/TurretFullRight.h>


// Allows the driver to drive the robot by making the speed of the robot = the Y axis value

// needs the undivided attention of the drive subsystem
TurretFullRight::TurretFullRight():
	CommandBase("TurretFullRight")
{
	Requires(turret.get());
}

// Called just before this Command runs the first time
void TurretFullRight::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
//makes the speed of the robot = the Y axis value of the joysticks
void TurretFullRight::Execute()
{
	if(!turret->Turret->IsFwdLimitSwitchClosed()){
		turret->SetPower(0.45);
	}else{
		turret->SetPower(0.0);
	}
}

// Make this return true when this Command no longer needs to run execute()
// never ends
bool TurretFullRight::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
//stops the drive motor
void TurretFullRight::End()
{
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
//stops the drive motors when .....see above....
void TurretFullRight::Interrupted()
{

}
