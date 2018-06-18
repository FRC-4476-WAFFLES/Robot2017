/**
 * OI is a class that is used to setup user input to the robot.
 */

#include "OI.h"
#include <math.h>
#include <DriverStation.h>
#include <Buttons/Button.h>
#include <Buttons/JoystickButton.h>
#include "SmartDashboard/SmartDashboard.h"

OI::OI()
{
	//Options between button types: WhenPressed, WhileHeld, ToggleWhenPressed
	// Process operator interface input here.

	// Joystick port declarations
	joystickLeft = new Joystick(0);
	joystickRight = new Joystick(1);
	operatorController = new Joystick(2);
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

	SmartDashboard::PutNumber("Battery Voltage", DriverStation::GetInstance().GetBatteryVoltage());
	SmartDashboard::PutNumber("Match time", DriverStation::GetInstance().GetMatchTime());
}
