#include "../headers/particle_system.h"
#include "../headers/settings.h"

ParticleSystem::ParticleSystem(int numParticles, int numTypes)
{
    randomize(numParticles, numTypes);
}
const std::vector<Particle>& ParticleSystem::getParticles() const
{
    return particles;
}
void ParticleSystem::step(double timeDelta)
{
    for (int i = 0; i < numParticles; ++i)
    {
        for (int j = 0; j < numParticles; ++j)
        {
            if (i == j) continue;
            int id1 = particles[i].getTypeID();
            int id2 = particles[j].getTypeID();
            Vec2D offset = particles[j].getPos() - particles[i].getPos();
            double dist = offset.length();
            Vec2D force = offset / dist * interactions[id1][id2].eval(dist);
            particles[i].addForce(force);
        }
    }
    for (int i = 0; i < numParticles; ++i)
    {
        particles[i].step(timeDelta);
    }
}
void ParticleSystem::randomizeParticles(int numParticles)
{
    this->numParticles = numParticles;
    particles.clear();
    for (int i = 0; i < numParticles; ++i)
    {
        particles.push_back(Particle(types));
    }
}
void ParticleSystem::randomize(int numParticles, int numTypes)
{
    this->numParticles = numParticles;
    this->numTypes = numTypes;
    types.clear();
    interactions.clear();
    for (int i = 0; i < numTypes; ++i)
    {
        types.push_back(ParticleType(i));
    }
    interactions.resize(numTypes);
    for (int i = 0; i < numTypes; ++i)
    {
        for (int j = 0; j < numTypes; ++j)
        {
            if (symmetricInteractions && j < i) interactions[i].push_back(interactions[j][i]);
            else interactions[i].push_back(ParticleInteraction());
        }
    }
    randomizeParticles(numParticles);
}
ParticleController ParticleSystem::getController()
{
    return ParticleController(numParticles, particles, types);
}
