#ifndef PARTICLE_INTERACTION_H_INCLUDED
#define PARTICLE_INTERACTION_H_INCLUDED

struct ParticleInteraction
{
    ParticleInteraction();
    double eval(double dist) const;
    void randomize();
private:
    double eqDist, strength;  // m, N
    double lin, quad; // N * m, N * m^2
    void calcCoeffs();
};

#endif // PARTICLE_INTERACTION_H_INCLUDED
