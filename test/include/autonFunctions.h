#ifndef AUTONFUNCTIONS_H
#define AUTONFUNCTIONS_H 

int ticks(void);

void deploy();

int intakeOn(void);

int intakeStop(void);

int outtakeOn(void);

void crawlForward(double distance, double velocity);

int liftUp(void);

int liftDown(void);

void spinFwd(void);

void turnLR(double degrees, double velocity);

#endif