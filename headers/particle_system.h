#ifndef PARTICLE_SYSTEM_H_INCLUDED
#define PARTICLE_SYSTEM_H_INCLUDED

#include "particle.h"
#include "particle_interaction.h"
#include "particle_decay.h"
#include "particle_controller.h"

#include <vector>

struct ParticleSystem
{
    ParticleSystem(int numParticles, int numTypes);
    void randomize(int n, int t);
    void randomizeParticles(int n);
    ParticleController getController();

    const std::vector<Particle>& getParticles() const;

    void step(double timeDelta);

private:
    int numParticles, numTypes;
    std::vector<ParticleType> types;
    std::vector<std::vector<ParticleInteraction>> interactions;
    std::vector<ParticleDecay> decays;
    std::vector<Particle> particles;
};

#endif // PARTICLE_SYSTEM_H_INCLUDED
