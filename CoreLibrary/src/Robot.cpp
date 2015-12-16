#include "WPILib.h"
#include "CoreLib/CORERobot.h"
#include "CoreLib/CoreAuto.h"
#include "Actions/TestAction.h"
#include "Subsytems.h"

using namespace CORE;

class Robot: public SampleRobot
{
	CORERobot robot;
	AutoControl autoControl;
	LiftSubsystem lift;
	DriveSubsystem drive;

public:
	Robot() :
		robot(),
		autoControl(robot),
		lift(robot),
		drive(robot)
	{
		robot.add(lift);
		robot.add(drive);
	}





	void RobotInit() {
		robot.robotInit();
	}



	void Autonomous()
	{
//		TestAction test(robot,&conditions::testStart,&conditions::testEnd);
		TestAction test(robot);
		autoControl.add(test);
		autoControl.init();
		while (IsAutonomous() and !IsDisabled()) {
			autoControl.iter();
			Wait(robot.getLoopWait());
		}

	}


	void OperatorControl()
	{
		robot.teleopInit();
		while (IsOperatorControl() && IsEnabled())
		{
			robot.teleop();
			SmartDashboard::PutNumber("topLiftLim", robot.digitalSensorMap[digitalSensors::BOT_LIFT_LIMIT]->Get());
			SmartDashboard::PutNumber("botLiftLim", robot.digitalSensorMap[digitalSensors::TOP_LIFT_LIMIT]->Get());
			SmartDashboard::PutNumber("motorVal", robot.motorMap[motors::LIFT_MOTOR]->Get());
			SmartDashboard::PutNumber("joyval", robot.joystick.axis(controllerInputs::LIFT_AXIS));
			Wait(robot.getLoopWait());				// wait for a motor update time
		}
		robot.teleopEnd();
	}

	/**
	 * Runs during test mode
	 */
	void Test()
	{
	}
};

START_ROBOT_CLASS(Robot);
