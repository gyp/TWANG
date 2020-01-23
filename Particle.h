#ifndef PARTICLE_H
#define PARTICLE_H

#define FRICTION 1

class Particle
{
  public:
    void Spawn(int pos);
    void Tick(bool USE_GRAVITY, int BEND_POINT);
    void Kill();
    bool Alive();
    int _pos;
    uint8_t _power;
  private:
    uint8_t _life;
    bool _alive;
    int8_t _sp;
};

#endif /* PARTICLE_H */
