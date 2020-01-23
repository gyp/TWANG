#ifndef SPAWNER_H
#define SPAWNER_H

/*
A spawn pool is a point which spawns enemies forever

position: 0 to 1000  (start position on the strip)
rate: milliseconds between spawns, 1000 = 1 second
speed: speed of the enemies it spawns
direction: 0=towards start, 1=away from start
*/
class Spawner {
    public:
        void Spawn(int pos, int rate, uint8_t speed, bool dir, long activate);
        void Kill();
        bool Alive();
        int _pos;
        int _rate;
        uint8_t _speed;
        bool _dir;
        long _lastSpawned;
        long _activate;
    private:
        bool _alive;
};

#endif /* SPAWNER_H */