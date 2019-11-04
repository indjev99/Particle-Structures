#include "../headers/particle.h"
#include "../headers/settings.h"
#include "../headers/randomizer.h"

#include <math.h>

Particle::Particle(const std::vector<ParticleType>& types)
{
    randomize(types);
}
Particle::Particle(const ParticleType& type):
    type(&type)
{
    randomizePos();
}
int Particle::getTypeID() const
{
    return type->getID();
}
double Particle::getMass() const
{
    return type->getMass();
}
double Particle::getRadius() const
{
    return type->getRadius();
}
const Color& Particle::getColor() const
{
    return type->getColor();
}
const Vec2D& Particle::getPos() const
{
    return pos;
}
void Particle::addForce(const Vec2D& force)
{
    acc += force / getMass();
}
void Particle::addForceGrad(const Vec2D& forceGrad)
{
    jrk += forceGrad / getMass();
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
    if (locked) return;

    double currDrag = -dragCoeff * 2 * getRadius();
    addForce(vel * currDrag);
    addForceGrad(acc * currDrag);

    pos += vel * timeDelta + acc * timeDelta * timeDelta / 2 + jrk * timeDelta * timeDelta * timeDelta / 3;
    vel += acc * timeDelta + jrk * timeDelta * timeDelta / 2;
    acc = zero2D;
    jrk = zero2D;

    bounce(pos.x, vel.x, univRad - getRadius());
    bounce(pos.y, vel.y, univRad - getRadius());
}
void Particle::randomize(const std::vector<ParticleType>& types)
{
    int typeID = random_int(0, types.size() - 1);
    type = &types[typeID];
    randomizePos();
}
void Particle::randomizePos()
{
    double x = random_double(getRadius() - univRad, univRad - getRadius());
    double y = random_double(getRadius() - univRad, univRad - getRadius());
    pos = {x, y};
    vel = zero2D;
    acc = zero2D;
    jrk = zero2D;
    locked = false;
}
void bound(double& pos, double bound)
{
    if (fabs(pos) > bound)
    {
        pos = bound * sign(pos);
    }
}
void Particle::updatePos(const Vec2D& newPos, double timeDelta)
{
    Vec2D boundNewPos = newPos;
    bound(boundNewPos.x, univRad - getRadius());
    bound(boundNewPos.y, univRad - getRadius());
    vel = (boundNewPos - pos) / timeDelta;
    pos = boundNewPos;
}
void Particle::lock()
{
    locked = true;
}
void Particle::unlock()
{
    locked = false;
}
