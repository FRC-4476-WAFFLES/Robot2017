/**
 * ShooterSubsystem is a class that keeps references to each of the
 * drive motors and drive encoder.
 */
#include <Commands/Shooter/ShooterDefault.h>
#include "ShooterSubsystem.h"
#include "../RobotMap.h"
#include "CANTalon.h"
#include "vision/run_result.hpp"
ShooterSubsystem::ShooterSubsystem():
		Subsystem("ShooterSubsystem")
{

	 Rollers = new CANTalon(SHOOTER_ROLLER);
	 Rollers_Slave = new CANTalon(SHOOTER_ROLLER_SLAVE);
	 Load = new VictorSP(SHOOTER_LOAD);

	 //CANTALLON SETUP//
	 Rollers->SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);
	 Rollers->SetSensorDirection(true);


	 //peak outputs
     Rollers->ConfigNominalOutputVoltage(+0.0f, -0.0f);
     Rollers->ConfigPeakOutputVoltage(+0.0f, -12.0f);


     //PID things
	 Rollers_Slave->SetControlMode(CANSpeedController::kFollower);
	 Rollers_Slave->Set(SHOOTER_ROLLER);
}

void ShooterSubsystem::InitDefaultCommand()
{
	// When no other commands are running, we do operator control
	SetDefaultCommand(new ShooterDefault);
}

void UpdateRollersPID(CANTalon* Rollers) {
    Rollers->SelectProfileSlot(0);
    Rollers->SetF(Preferences::GetInstance()->GetDouble("F", 0.015));
	Rollers->SetP(Preferences::GetInstance()->GetDouble("P", 0.16));
	Rollers->SetI(Preferences::GetInstance()->GetDouble("I", 0.0));
	Rollers->SetD(Preferences::GetInstance()->GetDouble("D", 0.0));
}

void ShooterSubsystem::SetSpeed(double RPM) {
	if(-Rollers->GetSpeed() < -RPM/2) {
		SetPower(-0.5);
	} else {
		UpdateRollersPID(Rollers);
		Rollers->SetTalonControlMode(CANTalon::kSpeedMode);
		Rollers->Set(RPM);
	}
}

void ShooterSubsystem::SetPower(double power) {
	Rollers->SetControlMode(CANTalon::kPercentVbus);
	Rollers->Set(power);
}

void ShooterSubsystem::RunLoad() {
	Load->Set(-1.0);
}

void ShooterSubsystem::StopLoad() {
	Load->Set(0.0);
}

void ShooterSubsystem::prints() {
	SmartDashboard::PutNumber("Shooter Wheel Speed", Rollers->GetSpeed());
}


