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
  servoMotor.write(0);
}

void loop() {
  if (digitalRead(touchPin) == HIGH) {
    if (!isTouched) {
      isTouched = true;
      if (!ledOn) {
        digitalWrite(ledPin, HIGH);
        ledOn = true;
      }
      servoMotor.write(180);
      delay(100);
    }
  } else {
    if (isTouched) {
      isTouched = false;
      if (ledOn) {
        digitalWrite(ledPin, LOW);
        ledOn = false;
      }
      servoMotor.write(0);
      delay(100);
    }
  }
}
