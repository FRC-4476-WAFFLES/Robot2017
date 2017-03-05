#include "AutoDoNothing.h"
#include "Commands/Misc/WaitTime.h"
#include "Commands/Drive/DriveAuto.h"
#include "Commands/Intake/ConveyorAuto.h"

AutoDoNothing::AutoDoNothing()
{
	SetTimeout(15.0);
	AddParallel(new ConveyorAuto(1.0,1.0));
	AddSequential(new WaitTime(1.0));
}
