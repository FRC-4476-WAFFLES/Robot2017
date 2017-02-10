#include "DriveBackLoadStation.h"
#include "Commands/Drive/DriveHalfRelative.h"
#include "Commands/Drive/DriveAutoRelative.h"
#include "Commands/Drive/DriveOperator.h"
DriveBackLoadStation::DriveBackLoadStation() {
	SetTimeout(2.0);
	AddSequential(new DriveAutoRelative(-0.5,0,1));
	AddSequential(new DriveHalfRelative(+135.0,2));

	//-153.6666666666667
}
void DriveBackLoadStation::Execute(){
	if(CommandBase::oi->DriveActive()){
		Scheduler::GetInstance()->Remove(this);
		Scheduler::GetInstance()->AddCommand(new DriveOperator);
	}
}
