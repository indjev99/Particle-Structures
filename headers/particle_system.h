#ifndef PARTICLE_SYSTEM_H_INCLUDED
#define PARTICLE_SYSTEM_H_INCLUDED

#include "particle.h"
#include "particle_interaction.h"
#include "particle_controller.h"

#include <vector>

struct ParticleSystem
{
    ParticleSystem(int numParticles, int numTypes);
    const std::vector<Particle>& getParticles() const;
    void step(double timeDelta);
    void randomizeParticles(int n);
    void randomize(int n, int t);
    ParticleController getController();
private:
    int numParticles, numTypes;
    std::vector<ParticleType> types;
    std::vector<std::vector<ParticleInteraction>> interactions;
    std::vector<Particle> particles;
};

#endif // PARTICLE_SYSTEM_H_INCLUDED
