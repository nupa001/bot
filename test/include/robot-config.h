using namespace vex;

extern brain Brain;

extern motor front_L;
extern motor back_L;
extern motor front_R;
extern motor back_R;
extern motor intake;
extern motor lift;
extern inertial imu;
extern controller Controller1;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void);
