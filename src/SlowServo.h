#include <Servo.h>

#ifndef SlowServo_h
#define SlowServo_h

class SlowServo
{
public:
  SlowServo();
  uint8_t attach(int pin);           // attach the given pin to the next free channel, sets pinMode, returns channel number or 0 if failure
  uint8_t attach(int pin, int min, int max); // as above but also sets min and max values for writes. 
  void detach();
  void moveto(int degrees);             // if value is < 200 it is treated as an angle, otherwise it does nothing
  void moveto(int degrees,float newSpeed);   // as above but also sets the speed
  void speed(float newSpeed);            // the speed of movement in degrees per second 
  int position();                     // returns current position as an angle between 0 and 180 degrees
  bool moving();                      // returns flag reporting that the servo is on it's way to the desired position
  bool attached();                    // return true if this servo is attached, otherwise false 
  void run();                         // move if needed
private:
   Servo myServo;                     // the wraped servo
   int pos;                           // current position
   int targetPos;                     // desired position
   float targetSpeed;                 // desired speed
   unsigned long lastRun;              // used for calcuating speed
}; 

#endif
