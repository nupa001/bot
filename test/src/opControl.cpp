#include "vex.h"
#include "opControl.h"
#include "autonFunctions.h"
using namespace vex;

int joystick() {
  while (true) {
    // Get the velocity percentage of the left motor. (Axis2 + Axis1)
    int leftMotorSpeed =
        Controller1.Axis2.position() + Controller1.Axis1.position();
    // Get the velocity percentage of the right motor. (Axis2 - Axis1)
    int rightMotorSpeed =
        Controller1.Axis2.position() - Controller1.Axis1.position();

    front_L.setVelocity(leftMotorSpeed, percent);
    back_L.setVelocity(leftMotorSpeed, percent);

    front_R.setVelocity(rightMotorSpeed, percent);
    back_R.setVelocity(rightMotorSpeed, percent);

    // Spin both motors in the forward direction.
    front_L.spin(forward);
    front_R.spin(forward);
    back_L.spin(forward);
    back_R.spin(forward);

    task::sleep(10);
  }
}

int intakeToggle() {
  intake.setVelocity(100, percent);
  while(true) {
    if(Controller1.ButtonR1.pressing()) {
      intake.spin(forward);
    }
    else if(Controller1.ButtonR2.pressing()) {
      intake.spin(reverse);
    }
    else {
      intake.stop(coast);
    }

    task::sleep(10);
  }
}

int liftToggle() {
  lift.setVelocity(100, percentUnits::pct);
  bool up = false;
  while(true) {
    if(Controller1.ButtonL1.pressing() && up == false) {
      lift.spin(forward);
      wait(1000, msec);
      up = true;
    }
    else if(Controller1.ButtonL1.pressing() && up == true){
      lift.spin(reverse);
      wait(1000, msec);
      up = false;
    }
    else{
      lift.stop(hold);
    }
    task::sleep(10);
  }
}