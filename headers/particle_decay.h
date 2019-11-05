#ifndef PARTICLE_DECAY_H_INCLUDED
#define PARTICLE_DECAY_H_INCLUDED

#include "particle_decay_result.h"

struct ParticleDecay
{
    ParticleDecay(const std::vector<ParticleType>& types);
    void randomize();

    ParticleDecayResult step(const Particle& particle, double timeDelta);

private:
    bool shouldDecay(double timeDelta);
    ParticleDecayResult doDecay(const Particle& particle);

    double meanLife; // s
    int numDecayParticles;
    std::vector<int> decayTypeIDs;
    const std::vector<ParticleType>& types;
};

#endif // PARTICLE_DECAY_H_INCLUDED
