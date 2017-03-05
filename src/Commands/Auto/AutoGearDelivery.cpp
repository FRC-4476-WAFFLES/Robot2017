#include "AutoGearDelivery.h"
#include "Commands/Misc/WaitTime.h"
#include "Commands/Drive/DriveAuto.h"
#include "Commands/Shooter/ShooterPrepAuto.h"
#include "Commands/Shooter/ShootAutoUntil.h"
#include "Commands/Intake/ConveyorAuto.h"
#include "Commands/Turret/TurretCenterShot.h"
#include "Commands/Gear/GearCloseAuto.h"
#include "Commands/Gear/GearAuto.h"
#include "Commands/Turret/TurretVision.h"

AutoGearDelivery::AutoGearDelivery()
{
	SetTimeout(15.0);
	AddParallel(new TurretCenterShot());
//	AddParallel(new ConveyorAuto(1.0,3.0));
	AddSequential(new DriveAuto(6.2, 0, 0.3));
	AddSequential(new GearAuto());
	AddSequential(new ShooterPrepAuto());
	AddSequential(new WaitTime(1.0));
//	AddParallel(new TurretVision());
	AddSequential(new ShootAutoUntil(t, 10.0));
	AddParallel(new ShootAutoUntil(t, 15.0));
	AddSequential(new DriveAuto(5.2, 0, 0.8));
	AddSequential(new DriveAuto(2.5, 0, 0.3));
	AddParallel(new GearCloseAuto());
}

void AutoGearDelivery::Initialize() {
	t.Reset();
	t.Start();
}
