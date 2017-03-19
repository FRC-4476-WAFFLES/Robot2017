#include "Auto.h"
#include <DriverStation.h>
#include "Commands/Misc/WaitTime.h"
#include "Commands/Drive/DriveAuto.h"
#include "Commands/Shooter/ShooterPrepAuto.h"
#include "Commands/Shooter/ShootAutoUntil.h"
#include "Commands/Intake/ConveyorAuto.h"
#include "Commands/Turret/TurretCenterShot.h"
#include "Commands/Gear/GearCloseAuto.h"
#include "Commands/Gear/GearAuto.h"
#include "Commands/Gear/GearAutoUltrasonic.h"
#include "Commands/Turret/TurretVision.h"

Auto::Auto():
	// Default values for each number
	Auto(0, 0, 0) { }

Auto::Auto(int autonomousposition, int autonomousbackup, int autonomousultrasonic)
{
	// the idea is to use one command for any of the 20-30 possible auto modes using if statements
	//position
	//0 = nothing
	//1 = center
	//2 = right
	//3 = left
	//4 = drive forward
	//backup
	//1 = hopper
	//2 = part way
	//3 = no
	//ultrasonic
	//1 = yes
	//2 = no

	SetTimeout(15.0);
	AddParallel(new GearCloseAuto());

	// All of these cases bail early and do nothing
	if(autonomousposition == 0 || // Nothing auto
	   (DriverStation::GetInstance().GetAlliance() != DriverStation::Alliance::kBlue
	   && DriverStation::GetInstance().GetAlliance() != DriverStation::Alliance::kRed
	   && autonomousposition != 1 && autonomousposition != 4) // We don't know which alliance we're on (and need to)
	) {
		AddSequential(new WaitTime(30.0));
		return;
	}

	switch(autonomousposition) {
		default: // Shouldn't be possible
		AddSequential(new WaitTime(30.0));
		return;

		case 1: // Deliver gear middle
		AddSequential(new DriveAuto(7.2, 0, 0.3));
		break;

		case 2: // Deliver gear right
		// I think we don't want to check for alliance colour here
		AddSequential(new DriveAuto(6.55, 0, 0.3));
		AddSequential(new DriveAuto(6.55, -60, 0.3));
		AddSequential(new DriveAuto(12.95, -60, 0.3));
		break;

		case 3: // Deliver gear left
		// I think we don't want to check for alliance colour here
		AddSequential(new DriveAuto(6.55, 0, 0.3));
		AddSequential(new DriveAuto(6.55, 60, 0.3));
		AddSequential(new DriveAuto(12.95, 60, 0.3));
		break;

		case 4: // Just drive forward
		AddSequential(new DriveAuto(6, 0, 0.3));
		AddSequential(new WaitTime(1.0));
		return; // This auto stops here. Don't deliver gear.
	}

	if(autonomousultrasonic == 2) {
		// Yes ultrasonic
		AddSequential(new GearAutoUltrasonic());
	} else {
		// No ultrasonic
		switch(autonomousposition) {
			case 1: // Deliver gear middle
			AddSequential(new DriveAuto(7.2, 0, 0.3));
			break;

			case 2: // Deliver gear right
			AddSequential(new DriveAuto(12.95, -60, 0.3));
			break;

			case 3: // Deliver gear left
			AddSequential(new DriveAuto(12.95, 60, 0.3));
			break;
		}
	}

	// If we get here, we (should be) at the peg.
	AddSequential(new GearAuto());
	AddParallel(new GearCloseAuto());

	switch(autonomousbackup) {
	default: // No back up
		AddSequential(new WaitTime(30.0));
		break;
		case 1: // Back up and hit hopper
		// TODO: hopper
		break;
		case 2: // Back up part way
		switch(autonomousposition) {
			case 1: // Deliver gear middle
			AddSequential(new DriveAuto(5.2, 0, 0.8));
			AddSequential(new DriveAuto(2.5, 0, 0.3));
			AddSequential(new GearCloseAuto());
			break;
			
			case 2: // Deliver gear right
			AddSequential(new DriveAuto(8, -60, 0.3));
			AddSequential(new GearCloseAuto());
			break;

			case 3: // Deliver gear left
			AddSequential(new DriveAuto(8, 60, 0.3));
			AddSequential(new GearCloseAuto());
			break;
		}
	}
}
