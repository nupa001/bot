#include "vex.h"
#include "autonFunctions.h"
using namespace vex;

void reset(){
  front_L.resetPosition();
  back_L.resetPosition();
  front_R.resetPosition();
  back_R.resetPosition();
}

void setVel(double velL, double velR){
  front_L.setVelocity(velL, percentUnits::pct);
  front_R.setVelocity(velR, percentUnits::pct);
  back_R.setVelocity(velR, percentUnits::pct);
  back_L.setVelocity(velL, percentUnits::pct);
}

void spinFwd(){
  front_L.spin(forward);
  back_L.spin(forward);
  front_R.spin(forward);
  back_R.spin(forward);
}

void deploy(){  
  front_L.spin(reverse, 75, percentUnits::pct);
  back_L.spin(reverse, 75, percentUnits::pct);
  front_R.spin(reverse, 75, percentUnits::pct);
  back_R.spin(reverse, 75, percentUnits::pct);

  wait(100, msec);
  
  front_L.spin(forward, 75, percentUnits::pct);
  back_L.spin(forward, 75, percentUnits::pct);
  front_R.spin(forward, 75, percentUnits::pct);
  back_R.spin(forward, 75, percentUnits::pct);

  wait(250, msec);

  front_L.stop(coast);
  back_L.stop(coast);
  front_R.stop(coast);
  back_R.stop(coast);

  task::sleep(10);
}

int intakeOn(){
  intake.spin(forward, 100, percentUnits::pct);
  return 1;
}

int intakeStop(){
  intake.stop(coast);
  return 1;
}

int outtakeOn(){
  intake.spin(reverse, 100, percentUnits::pct);
  return 1;
}

int liftUp() {
  lift.setVelocity(100, percentUnits::pct);
  lift.spin(forward);
  wait(1000, msec);
  return 1;
}

int liftDown() {
  lift.setVelocity(100, percentUnits::pct);
  lift.spin(reverse);
  wait(1000, msec);
  return 1;
}

void crawlForward(double distance, double vel){
  double circumference = 3.14159 * 4;
  double wheelRevs = distance / circumference;
  reset();

  setVel(vel,vel);

  front_L.rotateFor(fwd, wheelRevs, rotationUnits::rev, false);
  front_R.rotateFor(fwd, wheelRevs, rotationUnits::rev, false);
  back_R.rotateFor(fwd, wheelRevs, rotationUnits::rev, false);
  back_L.rotateFor(fwd, wheelRevs, rotationUnits::rev, true);

  front_L.stop(coast);
  front_R.stop(coast);
  back_R.stop(coast);
  back_L.stop(coast);
}

void turnLR(double degrees, double velocity){
  //right turns
  if(degrees > 0){
    while(imu.rotation(deg) < degrees-5) {
      setVel(velocity, -velocity);
      spinFwd();

    }
    front_L.stop(hold);
    front_R.stop(hold);
    back_L.stop(hold);
    back_R.stop(hold);
  }
  //left turns
  if(degrees < 0){
    while(imu.rotation(deg) > degrees+5) {
      setVel(-velocity, velocity);
      spinFwd();
    }
    front_L.stop(hold);
    front_R.stop(hold);
    back_L.stop(hold);
    back_R.stop(hold);
  }
}

int ticks(){
  while(true){
    double circumference = 3.14159 * 4;
    double distance = front_L.position(rotationUnits::rev) * circumference;

    // double pog = front_L.position(rotationUnits::raw);
    // double pogpog = front_L.position(rotationUnits::rev);
    // double pogpogpog = intake.position(rotationUnits::deg);
    printf("distance %f\n", distance);
    printf("deg %f\n", imu.rotation(deg));
    // printf("rev %f\n", pogpog);
    // printf("deg %f\n", pogpogpog);
    task::sleep(20);
  }
}