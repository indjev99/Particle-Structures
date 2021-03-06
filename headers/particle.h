#ifndef PARTICLE_H_INCLUDED
#define PARTICLE_H_INCLUDED

#include "particle_type.h"
#include "vec2d.h"

#include <vector>

struct Particle
{
    Particle(const ParticleType& type);
    Particle(const ParticleType& type, const Vec2D& pos, const Vec2D& impulse=zero2D);
    void randomize(const ParticleType& type);
    void randomizePos();

    int getTypeID() const;
    double getMass() const;
    double getRadius() const;
    const Color& getColor() const;
    const Vec2D& getPos() const;
    const Vec2D& getVel() const;
    Vec2D getImpulse() const;

    void addForce(const Vec2D& force);
    void addForceGrad(const Vec2D& forceGrad);
    void step(double timeDelta);

    void updatePos(const Vec2D& newPos, double timeDelta);

private:
    const ParticleType* type;
    Vec2D pos; // m
    Vec2D vel; // m / s
    Vec2D frc; // N
    Vec2D fgrad; // N / s
};

#endif // PARTICLE_H_INCLUDED
