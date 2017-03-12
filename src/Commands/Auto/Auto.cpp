#include "Auto.h"
#include "Commands/Misc/WaitTime.h"
#include "Commands/Drive/DriveAuto.h"
#include "Commands/Intake/ConveyorAuto.h"

Auto::Auto():
	// Default values for each number
	Auto(0, 0, 0) { }

Auto::Auto(int autonomousposition, int autonomousbackup, int autonomousultrasonic)
{
	// the idea is to use one command for any of the 20-30 possible auto modes using if statements
	SetTimeout(15.0);
	AddSequential(new WaitTime(1.0));
}
