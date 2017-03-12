#include "Auto.h"
#include "Commands/Misc/WaitTime.h"
#include "Commands/Drive/DriveAuto.h"
#include "Commands/Intake/ConveyorAuto.h"

Auto::Auto()
{
	// the idea is to use one command for any of the 20-30 possible auto modes using if statements
	SetTimeout(15.0);
	AddSequential(new WaitTime(1.0));
	if()
}
