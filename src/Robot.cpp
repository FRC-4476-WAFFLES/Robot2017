#include "WPILib.h"

class Robot: public IterativeRobot
{
private:
	LiveWindow *lw = LiveWindow::GetInstance();
	Talon *Motor7;
	Talon *Motor6;
	Talon *Motor5;
	Talon *Motor4;
	Joystick *LeftJoystick;
	Joystick *RightJoystick;
	RobotDrive *DriveBase;

	void RobotInit()
	{
		LeftJoystick = new Joystick(0);
		RightJoystick = new Joystick(1);
		DriveBase = new RobotDrive(0,1,2,3);
		DriveBase->SetInvertedMotor(RobotDrive::kFrontLeftMotor,true);
		DriveBase->SetInvertedMotor(RobotDrive::kFrontRightMotor,true);
		DriveBase->SetInvertedMotor(RobotDrive::kRearLeftMotor,true);
		DriveBase->SetInvertedMotor(RobotDrive::kRearRightMotor,true);
		Motor7 = new Talon(7);
		Motor6 = new Talon(6);
		Motor5 = new Talon(5);
		Motor4 = new Talon(4);
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

	}

	void AutonomousPeriodic()
	{

	}

	void TeleopInit()
	{

	}

	void TeleopPeriodic()
	{
		DriveBase->TankDrive(LeftJoystick,RightJoystick,false);

	}

	void TestPeriodic()
	{
		lw->Run();
	}
};

START_ROBOT_CLASS(Robot)
