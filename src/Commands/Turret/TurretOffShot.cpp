#include <Commands/Turret/TurretOffShot.h>


// Allows the driver to drive the robot by making the speed of the robot = the Y axis value

// needs the undivided attention of the drive subsystem
TurretOffShot::TurretOffShot():
	CommandBase("TurretOffShot")
{
	Requires(turret.get());
}

// Called just before this Command runs the first time
void TurretOffShot::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
//makes the speed of the robot = the Y axis value of the joysticks
void TurretOffShot::Execute()
{
	turret->Determined_Speed = Preferences::GetInstance()->GetDouble("Off Speed", 110.0);

	if(DriverStation::GetInstance().GetAlliance() == DriverStation::kBlue){
		turret->SetAngle(90.0+16.3);
	}else{
		turret->SetAngle(90.0-16.3);
	}
}

// Make this return true when this Command no longer needs to run execute()
// never ends
bool TurretOffShot::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
//stops the drive motor
void TurretOffShot::End()
{
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
//stops the drive motors when .....see above....
void TurretOffShot::Interrupted()
{

}
