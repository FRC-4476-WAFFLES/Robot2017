/**
 * OI is a class that is used to setup user input to the robot.
 */

#include "OI.h"
#include <math.h>
#include <DriverStation.h>
#include <Buttons/Button.h>
#include <Buttons/JoystickButton.h>
//#include "Commands/Gear/GearOpenAutoUltrasonic.h"
//#include "Commands/SemiAuto/DriveBackAirship.h"
//#include "Commands/SemiAuto/DriveBackLoadStation.h"
//#include "Commands/Shooter/ShooterShoot.h"
//#include "Commands/Shooter/ShooterPrep.h"
//#include "Commands/Intake/IntakeIn.h"
//#include "Commands/Intake/IntakeOut.h"
//#include "Commands/Gear/GearDefault.h"
//#include "Commands/Gear/GearToggle.h"
#include "Commands/Gear/GearCloseAuto.h"
#include "Commands/Gear/GearOpenAuto.h"
#include "Commands/Gear/CancelGearCommand.h"
#include "Commands/Gear/GearSafeMode.h"
//#include "Commands/Gear/GearOpenAutoUltrasonic.h"
//#include "Commands/Turret/TurretFullLeft.h"
//#include "Commands/Turret/TurretFullRight.h"
//#include "Commands/Turret/TurretCenterShot.h"
//#include "Commands/Turret/TurretOffShot.h"
//#include "Commands/Turret/TurretVision.h"
//#include "Commands/Drive/DriveAuto.h"
#include "Commands/Climber/ClimberClimb.h"
#include "Commands/Climber/ClimberStop.h"
#include "Commands/Drawer/DrawerOut.h"
#include "Commands/Drawer/DrawerIn.h"
#include "Commands/Drawer/DrawerBumper.h"
#include "Commands/Climber/ClimberFudge.h"
#include "Commands/Climber/ClimberGrab.h"
#include "Commands/Climber/ClimberGrabReverse.h"
#include "Commands/Climber/ClimberAutomaticClimb.h"
#include "SmartDashboard/SmartDashboard.h"

OI::OI()
{
	//Options between button types: WhenPressed, WhileHeld, ToggleWhenPressed
	// Process operator interface input here.

	// Joystick port declarations
	joystickLeft = new Joystick(0);
	joystickRight = new Joystick(1);
	operatorController = new Joystick(2);

//	Button* Airship1 = new JoystickButton(joystickLeft, 8);
//	Button* Airship2 = new JoystickButton(joystickLeft, 9);
//	Button* Airship3 = new JoystickButton(joystickRight, 8);
//	Button* Airship4 = new JoystickButton(joystickRight, 9);
//	Airship1->WhenReleased(new DriveBackLoadStation);
//	Airship2->WhenReleased(new DriveBackLoadStation);
//	Airship3->WhenReleased(new DriveBackLoadStation);
//	Airship4->WhenReleased(new DriveBackLoadStation);
//
//	Button* Load1 = new JoystickButton(joystickLeft, 6);
//	Button* Load2 = new JoystickButton(joystickLeft, 7);
//	Button* Load3 = new JoystickButton(joystickRight, 10);
//	Button* Load4 = new JoystickButton(joystickRight, 11);
//	Load1->WhenReleased(new DriveBackAirship(false));
//	Load2->WhenReleased(new DriveBackAirship(false));
//	Load3->WhenReleased(new DriveBackAirship(true));
//	Load4->WhenReleased(new DriveBackAirship(true));
//
//	Button* Shoot = new JoystickButton(operatorController, OperatorButton::BumperBottomRight);
//	Shoot->WhileHeld(new ShooterShoot());
//	Shoot->WhileHeld(new IntakeIn());
//	Button* SpeedUp = new JoystickButton(operatorController, OperatorButton::B);
//	SpeedUp->ToggleWhenPressed(new ShooterPrep());

//	Button* Intake = new JoystickButton(operatorController, OperatorButton::A);
//	Intake->WhileHeld(new IntakeIn());
//	Button* Outtake = new JoystickButton(operatorController, OperatorButton::Y);
//	Outtake->WhileHeld(new IntakeOut());

	Button* CancelGear = new JoystickButton(operatorController, OperatorButton::Start);
	CancelGear->WhenPressed(new CancelGearCommand());
	Button* ToggleGear = new JoystickButton(operatorController, OperatorButton::X);
	ToggleGear->WhenReleased(new GearCloseAuto());
	ToggleGear->WhenPressed(new GearOpenAuto());

	Button* DrawerFullOut = new JoystickButton(operatorController, OperatorButton::Y);
	DrawerFullOut->WhenReleased(new DrawerOut());
	Button* DrawerFullIn = new JoystickButton(operatorController, OperatorButton::A);
	DrawerFullIn->WhenReleased(new DrawerIn());
	Button* DrawerToBumper = new JoystickButton(operatorController, OperatorButton::B);
	DrawerToBumper->WhenReleased(new DrawerBumper());

//	Button* GrabRope = new JoystickButton(operatorController, OperatorButton::BumperTopLeft);
	//GrabRope->WhileHeld(new ClimberGrab());
	Button* saftyfirst = new JoystickButton(operatorController, OperatorButton::BumperTopRight);
	saftyfirst->WhenPressed(new GearSafeMode());

	Button* AutoClimb = new JoystickButton(operatorController, OperatorButton::BumperTopLeft);
	AutoClimb->WhileHeld(new ClimberAutomaticClimb());
	// GrabRope->WhenReleased(new ClimberStop());
	// Button* climb = new JoystickButton(operatorController, OperatorButton::BumperTopRight);
	// climb->WhenReleased(new ClimberClimb());


//	Trigger* FullLeft = new POVTrigger(operatorController, 270);
//	FullLeft->WhenActive(new TurretFullLeft());
//	Trigger* FullRight = new POVTrigger(operatorController, 90);
//	FullRight->WhenActive(new TurretFullRight());
//	Trigger* OffShot = new POVTrigger(operatorController, 180);
//	OffShot->WhenActive(new TurretOffShot());
//	Trigger* CenterShot = new POVTrigger(operatorController,  0);
//	CenterShot->WhenActive(new TurretCenterShot());
//
//	Button* ToggleVision = new JoystickButton(operatorController, OperatorButton::Back);
//	ToggleVision->WhileHeld(new TurretVision());
//
//	Button* DriveSomewhere = new JoystickButton(operatorController, OperatorButton::BumperTopLeft);
//	DriveSomewhere->WhenReleased(new DriveAuto(0.0,90.0,1.0));
}

