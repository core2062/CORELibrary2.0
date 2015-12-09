/*
 * liftSubsystem.h
 *
 *  Created on: Dec 8, 2015
 *      Author: core
 */

#ifndef SRC_SUBSYSTEMS_LIFTSUBSYSTEM_H_
#define SRC_SUBSYSTEMS_LIFTSUBSYSTEM_H_

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
	{}

	void robotInit(void);
	void teleopInit(void);
	void teleop(void);





};



#endif /* SRC_SUBSYSTEMS_LIFTSUBSYSTEM_H_ */
