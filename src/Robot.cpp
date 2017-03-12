#include <Commands/Auto/AutoLeftGearDeliveryBlue.h>
#include "WPILib.h"
#include "CommandBase.h"
#include "Commands/Auto/Auto.h"
#include "Subsystems/TurretSubsystem.h"

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
	Auto* autoCommand;

	void RobotInit()
	{
		CommandBase::init();
		position = new SendableChooser<int*>();
		position->AddDefault("nothing", new int(0));
		position->AddObject("Center", new int(1));
		position->AddObject("Right", new int(2));
		position->AddObject("Left", new int(3));
		position->AddObject("DriveForeward", new int(4));
		SmartDashboard::PutData("Position", position);

		backup = new SendableChooser<int*>();
		backup->AddObject("Hopper", new int(1));
		backup->AddObject("part way", new int(2));
		backup->AddDefault("no", new int(3));
		SmartDashboard::PutData("backup", backup);

		ultrasonic = new SendableChooser<int*>();
		ultrasonic->AddObject("Yes", new int(1));
		ultrasonic->AddDefault("no", new int(2));
		SmartDashboard::PutData("ultrasonic", ultrasonic);

		autoCommand = new Auto();
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
		autonomousbackup = *backup->GetSelected();
		autonomousultrasonic = *ultrasonic->GetSelected();

		// Remove the previous autonomous command
		frc::Scheduler::GetInstance()->Remove(autoCommand);
		delete autoCommand;
		// Create a new autonomous command
		autoCommand = new Auto(autonomousposition, autonomousbackup, autonomousultrasonic);
		// Run it.
		autoCommand->Start();
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
