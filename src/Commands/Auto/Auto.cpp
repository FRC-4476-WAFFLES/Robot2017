#include "Auto.h"
#include "Commands/Misc/WaitTime.h"
#include "Commands/Drive/DriveAuto.h"
#include "Commands/Intake/ConveyorAuto.h"

Auto::Auto()
{
	SetTimeout(15.0);
	AddSequential(new WaitTime(1.0));
}
