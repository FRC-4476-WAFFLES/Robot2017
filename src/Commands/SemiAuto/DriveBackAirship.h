#pragma once

#include <Commands/CommandGroup.h>

class DriveBackAirship : public CommandGroup {
public:
	DriveBackAirship(bool right);
	void Execute();
};


