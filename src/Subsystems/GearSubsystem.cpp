/**
 * GearSubsystem is a class that keeps references to each of the
 * drive motors and drive encoder.
 */
#include <Commands/Intake/IntakeDefault.h>
#include "GearSubsystem.h"
#include "../RobotMap.h"

GearSubsystem::GearSubsystem():
		Subsystem("GearSubsystem")
{
	Gear = new Servo(GEAR);
}

void GearSubsystem::InitDefaultCommand()
{
	// When no other commands are running, we do operator control
	SetDefaultCommand(new IntakeDefault());
}





