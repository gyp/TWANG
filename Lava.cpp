#include <Arduino.h>

#include "Lava.h"

void Lava::Spawn(int left, int right, int ontime, int offtime, int offset, bool state) {
    _left = left;
    _right = right;
    _ontime = ontime;
    _offtime = offtime;
    _offset = offset;
    _alive = 1;
    _lastOn = millis()-offset;
    _state = state;
}

void Lava::Kill() {
    _alive = 0;
}

bool Lava::Alive() {
    return _alive;
}
