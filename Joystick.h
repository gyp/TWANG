#ifndef JOYSTICK_H
#define JOYSTICK_H

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
class ThreeButtonJoystick {
    public:
        int angle;
        bool buttonPressed;

        ThreeButtonJoystick(int _leftPin, int _middlePin, int _rightPin, int _acceleration = 90);
        void readInputs();

    private:
        int leftPin, middlePin, rightPin, acceleration;
        unsigned long int directionStarted = 0;
        float preciseAngle = 0.0;

        void dummyInputLogic();
};

#endif /* JOYSTICK_H */
