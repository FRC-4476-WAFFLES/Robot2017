#include <Commands/Auto/AutoLeftGearDeliveryBlue.h>
#include "Commands/Drive/DriveAuto.h"
#include "Commands/Gear/GearAuto.h"
#include "Commands/Gear/GearCloseAuto.h"
#include "Commands/Turret/TurretOffShot.h"
#include "Commands/Turret/ReleaseIntake.h"
#include "Commands/Intake/ConveyorAuto.h"
#include "Commands/Shooter/ShooterPrep.h"
#include "Commands/Shooter/ShootAutoUntil.h"
#include "Commands/Misc/WaitTime.h"

AutoLeftGearDeliveryBlue::AutoLeftGearDeliveryBlue() {
	SetTimeout(15.0);
//	AddParallel(new ConveyorAuto(1.0,3.0));
	AddParallel(new GearCloseAuto());
	AddParallel(new TurretOffShot());
	AddSequential(new DriveAuto(6.55, 0, 0.3));
	AddSequential(new DriveAuto(6.55, 60, 0.3));
	AddSequential(new DriveAuto(11.25, 60, 0.3));
	AddSequential(new GearAuto());
	AddParallel(new ShooterPrep());
	AddSequential(new WaitTime(1.0));
	AddSequential(new ShootAutoUntil(t, 10.0));
	AddSequential(new DriveAuto(8, 60, 0.3));
	AddParallel(new GearCloseAuto());
	AddSequential(new DriveAuto(8, -89, 0.3));
//	AddSequential(new DriveAuto(3.5, 47, 0.5));
//	AddSequential(new DriveAuto(3.5, 0, 0.5));
//	AddSequential(new DriveAuto(20.0, 0, 0.5));
}

void AutoLeftGearDeliveryBlue::Initialize() {
	t.Reset();
	t.Start();
}

