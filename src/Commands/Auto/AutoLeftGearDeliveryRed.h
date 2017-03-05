#pragma once

#include "WPILib.h"
#include <Commands/CommandGroup.h>

class AutoLeftGearDeliveryRed : public CommandGroup {
private:
	Timer t;
public:
	AutoLeftGearDeliveryRed();
	void Initialize();
};
