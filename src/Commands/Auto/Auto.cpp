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
#include "Commands/Drawer/DrawerOut.h"
#include <Commands/StartCommand.h>
#include "Commands/Drive/DriveHalfRelative.h"
#include "Commands/Drive/DriveAutoRelative.h"
#include "Commands/Drawer/DrawerIn.h"
#include "Commands/Climber/ClimberClimb.h"
#include "Commands/Drive/DriveAutoTolerant.h"
#include "Commands/Drawer/DrawerBumper.h"

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
	AddParallel(new StartCommand(new DrawerOut()));

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
		AddSequential(new DriveAuto(3.9, 0, 0.5));
		break;

		case 2: // Deliver gear right
		// I think we don't want to check for alliance colour here
		AddSequential(new DriveAuto(6.55, 0, 0.5));
		AddSequential(new DriveAuto(6.55, -62, 0.5));
		AddSequential(new DriveAuto(8.65, -62, 0.5));
		break;

		case 3: // Deliver gear left
		// I think we don't want to check for alliance colour here
		AddSequential(new DriveAuto(6.65, 0, 0.5));
		AddSequential(new DriveAuto(6.65, 62, 0.5));
		AddSequential(new DriveAuto(8.75, 62, 0.5));//.549
		break;

		case 4: // Just drive forward
		AddSequential(new DriveAuto(6, 0, 0.5));
		AddSequential(new WaitTime(1.0));
		break;


		case 5: // Deliver gear left Fast
		// I think we don't want to check for alliance colour here
		AddSequential(new DriveAuto(6.2, 0, 0.6));
		AddSequential(new DriveAuto(6.2, 62, 0.4));
		AddSequential(new DriveAuto(8.65, 62, 0.7));
		break;
		return; // This auto stops here. Don't deliver gear.

		case 6: // test
		AddSequential(new DriveAuto(3, 0, 0.3));
		AddSequential(new GearAuto());
		AddSequential(new WaitTime(2));
		AddSequential(new GearCloseAuto());
		AddSequential(new DriveAuto(3, 0, 0.3));
		AddSequential(new DriveAuto(3, 0, 0.3));
		AddParallel(new StartCommand(new DrawerIn()));
		AddParallel(new StartCommand(new DrawerOut()));
		AddSequential(new ClimberClimb());
		return;
	}

	if(autonomousultrasonic == 1) {
		// Yes ultrasonic
		AddSequential(new GearAutoUltrasonic());
	} else {
		// No ultrasonic
		switch(autonomousposition) {
			case 1: // Deliver gear middle
			AddSequential(new DriveAuto(6.2, 0, 0.6));
			break;

			case 2: // Deliver gear right
			AddSequential(new DriveAuto(11.85, -62, 0.6));
			break;

			case 3: // Deliver gear left
			AddSequential(new DriveAuto(11.85, 62, 0.6));
			break;
			case 5: // Deliver gear left Fast
			AddSequential(new DriveAuto(11.85, 62, 0.6));
			break;

			case 6: // test
			break;
		}
	}

	// If we get here, we (should be) at the peg.
	AddSequential(new GearAuto());

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
			AddSequential(new DriveAuto(5.2, 0, 0.5));
			AddSequential(new DriveAuto(2.5, 0, 0.5));
			AddParallel(new StartCommand(new DrawerBumper()));
			AddSequential(new GearCloseAuto());
			break;
			
			case 2: // Deliver gear right
			AddSequential(new DriveAuto(8, -62, 0.5));
			AddParallel(new StartCommand(new DrawerBumper()));
			AddSequential(new GearCloseAuto());
			break;

			case 3: // Deliver gear left
			AddSequential(new DriveAuto(8, 62, 0.5));
			AddParallel(new StartCommand(new DrawerBumper()));
			AddSequential(new GearCloseAuto());
			break;

			case 5: // Deliver gear left Fast
			AddSequential(new DriveAuto(8, 62, 0.5));
			AddParallel(new StartCommand(new DrawerBumper()));
			AddSequential(new GearCloseAuto());
			break;

			case 6: // test
			break;
		}
		break;
		case 4://backup and drive down the field
		switch(autonomousposition) {
			case 1: // Deliver gear middle
			AddSequential(new DriveAuto(5.2, 0, 0.3));
			AddSequential(new DriveAuto(2.5, 0, 0.3));
			AddParallel(new StartCommand(new DrawerBumper()));
			AddSequential(new GearCloseAuto());
			break;

			case 2: // Deliver gear right
			AddSequential(new DriveAuto(8, -62, 0.3));
			AddParallel(new StartCommand(new DrawerBumper()));
			AddSequential(new GearCloseAuto());
			AddSequential(new DriveAuto(8, 0, 0.3));
			AddSequential(new DriveAuto(30, 0, 0.6));
			break;

			case 3: // Deliver gear left
			AddSequential(new DriveAuto(8, 62, 0.3));
			AddParallel(new StartCommand(new DrawerBumper()));
			AddSequential(new GearCloseAuto());
			AddSequential(new DriveAuto(8, 0, 0.3));
			AddSequential(new DriveAuto(30, 0, 0.6));
			break;

			case 5: // Deliver gear left Fast
			AddSequential(new DriveAuto(8, 62, 0.6));
			AddParallel(new StartCommand(new DrawerBumper()));
			AddSequential(new GearCloseAuto());
			AddSequential(new DriveAuto(8, 0, 0.6));
			AddSequential(new DriveAuto(30, 0, 0.8));
			break;

			case 6: //test
			break;
		}
		break;
		case 5: //backup and drive down the field with cross over
		switch(autonomousposition) {
			case 1: // Deliver gear middle
			AddSequential(new DriveAuto(5.2, 0, 0.3));
			AddSequential(new DriveAuto(2.5, 0, 0.3));
			AddParallel(new StartCommand(new DrawerBumper()));
			AddSequential(new GearCloseAuto());
			break;

			case 2: // Deliver gear right
			AddSequential(new DriveAutoTolerant(8, -62, 0.8));
			AddParallel(new StartCommand(new DrawerBumper()));
			AddSequential(new GearCloseAuto());
			AddSequential(new DriveAutoTolerant(8, 0, 0.8));
			AddSequential(new DriveAutoTolerant(16, 0, 1.0));
			AddSequential(new DriveAutoTolerant(16, -40, 0.5));
			AddSequential(new DriveAuto(35, -40, 1.0));
			break;

			case 3: // Deliver gear left
			AddSequential(new DriveAutoTolerant(8, 62, 0.8));
			AddParallel(new StartCommand(new DrawerBumper()));
			AddSequential(new GearCloseAuto());
			AddSequential(new DriveAutoTolerant(8, 0, 0.8));
			AddSequential(new DriveAutoTolerant(16, 0, 1.0));
			AddSequential(new DriveAutoTolerant(16, 40, 0.5));
			AddSequential(new DriveAuto(35, 40, 1.0));
			break;

			case 5: // Deliver gear left Fast
			AddSequential(new DriveAutoTolerant(8, 62, 0.8));
			AddParallel(new StartCommand(new DrawerBumper()));
			AddSequential(new GearCloseAuto());
			AddSequential(new DriveAutoTolerant(8, 0, 0.8));
			AddSequential(new DriveAutoTolerant(16, 0, 1.0));
			AddSequential(new DriveAutoTolerant(16, 40, 0.5));
			AddSequential(new DriveAuto(35, 40, 1.0));
			break;

			case 6: //test
			break;
		}
		break;
		case 6: // Drive left around the airship after center auto
		if(autonomousposition == 1) {
			// Deliver gear middle
			AddSequential(new DriveAutoRelative(-3, 0));
			AddSequential(new DriveAutoRelative(0, -90));
			AddSequential(new DriveAutoRelative(8, 0));
			AddParallel(new StartCommand(new DrawerBumper()));
			AddSequential(new DriveAutoRelative(0, 80));
			AddSequential(new DriveAutoRelative(20, 0));
		}
		break;
		case 7: // Drive right around the airship after center auto
		if(autonomousposition == 1) {
			// Deliver gear middle
			AddSequential(new DriveAutoRelative(-3, 0));
			AddSequential(new DriveAutoRelative(0, 90));
			AddSequential(new DriveAutoRelative(8, 0));
			AddParallel(new StartCommand(new DrawerBumper()));
			AddSequential(new DriveAutoRelative(0, -80));
			AddSequential(new DriveAutoRelative(20, 0));
		}
		break;
	}
}
