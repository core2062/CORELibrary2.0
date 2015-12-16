
#include "CORERobot.h"

using namespace CORE;


void CORERobot::add(CORESubsystem& subsystem){
	subsystems.push_back(&subsystem);
}

std::vector<CORESubsystem*>& CORERobot::getSubsystems(void){
	return subsystems;
}

void CORERobot::robotInit(void){
	outLog.appendLog("---------Robot Init---------");
	std::vector<CORESubsystem*>::iterator it;
		for(it = subsystems.begin(); it != subsystems.end(); ++it){
//			cout << "robot init " << (*it)->name() << endl;
			(*it)->robotInit();
		}
	outLog.appendLog("\n\n\n\n\n");
	outLog.printLog();
	loopTimer.Reset();
	loopTimer.Start();
	loopStarted = true;
//	CD.updateSD();
}

void CORERobot::teleopInit(void){
	outLog.appendLog("--------- Teleop Init---------");
	outLog.startTime();
//	outLog.Mode = Log::TELE;
	std::vector<CORESubsystem*>::iterator it;
	for(it = subsystems.begin(); it != subsystems.end(); ++it){
//		cout << "tele init " << (*it)->name() << endl;
		(*it)->teleopInit();
	}
	outLog.appendLog("\n\n\n\n\n");
	outLog.printLog();
	loopTimer.Reset();
	loopTimer.Start();
	loopStarted = true;
//	CD.updateSD();
}

void CORERobot::teleop(){
	std::vector<CORESubsystem*>::iterator it;
	joystick.update_cache();
	for (it = subsystems.begin(); it != subsystems.end(); ++it){
//		cout << "teleop " << (*it)->name() << endl;
		(*it)->teleop();
	}
//	CD.updateSD();
}
void CORERobot::teleopEnd(){
	std::vector<CORESubsystem*>::iterator it;
	joystick.update_cache();
	for (it = subsystems.begin(); it != subsystems.end(); ++it){
//		cout << "teleop " << (*it)->name() << endl;
		(*it)->teleopEnd();
	}
	outLog.printLog();
	loopStarted = false;
//	CD.updateSD();
}

std::string CORESubsystem::name(void){
	return "undefined";
}

void CORESubsystem::robotInit(void){
	printf("Unimplemented robot_init\n");
}

void CORESubsystem::teleopInit(void){
	printf("Unimplemented teleop_init\n");
}

void CORESubsystem::teleop(){
	printf("Unimplemented teleop function\n");
}
void CORERobot::addMotor(motors motors,CANSpeedController* motor){
	motorMap[motors] = motor;
}
void CORERobot::addDigitalSensor(digitalSensors digitalSensors,DigitalInput* sensor){
	digitalSensorMap[digitalSensors] = sensor;
}
void CORERobot::addAnalogSensor(analogSensors analogSensors,AnalogInput* sensor){
	analogSensorMap[analogSensors] = sensor;
}
double CORERobot::getLoopWait(){
	if (!loopStarted){
		loopTimer.Reset();
		loopTimer.Start();
		loopStarted = true;
	}
	double loopTime = loopTimer.Get()<.1?0.1-loopTimer.Get():0.0;
	SmartDashboard::PutNumber("Timer", loopTimer.Get());
	if (loopTimer.Get() >= .12){
		outLog.appendLog("[PROBLEM] Loop Time High! Timer at: ",loopTimer.Get());
	}
	loopTimer.Reset();
	return loopTime;
}




