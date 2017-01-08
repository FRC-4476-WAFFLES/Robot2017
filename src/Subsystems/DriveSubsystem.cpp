/**
 * DriveSubsystem is a class that keeps references to each of the
 * drive motors and drive encoder.
 */


#include <Commands/Drive/DriveOperator.h>
#include "DriveSubsystem.h"
#include "../RobotMap.h"

DriveSubsystem::DriveSubsystem():
		Subsystem("DriveSubsystem")
{
	 RightMotorFront = new Victor(DRIVE_MOTOR_RIGHT_FRONT);
	 RightMotorBack = new  Victor(DRIVE_MOTOR_RIGHT_BACK);
	 LeftMotorFront = new Victor(DRIVE_MOTOR_LEFT_FRONT);
	 LeftMotorBack = new Victor(DRIVE_MOTOR_LEFT_BACK);

	 gyro = new ADXRS450_Gyro();
	 DriveEncoder = new Encoder(DRIVE_ENCODER_A , DRIVE_ENCODER_B);
}

void DriveSubsystem::InitDefaultCommand()
{
	// When no other commands are running, we do operator control
	SetDefaultCommand(new DriveOperator());
}

double DriveSubsystem::GetGyro() {
	return gyro->GetAngle();
}

void DriveSubsystem::resetGyro(){
	gyro->Reset();
}

void DriveSubsystem::Drive(double left, double right)
{
	RightMotorFront->SetSpeed(right);
	LeftMotorFront->SetSpeed(-left);
	RightMotorBack->SetSpeed(right);
	LeftMotorBack->SetSpeed(-left);
}

double DriveSubsystem::driveEncoder()
{
	return DriveEncoder->Get();
}
void DriveSubsystem::ReZero(){
	resetGyro();
	DriveEncoder->Reset();
}

