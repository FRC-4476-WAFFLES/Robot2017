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

	Turret->EnableZeroSensorPositionOnReverseLimit(true);

     Turret->SelectProfileSlot(0);
     Turret->SetP(0.0022);
     Turret->SetI(0);
     Turret->SetD(0);
}

void TurretSubsystem::InitDefaultCommand()
{
	// When no other commands are running, we do operator control
	SetDefaultCommand(new TurretDefault());
}

void TurretSubsystem::AngleIntrepreter(){
	Turret->SetSetpoint(Turret->GetEncPosition() + table->GetNumber("Angle",0.0));
}

void TurretSubsystem::prints(){
	SmartDashboard::PutNumber("Angle", table->GetNumber("Angle",0.0));
	SmartDashboard::PutNumber("Distance", table->GetNumber("Distance",0.0));
	SmartDashboard::PutNumber("Turret Encoder", GetAngle());
	SmartDashboard::PutBoolean("Left Switch", Turret->IsFwdLimitSwitchClosed());
	SmartDashboard::PutBoolean("Right Switch", Turret->IsRevLimitSwitchClosed());
}

void TurretSubsystem::UpdateRollersPID() {
    Turret->SelectProfileSlot(0);
	Turret->SetP(Preferences::GetInstance()->GetDouble("Turret P", 5.0));
	Turret->SetI(Preferences::GetInstance()->GetDouble("Turret I", 0.0));
	Turret->SetD(Preferences::GetInstance()->GetDouble("Turret D", 70.0));
}

double TurretSubsystem::GetAngle() {
	return (Turret->GetPosition()/2.7)*180.0;
}

void TurretSubsystem::SetAngle(double angle){
	UpdateRollersPID();
	Turret->SetTalonControlMode(CANTalon::kPositionMode);
	Turret->Set(angle*2.7/180.0);
}

void TurretSubsystem::SetAngleSlow(double angle){
	Turret->SelectProfileSlot(1);
	Turret->SetP(1.0);
	Turret->SetI(0.0);
	Turret->SetD(0.0);
	Turret->SetTalonControlMode(CANTalon::kPositionMode);
	Turret->Set(angle*2.7/180.0);
}

void TurretSubsystem::SetPower(double power) {
	Turret->SetControlMode(CANTalon::kPercentVbus);
	Turret->Set(power);
}

void TurretSubsystem::AimVision() {
	double kP = 0.3;
	double kD = 0.0;
	double new_vision = -table->GetNumber("Angle",0.0);
	if(last_vision != new_vision && table->GetBoolean("Found", false)) {
		double power = kP * new_vision + kD * (new_vision - last_vision) / last_pid_time.Get();
		last_pid_time.Reset();
		last_pid_time.Start();
		SetAngleSlow(GetAngle() + power);
	}
	last_vision = new_vision;
}

void TurretSubsystem::TurretHome(){
	if(Turret->IsFwdLimitSwitchClosed()){
		Turret->SetPosition(2.7);
	}
}
