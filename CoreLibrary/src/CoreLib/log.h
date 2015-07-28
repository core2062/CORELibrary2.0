
#ifndef LOG_H
#define LOG_H

#include "WPILib.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>

class Log{
	private:
		std::string fileName;
		std::string base = "/home/lvuser/logs/robotLog";
		std::ofstream outFile;
		std::vector<std::string> lines;
		double time;
		Timer timer;

	public:
		enum Mode{
			TELE = 0,
			Auto = 1
		};
		Mode mode;
		Log(){
			createFile();
			mode = TELE;
		}

		void createFile();
		void startTime();
		void appendLog(std::string s, double d);
		void appendLog(std::string s);
		void printLog();

};


#endif
