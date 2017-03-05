#pragma once

#include "WPILib.h"
#include <Commands/CommandGroup.h>

class AutoLeftGearDeliveryBlue : public CommandGroup {
private:
	Timer t;
public:
	AutoLeftGearDeliveryBlue();
	void Initialize();
};
