#include "COREHardware.h"
#include "WPILIB.h"

using namespace CORE;

void CORETalon::Set(float speed) {
	if(currentRunState == ROBOT) {
		motor.Set(speed);
	}
	currentSpeed = speed;
}
float CORETalon::Get() {
	return currentSpeed;
}
