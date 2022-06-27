#ifndef MAIN_H
#define MAIN_H

#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/TimedRobot.h>
#include <frc/motorcontrol/PWMSparkMax.h>
#include <frc/Joystick.h>
#include <frc/Compressor.h>
#include <frc/DoubleSolenoid.h>

using namespace frc;

#include <ctre/Phoenix.h>

#include "tyler_basics.h"

struct Robot : public frc::TimedRobot {
 
 TalonSRX LeftFlyWheel;
 TalonSRX RightFlyWheel;
 
 PWMSparkMax FrontLeftDrive;
 PWMSparkMax FrontRightDrive;
 PWMSparkMax RearLeftDrive;
 PWMSparkMax RearRightDrive;
 
 Joystick MainJoystick;
 
 Compressor MainCompressor;

 DoubleSolenoid Solenoid0;
 DoubleSolenoid Solenoid1;
 DoubleSolenoid Solenoid2;
 DoubleSolenoid Solenoid3;

 Robot();
 void RobotInit() override;
 void RobotPeriodic() override;
 void AutonomousInit() override;
 void AutonomousPeriodic() override;
 void TeleopInit() override;
 void TeleopPeriodic() override;
 void DisabledInit() override;
 void DisabledPeriodic() override;
 void TestInit() override;
 void TestPeriodic() override;
 void SimulationInit() override;
 void SimulationPeriodic() override;
};

#define rpm_to_ctre_mag_units(rpm) ((rpm)*(4096.0/600.0))
#define ctre_mag_units_to_rpm(units) ((units)/(4096.0/600.0))
#define rpm_to_hi_res_cimcoder_units(rpm) ((rpm)*(1024.0/600.0))
#define hi_res_cimcoder_units_to_rpm(units) ((units)/(1024.0/600.0))
#define square(value) ((value)*(value))

global_constant u32 LEFT_FLY_WHEEL_ID  = 3;
global_constant u32 RIGHT_FLY_WHEEL_ID = 4;

global_constant u32 FRONT_LEFT_DRIVE_PORT  = 1;
global_constant u32 FRONT_RIGHT_DRIVE_PORT = 2;
global_constant u32 REAR_LEFT_DRIVE_PORT   = 3;
global_constant u32 REAR_RIGHT_DRIVE_PORT  = 4;

global_constant u32 JOYSTICK_X_AXIS = 0;
global_constant u32 JOYSTICK_Y_AXIS = 1;
global_constant u32 JOYSTICK_Z_AXIS = 2;

#endif // MAIN_H