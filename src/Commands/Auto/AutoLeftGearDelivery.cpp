#include "AutoLeftGearDelivery.h"
#include "Commands/Drive/DriveAuto.h"
#include "Commands/Gear/GearAuto.h"
#include "Commands/Gear/GearCloseAuto.h"
#include "Commands/Turret/TurretOffShot.h"
#include "Commands/Turret/ReleaseIntake.h"
#include "Commands/Shooter/ShooterPrep.h"
#include "Commands/Misc/WaitTime.h"
#include "Commands/Shooter/ShootAutoUntil.h"

AutoLeftGearDelivery::AutoLeftGearDelivery() {
	SetTimeout(15.0);
	AddParallel(new GearCloseAuto());
//	AddParallel(new TurretOffShot());
	AddSequential(new DriveAuto(6.55, 0, 1.0));
	AddSequential(new DriveAuto(6.55, 58, 1.0));
	AddSequential(new DriveAuto(11.25, 58, 0.5));
	AddSequential(new GearAuto());
	AddSequential(new DriveAuto(8, 58, 1.0));
	AddParallel(new GearCloseAuto());
	AddSequential(new DriveAuto(8, -89, 1.0));
	AddParallel(new ShooterPrep());
	AddSequential(new WaitTime(1.0));
	AddSequential(new ShootAutoUntil(t, 10.0));
}

void AutoLeftGearDelivery::Initialize() {
	t.Reset();
	t.Start();
}
