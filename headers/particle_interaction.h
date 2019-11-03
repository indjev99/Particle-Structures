#ifndef PARTICLE_INTERACTION_H_INCLUDED
#define PARTICLE_INTERACTION_H_INCLUDED

struct ParticleInteraction
{
    ParticleInteraction();
    double eval(double dist) const;
    void randomize();
private:
    double quad, lin;
    void calcCoeffs(double dist);
};

#endif // PARTICLE_INTERACTION_H_INCLUDED
