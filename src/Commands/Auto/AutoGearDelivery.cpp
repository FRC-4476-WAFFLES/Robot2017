#include "AutoGearDelivery.h"
#include "Commands/Misc/WaitTime.h"
#include "Commands/Drive/DriveAuto.h"
#include "Commands/Intake/ConveyorAuto.h"
#include "Commands/Turret/TurretOffShot.h"
#include "Commands/Gear/GearCloseAuto.h"
#include "Commands/Gear/GearAuto.h"


AutoGearDelivery::AutoGearDelivery()
{
	SetTimeout(15.0);
	AddParallel(new TurretOffShot());
//	AddParallel(new ConveyorAuto(1.0,3.0));
	AddSequential(new DriveAuto(6.2, 0, 0.3));
	AddSequential(new GearAuto());
	AddSequential(new DriveAuto(5.2, 0, 0.8));
	AddSequential(new DriveAuto(2.5, 0, 0.3));
	AddParallel(new GearCloseAuto());
	AddSequential(new WaitTime(1.0));
}
