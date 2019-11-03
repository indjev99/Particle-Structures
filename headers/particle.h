#ifndef PARTICLE_H_INCLUDED
#define PARTICLE_H_INCLUDED

#include "particle_type.h"
#include "vec2d.h"

#include <vector>

struct Particle
{
    Particle(const std::vector<ParticleType>& types);
    const ParticleType& getType() const;
    const Vec2D& getPos() const;
    void addForce(const Vec2D force);
    void step(double timeDelta);
    void randomize(const std::vector<ParticleType>& types);
private:
    const ParticleType* type;
    Vec2D pos;
    Vec2D vel;
    Vec2D acc;
};

#endif // PARTICLE_H_INCLUDED
