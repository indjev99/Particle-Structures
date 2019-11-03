#include "../headers/particle.h"

#include <stdlib.h>

Particle::Particle(const std::vector<ParticleType>& types)
{
    randomize(types);
}
const ParticleType& Particle::getType() const
{
    return *type;
}
const Vec2D& Particle::getPos() const
{
    return pos;
}
void Particle::addForce(const Vec2D force)
{
    acc += force / type->mass;
}
void Particle::step(double timeDelta)
{
    Vec2D newpos = pos;
    newpos += vel * timeDelta + acc * timeDelta * timeDelta / 2;
    if (newpos.x < -95 || newpos.x > 95) vel.x *= -1;
    if (newpos.y < -95 || newpos.y > 95) vel.y *= -1;
    pos += vel * timeDelta + acc * timeDelta * timeDelta / 2;
    vel += acc * timeDelta;
    vel *= 0.997;
    acc = {0, 0};
}
void Particle::randomize(const std::vector<ParticleType>& types)
{
    int typeID = rand() % types.size(); ///TODO: RANDOMIZER
    type = &types[typeID];

    pos = {0, 0}; /// TODO: RANDOMIZER

    double x = rand() % 191 - 95;
    double y = rand() % 191 - 95;
    pos = {x, y};

    vel = {0, 0};
    acc = {0, 0};
}
