/*
 * liftSubsystem.h
 *
 *  Created on: Dec 8, 2015
 *      Author: core
 */

#ifndef SRC_SUBSYSTEMS_LIFTSUBSYSTEM_H_
#define SRC_SUBSYSTEMS_LIFTSUBSYSTEM_H_

#include "CORELIB/CORERobot.h"
#include "WPILib.h"
#include <string>

using namespace CORE;

class LiftSubsystem : public CORESubsystem {
public:
	DigitalInput bottomLimit;
	DigitalInput topLimit;
	CANTalon liftMotor;




	bool bottomLatch = false;
	bool topLatch = true;

	LiftSubsystem(CORERobot& robot):
		CORESubsystem(robot),
		bottomLimit(0),
		topLimit(1),
		liftMotor(14)
	{
		robot.motorMap.insert(std::pair<motors,CANSpeedController*>(motors::LIFT_MOTOR,&liftMotor));
		robot.digitalSensorMap.insert(std::pair<digitalSensors,DigitalInput*>(digitalSensors::BOT_LIFT_LIMIT,&bottomLimit));
		robot.digitalSensorMap.insert(std::pair<digitalSensors,DigitalInput*>(digitalSensors::TOP_LIFT_LIMIT,&topLimit));

	}

	void robotInit(void);
	void teleopInit(void);
	void teleop(void);
	std::string name(){return "Lift";}





};



#endif /* SRC_SUBSYSTEMS_LIFTSUBSYSTEM_H_ */
