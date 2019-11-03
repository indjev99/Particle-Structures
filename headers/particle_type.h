#ifndef PARTICLE_TYPE_H_INCLUDED
#define PARTICLE_TYPE_H_INCLUDED

#include "color.h"

struct ParticleType
{
    static void resetIDs();
    double mass; // kg
    double radius; // m
    Color color;
    ParticleType();
    int getID() const;
    void randomize();
private:
    int ID;
};

#endif // PARTICLE_TYPE_H_INCLUDED
