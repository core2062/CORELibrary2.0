
#ifndef COREAUTO_H
#define COREAUTO_H

#include <vector>
#include <string>
#include "CORERobot.h"
#include "conditions.h"


namespace CORE{


class ConditionAction{
	CORERobot& robot;
//	bool (conditions::*condition)(void);
//	bool (conditions::*endCondition)(void);
	bool active = false;
	virtual bool startCondition() = 0;
	virtual bool endCondition() = 0;

	bool firstTest(){
		return true;
	}

	void test(){
		if (startCondition()){
			active = true;
			init();
		}
	}

	void endTest(){
		if (endCondition()){
//			~Action();
		}
	}

	public:
		ConditionAction(CORERobot& robot):
			robot(robot){
		};
//		Action(CORERobot& robot, bool x):
//			robot(robot){
//			condition = firstTest;
//		};



	void call(){
		if (active){
			autoCall();
			endTest();
		}else{
			test();
		}
	}

	virtual void autoCall(void) = 0;
	virtual void init(void) = 0;
	virtual ~ConditionAction(void){

	};


};

class OrderAction{
	CORERobot& robot;
//	bool (conditions::*condition)(void);
//	bool (conditions::*endCondition)(void);
	bool active = false;

	bool firstTest(){
		return true;
	}





	public:
		OrderAction(CORERobot& robot):
			robot(robot){
		};
//		Action(CORERobot& robot, bool x):
//			robot(robot){
//			condition = firstTest;
//		};



	void call(){
		if (active){
			autoCall();
//			endTest();
		}else{
//			test();
		}
	}

	virtual void autoCall(void) = 0;
	virtual void init(void) = 0;
	virtual ~OrderAction(void){

	};


};


class AutoControl{
	std::vector<OrderAction*> actions;

public:
	AutoControl():
		actions(){};

	void iter (void);
	void add (OrderAction* a){
		actions.push_back(a);
	}


};

}
#endif
