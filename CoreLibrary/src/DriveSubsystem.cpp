#include "DriveSubsystem.h"
#include <iostream>


std::string DriveSubsystem::name(void){
	return "Drive";
}

void DriveSubsystem::robotInit(void){

	robot.outLog.appendLog("DriveSubsystem: RobotInit Success");
}
void DriveSubsystem::teleopInit(void){
	robot.outLog.appendLog("DriveSubsystem: TeleopInit Success");


	frontLeft.SetSafetyEnabled(true);
	backLeft.SetSafetyEnabled(true);
	frontRight.SetSafetyEnabled(true);
	backRight.SetSafetyEnabled(true);
	frontLeft.Set(0.0);
	backLeft.Set(0.0);
	frontRight.Set(0.0);
	backRight.Set(0.0);
	robot.joystick.register_axis(controllerInputs::DRIVE_X, 0, 0);
	robot.joystick.register_axis(controllerInputs::DRIVE_ROT, 0, 2);
	robot.joystick.register_axis(controllerInputs::DRIVE_Y, 0, 1);
	robot.joystick.register_button(controllerInputs::DRIVE_SPEED, 0, 5);




	//UltraSonic Values
//	feederStationChooser.AddDefault("Right Feeder Station", new std::string("right"));
//	feederStationChooser.AddObject("Left Feeder Station", new std::string("left"));
//	SmartDashboard::PutData("feederStation", &feederStationChooser);
}

void DriveSubsystem::teleop(void){

	shoulderSpeed = robot.joystick.button(controllerInputs::DRIVE_SPEED);
	SmartDashboard::PutNumber("drive x", drive_x);
	SmartDashboard::PutNumber("drive y", drive_y);
	SmartDashboard::PutNumber("drive rot", drive_rotation);		dPad = false;
//Simple Dead-banding
		drive_x = robot.joystick.axis(controllerInputs::DRIVE_X);
		if (drive_x < 0.05 && drive_x > -.05){
			drive_x = 0;
		}
		drive_y = robot.joystick.axis(controllerInputs::DRIVE_Y);
		if (drive_y < .05 && drive_y > -.05){
			drive_y = 0;
		}
		drive_y *= -1;
	drive_rotation = robot.joystick.axis(controllerInputs::DRIVE_ROT);
	if (drive_rotation < .05 && drive_rotation > -.05){
		drive_rotation = 0;
	}




			if(shoulderSpeed){
				frontLeft.Set(frontLeftInvert
						*(drive_x+drive_y+drive_rotation)
						*((mode == CANSpeedController::kVoltage)?12.0:1.0));
				frontRight.Set(frontRightInvert
						*(-drive_x+drive_y-drive_rotation)
						*((mode == CANSpeedController::kVoltage)?12.0:1.0));
				backLeft.Set(backLeftInvert
						*(-drive_x+drive_y+drive_rotation)
						*((mode == CANSpeedController::kVoltage)?12.0:1.0));
				backRight.Set(backRightInvert
						*(drive_x+drive_y-drive_rotation)
						*((mode == CANSpeedController::kVoltage)?12.0:1.0));
			}else{
				frontLeft.Set(frontLeftInvert
						*(drive_x+drive_y+drive_rotation)
						* SmartDashboard::GetNumber("JoystickMultiplier",.2)
						*((mode == CANSpeedController::kVoltage)?12.0:1.0));
				frontRight.Set(frontRightInvert
						*(-drive_x+drive_y-drive_rotation)
						*SmartDashboard::GetNumber("JoystickMultiplier",.2)
						*((mode == CANSpeedController::kVoltage)?12.0:1.0));
				backLeft.Set(backLeftInvert
						*(-drive_x+drive_y+drive_rotation)
						*SmartDashboard::GetNumber("JoystickMultiplier",.2)
						*((mode == CANSpeedController::kVoltage)?12.0:1.0));
				backRight.Set(backRightInvert
						*(drive_x+drive_y-drive_rotation)
						* SmartDashboard::GetNumber("JoystickMultiplier",.2)
						*((mode == CANSpeedController::kVoltage)?12.0:1.0));
			}



	}

void DriveSubsystem::teleopEnd(void){
	robot.outLog.appendLog("drive tele end");
	frontLeft.SetSafetyEnabled(false);
	frontRight.SetSafetyEnabled(false);
	backLeft.SetSafetyEnabled(false);
	backRight.SetSafetyEnabled(false);
	frontLeft.Set(0.0);
	frontRight.Set(0.0);
	backLeft.Set(0.0);
	backRight.Set(0.0);
}
