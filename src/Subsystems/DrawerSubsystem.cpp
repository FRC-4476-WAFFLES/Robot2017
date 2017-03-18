/**
 * DrawerSubsytem is a class that keeps references to each of the
 * drive motors and drive encoder.
 */
#include <Commands/Drawer/DrawerDefault.h>
#include <Subsystems/DrawerSubsystem.h>
#include "../RobotMap.h"
#include "Helpers/PIDPreferences.h"

DrawerSubsystem::DrawerSubsystem():
		Subsystem("DrawerSubsytem")
{
	 Drawer = new CANTalon(DRAWER);

	 Drawer->SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);
	 Drawer->SetSensorDirection(false);

	 Drawer->ConfigNominalOutputVoltage(+0.0f, -0.0f);
	 Drawer->ConfigPeakOutputVoltage(+12.0f, -12.0f);

	 Drawer->EnableZeroSensorPositionOnReverseLimit(true);

	 UpdatePID("Drawer", Drawer);
}

void DrawerSubsystem::InitDefaultCommand()
{
	// When no other commands are running, we do operator control
	SetDefaultCommand(new DrawerDefault());
}

void DrawerSubsystem::SetSetpoint(double point) {
	UpdatePID("Drawer", Drawer);
	Drawer->SetControlMode(CANTalon::kPosition);
	Drawer->SetSetpoint(point);
}

double DrawerSubsystem::GetSetpoint() {
	return Drawer->GetSetpoint();
}

void DrawerSubsystem::prints() {
	SmartDashboard::PutNumber("Drawer Encoder", Drawer->GetPosition());
}


