
#ifndef COREAUTO_H
#define COREAUTO_H

#include <vector>
#include "CORERobot.h"

namespace CORE{


class Action{
	CORERobot& robot;
	bool (*condition)(void);
	bool active = false;


	bool firstTest(){
		return true;
	}

	void test(){
		if (condition()){
			active = true;
			init();
		}
	}


	public:
		Action(CORERobot& robot, bool (*cond) (void)):
			robot(robot){
			condition = cond;
		};
//		Action(CORERobot& robot, bool x):
//			robot(robot){
//			condition = firstTest;
//		};



	void call(){
		if (active){
			autoCall();
		}else{
			test();
		}
	}

	virtual void autoCall(void) = 0;
	virtual void init(void) = 0;
	~Action(void){

	};


};

class AutoControl{
	std::vector<Action*> actions;

public:
	AutoControl():
		actions(){};

	void iter (void);



};

}
#endif
