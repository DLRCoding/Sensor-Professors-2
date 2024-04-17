#include <Servo.h>

const int touchPin = 2;
const int ledPin = 13;

Servo servoMotor;
bool isTouched = false;
bool ledOn = false;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(touchPin, INPUT);
  servoMotor.attach(9);
  servoMotor.write(0); // sets the servo angle to start at 0 degrees
}

void loop() {
  if (digitalRead(touchPin) == HIGH) {
    if (!isTouched) {
      isTouched = true;
      if (!ledOn) {
        digitalWrite(ledPin, HIGH);
        ledOn = true;
      }
      servoMotor.write(180); // rotates the servo to 180 degrees when the circuit is completed
      delay(100);
    }
  } else {
    if (isTouched) {
      isTouched = false; // detects whenever the circuit is not touching to turn off the led and reset the servo to it's original position
      if (ledOn) {
        digitalWrite(ledPin, LOW);
        ledOn = false;
      }
      servoMotor.write(0);
      delay(100);
    }
  }
}
