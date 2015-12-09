#include "WPILib.h"
#include "CoreLib/CORERobot.h"
#include "CoreLib/CoreAuto.h"
#include "Actions/TestAction.h"
#include "Subsystems/Subsytems.h"

using namespace CORE;

class Robot: public SampleRobot
{
	CORERobot robot;
	AutoControl autoControl;

public:
	Robot() :
		robot(),
		autoControl(robot)
	{

	}





	void RobotInit() {
		robot.robotInit();
	}



	void Autonomous()
	{
//		TestAction test(robot,&conditions::testStart,&conditions::testEnd);
		TestAction test(robot);
		autoControl.add(test);

	}


	void OperatorControl()
	{
		robot.teleopInit();
		while (IsOperatorControl() && IsEnabled())
		{
			robot.teleop();
			Wait(0.005);				// wait for a motor update time
		}
	}

	/**
	 * Runs during test mode
	 */
	void Test()
	{
	}
};

START_ROBOT_CLASS(Robot);
