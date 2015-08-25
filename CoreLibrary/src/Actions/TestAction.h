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

class TestAction : public ConditionAction{

public:

//	TestAction(CORERobot& robot, bool (*cond) (void), bool (*endCond) (void)):
//		Action(robot, cond , endCond)
//	{}
	virtual bool startCondition(){
		return false;
	}
	virtual bool endCondition(){
		return false;
	}
	TestAction(CORERobot& robot):
		ConditionAction(robot){
	};

	void init(){}
	void end(){}
	ControlFlow autoCall(){
		return CONTINUE;
	}

	~TestAction(){

	}
};



#endif /* TESTACTION_H_ */
