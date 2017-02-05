#include <Commands/Shooter/ShooterDefault.h>


// Allows the driver to drive the robot by making the speed of the robot = the Y axis value

// needs the undivided attention of the drive subsystem
ShooterDefault::ShooterDefault():
	CommandBase("ShooterDefault")
{
	Requires(shooter.get());
}

// Called just before this Command runs the first time
void ShooterDefault::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
//makes the speed of the robot = the Y axis value of the joysticks
void ShooterDefault::Execute()
{
	shooter->Turret->Set(0.0);
	//shooter->Rollers->Set(0.0);
	if(oi->operatorController->GetRawButton(oi->A)){
	shooter->Load->Set(1.0);

	}else{
		shooter->Load->Set(0.0);
	}
	if(oi->operatorController->GetRawButton(oi->B)){
	shooter->Rollers->Set(Preferences::GetInstance()->GetDouble("Shot_Speed", 0.0));

	}else{
		shooter->Rollers->Set(0.0);
	}

}

// Make this return true when this Command no longer needs to run execute()
// never ends
bool ShooterDefault::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
//stops the drive motor
void ShooterDefault::End()
{
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
//stops the drive motors when .....see above....
void ShooterDefault::Interrupted()
{

}
