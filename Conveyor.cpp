#include <Arduino.h>

#include "Conveyor.h"

void Conveyor::Spawn(int startPoint, int endPoint, int speed){
    _startPoint = startPoint;
    _endPoint = endPoint;
    _speed = speed;  // must be less than +/- max player speed
    _alive = true;
}

void Conveyor::Kill(){
    _alive = false;
}
