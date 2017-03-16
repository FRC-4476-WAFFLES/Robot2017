#pragma once

#include <Commands/CommandGroup.h>

class Auto: public CommandGroup
{
public:
	Auto();
	Auto(int autonomousposition, int autonomousbackup, int autonomousultrasonic);
};


