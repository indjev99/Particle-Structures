#ifndef PARTICLE_TYPE_H_INCLUDED
#define PARTICLE_TYPE_H_INCLUDED

#include "color.h"

struct ParticleType
{
    ParticleType(int ID);
    int getID() const;
    double getMass() const;
    double  getRadius() const;
    const Color& getColor() const;
    void randomize();
private:
    int ID;
    double mass; // kg
    double radius; // m
    Color color;
};

#endif // PARTICLE_TYPE_H_INCLUDED
