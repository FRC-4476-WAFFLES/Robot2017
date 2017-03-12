#include <Commands/Auto/AutoLeftGearDeliveryBlue.h>
#include "WPILib.h"
#include "CommandBase.h"
#include "Commands/Auto/AutoDoNothing.h"
#include "Commands/Auto/AutoGearDelivery.h"
#include "Subsystems/TurretSubsystem.h"
#include "Commands/Auto/AutoLeftGearDeliveryRed.h"
#include "Commands/Auto/AutoDriveForward.h"
class Robot: public IterativeRobot
{
private:
	LiveWindow *lw = LiveWindow::GetInstance();
	int autonomousposition;
	int autonomousbackup;
	int autonomousultrasonic;
	SendableChooser<int*>* position;
	SendableChooser<int*>* backup;
	SendableChooser<int*>* ultrasonic;

	void RobotInit()
	{
		CommandBase::init();
		position = new SendableChooser<int*>();
		position->AddDefault("Center", new int(1));
		position->AddObject("Right", new int(2));
		position->AddObject("Left", new int(3));
		SmartDashboard::PutData("Position", position);

		backup = new SendableChooser<int*>();
		backup->AddDefault("Hopper", new int(1));
		backup->AddObject("part way", new int(2));
		backup->AddObject("no", new int(3));
		SmartDashboard::PutData("backup", backup);

		ultrasonic = new SendableChooser<int*>();
		ultrasonic->AddDefault("Yes", new int(1));
		ultrasonic->AddObject("no", new int(2));
		SmartDashboard::PutData("ultrasonic", ultrasonic);

		printf("running");
	}


	/**
	 * This autonomous (along with the chooser code above) shows how to select between different autonomous modes
	 * using the dashboard. The sendable chooser code works with the Java SmartDashboard. If you prefer the LabVIEW
	 * Dashboard, remove all of the chooser code and uncomment the GetString line to get the auto name from the text box
	 * below the Gyro
	 *
	 * You can add additional auto modes by adding additional comparisons to the if-else structure below with additional strings.
	 * If using the SendableChooser make sure to add them to the chooser code above as well.
	 */
	void AutonomousInit()
	{
		if(CommandBase::drive != nullptr)
			CommandBase::drive->zero_sensors();
		autonomousposition = *position->GetSelected();
		//starts the selected command
		autonomousbackup = *backup->GetSelected();
		autonomousultrasonic = *ultrasonic->GetSelected();
	}

	void AutonomousPeriodic()
	{
		frc::Scheduler::GetInstance()->Run();
		CommandBase::prints();
//		CommandBase::turret->TurretHome();
	}

	void TeleopInit()
	{
//		if (autonomousposition != NULL)
//			autonomousposition->Cancel();
	}

	void TeleopPeriodic()
	{
		frc::Scheduler::GetInstance()->Run();
		CommandBase::prints();
		CommandBase::drawer->Drawer->SetPosition(0.0);
//		CommandBase::turret->TurretHome();
	}

	void TestPeriodic()
	{
		lw->Run();
		CommandBase::drawer->Drawer->SetPosition(0.0);
//		CommandBase::turret->TurretHome();
	}
	void DisabledPeriodic()
	{
		CommandBase::prints();
		CommandBase::drawer->Drawer->SetPosition(0.0);
//		CommandBase::turret->TurretHome();
	}
};

START_ROBOT_CLASS(Robot)
