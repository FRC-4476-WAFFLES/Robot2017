#include <Commands/Shooter/TurretTest.h>


// Allows the driver to drive the robot by making the speed of the robot = the Y axis value

// needs the undivided attention of the drive subsystem
TurretTest::TurretTest():
	CommandBase("TurretTest")
{
	Requires(shooter.get());
}

// Called just before this Command runs the first time
void TurretTest::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
//makes the speed of the robot = the Y axis value of the joysticks
void TurretTest::Execute()
{
	shooter->Load->Set(0.0);
	shooter->SetSpeed(0.0);

	if(oi->BumperBottomLeft){
		shooter->SetTurret(-15.0);
	}else if(oi->BumperBottomRight){
		shooter->SetTurret(15.0);
	}else{
		shooter->SetTurret(0.0);
	}


}

// Make this return true when this Command no longer needs to run execute()
// never ends
bool TurretTest::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
//stops the drive motor
void TurretTest::End()
{
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
//stops the drive motors when .....see above....
void TurretTest::Interrupted()
{

}




