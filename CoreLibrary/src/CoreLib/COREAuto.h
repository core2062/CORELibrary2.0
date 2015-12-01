
#ifndef COREAUTO_H
#define COREAUTO_H

#include <vector>
#include <string>
#include <queue>
#include "CORERobot.h"

namespace CORE{

enum ControlFlow{
	CONTINUE,
	END,
	BACKGROUND
};



class Action{
	bool active = false;

	public:

	std::string name = "Base";

	Action(){};

	virtual bool startCondition(int pos = -1){
		return false;
	}
	virtual bool backgroundCondition(int pos = -1){
		return false;
	}
	virtual bool endCondition(int pos = -1){
		return false;
	}



	virtual ControlFlow call(int pos = -1) = 0;

	virtual ControlFlow autoCall(void){
		return END;
	};
	virtual void init(void) = 0;
	virtual void end(void) = 0;
	virtual ~Action(void){

	};
};



class ConditionAction : public Action{
	CORERobot& robot;
//	bool (conditions::*condition)(void);
//	bool (conditions::*endCondition)(void);
	bool active = false;

	public:
		ConditionAction(CORERobot& robot):
			robot(robot){
		};
//		Action(CORERobot& robot, bool x):
//			robot(robot){
//			condition = firstTest;
//		};



	ControlFlow call( int pos = -1){
		if (startCondition(pos) && !active){
			active = true;
			init();
		}
		if (active){
			ControlFlow f = autoCall();
			if (f!=CONTINUE){
				if (f == END){
					active = false;
					end();
				}
				return f;
			}else{
				if (endCondition(pos)){
					active = false;
					end();
					return END;
				}else{
					return CONTINUE;
				}
			}
		}else{
		}
		return END;
	}

	virtual ControlFlow autoCall(void) = 0;
	virtual void init(void) = 0;
	virtual void end(void) = 0;
	virtual ~ConditionAction(void){

	};


};

class OrderAction : public Action{
	CORERobot& robot;
//	bool (conditions::*condition)(void);
//	bool (conditions::*endCondition)(void);
	bool active = false;

	public:
		OrderAction(CORERobot& robot):
			robot(robot){
		};
//		Action(CORERobot& robot, bool x):
//			robot(robot){
//			condition = firstTest;
//		};



	ControlFlow call(int pos = -1){
		ControlFlow f = autoCall();
		if (f!=CONTINUE){
			if (f == END){
				end();
			}
			return f;
		}else{
			if (endCondition(pos)){
				end();
				return END;
			}else if (backgroundCondition(pos)){
				return BACKGROUND;
			}else{
				return CONTINUE;
			}
		}
	}

//	virtual ControlFlow autoCall(void) = 0;
	virtual void init(void) = 0;
	virtual void end(void) = 0;
	virtual ~OrderAction(void){

	};


};


class AutoControl{
	CORERobot& robot;
	std::queue<OrderAction*> aqueue;
	std::vector<Action*> background;
	bool queueEmpty = false;
	int position = 1;
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
