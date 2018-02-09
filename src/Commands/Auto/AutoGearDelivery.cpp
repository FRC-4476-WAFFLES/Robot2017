#include "AutoGearDelivery.h"
#include "Commands/Misc/WaitTime.h"
#include "Commands/Drive/DriveAuto.h"
#include "Commands/Intake/ConveyorAuto.h"
#include "Commands/Gear/GearCloseAuto.h"
#include "Commands/Gear/GearAuto.h"

AutoGearDelivery::AutoGearDelivery()
{
	SetTimeout(15.0);
//	AddParallel(new TurretCenterShot());
//	AddParallel(new ConveyorAuto(1.0,1.0));
	AddSequential(new DriveAuto(7.2, 0, 0.3));
	AddSequential(new GearAuto());
//	AddSequential(new ShooterPrepAuto());
//	AddParallel(new TurretVision());
//	AddSequential(new ShootAutoUntil(t, 10.0));
	AddSequential(new DriveAuto(5.2, 0, 0.8));
	AddSequential(new DriveAuto(2.5, 0, 0.3));
	AddParallel(new GearCloseAuto());
}

void AutoGearDelivery::Initialize() {
	t.Reset();
	t.Start();
}
