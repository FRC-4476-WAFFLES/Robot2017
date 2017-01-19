/**
 * ShooterSubsystem is a class that keeps references to each of the
 * drive motors and drive encoder.
 */
#include <Commands/Shooter/ShooterDefault.h>
#include "ShooterSubsystem.h"
#include "../RobotMap.h"
#include "CANTalon.h"

ShooterSubsystem::ShooterSubsystem():
		Subsystem("ShooterSubsystem")
{
	 Turret = new Victor(SHOOTER_TURRET);
	 Rollers = new CANTalon(SHOOTER_ROLLER);

	 //CANTALLON SETUP//
	 Rollers->SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);
	 Rollers->SetSensorDirection(false);
	 //peak outputs
     Rollers->ConfigNominalOutputVoltage(+0.0f, -0.0f);
     Rollers->ConfigPeakOutputVoltage(+12.0f, 0.0f);

     //PID things
     Rollers->SelectProfileSlot(0);
     Rollers->SetF(0.1097);
	 Rollers->SetP(0.22);
	 Rollers->SetI(0);
	 Rollers->SetD(0);

}

void ShooterSubsystem::InitDefaultCommand()
{
	// When no other commands are running, we do operator control
	SetDefaultCommand(new ShooterDefault());
}

void ShooterSubsystem::SetSpeed(double RPM){
	Rollers->ApplyControlMode(CANTalon::kSpeedMode);
	Rollers->SetSetpoint(RPM); /* 1500 RPM in either direction */
}



