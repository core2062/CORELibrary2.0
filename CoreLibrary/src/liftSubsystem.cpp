/*
 * liftSubsystem.cpp
 *
 *  Created on: Dec 8, 2015
 *      Author: core
 */
#include "liftSubsystem.h"


	void LiftSubsystem::robotInit(void){
		robot.outLog.appendLog("Lift Robot Init");
	}
	void LiftSubsystem::teleopInit(void){
		liftMotor.SetSafetyEnabled(true);
		liftMotor.Set(0);
		liftMotor.SetExpiration(0.25);
		robot.outLog.appendLog("LiftSubsystem: TeleopInit Success");
		robot.joystick.register_axis(controllerInputs::LIFT_AXIS, 1, 1);
	}
	void LiftSubsystem::teleop(void){

		double liftValue = robot.joystick.axis(controllerInputs::LIFT_AXIS);

		if (!bottomLimit.Get()){
			bottomLatch = true;
		}
		if (!topLimit.Get()){
			topLatch = true;
		}
		if (liftValue < 0.1 && liftValue > -.1){
			liftValue = 0;
		}


		if (liftValue < 0.0 && topLatch == false){

			bottomLatch = false;
			liftMotor.Set(-liftValue);

		}else if (liftValue > 0.0 && bottomLatch == false){
			topLatch = false;
			liftMotor.Set(-liftValue);
		}else{
			liftMotor.Set(0.0);
		}

	}






