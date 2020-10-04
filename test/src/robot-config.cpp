#include "vex.h"

using namespace vex;

// A global instance of brain used for printing to the V5 brain screen
brain Brain;

//motors
motor front_L = motor(PORT3, ratio18_1, false);
motor front_R = motor(PORT9, ratio18_1, true);
motor back_R = motor(PORT10, ratio18_1, true);
motor back_L = motor(PORT2, ratio18_1, false);
motor intake = motor(PORT4, ratio6_1, true);
motor lift = motor(PORT8, ratio18_1, true);
inertial imu = inertial(PORT5);
controller Controller1 = controller(primary);

bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void) {
  // Nothing to initialize
}