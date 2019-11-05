#include "../headers/particle.h"
#include "../headers/settings.h"
#include "../headers/randomizer.h"
#include "../headers/my_math.h"

Particle::Particle(const std::vector<ParticleType>& types):
    locked(false)
{
    randomize(types);
}
Particle::Particle(const ParticleType& type):
    type(&type),
    locked(false)
{
    randomizePos();
}
Particle::Particle(const ParticleType& type, const Vec2D& pos, const Vec2D& impulse):
    type(&type),
    pos(pos),
    locked(false)
{
    vel = impulse / getMass();
}
void Particle::randomize(const std::vector<ParticleType>& types)
{
    int typeID = randomInt(0, types.size() - 1);
    type = &types[typeID];
    randomizePos();
}
void Particle::randomizePos()
{
    double x = randomDouble(getRadius() - univRad, univRad - getRadius());
    double y = randomDouble(getRadius() - univRad, univRad - getRadius());
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
<<<<<<< HEAD
Vec2D Particle::getImpulse() const
{
    return vel * getMass();
}

void Particle::clearForces()
{
    acc = zero2D;
    jrk = zero2D;
}
=======
>>>>>>> 66ade8357150f8989747cf9112c63a0008b1786b
void Particle::addForce(const Vec2D& force)
{
    acc += force / getMass();
}
void Particle::addForceGrad(const Vec2D& forceGrad)
<<<<<<< HEAD
=======
{
    jrk += forceGrad / getMass();
}
double sign(double x)
>>>>>>> 66ade8357150f8989747cf9112c63a0008b1786b
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
<<<<<<< HEAD

=======
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
>>>>>>> 66ade8357150f8989747cf9112c63a0008b1786b
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
bool Particle::isLocked() const
{
    return locked;
}
void Particle::lock()
{
    locked = true;
}
void Particle::unlock()
{
    locked = false;
}
