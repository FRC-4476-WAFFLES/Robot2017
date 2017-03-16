#pragma once

#include <Commands/CommandGroup.h>
#include <Timer.h>

class AutoLeftGearDeliveryBlue : public CommandGroup {
private:
	Timer t;
public:
	AutoLeftGearDeliveryBlue();
	void Initialize();
};
