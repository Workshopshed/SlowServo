#include "SlowServo.h"
#include <Arduino.h>  //For Millis

SlowServo::SlowServo() {
  targetSpeed = 10;
  //??Do I need to call the constructor for "myServo" ?
}

uint8_t SlowServo::attach(int pin) {
  return myServo.attach(pin);
}

uint8_t SlowServo::attach(int pin, int min, int max) {
  return myServo.attach(pin, min, max);
}

void SlowServo::detach() {
  return myServo.detach();
}

void SlowServo::moveto(int degrees) {
  if (degrees > 200) return;
  lastRun = millis();
  targetPos = degrees;
}

void SlowServo::moveto(int degrees,float newSpeed) {
  moveto(degrees);
  speed(newSpeed);
}

void SlowServo::speed(float newSpeed) {
  if (newSpeed > 1000) return;
  targetSpeed = newSpeed;
}

int SlowServo::position() {
  return (int)pos;
}

bool SlowServo::moving() {
  return (pos != targetPos);
}

bool SlowServo::attached() {
  return myServo.attached();
}

void SlowServo::run() {
  if (!moving()) return;
  
  float targetDelay = 1000.0 / targetSpeed;     // How many milliseconds per degree
  if ((millis() - lastRun) < targetDelay)  return;
  
  int direction = ((targetPos-pos) > 0) - ((targetPos-pos) < 0);

  //Don't overshoot
  if (abs(targetPos - pos) < 1.0) { 
    pos = targetPos;
  }
  else {
    pos = pos + (1.0 * direction);
  }

  myServo.write(pos);
   
  //For Testing
  Serial.print(targetDelay);
  Serial.print("\t");
  Serial.print(direction);
  Serial.print("\t");
  Serial.println(pos);

  lastRun = millis();
}
