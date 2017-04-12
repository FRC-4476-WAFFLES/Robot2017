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
	 Climber = new CANTalon(TOP_CLIMBER_ROLLER);
	 Climber_Slave = new CANTalon(TOP_CLIMBER_SLAVE);

	 Climber->SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);
	 Climber->SetSensorDirection(true);

	 //peak outputs
     Climber->ConfigNominalOutputVoltage(+0.0f, -0.0f);
     Climber->ConfigPeakOutputVoltage(+12.0f, -12.0f);

     //PID things
     Climber_Slave->SetControlMode(CANSpeedController::kFollower);
	 Climber_Slave->Set(TOP_CLIMBER_ROLLER);

	 UpdatePID("Climber", Climber);
}

void ClimberSubsystem::InitDefaultCommand()
{
	// When no other commands are running, we do operator control
	SetDefaultCommand(new ClimberFudge());
}

void ClimberSubsystem::SetPosition(double position) {
	UpdatePID("Climber", Climber);
	Climber->SetControlMode(CANTalon::kPosition);
	Climber->Set(position);
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
	SmartDashboard::PutNumber("Climber Encoder", Climber->GetPosition());
	SmartDashboard::PutNumber("y axis slow", CommandBase::oi->operatorController->GetRawAxis(3));
}
