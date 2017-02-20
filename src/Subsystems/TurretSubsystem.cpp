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

double* TurretSubsystem::LookupHistory(int delta, bool increment) {
	if(increment) {
		vision_index++;
		if(vision_index > 100) {
			vision_index = 0;
		}
	}
	size_t target = ((vision_index + delta) % 100 + 100) % 100;
	return &(vision_history[target]);
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
	Turret->SetP(2.0);
	Turret->SetI(0.0);
	Turret->SetD(10.0);
	Turret->SetTalonControlMode(CANTalon::kPositionMode);
	Turret->Set(angle*2.7/180.0);
}

void TurretSubsystem::SetPower(double power) {
	Turret->SetControlMode(CANTalon::kPercentVbus);
	Turret->Set(power);
}

void TurretSubsystem::AimVision() {
	double kP = Preferences::GetInstance()->GetDouble("Vision P", 0.5);
	double new_vision = -table->GetNumber("Angle", 0.0) * 1.196 - Preferences::GetInstance()->GetDouble("Vision Offset", 0.0);
	double angle_at_frame = *LookupHistory(-Preferences::GetInstance()->GetDouble("Vision Delay", 10), false);
	if(last_vision != new_vision && table->GetBoolean("Found", false) && fabs(CommandBase::drive->angle_rate()) < 10.0) {
		double power = kP * new_vision;
		last_pid_time.Reset();
		last_pid_time.Start();
		last_gyro = CommandBase::drive->angle();
		last_angle = angle_at_frame + power;
		SetAngleSlow(last_angle);
		last_vision = new_vision;
	} else {
		SetAngleSlow(last_angle + (CommandBase::drive->angle() - last_gyro));
	}
}

void TurretSubsystem::TurretHome(){
	*LookupHistory(0, true) = GetAngle();
	if(Turret->IsFwdLimitSwitchClosed()){
		Turret->SetPosition(2.7);
	}
}
