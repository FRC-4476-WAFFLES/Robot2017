#include "AutoGearDelivery.h"
#include "Commands/Misc/WaitTime.h"
#include "Commands/Drive/DriveAuto.h"


AutoGearDelivery::AutoGearDelivery()
{
	SetTimeout(15.0);
	//TODO: Make this not magic numbers
	AddSequential(new DriveAuto(3000, 0, 0.3));
	AddSequential(new WaitTime(1.0));
}
