/*
 * TurretVision.cpp
 *
 *  Created on: Feb 19, 2017
 *      Author: WAFFLES
 */

#include "Commands/Turret/TurretVision.h"
#include "CommandBase.h"

TurretVision::TurretVision():
	CommandBase("TurretVision") {
	Requires(turret.get());
}

void TurretVision::Initialize()
{

}

void TurretVision::Execute()
{
	turret->AimVision();
}

bool TurretVision::IsFinished()
{
	return false;
}

void TurretVision::End()
{
}

void TurretVision::Interrupted()
{

}
