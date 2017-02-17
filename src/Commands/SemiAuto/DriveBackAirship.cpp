#include "DriveBackAirship.h"
#include "Commands/Drive/DriveHalfRelative.h"
#include "Commands/Drive/DriveAutoRelative.h"
#include "Commands/Drive/DriveOperator.h"
#include "Commands/Gear/GearAuto.h"
#include "Commands/Gear/GearCloseAuto.h"

DriveBackAirship::DriveBackAirship(bool right) {
	SetTimeout(3.0);
//	AddSequential(new GearAuto());
//	AddSequential(new DriveAutoRelative(-1,0,1));
//	AddParallel(new GearCloseAuto());
	if(right)
		AddSequential(new DriveHalfRelative(70.0,0.03));
	else
		AddSequential(new DriveHalfRelative(-70.0,0.97));

	//-153.6666666666667
}

void DriveBackAirship::Execute(){
	if(CommandBase::oi->DriveActive()){
		Scheduler::GetInstance()->Remove(this);
		Scheduler::GetInstance()->AddCommand(new GearCloseAuto());
		Scheduler::GetInstance()->AddCommand(new DriveOperator());
	}
}
