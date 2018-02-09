#include <Commands/Auto/AutoLeftGearDeliveryBlue.h>
#include "Commands/Drive/DriveAuto.h"
#include "Commands/Gear/GearAuto.h"
#include "Commands/Gear/GearCloseAuto.h"
#include "Commands/Intake/ConveyorAuto.h"
#include "Commands/Misc/WaitTime.h"

AutoLeftGearDeliveryBlue::AutoLeftGearDeliveryBlue() {
	SetTimeout(15.0);
	AddParallel(new GearCloseAuto());
	AddSequential(new DriveAuto(6.55, 0, 0.3));
	AddSequential(new DriveAuto(6.55, 60, 0.3));
	AddSequential(new DriveAuto(12.75, 60, 0.3));
	AddSequential(new GearAuto());
	AddSequential(new DriveAuto(8, 60, 0.3));
	AddParallel(new GearCloseAuto());
	AddSequential(new DriveAuto(8, -89, 0.3));
}

void AutoLeftGearDeliveryBlue::Initialize() {
	t.Reset();
	t.Start();
}

