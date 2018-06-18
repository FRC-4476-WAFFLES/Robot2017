#include <IterativeRobot.h>
#include <SmartDashboard/SendableChooser.h>
#include <LiveWindow/LiveWindow.h>
#include "CommandBase.h"
#include "Subsystems/DriveSubsystem.h"
#include "OI.h"
#include "WPILib.h"


class Robot: public IterativeRobot
{
private:
	LiveWindow *lw = LiveWindow::GetInstance();
	void RobotInit()
	{
		CommandBase::init();
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
	}

	void AutonomousPeriodic()
	{
		frc::Scheduler::GetInstance()->Run();
		CommandBase::prints();
	}

	void TeleopInit()
	{

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
		// Most commands will cancel themselves when run in disabled mode.
		frc::Scheduler::GetInstance()->Run();
		CommandBase::prints();
	}
};

START_ROBOT_CLASS(Robot)
