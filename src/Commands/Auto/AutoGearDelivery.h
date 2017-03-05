#pragma once

#include "CommandBase.h"
#include "WPILib.h"

class AutoGearDelivery: public CommandGroup
{
private:
	Timer t;
public:
	AutoGearDelivery();
	void Initialize();
};


