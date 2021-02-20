#ifndef PARTICLE_INTERACTION_H_INCLUDED
#define PARTICLE_INTERACTION_H_INCLUDED

#include "vec2d.h"

struct ParticleInteraction
{
    ParticleInteraction();
    void randomize();
    void scale(double a);

    double getStrength() const;

    Vec2D eval(const Vec2D& dist) const;
    Vec2D evalGrad(const Vec2D& dist, const Vec2D& distGrad) const;

private:
    void calcCoeffs();

    double eqDist, strength;  // m, N
    double lin, quad; // N * m, N * m^2
};

#endif // PARTICLE_INTERACTION_H_INCLUDED
