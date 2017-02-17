/**
 * ShooterSubsystem is a class that keeps references to each of the
 * drive motors and drive encoder.
 */
#include <Commands/Shooter/ShooterDefault.h>
#include "ShooterSubsystem.h"
#include "../RobotMap.h"

ShooterSubsystem::ShooterSubsystem():
		Subsystem("ShooterSubsystem")
{
	//shot speed: main shot->15 velocity->15.38s setting on current PID
	 Rollers = new CANTalon(SHOOTER_ROLLER);
	 Rollers_Slave = new CANTalon(SHOOTER_ROLLER_SLAVE);
	 Load = new VictorSP(SHOOTER_LOAD);

	 //CANTALLON SETUP//
	 Rollers->SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);
	 Rollers->SetSensorDirection(true);
	 Rollers->SetClosedLoopOutputDirection(true);

	 //peak outputs
     Rollers->ConfigNominalOutputVoltage(+0.0f, -0.0f);
     Rollers->ConfigPeakOutputVoltage(+0.0f, -9.0f);

     //PID things
	 Rollers_Slave->SetControlMode(CANSpeedController::kFollower);
	 Rollers_Slave->Set(SHOOTER_ROLLER);
}

void ShooterSubsystem::InitDefaultCommand()
{
	// When no other commands are running, we do operator control
	SetDefaultCommand(new ShooterDefault);
}

void UpdateRollersPID(CANTalon* Rollers, double RPM) {
    Rollers->SelectProfileSlot(0);
    // F for 20 = 4.4
    // F for 15 = 4.9
    // F for 10 = 5.6
    // F for 5 = 7.0
    // F = 12*x^-0.334587
    Rollers->SetF(Preferences::GetInstance()->GetDouble("Shooter F", 20.0)*pow(RPM, -0.334587));
	Rollers->SetP(Preferences::GetInstance()->GetDouble("Shooter P", 50.0));
	Rollers->SetI(Preferences::GetInstance()->GetDouble("Shooter I", 0.0));
	Rollers->SetD(Preferences::GetInstance()->GetDouble("Shooter D", 0.0));
}

double ShooterSubsystem::ramp(double Target) {
	if(Rollers->Get() == Target){
		return Target;
	}else if(Rollers->Get() < Target){
		return Rollers->Get() + 0.1;
	}else{
		return Target;
	}
}

void ShooterSubsystem::SetSpeed(double RPM) {
	UpdateRollersPID(Rollers, RPM);
	if(Rollers->GetSpeed() > RPM/2.0) {
		Rollers->SetTalonControlMode(CANTalon::kSpeedMode);
		Rollers->Set(RPM);
	} else {
		SetPower(-0.5);
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
	SmartDashboard::PutNumber("Shooter Velocity",Rollers->GetSpeed());
	SmartDashboard::PutNumber("Shooter Ready?", fabs(Rollers->GetSpeed() - Rollers->GetSetpoint()) < 0.1);
	SmartDashboard::PutNumber("dpad angle",CommandBase::oi->operatorController->GetPOV());
}


