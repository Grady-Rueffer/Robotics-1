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
  if (Inertial7.acceleration(xaxis) < lastSpeed - decelBuffer) {
    return true;
  } else {
    return false;
  }
}

void turn(bool rDir, int rotationDegrees) {

  RightMotor.setVelocity(0, percent);
  LeftMotor.setVelocity(0, percent);

  if (rDir) {
    double rotationTotal = Inertial7.rotation(degrees) + rotationDegrees;

    while (Inertial7.rotation(degrees) < rotationTotal) {
    }
    double speed = rotationTotal - Inertial7.rotation(degrees);

    RightMotor.spin(reverse);
    LeftMotor.spin(forward);

    RightMotor.setVelocity(speed, percent);
    LeftMotor.setVelocity(speed, percent);
  }

  else {
    double rotationTotal = Inertial7.rotation(degrees) - rotationDegrees;
    while (Inertial7.rotation(degrees) > rotationTotal) {

double speed = (rotationTotal - Inertial7.rotation(degrees)) * -1;

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

    turn(1, 90);
    // move forward lil bit
    // rotate 45ish degrees right
    // move forward until hit goal (method TBD)
/*
    int lastSpeed = Inertial7.acceleration(xaxis);

    while (!bounceDetect(lastSpeed)) {
      RightMotor.setVelocity(50, percent);
      LeftMotor.setVelocity(50, percent);

      lastSpeed = Inertial7.acceleration(xaxis);
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

  while (rc) {
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
  }

  if (Controller1.ButtonRight.pressing()) {
    //right side
    autoMode(1);
  } else if (Controller1.ButtonLeft.pressing()) {
    //left side auto
    autoMode(0);
  }
}
