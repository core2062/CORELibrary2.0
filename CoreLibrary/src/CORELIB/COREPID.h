#ifndef SRC_CORELIBRARY_COREPID_H_
#define SRC_CORELIBRARY_COREPID_H_
#include <vector>
#include "WPILIB.h"
#include "CORERobot.h"


namespace CORE {
class COREPID {
private:
	struct PIDProfile{
		double P,I,D,porportional,integral,derivative,output;
		std::vector<double> mistake;
	}PID1, PID2;
	struct {
		double setPoint,actualPosition;
		bool calculated,enabled = false;
		Timer timer;
	}PID;
public:
	COREPID(double pProfile1Value, double iProfile1Value, double dProfile1Value, double pProfile2Value = 0, double iProfile2Value = 0, double dProfile2Value = 0, int integralAccuracy = 1) {
		PID1.P = pProfile1Value;
		PID1.I = iProfile1Value;
		PID1.D = dProfile1Value;
		PID2.P = pProfile2Value;
		PID2.I = iProfile2Value;
		PID2.D = dProfile2Value;
		if(integralAccuracy < 1) {
			integralAccuracy = 1;
		}
		PID1.mistake.reserve(integralAccuracy);
		PID1.mistake[1] = 0;
		PID2.mistake.reserve(integralAccuracy);
		PID2.mistake[1] = 0;
		PID.timer.Reset();
		PID.timer.Start();
	}
	void calculate(int profile = 1);
	void setPoint(double setPoint);
	void setActualPosition(double actualPosition);
	double getSetPoint();
	double getP(int profile = 1);
	double getI(int profile = 1);
	double getD(int profile = 1);
	void setP(double value, int profile = 1);
	void setI(double value, int profile = 1);
	void setD(double value, int profile = 1);
	double getOutput(int profile = 1);
	double getPorportional(int profile = 1);
	double getIntegral(int profile = 1);
	double getDerivative(int profile = 1);
};
}
#endif
