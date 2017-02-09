#include <Commands/Drive/DriveOperator.h>
#include <Commands/Intake/IntakeDefault.h>
#include <Subsystems/DriveSubsystem.h>
IntakeDefault::IntakeDefault():
	CommandBase("IntakeOut")
	{
	Requires(intake.get());
	}
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());


// Called just before this Command runs the first time
void IntakeDefault::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void IntakeDefault::Execute() {
//	intake->BallConveyor->SetSpeed(oi->operatorController->GetRawAxis(1));
//	if((oi.get()->joystickLeft->GetRawAxis(1) > 0.1 && oi.get()->joystickRight->GetRawAxis(1) > 0.1) || oi->joystickLeft->GetRawButton(1)){
//		intake->IntakeRollers->SetSpeed(0.7258);
//		intake->BallConveyor->SetSpeed(1.0);
//	} else {
//		intake->IntakeRollers->SetSpeed(0.0);
//		intake->BallConveyor->SetSpeed(0.0);
//	}
	intake->IntakeRollers->SetSpeed(0);
	intake->BallConveyor->Set(0);
}

// Make this return true when this Command no longer needs to run execute()
bool IntakeDefault::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void IntakeDefault::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void IntakeDefault::Interrupted() {

}
