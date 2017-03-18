#pragma once

#include <Commands/CommandGroup.h>
#include <Timer.h>

class AutoLeftGearDeliveryRed : public CommandGroup {
private:
	Timer t;
public:
	AutoLeftGearDeliveryRed();
	void Initialize();
};
