#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include <Subsystems/DrawerSubsystem.h>
#include <string>
#include <mutex>
#include "Subsystems/DriveSubsystem.h"
#include "Subsystems/ShooterSubsystem.h"
#include "Subsystems/GearSubsystem.h"
#include "Subsystems/TurretSubsystem.h"
#include "Subsystems/ClimberSubsystem.h"
#include "OI.h"
#include "WPILib.h"


/**
 * The base for all commands. All atomic commands should subclass CommandBase.
 * CommandBase stores creates and stores each control system. To access a
 * subsystem elsewhere in your code in your code use CommandBase.examplesubsystem
 */
class CommandBase: public Command
{
public:
	CommandBase(const std::string &name);
	static void init();
	static void prints();
	static bool is_init;
	// Create a single static instance of all of your subsystems
	static std::unique_ptr<DriveSubsystem> drive;
	static std::unique_ptr<OI> oi;
	static std::unique_ptr<ClimberSubsystem> climber;
//	static std::unique_ptr<ShooterSubsystem> shooter;
	static std::unique_ptr<DrawerSubsystem> drawer;
	static std::unique_ptr<GearSubsystem> gear;
//	static std::unique_ptr<TurretSubsystem> turret;

};

#endif
