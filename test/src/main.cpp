#include "vex.h"
#include "opControl.h"
#include "autonFunctions.h"
using namespace vex;

// A global instance of competition
competition Competition;

//pre_auton
void pre_auton(void) {
  vexcodeInit();
}

//autonomous
void autonomous(void) {
  imu.calibrate();
  while(imu.isCalibrating()) {
    wait(100, msec);
  }
  deploy();
  intakeOn();
  wait(1000, msec);
  task d = task(ticks);
  crawlForward(10, 25);
  turnLR(90, 25);
  wait(500, msec);
  turnLR(-90, 25);
  intakeStop();
  liftUp();
  outtakeOn();
  liftDown();
}

//usercontrol
void usercontrol(void) {
  front_L.stop(coast);
  front_R.stop(coast);
  back_L.stop(coast);
  back_R.stop(coast);
  
  task a = task(joystick);
  task b = task(intakeToggle);
  task c = task(liftToggle);
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
