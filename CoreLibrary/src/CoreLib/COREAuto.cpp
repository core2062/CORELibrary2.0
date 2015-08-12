#include "COREAuto.h"

using namespace CORE;


void AutoControl::iter(){
	std::vector<OrderAction*>::iterator it = actions.begin();
	for(it = actions.begin(); it != actions.end(); ++it){
//		cout << "tele init " << (*it)->name() << endl;
		(*it)->call();
	}
}


