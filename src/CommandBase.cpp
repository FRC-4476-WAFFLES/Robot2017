#include "./CommandBase.h"
#include "Commands/Scheduler.h"

/**
 * CommandBase is a class that is the parent class to each of the commands used by the robot.
 * This allows the commands to access each subsystem.
 */

// Initialize a single static instance of all of your subsystems to NULL
std::unique_ptr<OI> CommandBase::oi;
std::unique_ptr<DriveSubsystem> CommandBase::drive;
std::unique_ptr<ShooterSubsystem> CommandBase::shooter;
std::unique_ptr<IntakeSubsystem> CommandBase::intake;
// Empty constructors
CommandBase::CommandBase(const std::string &name) :
		Command(name)
{
}

// Creates each subsystem, should only be run once!
void CommandBase::init()
{
  // Create a single static instance of all of your subsystems. The following
  // line should be repeated for each subsystem in the project.
  drive.reset(new DriveSubsystem());
  shooter.reset(new ShooterSubsystem());
  intake.reset(new IntakeSubsystem());

  oi.reset(new OI());
}

// Print out some useful information about each subsystem
void CommandBase::prints() {
  if(drive != nullptr) drive->prints();
}
