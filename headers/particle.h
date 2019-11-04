#ifndef PARTICLE_H_INCLUDED
#define PARTICLE_H_INCLUDED

#include "particle_type.h"
#include "vec2d.h"

#include <vector>

struct Particle
{
    Particle(const std::vector<ParticleType>& types);
    Particle(const ParticleType& type);
    int getTypeID() const;
    double getMass() const;
    double getRadius() const;
    const Color& getColor() const;
    const Vec2D& getPos() const;
    void addForce(const Vec2D& force);
    void addForceGrad(const Vec2D& forceGrad);
    void step(double timeDelta);
    void randomize(const std::vector<ParticleType>& types);
    void updatePos(const Vec2D& newPos, double timeDelta);
    void lock();
    void unlock();
private:
    void randomizePos();
    const ParticleType* type;
    Vec2D pos; // m
    Vec2D vel; // m / s
    Vec2D acc; // m / s^2
    Vec2D jrk; // m / s^3
    bool locked;
};

#endif // PARTICLE_H_INCLUDED
