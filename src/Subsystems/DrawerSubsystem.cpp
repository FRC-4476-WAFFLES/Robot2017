/**
 * DrawerSubsytem is a class that keeps references to each of the
 * drive motors and drive encoder.
 */
#include <Commands/Drawer/DrawerDefault.h>
#include <Subsystems/DrawerSubsystem.h>
#include "../RobotMap.h"
#include "Helpers/PIDPreferences.h"
#include "WPILib.h"
#include <ctre/phoenix/MotorControl/CAN/TalonSRX.h>
#include <ctre/Phoenix.h>

DrawerSubsystem::DrawerSubsystem():
		Subsystem("DrawerSubsytem")
{
	 Drawer = new TalonSRX(DRAWER);

	 Drawer->ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder,0,0);
	 Drawer->SetSensorPhase(true);
	 Drawer->SetInverted(true);



	 UpdatePID("Drawer", Drawer);
}

void DrawerSubsystem::InitDefaultCommand()
{
	// When no other commands are running, we do operator control
	SetDefaultCommand(new DrawerDefault());
}

void DrawerSubsystem::SetSetpoint(double point) {
	UpdatePID("Drawer", Drawer);
	Drawer->Set(ControlMode::Position, point);

}

double DrawerSubsystem::GetSetpoint() {
	return Drawer->GetClosedLoopTarget(0);
}

void DrawerSubsystem::prints() {
	Command* current = GetCurrentCommand();
	if(current != nullptr) {
		SmartDashboard::PutString("Drawer Command", current->GetName());
	} else {
		SmartDashboard::PutString("Drawer Command", "None");
	}
	SmartDashboard::PutNumber("Drawer Encoder", Drawer->GetSelectedSensorPosition(0));
	SmartDashboard::PutNumber("Drawer Encoder Target", Drawer->GetClosedLoopTarget(0));
}


