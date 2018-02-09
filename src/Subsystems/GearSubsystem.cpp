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
#include "WPILib.h"

GearSubsystem::GearSubsystem():
		Subsystem("GearSubsystem")
{
	Gear = new TalonSRX(GEAR);

	Gear->ConfigSelectedFeedbackSensor(FeedbackDevice::PulseWidthEncodedPosition,0,0);
	Gear->SetSensorPhase(false);


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
	SetAngle(vopen, -0.5);
}

void GearSubsystem::Closed(){
	SetAngle(vclosed, 0.5);
}

void GearSubsystem::SetAngle(double setpoint, double override_speed) {
	UpdatePID("Gear", Gear);
	if(IsSensorWorking(floor(Gear->getSelectedSensorPosition()) + setpoint)) {
		SmartDashboard::PutBoolean("Using PID?", true);
		Gear->SetControlMode(CANSpeedController::kPosition);
		Gear->Set(floor(Gear->GetPosition()) + setpoint);
		SmartDashboard::PutNumber("Gear Target", floor(Gear->GetPosition()) + setpoint);
		Gear->ConfigPeakOutputVoltage(+12.0f, -12.0f);
	} else {
		SmartDashboard::PutBoolean("Using PID?", false);
		Gear->SetControlMode(CANSpeedController::kPercentVbus);
		Gear->Set(override_speed);
		Gear->ConfigPeakOutputVoltage(+6.0f, -6.0f);
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

	if(SafeMode == true){
		stuck_timer->Reset();
		stuck_timer->Start();
		return false;
	}

	// Detection for stuck_timer

	if(GearPowerDraw.GetCurrent(5) < 10){
		stuck_timer->Reset();
		stuck_timer->Start();
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
	Command* current = GetCurrentCommand();
	if(current != nullptr) {
		SmartDashboard::PutString("Gear Command", current->GetName());
	} else {
		SmartDashboard::PutString("Gear Command", "None");
	}

	// Reset stuck when disabled
	if(DriverStation::GetInstance().IsDisabled()) {
		stuck_timer->Reset();
		stuck_timer->Start();
	}

	SmartDashboard::PutNumber("Gear voltage output", Gear->GetOutputVoltage());
	SmartDashboard::PutBoolean("Gear Open?", is_open);
	SmartDashboard::PutNumber("Gear Encoder", Gear->GetPosition());
	SmartDashboard::PutNumber("Gear Encoder Target", Gear->Get());
	SmartDashboard::PutNumber("Gear encoder present?", Gear->IsSensorPresent(CANTalon::CtreMagEncoder_Absolute));
}
