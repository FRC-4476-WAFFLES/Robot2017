/**
 * ShooterSubsystem is a class that keeps references to each of the
 * drive motors and drive encoder.
 */
#include <Commands/Shooter/ShooterDefault.h>
#include "ShooterSubsystem.h"
#include "../RobotMap.h"

ShooterSubsystem::ShooterSubsystem():
		Subsystem("ShooterSubsystem")
{
	 Turret = new Victor(SHOOTER_TURRET);
	 Rollers = new Victor(SHOOTER_ROLLER);
}

void ShooterSubsystem::InitDefaultCommand()
{
	// When no other commands are running, we do operator control
	SetDefaultCommand(new ShooterDefault());
}




