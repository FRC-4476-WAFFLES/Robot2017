#include "AutoLeftGearDelivery.h"
#include "Commands/Drive/DriveAuto.h"
#include "Commands/Gear/GearAuto.h"

AutoLeftGearDelivery::AutoLeftGearDelivery() {
	SetTimeout(15.0);
	AddSequential(new DriveAuto(4.0, 0, 0.5));
	AddSequential(new DriveAuto(4.0, 47, 0.5));
	AddSequential(new DriveAuto(4.7, 47, 0.5));
	AddSequential(new GearAuto());
	AddSequential(new DriveAuto(3.5, 47, 0.5));
	AddSequential(new DriveAuto(3.5, 0, 0.5));
	AddSequential(new DriveAuto(20.0, 0, 0.5));
}
