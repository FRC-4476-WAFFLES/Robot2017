#include "Auto.h"
#include <DriverStation.h>
#include "Commands/Misc/WaitTime.h"
#include "Commands/Drive/DriveAuto.h"
#include "Commands/Shooter/ShooterPrepAuto.h"
#include "Commands/Shooter/ShootAutoUntil.h"
#include "Commands/Intake/ConveyorAuto.h"
#include "Commands/Turret/TurretCenterShot.h"
#include "Commands/Gear/GearCloseAuto.h"
#include "Commands/Gear/GearAuto.h"
#include "Commands/Gear/GearAutoUltrasonic.h"
#include "Commands/Turret/TurretVision.h"

Auto::Auto():
	// Default values for each number
	Auto(0, 0, 0) { }

Auto::Auto(int autonomousposition, int autonomousbackup, int autonomousultrasonic)
{
	// the idea is to use one command for any of the 20-30 possible auto modes using if statements
	//position
	//0 = nothing
	//1 = center
	//2 = right
	//3 = left
	//4 = drive forward
	//backup
	//1 = hopper
	//2 = part way
	//3 = no
	//ultrasonic
	//1 = yes
	//2 = no

	SetTimeout(15.0);
	AddSequential(new WaitTime(1.0));
	AddParallel(new GearCloseAuto());

	if(autonomousultrasonic == 2){

		if(autonomousposition == 0){
			AddSequential(new WaitTime(30.0));

		}else if(autonomousposition == 1){
			AddSequential(new DriveAuto(7.2, 0, 0.3));
			AddSequential(new GearAuto());

		}else if(autonomousposition == 2){//right
			if(DriverStation::GetInstance().GetAlliance() == DriverStation::Alliance::kBlue){
				//from gear delivery left red
				AddSequential(new DriveAuto(6.55, 0, 0.3));
				AddSequential(new DriveAuto(6.55, -60, 0.3));
				AddSequential(new DriveAuto(12.95, -60, 0.3));
				AddSequential(new GearAuto());
			}else if(DriverStation::GetInstance().GetAlliance() == DriverStation::Alliance::kRed){
				AddSequential(new DriveAuto(6.55, 0, 0.3));
				AddSequential(new DriveAuto(6.55, 60, 0.3));
				AddSequential(new DriveAuto(12.75, 60, 0.3));
				AddSequential(new GearAuto());
			}else{
				AddSequential(new WaitTime(30.0));
			}

		}else if(autonomousposition == 3){
			//from auto gear delivery left blue
			if(DriverStation::GetInstance().GetAlliance() == DriverStation::Alliance::kBlue){
				AddSequential(new DriveAuto(6.55, 0, 0.3));
				AddSequential(new DriveAuto(6.55, -60, 0.3));
				AddSequential(new DriveAuto(12.95, -60, 0.3));
				AddSequential(new GearAuto());
			}else if(DriverStation::GetInstance().GetAlliance() == DriverStation::Alliance::kRed){

				AddSequential(new DriveAuto(6.55, 0, 0.3));
				AddSequential(new DriveAuto(6.55, 60, 0.3));
				AddSequential(new DriveAuto(12.75, 60, 0.3));
				AddSequential(new GearAuto());
			}else{
				AddSequential(new WaitTime(30.0));
			}

		}else if(autonomousposition == 4){
			AddSequential(new DriveAuto(6, 0, 0.3));
			AddSequential(new WaitTime(1.0));
		}

	  if(autonomousposition != 0||autonomousposition != 4){
		if(autonomousbackup == 1){//hopper
			//TODO add code here
		}else if(autonomousbackup == 1){//part way
			if(autonomousposition == 2){
				AddSequential(new DriveAuto(8, -60, 0.3));
				AddParallel(new GearCloseAuto());
				AddSequential(new DriveAuto(8, -89, 0.3));
				AddSequential(new GearAuto());
			}else if(DriverStation::GetInstance().GetAlliance() == DriverStation::Alliance::kRed){
				AddSequential(new DriveAuto(8, 60, 0.3));
				AddParallel(new GearCloseAuto());
				AddSequential(new DriveAuto(8, -89, 0.3));
			}else{
				AddSequential(new WaitTime(30.0));
			}

			}else if(autonomousposition == 3){
				if(DriverStation::GetInstance().GetAlliance() == DriverStation::Alliance::kBlue){
					AddSequential(new DriveAuto(8, -60, 0.3));
					AddParallel(new GearCloseAuto());
					AddSequential(new DriveAuto(8, -89, 0.3));
				}else if(DriverStation::GetInstance().GetAlliance() == DriverStation::Alliance::kRed){

					AddSequential(new DriveAuto(8, 60, 0.3));
					AddParallel(new GearCloseAuto());
					AddSequential(new DriveAuto(8, -89, 0.3));
				}else{
					AddSequential(new WaitTime(30.0));
				}

			}else{
				AddSequential(new DriveAuto(5.2, 0, 0.8));
				AddSequential(new DriveAuto(2.5, 0, 0.3));
				AddParallel(new GearCloseAuto());
			}

	  }else{
		  AddSequential(new WaitTime(30.0));
	  }








	  //TODO add ultrasonic code here\|/

	}else{

		if(autonomousposition == 0){
			AddSequential(new WaitTime(30.0));

		}else if(autonomousposition == 1){
			AddSequential(new DriveAuto(7.2, 0, 0.3));
			AddSequential(new GearAutoUltrasonic());

		}else if(autonomousposition == 2){//right
			if(DriverStation::GetInstance().GetAlliance() == DriverStation::Alliance::kBlue){
				//from gear delivery left red
				AddSequential(new DriveAuto(6.55, 0, 0.3));
				AddSequential(new DriveAuto(6.55, -60, 0.3));
				AddSequential(new DriveAuto(12.95, -60, 0.3));
				AddSequential(new GearAutoUltrasonic());
			}else if(DriverStation::GetInstance().GetAlliance() == DriverStation::Alliance::kRed){
				AddSequential(new DriveAuto(6.55, 0, 0.3));
				AddSequential(new DriveAuto(6.55, 60, 0.3));
				AddSequential(new DriveAuto(12.75, 60, 0.3));
				AddSequential(new GearAutoUltrasonic());
			}else{
				AddSequential(new WaitTime(30.0));
			}

		}else if(autonomousposition == 3){
			//from auto gear delivery left blue
			if(DriverStation::GetInstance().GetAlliance() == DriverStation::Alliance::kBlue){
				AddSequential(new DriveAuto(6.55, 0, 0.3));
				AddSequential(new DriveAuto(6.55, -60, 0.3));
				AddSequential(new DriveAuto(12.95, -60, 0.3));
				AddSequential(new GearAutoUltrasonic());
			}else if(DriverStation::GetInstance().GetAlliance() == DriverStation::Alliance::kRed){

				AddSequential(new DriveAuto(6.55, 0, 0.3));
				AddSequential(new DriveAuto(6.55, 60, 0.3));
				AddSequential(new DriveAuto(12.75, 60, 0.3));
				AddSequential(new GearAutoUltrasonic());
			}else{
				AddSequential(new WaitTime(30.0));
			}

		}else if(autonomousposition == 4){
			AddSequential(new DriveAuto(6, 0, 0.3));
			AddSequential(new WaitTime(1.0));
		}

	  if(autonomousposition != 0||autonomousposition != 4){
		if(autonomousbackup == 1){//hopper
			//TODO add code here
		}else if(autonomousbackup == 1){//part way
			if(autonomousposition == 2){
				AddSequential(new DriveAuto(8, -60, 0.3));
				AddParallel(new GearCloseAuto());
				AddSequential(new DriveAuto(8, -89, 0.3));
				AddSequential(new GearAutoUltrasonic());
			}else if(DriverStation::GetInstance().GetAlliance() == DriverStation::Alliance::kRed){
				AddSequential(new DriveAuto(8, 60, 0.3));
				AddParallel(new GearCloseAuto());
				AddSequential(new DriveAuto(8, -89, 0.3));
			}else{
				AddSequential(new WaitTime(30.0));
			}

			}else if(autonomousposition == 3){
				if(DriverStation::GetInstance().GetAlliance() == DriverStation::Alliance::kBlue){
					AddSequential(new DriveAuto(8, -60, 0.3));
					AddParallel(new GearCloseAuto());
					AddSequential(new DriveAuto(8, -89, 0.3));
				}else if(DriverStation::GetInstance().GetAlliance() == DriverStation::Alliance::kRed){

					AddSequential(new DriveAuto(8, 60, 0.3));
					AddParallel(new GearCloseAuto());
					AddSequential(new DriveAuto(8, -89, 0.3));
				}else{
					AddSequential(new WaitTime(30.0));
				}

			}else{
				AddSequential(new DriveAuto(5.2, 0, 0.8));
				AddSequential(new DriveAuto(2.5, 0, 0.3));
				AddParallel(new GearCloseAuto());
			}

	  }else{
		  AddSequential(new WaitTime(30.0));
	  }
	}

}


