#ifndef PARTICLE_SYSTEM_H_INCLUDED
#define PARTICLE_SYSTEM_H_INCLUDED

#include "particle.h"
#include "particle_interaction.h"

#include <vector>

struct ParticleSystem
{
    ParticleSystem(int n, int t);
    const std::vector<Particle>& getParticles() const;
    void step(double timeDelta);
    void randomize(int n, int t);
private:
    int n, t;
    std::vector<ParticleType> types;
    std::vector<std::vector<ParticleInteraction>> interactions;
    std::vector<Particle> particles;
};

#endif // PARTICLE_SYSTEM_H_INCLUDED
