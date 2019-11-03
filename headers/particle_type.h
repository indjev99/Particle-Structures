#ifndef PARTICLE_TYPE_H_INCLUDED
#define PARTICLE_TYPE_H_INCLUDED

#include "color.h"

struct ParticleType
{
    double mass;
    Color color;
    ParticleType();
    int getID() const;
    void randomize();
private:
    int ID;
};

void resetIDs();

#endif // PARTICLE_TYPE_H_INCLUDED
