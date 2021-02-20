#include "../headers/particle_decay_result.h"

const ParticleDecayResult noDecay = ParticleDecayResult();

ParticleDecayResult::ParticleDecayResult():
    didDecay(false),
    particles({}) {}

ParticleDecayResult::ParticleDecayResult(const std::vector<Particle>& particles):
    didDecay(true),
    particles(particles) {}
