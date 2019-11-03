#include "../headers/particle.h"
#include "../headers/settings.h"

#include <math.h>
#include <stdlib.h>

Particle::Particle(const std::vector<ParticleType>& types)
{
    randomize(types);
}
int Particle::getTypeID() const
{
    return type->getID();
}
double Particle::getMass() const
{
    return type->mass;
}
double Particle::getRadius() const
{
    return type->radius;
}
const Color& Particle::getColor() const
{
    return type->color;
}
const Vec2D& Particle::getPos() const
{
    return pos;
}
void Particle::addForce(const Vec2D force)
{
    acc += force / getMass();
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
    double currDrag = dragCoeff * 2 * getRadius() / getMass();
    acc += -vel * currDrag;
    pos += vel * timeDelta + acc * timeDelta * timeDelta / 2;
    vel += acc * timeDelta - acc * currDrag * timeDelta * timeDelta / 2;
    acc = {0, 0};

    bounce(pos.x, vel.x, univRad - getRadius());
    bounce(pos.y, vel.y, univRad - getRadius());
}
void Particle::randomize(const std::vector<ParticleType>& types)
{
    int typeID = rand() % types.size(); ///TODO: RANDOMIZER
    type = &types[typeID];

    pos = {0, 0}; /// TODO: RANDOMIZER

    int range = (univRad - getRadius()) * 20 + 1;
    double x = rand() % range / 10.0 - univRad + getRadius();
    double y = rand() % range / 10.0 - univRad + getRadius();
    pos = {x, y};

    vel = {0, 0};
    acc = {0, 0};
}
