
#ifndef COREAUTO_H
#define COREAUTO_H

#include <vector>
#include <string>
#include <queue>
#include "CORERobot.h"
#include "conditions.h"


namespace CORE{

enum ControlFlow{
	CONTINUE,
	END,
	BACKGROUND
};



class Action{
	bool active = false;



	bool firstTest(){
		return true;
	}


	public:

	std::string name = "Base";

	Action(){};



	virtual bool startCondition() = 0;
	virtual bool backgroundCondition(){
		return false;
	}
	virtual bool endCondition(){
		return false;
	}



	virtual ControlFlow call() = 0;

	virtual ControlFlow autoCall(void){
		return END;
	};
	virtual void init(void) = 0;
	virtual ~Action(void){

	};
};



class ConditionAction : public Action{
	CORERobot& robot;
//	bool (conditions::*condition)(void);
//	bool (conditions::*endCondition)(void);
	bool active = false;


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



	ControlFlow call(){
		if (active){
			autoCall();
			endTest();
		}else{
			test();
		}
		return END;
	}

	virtual ControlFlow autoCall(void) = 0;
	virtual void init(void) = 0;
	virtual ~ConditionAction(void){

	};


};

class OrderAction : public Action{
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



	ControlFlow call(){
		ControlFlow f = autoCall();
		if (f!=CONTINUE){
			return f;
		}else{
			if (backgroundCondition()){
				return BACKGROUND;
			}else if (endCondition()){
				return END;
			}else{
				return CONTINUE;
			}
		}
	}

//	virtual ControlFlow autoCall(void) = 0;
	virtual void init(void) = 0;
	virtual ~OrderAction(void){

	};


};


class AutoControl{
	CORERobot& robot;
	std::queue<OrderAction*> aqueue;
	std::vector<Action*> background;
	bool queueEmpty = false;
public:
	AutoControl(CORERobot& robot):
		robot(robot),
		aqueue(),
		background()
		{};

	void iter (void);
	void init(void){
		aqueue.front()->init();
	}
	void add (OrderAction& a){
		aqueue.push(&a);
	}
	void add (OrderAction* a){
		aqueue.push(a);
	}
	void add (ConditionAction& a){
		background.push_back(&a);
	}
	void add (ConditionAction* a){
		background.push_back(a);
	}

};

}
#endif
