/**
 * IntakeSubsystem is a class that keeps references to each of the
 * drive motors and drive encoder.
 */
#include <Commands/Turret/TurretDefault.h>
#include "Commands/Turret/TurretFudge.h"
#include "IntakeSubsystem.h"
#include "../RobotMap.h"
#include "CANTalon.h"

TurretSubsystem::TurretSubsystem():
		Subsystem("IntakeSubsystem")
{
	NetworkTable::SetUpdateRate(0.05);
	table = NetworkTable::GetTable("CameraTable");

	 Turret = new CANTalon(SHOOTER_TURRET);

	 Turret->SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);
	 Turret->SetSensorDirection(false);

     Turret->ConfigNominalOutputVoltage(+0.0f, -0.0f);
     Turret->ConfigPeakOutputVoltage(+12.0f, -12.0f);

     Turret->SelectProfileSlot(0);
     Turret->SetP(0.0022);
     Turret->SetI(0);
     Turret->SetD(0);
}

void TurretSubsystem::InitDefaultCommand()
{
	// When no other commands are running, we do operator control
	SetDefaultCommand(new TurretFudge());
}

void TurretSubsystem::AngleIntrepreter(){
	Turret->SetSetpoint(Turret->GetEncPosition() + table->GetNumber("Angle",0.0));
}


void TurretSubsystem::prints(){
	SmartDashboard::PutNumber("Angle", table->GetNumber("Angle",0.0));
	SmartDashboard::PutNumber("Distance", table->GetNumber("Distance",0.0));
	SmartDashboard::PutNumber("Turret Encoder", Turret->GetEncPosition());
}

void TurretSubsystem::SetAngle(double angle){
	Turret->SetTalonControlMode(CANTalon::kPositionMode);
	Turret->Set(angle);
}

void TurretSubsystem::SetPower(double power) {
	Turret->SetControlMode(CANTalon::kPercentVbus);
	Turret->Set(power);
}
