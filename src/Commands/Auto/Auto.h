#pragma once

#include "CommandBase.h"
#include "WPILib.h"

class Auto: public CommandGroup
{
public:
	Auto();
	Auto(int autonomousposition, int autonomousbackup, int autonomousultrasonic);
};


