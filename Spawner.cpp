#include <Arduino.h>

#include <stdint.h> // uint8_t type variables

#include "Spawner.h"

void Spawner::Spawn(int pos, int rate, uint8_t speed, bool dir, long activate) {
    _pos = pos;
    _rate = rate;
    _speed = speed;
    _dir = dir;
    _activate = millis()+activate;
    _alive = 1;
}

void Spawner::Kill() {
    _alive = 0;
    _lastSpawned = 0;
}

bool Spawner::Alive() {
    return _alive;
}
