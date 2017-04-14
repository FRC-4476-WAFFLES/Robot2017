/**
 * GearSubsystem is a class that keeps references to each of the
 * drive motors and drive encoder.
 */
#include <Commands/Gear/GearDefault.h>
#include "GearSubsystem.h"
#include "../RobotMap.h"
#include "Helpers/PIDPreferences.h"

GearSubsystem::GearSubsystem():
		Subsystem("GearSubsystem")
{
	Gear = new CANTalon(GEAR);

	Gear->SetFeedbackDevice(CANTalon::CtreMagEncoder_Absolute);
	Gear->SetSensorDirection(false);

	Gear->ConfigNominalOutputVoltage(+0.0f, -0.0f);
	Gear->ConfigPeakOutputVoltage(+12.0f, -12.0f);

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
	UpdatePID("Gear", Gear);
	Gear->SetControlMode(CANSpeedController::kPosition);
	Gear->Set(0.575);
}

void GearSubsystem::Closed(){
	UpdatePID("Gear", Gear);
	Gear->SetControlMode(CANSpeedController::kPosition);
	Gear->Set(0.688);
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
	SmartDashboard::PutBoolean("Gear Open?", is_open);
	SmartDashboard::PutNumber("Gear Encoder", Gear->GetPosition());
	SmartDashboard::PutNumber("Gear encoder present?", Gear->IsSensorPresent(CANTalon::CtreMagEncoder_Absolute));
}
