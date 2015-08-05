
#ifndef COREAUTO_H
#define COREAUTO_H

#include <vector>
#include <string>
#include "CORERobot.h"
#include "conditions.h"


namespace CORE{


class Action{
	CORERobot& robot;
	bool (conditions::*condition)(void);
	bool (conditions::*endCondition)(void);
	bool active = false;


	bool firstTest(){
		return true;
	}

	void test(){
		if ((this->(*condition))()){
			active = true;
			init();
		}
	}

	void endTest(){
		if (conditions::*endCondition()){
//			~Action();
		}
	}

	public:
		Action(CORERobot& robot, bool (conditions::*cond) (void), bool (conditions::*endCond) (void)):
			robot(robot){
			condition = cond;
			endCondition = endCond;
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
	virtual ~Action(void){

	};


};

class AutoControl{
	std::vector<Action*> actions;

public:
	AutoControl():
		actions(){};

	void iter (void);
	void add (Action* a){
		actions.push_back(a);
	}


};

}
#endif
