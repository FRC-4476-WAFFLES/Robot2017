#pragma once

#include <string>
#include <Commands/Command.h>
class DriveSubsystem;
class OI;

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

};
