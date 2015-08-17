#ifndef SRC_CORELIB_COREHARDWARE_H_
#define SRC_CORELIB_COREHARDWARE_H_
#include "WPILIB.h"

namespace CORE {
enum runState {
	ROBOT,
	EMULATOR
};
runState currentRunState = EMULATOR;
class CORETalon {
private:
	float currentSpeed = 0;
public:
	CANTalon motor;
	CORETalon(int port):
	motor(port)
	{

	}
	void Set(float speed);
	float Get();
};
}
#endif
