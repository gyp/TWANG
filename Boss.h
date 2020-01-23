#ifndef BOSS_H
#define BOSS_H

class Boss {
    public:
        void Spawn();
        void Hit();
        void Kill();
        bool Alive();
        int _pos;
        uint8_t _lives;
        int _ticks;
    private:
        bool _alive;
};

#endif /* BOSS_H */
