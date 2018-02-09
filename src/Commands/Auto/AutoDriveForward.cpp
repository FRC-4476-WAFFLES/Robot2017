#include "AutoDriveForward.h"
#include "Commands/Misc/WaitTime.h"
#include "Commands/Drive/DriveAuto.h"
#include "Commands/Gear/GearCloseAuto.h"
#include "Commands/Gear/GearAuto.h"


AutoDriveForward::AutoDriveForward()
{
	SetTimeout(15.0);
//	AddParallel(new ConveyorAuto(1.0,3.0));
	AddSequential(new DriveAuto(2.5, 0, 0.3));
	AddSequential(new WaitTime(1.0));
}
