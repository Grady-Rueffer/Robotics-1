// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// RightMotor           motor         11              
// LeftMotor            motor         20              
// Inertial1            inertial      1               
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// RightMotor           motor         11              
// LeftMotor            motor         20              
// Inertial1            inertial      7               
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// RightMotor           motor         11              
// LeftMotor            motor         10              
// Inertial1            inertial      7               
// ---- END VEXCODE CONFIGURED DEVICES ----
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\Parker                                           */
/*    Created:      Tue Nov 09 2021                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller
// RightMotor           motor         1
// LeftMotor            motor         10
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "cmath"
// :^)
using namespace vex;

bool bounceDetect(float lastSpeed) {
  int decelBuffer = 50;
  if (Inertial1.acceleration(xaxis) < lastSpeed - decelBuffer) {
    return true;
  } else {
    return false;
  }
}

void turn(bool rDir, int rotationDegrees) {
double Kp = 0.5;
  RightMotor.setVelocity(0, percent);
  LeftMotor.setVelocity(0, percent);

  if (rDir) {
    double rotationTotal = Inertial1.rotation(degrees) + rotationDegrees;

    while (Inertial1.rotation(degrees) < rotationTotal) {
  

    double error = rotationTotal - Inertial1.rotation(degrees);
double speed = error * Kp;
if (speed < 10) {
  speed = 10;
}

    RightMotor.spin(reverse);
    LeftMotor.spin(forward);

    RightMotor.setVelocity(speed, percent);
    LeftMotor.setVelocity(speed, percent);
    }
  }

  else {
    double rotationTotal = Inertial1.rotation(degrees) - rotationDegrees;
    while (Inertial1.rotation(degrees) > rotationTotal) {

double error = (rotationTotal - Inertial1.rotation(degrees)) * -1;
double speed = error * Kp;
if (speed < 10) {
  speed = 10;
}
      RightMotor.spin(forward);
      LeftMotor.spin(reverse);

      RightMotor.setVelocity(speed, percent);
      LeftMotor.setVelocity(speed, percent);
    }
  }
  RightMotor.setVelocity(0, percent);
  LeftMotor.setVelocity(0, percent);
}

void autoMode(bool rSide) {
  // uncurl

  if (rSide) {
Controller1.Screen.clearScreen();
Controller1.Screen.print("Good");
    turn(1, 180);
    // move forward lil bit
    // rotate 45ish degrees right
    // move forward until hit goal (method TBD)
/*
    int lastSpeed = Inertial1.acceleration(xaxis);

    while (!bounceDetect(lastSpeed)) {
      RightMotor.setVelocity(50, percent);
      LeftMotor.setVelocity(50, percent);

      lastSpeed = Inertial1.acceleration(xaxis);
    }
*/
    // move back small amount
    // turn so arm is over pole
    // dump the rings

    // turn back
    // move forwards
    // pick up goal
    // move back until past line
    // rotate goal
    // put down

    // move to other goal
    // pickup
    // bring back

  } else {
    turn(0, 90);
    // angle bot
    // dump rings
    // unangle bot
    // pick up goal
    // move onto goal
  }
}

bool rc = true;
int deadBand = 5;
int rightSpeed;
int leftSpeed;

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  Inertial1.calibrate();

  while (rc) {
    Controller1.Screen.clearScreen();
    Controller1.Screen.setCursor(0,0);
  Controller1.Screen.print(Inertial1.rotation(degrees));

    // how fast it move
    
    rightSpeed = Controller1.Axis2.position(percent);
    leftSpeed = Controller1.Axis3.position(percent);
    // antistick-drift
    if (abs(rightSpeed) < deadBand) {
      RightMotor.setVelocity(0, percent);

    } else {
      RightMotor.setVelocity(rightSpeed, percent);
    }

    if (abs(leftSpeed) < deadBand) {
      LeftMotor.setVelocity(0, percent);

    } else {
      LeftMotor.setVelocity(leftSpeed, percent);
    }
    RightMotor.spin(forward);
    LeftMotor.spin(forward);

    if (Controller1.ButtonRight.pressing()) {
      
    //right side
    autoMode(1);
  } else if (Controller1.ButtonLeft.pressing()) {
    //left side auto
    autoMode(0);
  }
  }

  
}
