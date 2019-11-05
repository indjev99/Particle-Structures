#ifndef PARTICLE_DECAY_RESULT_H_INCLUDED
#define PARTICLE_DECAY_RESULT_H_INCLUDED

#include "particle.h"

#include <vector>

struct ParticleDecayResult
{
    ParticleDecayResult();
    ParticleDecayResult(const std::vector<Particle>& particles);

    const bool didDecay;
    const std::vector<Particle> particles;
};

extern const ParticleDecayResult noDecay;

#endif // PARTICLE_DECAY_RESULT_H_INCLUDED
