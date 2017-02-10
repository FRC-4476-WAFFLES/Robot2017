/**
 * ShooterSubsystem is a class that keeps references to each of the
 * drive motors and drive encoder.
 */
#include <Commands/Shooter/ShooterDefault.h>
#include "ShooterSubsystem.h"
#include "../RobotMap.h"
#include "CANTalon.h"
#include "vision/run_result.hpp"
ShooterSubsystem::ShooterSubsystem():
		Subsystem("ShooterSubsystem")
{

	 Rollers = new CANTalon(SHOOTER_ROLLER);
	 Rollers_Slave = new CANTalon(SHOOTER_ROLLER_SLAVE);
	 Load = new VictorSP(SHOOTER_LOAD);

	 //CANTALLON SETUP//
//	 Rollers->SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);
//	 Rollers->SetSensorDirection(false);


	 //peak outputs
//     Rollers->ConfigNominalOutputVoltage(+0.0f, -0.0f);
//     Rollers->ConfigPeakOutputVoltage(+12.0f, -12.0f);



     //PID things
//     Rollers->SelectProfileSlot(0);
//     Rollers->SetF(0.1097);
//	 Rollers->SetP(0.22);
//	 Rollers->SetI(0);
//	 Rollers->SetD(0);
	 Rollers_Slave->SetControlMode(CANSpeedController::kFollower);
	 Rollers_Slave->Set(SHOOTER_ROLLER);
}

void ShooterSubsystem::InitDefaultCommand()
{
	// When no other commands are running, we do operator control
	SetDefaultCommand(new ShooterDefault);
}

//void ShooterSubsystem::SetSpeed(double RPM){
//	Rollers->SetTalonControlMode(CANTalon::kSpeedMode);
////	Rollers->SetSetpoint(RPM);
//	Rollers->Set(RPM);
//}
//



