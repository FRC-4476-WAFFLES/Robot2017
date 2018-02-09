/**
 * ClimberSubsystem is a class that keeps references to each of the
 * drive motors and drive encoder.
 */
#include <Commands/Climber/ClimberFudge.h>
#include "ClimberSubsystem.h"
#include "../RobotMap.h"
#include "Helpers/PIDPreferences.h"
#include "oi.h"

ClimberSubsystem::ClimberSubsystem():
		Subsystem("ClimberSubsystem")
{
	 Climber = new TalonSRX(TOP_CLIMBER_ROLLER);
	 Climber_Slave = new TalonSRX(TOP_CLIMBER_SLAVE);

	 Climber->ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder,0,0);
	 Climber->SetSensorPhase(true);


     //PID things
     Climber_Slave->Set(ControlMode::Follower,TOP_CLIMBER_ROLLER);

	 UpdatePID("Climber", Climber);


}

void ClimberSubsystem::InitDefaultCommand()
{
	// When no other commands are running, we do operator control
	SetDefaultCommand(new ClimberFudge());
}

void ClimberSubsystem::SetPosition(double position) {
	UpdatePID("Climber", Climber);
	Climber->SetControlMode(TalonSRX::PositionMode);
	Climber->Set(position);
}
void ClimberSubsystem::AutomaticClimb()
{
	//TODO: get real numbers here for climber power
	if(ClimberPower.GetCurrent(3) < 1.5){
		Climber->SetControlMode(CANSpeedController::kPercentVbus);
		Climber->Set(-0.2);
		hold = Climber->GetPosition();
	} else {
		Climber->SetControlMode(CANSpeedController::kPercentVbus);
		Climber->Set(-1.0);
		hold = Climber->GetPosition();
	}
}

double ClimberSubsystem::GetPosition() {
	return Climber->GetPosition();
}

double ClimberSubsystem::GetSetpoint() {
	return Climber->Get();
}

void ClimberSubsystem::SetPower(double power) {
	Climber->SetControlMode(CANTalon::kPercentVbus);
	Climber->Set(power);
}

void ClimberSubsystem::prints() {
	Command* current = GetCurrentCommand();
	if(current != nullptr) {
		SmartDashboard::PutString("Climber Command", current->GetName());
	} else {
		SmartDashboard::PutString("Climber Command", "None");
	}
	SmartDashboard::PutNumber("Climber Encoder", Climber->getSelectedSensorPosition());
	SmartDashboard::PutNumber("Climber Encoder Target", Climber->GetClosedLoopTarget());
}
