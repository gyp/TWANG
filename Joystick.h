#include <Arduino.h>

#define isHigh(pin) (digitalRead(pin) == HIGH)

/**
 * Simple simulation of an 1-button analog joystick with buttons that tries to be
 * more clever than just simply assigning the extremes when the buttons are
 * pressed.
 *
 * Initialize with the pin numbers, call readInputs() as frequently as possible
 * and read the current status through the public attributes angle and buttonPressed.
 *
 * It is absolutely not thread-safe.
 *
 * FIXME: this is dummy at this point and just goes to the extremes
 */
class ThreeButtonJoystick
{
  public:
    ThreeButtonJoystick(int _leftPin, int _middlePin, int _rightPin, int _acceleration = 90) {
      leftPin = _leftPin;
      middlePin = _middlePin;
      rightPin = _rightPin;
      acceleration = _acceleration;

      pinMode(leftPin, INPUT);
      pinMode(middlePin, INPUT);
      pinMode(rightPin, INPUT);
    }

    void readInputs() {
        // dummyInputLogic();
        // return;

        buttonPressed = isHigh(middlePin);

        bool leftPressed = isHigh(leftPin);
        bool rightPressed = isHigh(rightPin);

        if ((!leftPressed && !rightPressed) || (leftPressed && rightPressed)) {
          // if all buttons are pushed or released at the same time, stop immediately
          preciseAngle = 0.0;
          angle = 0;
          return;
        }

        unsigned long int now = millis();

        if (abs(preciseAngle) < 0.0001) {
          directionStarted = now;
          preciseAngle = (rightPressed ? 0.001 : -0.001);
        } else {
          // simple linear acceleration until +/- 90 degrees
          preciseAngle = (rightPressed ? 1.0 : -1.0) * acceleration/1000.0 * (now - directionStarted);
          preciseAngle = constrain(preciseAngle, -90, 90);

          #ifdef DEBUG
          Serial.print("angle: ");
          Serial.print(angle);
          Serial.print("floatangle: ");
          Serial.print(preciseAngle);
          Serial.print("\t timeDiff: ");
          Serial.println( (now-directionStarted) );
          #endif

          angle = (int) preciseAngle;
        }

    }

    int angle;
    bool buttonPressed;

  private:
    int leftPin, middlePin, rightPin, acceleration;
    unsigned long int directionStarted = 0;
    float preciseAngle = 0.0;

    void dummyInputLogic() {
      // stupid dummy logic to test it: if both or none pressed, make it zero,
      // otherwise just use the extremes -- remove when no longer needed
      angle = 0;
      if (isHigh(leftPin))
        angle -= 90;

      if (isHigh(rightPin))
        angle += 90;

      buttonPressed = isHigh(middlePin);
    }
};