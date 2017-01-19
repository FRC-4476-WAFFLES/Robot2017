/**
 * IntakeSubsystem is a class that keeps references to each of the
 * drive motors and drive encoder.
 */
#include <Commands/Intake/IntakeDefault.h>
#include "IntakeSubsystem.h"
#include "../RobotMap.h"

IntakeSubsystem::IntakeSubsystem():
		Subsystem("IntakeSubsystem")
{
	 IntakeRollers = new Victor(INTAKE_ROLLER);
}

void IntakeSubsystem::InitDefaultCommand()
{
	// When no other commands are running, we do operator control
	SetDefaultCommand(new IntakeDefault());
}



