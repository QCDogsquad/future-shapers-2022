// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma GCC diagnostic ignored "-Wpedantic"

#include "main.h"

Robot::Robot() : 
LeftFlyWheel(LEFT_FLY_WHEEL_ID),
RightFlyWheel(RIGHT_FLY_WHEEL_ID),
FrontLeftDrive(FRONT_LEFT_DRIVE_PORT),
FrontRightDrive(FRONT_RIGHT_DRIVE_PORT),
RearLeftDrive(REAR_LEFT_DRIVE_PORT),
RearRightDrive(REAR_RIGHT_DRIVE_PORT),
MainJoystick(0),
MainCompressor(PneumaticsModuleType::CTREPCM),
Solenoid0(PneumaticsModuleType::CTREPCM, 0, 1),
Solenoid1(PneumaticsModuleType::CTREPCM, 2, 3),
Solenoid2(PneumaticsModuleType::CTREPCM, 4, 5),
Solenoid3(PneumaticsModuleType::CTREPCM, 6, 7)
{
 
}

void Robot::RobotInit() {
 LeftFlyWheel.SetInverted(true);
 RightFlyWheel.SetInverted(false);
 Solenoid0.Set(DoubleSolenoid::kForward);
 Solenoid1.Set(DoubleSolenoid::kForward);
 Solenoid2.Set(DoubleSolenoid::kForward);
 Solenoid3.Set(DoubleSolenoid::kForward);
}

void Robot::RobotPeriodic() {
}

void Robot::AutonomousInit() {}

void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit() {
}

void Robot::TeleopPeriodic() {
    if(MainJoystick.GetTriggerPressed()){
        Solenoid0.Toggle();
        Solenoid1.Toggle();
        Solenoid2.Toggle();
        Solenoid3.Toggle();
    }
}

void Robot::DisabledInit() {}

void Robot::DisabledPeriodic() {}

void Robot::TestInit() {}

void Robot::TestPeriodic() {}

void Robot::SimulationInit() {}

void Robot::SimulationPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() {
 return frc::StartRobot<Robot>();
}
#endif
