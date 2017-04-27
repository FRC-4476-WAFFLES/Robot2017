/**
 * GearSubsystem is a class that keeps references to each of the
 * drive motors and drive encoder.
 */
#include <Commands/Gear/GearDefault.h>
#include "GearSubsystem.h"
#include "../RobotMap.h"
#include "Helpers/PIDPreferences.h"
#include "DriverStation.h"
#include "OI.h"

GearSubsystem::GearSubsystem():
		Subsystem("GearSubsystem")
{
	Gear = new CANTalon(GEAR);

	Gear->SetFeedbackDevice(CANTalon::CtreMagEncoder_Absolute);
	Gear->SetSensorDirection(false);

	Gear->ConfigNominalOutputVoltage(+0.0f, -0.0f);
	Gear->ConfigPeakOutputVoltage(+6.0f, -6.0f);

	stuck_timer = new Timer();

	UpdatePID("Gear", Gear);

	starting_angle = 0.0;
	is_open = false;
}

void GearSubsystem::InitDefaultCommand()
{
	// When no other commands are running, we do operator control
	SetDefaultCommand(new GearDefault());
}

void GearSubsystem::Open(){
	SetAngle(vopen, -10);
}

void GearSubsystem::Closed(){
	SetAngle(vclosed, 10);
}

void GearSubsystem::SetAngle(double setpoint, double override_speed) {
	UpdatePID("Gear", Gear);
	if(IsSensorWorking(floor(Gear->GetPosition()) + setpoint)) {
		SmartDashboard::PutBoolean("Using PID?", true);
		Gear->SetControlMode(CANSpeedController::kPosition);
		Gear->Set(floor(Gear->GetPosition()) + setpoint);
	} else {
		SmartDashboard::PutBoolean("Using PID?", false);
		Gear->SetControlMode(CANSpeedController::kPercentVbus);
		Gear->Set(override_speed);
	}
}

bool GearSubsystem::IsSensorWorking(double setpoint) {
	// If the sensor gets stuck for a period of time, it is not working
	if(stuck_timer->Get() > 0.3) {
		return false;
	}

	// If sensor isn't present, sensor isn't working
	if(Gear->IsSensorPresent(CANTalon::CtreMagEncoder_Absolute) != 1) {
		stuck_timer->Reset();
		stuck_timer->Start();
		return false;
	}

//	//detect jump
//	fmodGearEnc = Gear->GetPosition();
//	fmodGearEnc -= floor(fmodGearEnc);
//	if(fmodGearEnc > vclosed + 0.01 && fmodGearEnc < vopen - 0.01){
//		stuck_timer->Reset();
//		stuck_timer->Start();
//		return false;
//	}

	// Detection for stuck_timer
	double error = Gear->GetPosition() - setpoint;
	if(fabs(error) < 0.05 || fabs(error - last_error) > 0.01) {
		stuck_timer->Reset();
		stuck_timer->Start();
		last_error = error;
	}

	// If none of the above have returned false, the sensor is good.
	return true;
}

void GearSubsystem::Toggle(){
	is_open = !is_open;
}

void GearSubsystem::Persist(){
	if(is_open){
		Open();
	}else{
		Closed();
	}
}

void GearSubsystem::prints() {
	// Reset stuck when disabled
	if(DriverStation::GetInstance().IsDisabled()) {
		stuck_timer->Reset();
		stuck_timer->Start();
	}

	SmartDashboard::PutNumber("Gear voltage output", Gear->GetOutputVoltage());
	SmartDashboard::PutBoolean("Gear button", CommandBase::oi->operatorController->GetRawButton(OI::X));
	SmartDashboard::PutBoolean("Gear Open?", is_open);
	SmartDashboard::PutNumber("Gear Encoder", Gear->GetPosition());
	SmartDashboard::PutNumber("Gear encoder present?", Gear->IsSensorPresent(CANTalon::CtreMagEncoder_Absolute));
}
