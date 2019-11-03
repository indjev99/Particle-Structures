#include "../headers/particle_system.h"

ParticleSystem::ParticleSystem(int n, int t) : n{n}, t{t}
{
    randomize(n, t);
}
const std::vector<Particle>& ParticleSystem::getParticles() const
{
    return particles;
}
void ParticleSystem::step(double timeDelta)
{
    for (int i = 0; i < n; ++i)
    {;
        for (int j = 0; j < n; ++j)
        {
            if (i == j) continue;
            int id1 = particles[i].getType().getID();
            int id2 = particles[j].getType().getID();
            Vec2D diff = particles[i].getPos() - particles[j].getPos();
            double dist = diff.length();
            Vec2D force = diff / dist * interactions[id1][id2].eval(dist);
            particles[i].addForce(force);
        }
    }
    for (int i = 0; i < n; ++i)
    {
        particles[i].step(timeDelta);
    }
}
void ParticleSystem::randomize(int n, int t)
{
    resetIDs();
    types.clear();
    interactions.clear();
    particles.clear();

    for (int i = 0; i < t; ++i)
    {
        types.push_back(ParticleType());
    }
    interactions.resize(t);
    for (int i = 0; i < t; ++i)
    {
        for (int j = 0; j < t; ++j)
        {
            if (i <= j)
            {
                interactions[i].push_back(ParticleInteraction());
            }
            else
            {
                interactions[i].push_back(interactions[j][i]);
            }
        }
    }
    for (int i = 0; i < n; ++i)
    {
        particles.push_back(Particle(types));
    }
}

