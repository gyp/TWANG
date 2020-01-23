#include <Arduino.h>

#include <stdint.h> // uint8_t type variables

#include "Boss.h"

void Boss::Spawn() {
    _pos = 800;
    _lives = 3;
    _alive = 1;
}

void Boss::Hit() {
    _lives --;
    if (_lives == 0) {
        Kill();
        return;
    }
    if (_lives == 2) {
        _pos = 200;
    } else if(_lives == 1) {
        _pos = 600;
    }
}

bool Boss::Alive() {
    return _alive;
}

void Boss::Kill() {
    _alive = 0;
}
