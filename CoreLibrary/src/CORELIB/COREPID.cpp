#include "COREPID.h"
#include "WPILIB.h"

using namespace CORE;
	void COREPID::calculate(int profile) {
		struct PIDProfile *currentProfile = profile == 1 ? &PID1 : &PID2;

	double COREPID::getSetPoint() {
		return PID.setPoint;
	}
	double COREPID::getP(int profile) {
		if(profile == 1)
			return PID1.P;
		else
			return PID2.P;
	}
	double COREPID::getI(int profile) {
		if(profile == 1)
			return PID1.I;
		else
			return PID2.I;
	}
	double COREPID::getD(int profile) {
		if(profile == 1)
			return PID1.D;
		else
			return PID2.D;
	}
	void COREPID::setP(double value, int profile) {
		if(profile == 1)
			PID1.P = value;
		else
			PID2.P = value;
	}
	void COREPID::setI(double value, int profile) {
		if(profile == 1)
			PID1.I = value;
		else
			PID2.I = value;
	}
	void COREPID::setD(double value, int profile) {
		if(profile == 1)
			PID1.D = value;
		else
			PID2.D = value;
	}
	double COREPID::getOutput(int profile) {
		if(profile == 1)
			return PID1.output;
		else
			return PID2.output;
	}
	double COREPID::getPorportional(int profile) {
		if(profile == 1)
			return PID1.porportional;
		else
			return PID2.porportional;
	}
	double COREPID::getIntegral(int profile) {
		if(profile == 1)
			return PID1.integral;
		else
			return PID2.integral;
	}
	double COREPID::getDerivative(int profile) {
		if(profile == 1)
			return PID1.derivative;
		else
			return PID2.derivative;
	}
