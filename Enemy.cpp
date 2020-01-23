#include <Arduino.h>

#include <stdint.h> // uint8_t type variables

#include "Enemy.h"

void Enemy::Spawn(int pos, bool dir, uint8_t speed, uint16_t wobble) {
    _pos = pos;
    _dir = dir;          // 0 = left, 1 = right
    _wobble = wobble;    // 0 = no, >0 = yes, value is width of wobble
    _origin = pos;
    _speed = speed;
    _alive = 1;
}

void Enemy::Tick() {
    if (_alive) {
        if (_wobble > 0) {
            _pos = _origin + (sin((millis() / 3000.0) * _speed) * _wobble);
        } else {
            if (_dir == 0) {
                _pos -= _speed;
            } else {
                _pos += _speed;
            }
            if (_pos > 1000) {
                Kill();
            }
            if (_pos <= 0) {
                Kill();
            }
        }
    }
}

bool Enemy::Alive() {
    return _alive;
}

void Enemy::Kill() {
    _alive = 0;
}
