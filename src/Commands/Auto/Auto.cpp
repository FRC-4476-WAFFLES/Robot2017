#include "Auto.h"
#include "Commands/Misc/WaitTime.h"
#include "Commands/Drive/DriveAuto.h"
#include "Commands/Shooter/ShooterPrepAuto.h"
#include "Commands/Shooter/ShootAutoUntil.h"
#include "Commands/Intake/ConveyorAuto.h"
#include "Commands/Turret/TurretCenterShot.h"
#include "Commands/Gear/GearCloseAuto.h"
#include "Commands/Gear/GearAuto.h"
#include "Commands/Turret/TurretVision.h"

Auto::Auto():
	// Default values for each number
	Auto(0, 0, 0) { }

Auto::Auto(int autonomousposition, int autonomousbackup, int autonomousultrasonic)
{
	// the idea is to use one command for any of the 20-30 possible auto modes using if statements
	//position
	//1 = center
	//2 = right
	//3 = left
	//backup
	//1 = hopper
	//2 = part way
	//3 = no
	//ultrasonic
	//1 = yes
	//2 = no

	SetTimeout(15.0);
	AddSequential(new WaitTime(1.0));
	if(autonomousposition == 0){
		AddSequential(new WaitTime(30.0));
	}else if(autonomousposition == 1){
		AddSequential(new DriveAuto(7.2, 0, 0.3));
		AddSequential(new GearAuto());
	}else if(autonomousposition == 2){
		if(DriverStation::GetInstance().GetAlliance == DriverStation::Alliance::kBlue){

		}
	}

}
