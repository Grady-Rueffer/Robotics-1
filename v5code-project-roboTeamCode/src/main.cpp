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

#include "cmath"
#include "vex.h"

// :^)
using namespace vex;

#pragma region bounceDetect

void bounceDetect() {
  bool bump = false;
  double speed = 0;
  int delay = 10;

  while (!bump) {
    delay--;
     Controller1.Screen.clearScreen();
    Controller1.Screen.setCursor(0, 0);
    Controller1.Screen.print(speed);
    Controller1.Screen.setCursor(3, 0);
    Controller1.Screen.print(delay);

    speed += Inertial1.acceleration(yaxis) * -1;

    RightMotor.setVelocity(40, percent);
    LeftMotor.setVelocity(40, percent);

    RightMotor.spin(forward);
    LeftMotor.spin(forward);

    //if (speed < 0.25 && delay  < 0) {
    //  bump = true;
    //}
  }

  RightMotor.setVelocity(0, percent);
  LeftMotor.setVelocity(0, percent);
}

#pragma endregion

#pragma region autoTurn

void autoTurn(bool rDir, int rotationDegrees) {
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
      } else if (speed > 50) {
        speed = 50;
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

#pragma endregion

#pragma region autoMode
void autoMode(bool rSide) {
  // uncurl

  if (rSide) {

    bounceDetect();
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
    // autoTurn so arm is over pole
    // dump the rings

    // autoTurn back
    // move forwards
    // pick up goal
    // move back until past line
    // rotate goal
    // put down

    // move to other goal
    // pickup
    // bring back

  } else {
    autoTurn(0, 90);
    // angle bot
    // dump rings
    // unangle bot
    // pick up goal
    // move onto goal
  }
}

#pragma endregion

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
    Controller1.Screen.setCursor(0, 0);
    Controller1.Screen.print(Inertial1.acceleration(yaxis));

    // how fast it move
#pragma region rcMovement
    rightSpeed = Controller1.Axis2.position(percent) * 0.5;
    leftSpeed = Controller1.Axis3.position(percent) * 0.5;
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
#pragma endregion

    if (Controller1.ButtonRight.pressing()) {

      // right side
      autoMode(1);
    } else if (Controller1.ButtonLeft.pressing()) {
      // left side auto
      autoMode(0);
    }
  }
}
