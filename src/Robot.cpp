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
	Command* autonomousCommand;
	SendableChooser<Command*>* chooser;

	void RobotInit()
	{
		CommandBase::init();
		chooser = new SendableChooser<Command*>();
		chooser->AddDefault("Nothing Auto", new AutoDoNothing());
		chooser->AddObject("Gear Delivery Auto", new AutoGearDelivery());
		chooser->AddObject("RED Gear Delivery Right ", new AutoLeftGearDeliveryRed());
		chooser->AddObject("BLUE Gear Delivery Left ", new AutoLeftGearDeliveryBlue());
		chooser->AddDefault("drive forward Auto", new AutoDriveForward());
		SmartDashboard::PutData("Auto Modes", chooser);
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
		autonomousCommand = (Command*) chooser->GetSelected();
		//starts the selected command
		autonomousCommand->Start();
	}

	void AutonomousPeriodic()
	{
		frc::Scheduler::GetInstance()->Run();
		CommandBase::prints();
		CommandBase::turret->TurretHome();
	}

	void TeleopInit()
	{
		if (autonomousCommand != NULL)
			autonomousCommand->Cancel();
	}

	void TeleopPeriodic()
	{
		frc::Scheduler::GetInstance()->Run();
		CommandBase::prints();
		CommandBase::turret->TurretHome();
	}

	void TestPeriodic()
	{
		lw->Run();
		CommandBase::turret->TurretHome();
	}
	void DisabledPeriodic()
	{
		CommandBase::prints();
		CommandBase::turret->TurretHome();
	}
};

START_ROBOT_CLASS(Robot)
