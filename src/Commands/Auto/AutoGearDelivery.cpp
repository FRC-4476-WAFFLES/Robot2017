#include "AutoGearDelivery.h"
#include "Commands/Misc/WaitTime.h"
#include "Commands/Drive/DriveAuto.h"
#include "Commands/Intake/ConveyorAuto.h"


AutoGearDelivery::AutoGearDelivery()
{
	SetTimeout(15.0);
	AddParallel(new ConveyorAuto(1.0,3.0));
	AddSequential(new DriveAuto(5.5, 0, 0.3));
	AddSequential(new WaitTime(1.0));
}
