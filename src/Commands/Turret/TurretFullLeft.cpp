#include <Commands/Turret/TurretFullLeft.h>


// Allows the driver to drive the robot by making the speed of the robot = the Y axis value

// needs the undivided attention of the drive subsystem
TurretFullLeft::TurretFullLeft():
	CommandBase("TurretFullLeft")
{
	Requires(turret.get());
}

// Called just before this Command runs the first time
void TurretFullLeft::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
//makes the speed of the robot = the Y axis value of the joysticks
void TurretFullLeft::Execute()
{
	turret->Determined_Speed = Preferences::GetInstance()->GetDouble("Left Speed", 14.8);
	if(!turret->Turret->IsRevLimitSwitchClosed()){
		turret->SetPower(-0.45);
	}else{
		turret->SetPower(0.0);
	}
}

// Make this return true when this Command no longer needs to run execute()
// never ends
bool TurretFullLeft::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
//stops the drive motor
void TurretFullLeft::End()
{
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
//stops the drive motors when .....see above....
void TurretFullLeft::Interrupted()
{

}
