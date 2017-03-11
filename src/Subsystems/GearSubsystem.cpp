/**
 * GearSubsystem is a class that keeps references to each of the
 * drive motors and drive encoder.
 */
#include <Commands/Gear/GearDefault.h>
#include "GearSubsystem.h"
#include "../RobotMap.h"

GearSubsystem::GearSubsystem():
		Subsystem("GearSubsystem")
{
	Gear = new CANTalon(GEAR);

	Gear->SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);
	Gear->SetSensorDirection(false);

	Gear->ConfigNominalOutputVoltage(+0.0f, -0.0f);
	Gear->ConfigPeakOutputVoltage(+12.0f, -12.0f);

	Gear->EnableZeroSensorPositionOnReverseLimit(true);
	// TODO: tune pid to actual numbers
	Gear->SelectProfileSlot(0);
	Gear->SetP(0.0022);
	Gear->SetI(0);
	Gear->SetD(0);
/*	GearLeft = new Servo(GEAR_LEFT);
	GearRight = new Servo(GEAR_RIGHT);*/
}

void GearSubsystem::InitDefaultCommand()
{
	// When no other commands are running, we do operator control
	SetDefaultCommand(new GearDefault());
}
//TODO get numbers
void GearSubsystem::Open(){
	// TODO get actual numbers
	Gear->Set(0.0);
//	GearLeft->SetAngle(165);
//	GearRight->SetAngle(0);
}

void GearSubsystem::Closed(){
	// TODO get actual numbers
	Gear->Set(0.0);
//	GearLeft->SetAngle(110);
//	GearRight->SetAngle(60);
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
}
