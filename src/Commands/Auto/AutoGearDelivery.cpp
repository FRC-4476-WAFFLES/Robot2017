#include "AutoGearDelivery.h"
#include "Commands/Misc/WaitTime.h"
#include "Commands/Drive/DriveAuto.h"


AutoGearDelivery::AutoGearDelivery()
{
	SetTimeout(15.0);
	AddSequential(new DriveAuto(5.5, 0, 0.3));
	AddSequential(new WaitTime(1.0));
}
