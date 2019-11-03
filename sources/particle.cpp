#include "../headers/particle.h"
#include "../headers/settings.h"

#include <math.h>
#include <stdlib.h>

Particle::Particle(const std::vector<ParticleType>& types)
{
    randomize(types);
}
const ParticleType& Particle::getType() const
{
    return *type;
}
int Particle::getTypeID() const
{
    return type->getID();
}
const Vec2D& Particle::getPos() const
{
    return pos;
}
void Particle::addForce(const Vec2D force)
{
    acc += force / getType().mass;
}
double sign(double x)
{
    return x < 0 ? -1 : 1;
}
void bounce(double& pos, double& vel, double bound)
{
    if (fabs(pos) > bound)
    {
        pos = 2 * bound * sign(pos) - pos;
        vel *= -1;
    }
}
void Particle::step(double timeDelta)
{
    double currDrag = dragCoeff * 2 * getType().radius / getType().mass;
    acc += -vel * currDrag;
    pos += vel * timeDelta + acc * timeDelta * timeDelta / 2;
    vel += acc * timeDelta - acc * currDrag * timeDelta * timeDelta / 2;
    acc = {0, 0};

    bounce(pos.x, vel.x, univRad);
    bounce(pos.y, vel.y, univRad);
}
void Particle::randomize(const std::vector<ParticleType>& types)
{
    int typeID = rand() % types.size(); ///TODO: RANDOMIZER
    type = &types[typeID];

    pos = {0, 0}; /// TODO: RANDOMIZER

    int range = univRad * 20 + 1;
    double x = rand() % range / 10.0 - univRad;
    double y = rand() % range / 10.0 - univRad;
    pos = {x, y};

    vel = {0, 0};
    acc = {0, 0};
}
