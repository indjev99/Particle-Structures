#ifndef PARTICLE_INTERACTION_H_INCLUDED
#define PARTICLE_INTERACTION_H_INCLUDED

#include "vec2d.h"

struct ParticleInteraction
{
    ParticleInteraction();
<<<<<<< HEAD
=======
    Vec2D eval(const Vec2D& dist) const;
>>>>>>> 66ade8357150f8989747cf9112c63a0008b1786b
    void randomize();

    Vec2D eval(const Vec2D& dist) const;

private:
    double eqDist, strength;  // m, N
    double lin, quad; // N * m, N * m^2
    void calcCoeffs();
};

#endif // PARTICLE_INTERACTION_H_INCLUDED
