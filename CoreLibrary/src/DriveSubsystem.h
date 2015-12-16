#ifndef DRIVESUBSYSTEM_H
#define DRIVESUBSYSTEM_H

#include "CORELIB/CORERobot.h"
#include "WPILib.h"
#include <cmath>
#include <iostream>
#include <math.h>



#define PI 3.14159265

using namespace CORE;

const int frontLeftInvert = 1;
const int backLeftInvert = 1;
const int frontRightInvert = -1;
const int backRightInvert = -1;


class DriveSubsystem: public CORESubsystem{


	

	float drive_x = 0.0;
	float ultraVoltageScale = (1024.0 / 2.54); //403.1496
	float ultraValue = 0.0;
	float ultrasonicValue = 0.0;
	float drive_rotation = 0.0;
	float drive_y = 0.0;
	float drive_left_y = 0.0;
	float drive_right_y = 0.0;
	float centerDrivePower = 0.0;
	float frontLeftSet = 0.0;
	float frontRightSet = 0.0;
	float backLeftSet = 0.0;
	float backRightSet = 0.0;
	float initalUltraValue = 0.0;
	int oldFrontRight = 0;
	int oldFrontLeft = 0;
	int oldBackRight = 0;
	int oldBackLeft = 0;
	bool isTested = false;
	bool isBroken = true;
	bool switchEncoderMode = false;
	bool shoulderSpeed = false;
	bool oldRot = 0.0;
	int resetQ = 0;
	int POV = -1;
	bool leftPhotoVar = 0;
	bool middlePhotoVar = 0;
	bool rightPhotoVar = 0;
	bool tl = 0;
	bool tm = 0;
	bool tr = 0;
	bool alignError = 0;
	bool targetSeen = false;
	bool simple = true;
	bool oldCenterPhoto = false;
	int centerDirection = 1;
	bool oldCenterButton = true;
	bool rightFeederStation = true;
	bool modeSet = false;
	bool dPad = false;
	double alignPowerLeft = -.5;
	double alignPowerRight = .5;

	struct{
		double P = 0.0;
		double I = 0.0;
		double D = 0.0;
		double mistake;
		double actualPosition;
		double lastError;
		double integral = 0.0;
		double derivative;
		double setPoint = 0.0;
		bool enabled = false;
		double lastValue = 25.0;
		}gyroPID, leftUltraPID, rightUltraPID, feederAlignPID;

public:
		CANSpeedController::ControlMode mode = CANSpeedController::kPercentVbus;
//		CANSpeedController::ControlMode mode = CANSpeedController::kVoltage;

		// Drive Motors
		CANTalon frontLeft;
		CANTalon backLeft;
		CANTalon frontRight;
		CANTalon backRight;

	std::string name(void);
	DriveSubsystem(CORERobot& robot):
		CORESubsystem(robot),
		frontLeft(13),
		backLeft(12),
		frontRight(10),
		backRight(11)

		{
			//start false to avoid error
			frontLeft.SetSafetyEnabled(false);
			frontRight.SetSafetyEnabled(false);
			backLeft.SetSafetyEnabled(false);
			backRight.SetSafetyEnabled(false);
			frontLeft.Set(0.0);
			frontRight.Set(0.0);
			backLeft.Set(0.0);
			backRight.Set(0.0);
		}

	void robotInit(void);
	void teleopInit(void);
	void teleop(void);

void teleopEnd(void);
};








#endif

