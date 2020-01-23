#include <Arduino.h>

#include "Joystick.h"

ThreeButtonJoystick::ThreeButtonJoystick(int _leftPin, int _middlePin, int _rightPin, int _acceleration = 90) {
    leftPin = _leftPin;
    middlePin = _middlePin;
    rightPin = _rightPin;
    acceleration = _acceleration;

    pinMode(leftPin, INPUT);
    pinMode(middlePin, INPUT);
    pinMode(rightPin, INPUT);
}

void ThreeButtonJoystick::readInputs() {
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

void ThreeButtonJoystick::dummyInputLogic() {
      // stupid dummy logic to test it: if both or none pressed, make it zero,
      // otherwise just use the extremes -- remove when no longer needed
      angle = 0;
      if (isHigh(leftPin))
        angle -= 90;

      if (isHigh(rightPin))
        angle += 90;

      buttonPressed = isHigh(middlePin);
}
