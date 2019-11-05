#ifndef PARTICLE_CONTROLLER_H_INCLUDED
#define PARTICLE_CONTROLLER_H_INCLUDED

#include "particle.h"
#include "particle_type.h"

#include <vector>

struct ParticleController
{
    ParticleController(int& numParticles, std::vector<Particle>& particle, const std::vector<ParticleType>& types);
    void step(int mouseClick, const Vec2D& mousePos, bool mouseMoved, double timeDelta);

private:
    int& numParticles;
    std::vector<Particle>& particles;
    const std::vector<ParticleType>& types;
    int dragging;
    double sinceLastDrag;
    Vec2D draggingOffset;
    int copied;
};

#endif // PARTICLE_CONTROLLER_H_INCLUDED
