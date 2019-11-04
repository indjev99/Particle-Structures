#ifndef PARTICLE_INTERACTION_H_INCLUDED
#define PARTICLE_INTERACTION_H_INCLUDED

#include "vec2d.h"

struct ParticleInteraction
{
    ParticleInteraction();
    Vec2D eval(const Vec2D& dist) const;
    void randomize();
private:
    double eqDist, strength;  // m, N
    double lin, quad; // N * m, N * m^2
    void calcCoeffs();
};

#endif // PARTICLE_INTERACTION_H_INCLUDED
