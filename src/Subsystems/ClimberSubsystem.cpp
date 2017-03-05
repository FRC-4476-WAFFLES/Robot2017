/**
 * ClimberSubsystem is a class that keeps references to each of the
 * drive motors and drive encoder.
 */
#include <Commands/Intake/IntakeDefault.h>
#include "ClimberSubsystem.h"
#include "../RobotMap.h"

ClimberSubsystem::ClimberSubsystem():
		Subsystem("ClimberSubsystem")
{
	//shot speed: main shot->15 velocity->15.38s setting on current PID
	 Climber = new CANTalon(TOP_CLIMBER_ROLLER);
	 Climber_Slave = new CANTalon(TOP_CLIMBER_SLAVE);

	 //peak outputs
     Climber->ConfigNominalOutputVoltage(+0.0f, -0.0f);
     Climber->ConfigPeakOutputVoltage(+12.0f, -12.0f);

     //PID things
     Climber_Slave->SetControlMode(CANSpeedController::kFollower);
	 Climber_Slave->Set(TOP_CLIMBER_ROLLER);
}

void ClimberSubsystem::InitDefaultCommand()
{
	// When no other commands are running, we do operator control
	SetDefaultCommand(new IntakeDefault());
}

void ClimberSubsystem::SetPower(double power) {
	Climber->SetControlMode(CANTalon::kPercentVbus);
	Climber->Set(power);
}


