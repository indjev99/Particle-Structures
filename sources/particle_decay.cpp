#include "../headers/particle_decay.h"
#include "../headers/randomizer.h"
#include "../headers/settings.h"
#include "../headers/my_math.h"

ParticleDecay::ParticleDecay(const std::vector<ParticleType>& types):
    types(types)
{
    randomize();
}
void ParticleDecay::randomize()
{
    meanLife = randomDouble(minMeanLifetime, maxMeanLifetime);
    numDecayParticles = randomInt(minDecayParticles, maxDecayParticles);
    for (int i = 0; i < numDecayParticles; ++i)
    {
        int typeID = randomInt(0, types.size() - 1);
        decayTypeIDs.push_back(typeID);
    }
}
bool ParticleDecay::shouldDecay(double timeDelta)
{
    double prob = 1 - exp(-timeDelta / meanLife);
    double roll = randomDouble(0, 1 / prob);
    return roll < 1;
}
ParticleDecayResult ParticleDecay::doDecay(const Particle& particle)
{
    std::vector<Particle> particles;
    double dist = numDecayParticles - 1;
    double initAngle = randomDouble(0, 2 * PI);
    for (int i = 0; i < numDecayParticles; ++i)
    {
        double angle = initAngle + 2 * PI * i / numDecayParticles;
        Vec2D pos = particle.getPos() + dist * Vec2D(angle);
        Vec2D impulse = particle.getImpulse() / numDecayParticles;
        particles.push_back(Particle(types[decayTypeIDs[i]], pos, impulse));
    }
    return ParticleDecayResult(particles);
}
ParticleDecayResult ParticleDecay::step(const Particle& particle, double timeDelta)
{
    if (shouldDecay(timeDelta)) return doDecay(particle);
    else return noDecay;
}
