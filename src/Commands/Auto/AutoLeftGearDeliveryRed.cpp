#include <Commands/Auto/AutoLeftGearDeliveryRed.h>
#include "Commands/Drive/DriveAuto.h"
#include "Commands/Gear/GearAuto.h"
#include "Commands/Gear/GearCloseAuto.h"
#include "Commands/Misc/WaitTime.h"

AutoLeftGearDeliveryRed::AutoLeftGearDeliveryRed() {
	SetTimeout(15.0);
//	AddParallel(new ConveyorAuto(1.0,3.0));
	AddParallel(new GearCloseAuto());
	AddSequential(new DriveAuto(6.55, 0, 0.3));
	AddSequential(new DriveAuto(6.55, -60, 0.3));
	AddSequential(new DriveAuto(11.75, -60, 0.3));
	AddSequential(new GearAuto());
	AddSequential(new DriveAuto(8, -60, 0.3));
	AddParallel(new GearCloseAuto());
	AddSequential(new DriveAuto(8, -89, 0.3));
	//	AddSequential(new DriveAuto(3.5, 47, 0.5));
	//	AddSequential(new DriveAuto(3.5, 0, 0.5));
	//	AddSequential(new DriveAuto(20.0, 0, 0.5));
}

void AutoLeftGearDeliveryRed::Initialize() {
	t.Reset();
	t.Start();
}
