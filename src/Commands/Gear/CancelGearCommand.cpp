#include "CancelGearCommand.h"
#include "Subsystems/GearSubsystem.h"

CancelGearCommand::CancelGearCommand(): CommandBase("CancelGearCommand") {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called once when the command executes
void CancelGearCommand::Initialize() {
	gear->GetCurrentCommand()->Cancel();
}
