/*
 * TestAction.h
 *
 *  Created on: Jul 28, 2015
 *      Author: core
 */

#ifndef TESTACTION_H_
#define TESTACTION_H_

#include "CoreLib/COREAuto.h"

using namespace CORE;

class TestAction : public Action{

public:

	TestAction(CORERobot& robot, bool (*cond) (void), bool (*endCond) (void)):
		Action(robot, cond , endCond)
	{}


	void init(){}

	void autoCall(){}

	~TestAction(){

	}
};



#endif /* TESTACTION_H_ */
