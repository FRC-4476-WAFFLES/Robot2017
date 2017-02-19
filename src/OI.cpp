/**
 * OI is a class that is used to setup user input to the robot.
 */

#include "OI.h"
#include "Commands/SemiAuto/DriveBackAirship.h"
#include "Commands/SemiAuto/DriveBackLoadStation.h"
#include "Commands/Shooter/ShooterShoot.h"
#include "Commands/Shooter/ShooterPrep.h"
#include "Commands/Intake/IntakeIn.h"
#include "Commands/Intake/IntakeOut.h"
#include "Commands/Gear/GearDefault.h"
#include "Commands/Gear/GearToggle.h"
#include "Commands/Gear/GearCloseAuto.h"
#include "Commands/Gear/GearOpenAuto.h"
#include <math.h>
#include "Triggers/POVTrigger.h"
#include "Commands/Turret/TurretFullLeft.h"
#include "Commands/Turret/TurretFullRight.h"
#include "Commands/Turret/TurretCenterShot.h"
#include "Commands/Turret/TurretOffShot.h"
#include "Commands/Turret/TurretVision.h"
#include "Commands/Drive/DriveAuto.h"
OI::OI()
{
	/*

	*/
	//Options between button types: WhenPressed, WhileHeld, ToggleWhenPressed
	// Process operator interface input here.

	// Joystick port declarations
	joystickLeft = new Joystick(0);
	joystickRight = new Joystick(1);
	operatorController = new Joystick(2);

	Button* Airship1 = new JoystickButton(joystickLeft, 8);
	Button* Airship2 = new JoystickButton(joystickLeft, 9);
	Button* Airship3 = new JoystickButton(joystickRight, 8);
	Button* Airship4 = new JoystickButton(joystickRight, 9);
	Airship1->WhenReleased(new DriveBackLoadStation);
	Airship2->WhenReleased(new DriveBackLoadStation);
	Airship3->WhenReleased(new DriveBackLoadStation);
	Airship4->WhenReleased(new DriveBackLoadStation);

	Button* Load1 = new JoystickButton(joystickLeft, 6);
	Button* Load2 = new JoystickButton(joystickLeft, 7);
	Button* Load3 = new JoystickButton(joystickRight, 10);
	Button* Load4 = new JoystickButton(joystickRight, 11);
	Load1->WhenReleased(new DriveBackAirship(false));
	Load2->WhenReleased(new DriveBackAirship(false));
	Load3->WhenReleased(new DriveBackAirship(true));
	Load4->WhenReleased(new DriveBackAirship(true));

	Button* Shoot = new JoystickButton(operatorController, OperatorButton::BumperBottomRight);
	Shoot->WhileHeld(new ShooterShoot());
	Button* SpeedUp = new JoystickButton(operatorController, OperatorButton::B);
	SpeedUp->WhileHeld(new ShooterPrep());

	Button* Intake = new JoystickButton(operatorController, OperatorButton::A);
	Intake->WhileHeld(new IntakeIn());
	Button* Outtake = new JoystickButton(operatorController, OperatorButton::Y);
	Outtake->WhileHeld(new IntakeOut());

	Button* ToggleGear = new JoystickButton(operatorController, OperatorButton::Start);
	ToggleGear->WhenReleased(new GearCloseAuto());
	ToggleGear->WhenPressed(new GearOpenAuto());

	Trigger* FullLeft = new POVTrigger(operatorController, 270);
	FullLeft->WhenActive(new TurretFullLeft());
	Trigger* FullRight = new POVTrigger(operatorController, 90);
	FullRight->WhenActive(new TurretFullRight());
	Trigger* OffShot = new POVTrigger(operatorController, 180);
	OffShot->WhenActive(new TurretOffShot());
	Trigger* CenterShot = new POVTrigger(operatorController,  0);
	CenterShot->WhenActive(new TurretCenterShot());

	Button* ToggleVision = new JoystickButton(operatorController, OperatorButton::Back);
	ToggleVision->WhileHeld(new TurretVision());

	Button* DriveSomewhere = new JoystickButton(operatorController, OperatorButton::BumperTopLeft);
	DriveSomewhere->WhenReleased(new DriveAuto(0.0,90.0,1.0));
}

bool OI::DriveDeadzone(double x){
	return (fabs(x) < 0.05);
}

bool OI::DriveActive(){
	return !(fabs(joystickLeft->GetRawAxis(1)) < 0.15) ||!(fabs(joystickRight->GetRawAxis(1) < 0.15));
}
