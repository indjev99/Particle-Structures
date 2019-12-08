#include "../headers/particle.h"
#include "../headers/settings.h"
#include "../headers/randomizer.h"
#include "../headers/my_math.h"

Particle::Particle(const ParticleType& type)
{
    randomize(type);
}
Particle::Particle(const ParticleType& type, const Vec2D& pos, const Vec2D& impulse):
    type(&type),
    pos(pos),
    vel(impulse / getMass())
{}
void Particle::randomize(const ParticleType& type)
{
    this->type = &type;

    double x = randomDouble(getRadius() - currSettings.univRad, currSettings.univRad - getRadius());
    double y = randomDouble(getRadius() - currSettings.univRad, currSettings.univRad - getRadius());
    pos = Vec2D(x, y);
    vel = zero2D;
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
Vec2D Particle::getImpulse() const
{
    return vel * getMass();
}

void Particle::clearForces()
{
    acc = zero2D;
    jrk = zero2D;
}
void Particle::addForce(const Vec2D& force)
{
    acc += force / getMass();
}
void Particle::addForceGrad(const Vec2D& forceGrad)
{
    jrk += forceGrad / getMass();
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
    double currDrag = -currSettings.dragCoeff * 2 * getRadius();
    addForce(vel * currDrag);
    addForceGrad(acc * currDrag);

    pos += vel * timeDelta + acc * timeDelta * timeDelta / 2 + jrk * timeDelta * timeDelta * timeDelta / 3;
    vel += acc * timeDelta + jrk * timeDelta * timeDelta / 2;

    bounce(pos.x, vel.x, currSettings.univRad - getRadius());
    bounce(pos.y, vel.y, currSettings.univRad - getRadius());
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
    bound(boundNewPos.x, currSettings.univRad - getRadius());
    bound(boundNewPos.y, currSettings.univRad - getRadius());
    vel = (boundNewPos - pos) / timeDelta;
    pos = boundNewPos;
}
