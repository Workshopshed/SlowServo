#include <SlowServo.h>

// Needs to be a PWM pin
#define SERVO_PIN 4

SlowServo testServo;

void setup() {

  testServo.attach(SERVO_PIN);
  testServo.speed(15);
  Serial.begin(9600);

  Serial.println("Servo Moving");
}

void loop() {

  testServo.moveto(50);
  
  while (testServo.moving()) {
    testServo.run();
  }

  Serial.println("Reversing");

  testServo.moveto(0);
  
  while (testServo.moving()) {
    testServo.run();
  }

  Serial.println("Reversing");
  
}
