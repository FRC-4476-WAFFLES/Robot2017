#pragma once

#include "WPILib.h"
#include <Commands/CommandGroup.h>

class AutoLeftGearDelivery : public CommandGroup {
private:
	Timer t;
public:
	AutoLeftGearDelivery();
	void Initialize();
};
