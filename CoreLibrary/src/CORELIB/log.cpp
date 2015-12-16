#include "log.h"

void Log::createFile(){
//	std::string last = (new std::string(base))->append("10.txt");
	std::string last = base + "10.txt";
	std::string current;
	remove(last.c_str());
	for (int i = 9; i > 0; i--){
//		current = (new std::string(base))->append(std::to_string(i)+".txt");
		current = base + std::to_string(i)+".txt";
		rename (current.c_str(), last.c_str());
		last = current;
	}
	outFile.open(last.c_str());
	if(!outFile){
		std::cout << "ERROR: log file not created at " << last << std::endl;
	}
	outFile << "Log File Created" << std::endl;

}

void Log::appendLog(std::string s){
	time = timer.Get();
	time = (mode == TELE)?(time+15):(time);
	lines.push_back("["+std::to_string(time)+"] " + s);
}
void Log::appendLog(std::string s, double d){
	time = timer.Get();
	time = (mode == TELE)?(time+15):(time);
	lines.push_back("["+std::to_string(time)+"] " + s + std::to_string(d));
}

void Log::startTime(){
	timer.Reset();
	timer.Start();
}

void Log::printLog(){
	std::vector<std::string>::iterator it;
	for (it = lines.begin(); it != lines.end(); ++it){
		outFile << (*it).c_str() << std::endl;
	}
	lines.clear();
}


