#include "AutoGearDelivery.h"
#include "Commands/Misc/WaitTime.h"
#include "Commands/Drive/DriveAuto.h"
#include "Commands/Shooter/ShooterPrep.h"
#include "Commands/Shooter/ShootAutoUntil.h"

AutoGearDelivery::AutoGearDelivery()
{
	SetTimeout(15.0);
	AddSequential(new DriveAuto(5.5, 0, 0.3));
	AddParallel(new ShooterPrep());
	AddSequential(new WaitTime(1.0));
	AddSequential(new ShootAutoUntil(t, 10.0));
}

void AutoGearDelivery::Initialize() {
	t.Reset();
	t.Start();
}
