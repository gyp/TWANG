#ifndef CONVEYOR_H
#define CONVEYOR_H

class Conveyor {
    public:
        void Spawn(int startPoint, int endPoint, int speed);
        void Kill();
        int _startPoint;
        int _endPoint;
        int _speed;
        bool _alive;
};

#endif /* CONVEYOR_H */
