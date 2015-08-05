/*
 * conditions.h
 *
 *  Created on: Aug 4, 2015
 *      Author: core
 */

#ifndef SRC_CONDITIONS_H_
#define SRC_CONDITIONS_H_

namespace CORE{

class conditions{

public:

	bool testStart(){
		return (1==1)?true:false;
	}

	bool testEnd(){
		return (1==0)?true:false;
	}



};






}


#endif /* SRC_CONDITIONS_H_ */
