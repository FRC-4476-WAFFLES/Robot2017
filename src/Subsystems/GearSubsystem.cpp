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
	starting_angle = Gear->GetPosition();
	// When no other commands are running, we do operator control
	SetDefaultCommand(new GearDefault());
}

void GearSubsystem::Open(){
	// TODO get actual numbers
	UpdatePID("Gear", Gear);
	Gear->SetPosition(starting_angle + 45);
}

void GearSubsystem::Closed(){
	// TODO get actual numbers
	UpdatePID("Gear", Gear);
	Gear->SetPosition(starting_angle);
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
}
