# SlowServo Library for Arduino
This library allows an Arduino board to control RC (hobby) servo motors at a slower rate than the standard library. Note that the servo may still twitch as it zeros starting up. The only way to avoid that would be to record the value in persistent memory before shutting down and set the position to that on start up.

## Setup

* Include the library
* Create a slowservo variable
* Attach the servo to a pin, ensure it supports PWM, see http://www.arduino.cc/en/Reference/Servo for more details.
* Set the initial speed, the default value is 10 degrees per second (Optional)

```
#include <SlowServo.h>
SlowServo testServo;

void setup() {

  testServo.attach(SERVO_PIN);
  testServo.speed(15);

  Serial.println("Servo Moving");
}
```

## Moving

* Set the position
* Call run repeatedly until it gets there

```
testServo.moveto(50);
  
  while (testServo.moving()) {
    testServo.run();
  }
```
