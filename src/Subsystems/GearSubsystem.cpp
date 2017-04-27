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
	Gear->ConfigPeakOutputVoltage(+8.0f, -8.0f);

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
	Gear->Set(vopen);
}

void GearSubsystem::Closed(){
	UpdatePID("Gear", Gear);
	Gear->SetControlMode(CANSpeedController::kPosition);
	Gear->Set(vclosed);
}

void GearSubsystem::Toggle(){
	is_open = !is_open;
}

void GearSubsystem::Persist(){
	if(Gear->GetPosition()>1.0){
		Gear->SetPosition(fmod(Gear->GetPosition(), 1.0));
	}else if(Gear->GetPosition()<0.0){
		Gear->SetPosition(fmod(Gear->GetPosition(), 1.0) + 1.0);
	}
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

	SmartDashboard::PutBoolean("Gear Open?", is_open);
	SmartDashboard::PutNumber("Gear Encoder", Gear->GetPosition());
	SmartDashboard::PutNumber("Gear Encoder Target", Gear->Get());
	SmartDashboard::PutNumber("Gear encoder present?", Gear->IsSensorPresent(CANTalon::CtreMagEncoder_Absolute));
}
