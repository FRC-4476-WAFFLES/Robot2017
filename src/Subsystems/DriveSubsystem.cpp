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
	 DriveBase = new RobotDrive(0,1,2,3);

	 DriveBase->SetInvertedMotor(RobotDrive::kFrontLeftMotor,true);
	 DriveBase->SetInvertedMotor(RobotDrive::kFrontRightMotor,true);
	 DriveBase->SetInvertedMotor(RobotDrive::kRearLeftMotor,true);
	 DriveBase->SetInvertedMotor(RobotDrive::kRearRightMotor,true);

	 gyro = new ADXRS450_Gyro();
	 DriveEncoder = new Encoder(DRIVE_ENCODER_A , DRIVE_ENCODER_B);
	 DriveEncoder2 = new Encoder(DRIVE_ENCODER_C, DRIVE_ENCODER_D);
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
	DriveBase->TankDrive(left,right,false);
}

double DriveSubsystem::driveEncoder()
{

	return (DriveEncoder->Get() + DriveEncoder2->Get())/2.0;
}
void DriveSubsystem::ReZero(){
	resetGyro();
	DriveEncoder->Reset();
}