bool OI::DriveDeadzone(double x){
	return (fabs(x) < 0.05);
}

bool OI::DriveActive(){
	return !(fabs(joystickLeft->GetRawAxis(1)) < 0.15) ||!(fabs(joystickRight->GetRawAxis(1) < 0.15));
}

void OI::prints() {
	SmartDashboard::PutNumber("Operator (X)", operatorController->GetRawButton(OI::X));
	SmartDashboard::PutNumber("Operator (Y)", operatorController->GetRawButton(OI::Y));
	SmartDashboard::PutNumber("Operator (A)", operatorController->GetRawButton(OI::A));
	SmartDashboard::PutNumber("Operator (B)", operatorController->GetRawButton(OI::B));

	SmartDashboard::PutNumber("Operator Axis (Left Y)", operatorController->GetY(Joystick::kLeftHand));
	SmartDashboard::PutNumber("Operator Axis (Right Y)", operatorController->GetY(Joystick::kRightHand));

	SmartDashboard::PutNumber("Left Joystick Axis", joystickLeft->GetY());
	SmartDashboard::PutNumber("Right Joystick Axis", joystickRight->GetY());

	SmartDashboard::PutNumber("0 Drive",pdp.GetCurrent(0));
	SmartDashboard::PutNumber("1 Drive",pdp.GetCurrent(1));
	SmartDashboard::PutNumber("2 Drive",pdp.GetCurrent(2));

	SmartDashboard::PutNumber("13 Drive",pdp.GetCurrent(13));
	SmartDashboard::PutNumber("14 Drive",pdp.GetCurrent(14));
	SmartDashboard::PutNumber("15 Drive",pdp.GetCurrent(15));
	
	SmartDashboard::PutNumber("3 Climb",pdp.GetCurrent(3));
	SmartDashboard::PutNumber("12 Climb",pdp.GetCurrent(12));
	SmartDashboard::PutNumber("5 Gear",pdp.GetCurrent(5));
	SmartDashboard::PutNumber("7 Drawer",pdp.GetCurrent(7));
	SmartDashboard::PutNumber("11 Lights",pdp.GetCurrent(11));


	SmartDashboard::PutNumber("Battery Voltage", DriverStation::GetInstance().GetBatteryVoltage());
	SmartDashboard::PutNumber("Match time", DriverStation::GetInstance().GetMatchTime());
}
