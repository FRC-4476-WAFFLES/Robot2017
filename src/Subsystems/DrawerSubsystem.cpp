/**
 * DrawerSubsytem is a class that keeps references to each of the
 * drive motors and drive encoder.
 */
#include <Commands/Drawer/DrawerDefault.h>
#include <Subsystems/DrawerSubsystem.h>
#include "../RobotMap.h"

DrawerSubsystem::DrawerSubsystem():
		Subsystem("DrawerSubsytem")
{
	 Drawer = new CANTalon(DRAWER);

	 Drawer->SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);
	 Drawer->SetSensorDirection(false);

	 Drawer->ConfigNominalOutputVoltage(+0.0f, -0.0f);
	 Drawer->ConfigPeakOutputVoltage(+12.0f, -12.0f);

	 Drawer->EnableZeroSensorPositionOnReverseLimit(true);

	 Drawer->SelectProfileSlot(0);
	 Drawer->SetP(0.0022);
	 Drawer->SetI(0);
	 Drawer->SetD(0);
}

void DrawerSubsystem::InitDefaultCommand()
{
	// When no other commands are running, we do operator control
	SetDefaultCommand(new DrawerDefault());
}



