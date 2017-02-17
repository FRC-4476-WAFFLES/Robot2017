#include <Commands/Turret/TurretCenterShot.h>


// Allows the driver to drive the robot by making the speed of the robot = the Y axis value

// needs the undivided attention of the drive subsystem
TurretCenterShot::TurretCenterShot():
	CommandBase("TurretCenterShot")
{
	Requires(turret.get());
}

// Called just before this Command runs the first time
void TurretCenterShot::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
//makes the speed of the robot = the Y axis value of the joysticks
void TurretCenterShot::Execute()
{
	turret->Determined_Speed = Preferences::GetInstance()->GetDouble("Center Speed", 14.8);

	double angle = Preferences::GetInstance()->GetDouble("Center Angle", 74.1);
	if(DriverStation::GetInstance().GetAlliance() == DriverStation::kRed){
		turret->SetAngle(90.0-angle);
	}else{
		turret->SetAngle(90.0+angle);
	}
}

// Make this return true when this Command no longer needs to run execute()
// never ends
bool TurretCenterShot::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
//stops the drive motor
void TurretCenterShot::End()
{
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
//stops the drive motors when .....see above....
void TurretCenterShot::Interrupted()
{

}
