#pragma once

#include <Commands/CommandGroup.h>
#include <Timer.h>

class AutoGearDelivery: public CommandGroup
{
private:
	Timer t;
public:
	AutoGearDelivery();
	void Initialize();
};


