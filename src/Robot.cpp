#include <IterativeRobot.h>
#include <SmartDashboard/SendableChooser.h>
#include <LiveWindow/LiveWindow.h>
#include "CommandBase.h"
#include "Subsystems/DriveSubsystem.h"
#include "Subsystems/DrawerSubsystem.h"
#include "Subsystems/GearSubsystem.h"
#include "Commands/Auto/Auto.h"
#include "OI.h"
#include "WPILib.h"


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
		position->AddObject("Left Fast", new int(5));
		position->AddObject("Test", new int(6));
		SmartDashboard::PutData("Position", position);

		backup = new SendableChooser<int*>();
		backup->AddObject("Hopper", new int(1));
		backup->AddObject("Down The Field", new int(4));
		backup->AddObject("part way", new int(2));
		backup->AddObject("Crossover (only side autos)", new int(5));
		backup->AddObject("Go left around (only center auto)", new int(6));
		backup->AddObject("Go right around (only center auto)", new int(7));
		backup->AddDefault("no", new int(3));
		SmartDashboard::PutData("backup", backup);

		ultrasonic = new SendableChooser<int*>();
		ultrasonic->AddObject("Yes", new int(1));
		ultrasonic->AddDefault("no", new int(2));
		SmartDashboard::PutData("ultrasonic", ultrasonic);

		autoCommand = new Auto();
		printf("running \n");
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
		if (autoCommand != NULL)
			autoCommand->Cancel();

		CommandBase::gear->is_open = false;
	}

	void TeleopPeriodic()
	{
		frc::Scheduler::GetInstance()->Run();
		CommandBase::prints();
//		CommandBase::turret->TurretHome();
	}

	void TestPeriodic()
	{

//		CommandBase::turret->TurretHome();
	}
	void DisabledPeriodic()
	{
		if(CommandBase::oi->joystickLeft->GetRawButton(11)){
			CommandBase::drawer->Drawer->SetSelectedSensorPosition(0.0,0,0);
		}
		// Most commands will cancel themselves when run in disabled mode.
		frc::Scheduler::GetInstance()->Run();
		CommandBase::prints();
//		CommandBase::turret->TurretHome();
	}
};

START_ROBOT_CLASS(Robot)
