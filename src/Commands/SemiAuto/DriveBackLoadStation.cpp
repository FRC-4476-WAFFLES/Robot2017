#include "DriveBackLoadStation.h"
#include "Commands/Drive/DriveHalfRelative.h"
#include "Commands/Drive/DriveAutoRelative.h"
#include "Commands/Drive/DriveOperator.h"

DriveBackLoadStation::DriveBackLoadStation() {
	SetTimeout(10.0);
	AddSequential(new DriveAutoRelative(-2.0, 0, 1.0));
	// Blue
//	AddSequential(new DriveAutoRelative(-2.0, -45.0, 1.0));
//	AddSequential(new DriveHalfRelative(-90.0, 0.0, 0.5));
	// Red
	AddSequential(new DriveAutoRelative(-2.0, 45.0, 1.0));
	AddSequential(new DriveHalfRelative(90.0, 1.0, 1.0));
}

void DriveBackLoadStation::Execute(){
	if(CommandBase::oi->DriveActive()){
		Scheduler::GetInstance()->Remove(this);
		Scheduler::GetInstance()->AddCommand(new DriveOperator);
	}
}
