#ifndef ENEMY_H
#define ENEMY_H

class Enemy {
    public:
        void Spawn(int pos, bool dir, uint8_t speed, uint16_t wobble);
        void Tick();
        void Kill();
        bool Alive();
        int _pos;
        uint16_t _wobble;
        uint8_t playerSide;
    private:
        bool _dir;
        uint8_t _speed;
        bool _alive;
        int _origin;
};

#endif /* ENEMY_H */