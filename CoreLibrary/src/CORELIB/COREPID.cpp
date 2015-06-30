#include "COREPID.h"
#include "WPILIB.h"

using namespace CORE;
	void ManualPID::calculate(int profile) {
		if(profile == 1) {
			PID1.porportional = (PID.setPoint - PID.actualPosition) * PID1.P;
			PID1.mistake.insert(PID1.mistake.begin(), PID1.porportional);
			double sum = 0;
			for(int i = 1; i < (int) PID1.mistake.size(); i++) {
				sum += PID1.mistake[i];
			}
			double time = PID.timer.Get();
			PID1.integral += (sum * time) * PID1.I;
			PID1.derivative = ((PID1.mistake[0] - PID1.mistake[1]) / time) * PID1.D;
			PID.timer.Reset();
			PID1.output = PID1.porportional + PID1.integral + PID1.derivative;
		}
		else {
			PID2.porportional = (PID.setPoint - PID.actualPosition) * PID2.P;
			PID2.mistake.insert(PID2.mistake.begin(), PID2.porportional);
			double sum = 0;
			for(int i = 1; i < (int) PID2.mistake.size(); i++) {
				sum += PID2.mistake[i];
			}
			double time = PID.timer.Get();
			PID2.integral += (sum * time) * PID2.I;
			PID2.derivative = ((PID2.mistake[0] - PID2.mistake[1]) / time) * PID2.D;
			PID.timer.Reset();
			PID2.output = PID2.porportional + PID2.integral + PID2.derivative;
		}
	}
	void ManualPID::setPoint(double setPoint) {
		PID.setPoint = setPoint;
	}
	double ManualPID::getSetPoint() {
		return PID.setPoint;
	}
	double ManualPID::getP(int profile) {
		if(profile == 1)
			return PID1.P;
		else
			return PID2.P;
	}
	double ManualPID::getI(int profile) {
		if(profile == 1)
			return PID1.I;
		else
			return PID2.I;
	}
	double ManualPID::getD(int profile) {
		if(profile == 1)
			return PID1.D;
		else
			return PID2.D;
	}
	void ManualPID::setP(double value, int profile) {
		if(profile == 1)
			PID1.P = value;
		else
			PID2.P = value;
	}
	void ManualPID::setI(double value, int profile) {
		if(profile == 1)
			PID1.I = value;
		else
			PID2.I = value;
	}
	void ManualPID::setD(double value, int profile) {
		if(profile == 1)
			PID1.D = value;
		else
			PID2.D = value;
	}
	double ManualPID::getOutput(int profile) {
		if(profile == 1)
			return PID1.output;
		else
			return PID2.output;
	}
	double ManualPID::getPorportional(int profile) {
		if(profile == 1)
			return PID1.porportional;
		else
			return PID2.porportional;
	}
	double ManualPID::getIntegral(int profile) {
		if(profile == 1)
			return PID1.integral;
		else
			return PID2.integral;
	}
	double ManualPID::getDerivative(int profile) {
		if(profile == 1)
			return PID1.derivative;
		else
			return PID2.derivative;
	}
