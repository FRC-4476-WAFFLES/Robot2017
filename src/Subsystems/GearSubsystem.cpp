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
	GearLeft = new Servo(GEAR_LEFT);
	GearRight = new Servo(GEAR_RIGHT);
}

void GearSubsystem::InitDefaultCommand()
{
	// When no other commands are running, we do operator control
	SetDefaultCommand(new GearDefault());
}
//TODO get numbers
void GearSubsystem::Open(){
	GearLeft->SetAngle(60);
	GearRight->SetAngle(170);
}

void GearSubsystem::Closed(){
	GearLeft->SetAngle(170);
	GearRight->SetAngle(60);
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
