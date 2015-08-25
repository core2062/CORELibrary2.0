#include "COREAuto.h"

using namespace CORE;


void AutoControl::iter(){

	if(aqueue.empty() && !queueEmpty){
		robot.outLog.appendLog("Auto Queue Empty");
		queueEmpty = true;
	}

	Action* a = aqueue.front();

	ControlFlow returnVal = a->call(position);

	switch(returnVal){
	case CONTINUE:
		break;
	case BACKGROUND:
		robot.outLog.appendLog("Adding to Background:");
		robot.outLog.appendLog(a->name);
		background.push_back(a);
		/* no break */
	case END:
		position++;
		aqueue.pop();
		if(!aqueue.empty()){
			a = aqueue.front();
			robot.outLog.appendLog(a->name);
			a->init();
		}
		break;

	std::vector<Action*>::iterator it = background.begin();
	while(it != background.end()){
		ControlFlow return_val = (*it)->call(position);
		if (return_val == END){
			it = background.erase(it);
		}else{
			++it;
		}
	}

	}

	/*
	std::vector<OrderAction*>::iterator it = actions.begin();
	for(it = actions.begin(); it != actions.end(); ++it){
//		cout << "tele init " << (*it)->name() << endl;
		(*it)->call();
	}
	*/



}


