#include "../headers/particle_interaction.h"
#include "../headers/settings.h"
#include "../headers/randomizer.h"

#include <math.h>

ParticleInteraction::ParticleInteraction()
{
    randomize();
}
Vec2D ParticleInteraction::eval(const Vec2D& dist) const
{
    double len = dist.length();
    return dist * ((lin - quad / len) / len / len);
}
void ParticleInteraction::randomize()
{
    eqDist = random_double(minEqDist, maxEqDist);
    double base = eqDist * 2 / (minEqDist + maxEqDist);
    double power = random_double(minLogStrength, maxLogStrength);
    strength = baseStrength * pow(base, power);
    calcCoeffs();
}
void ParticleInteraction::calcCoeffs()
{
    lin = 4 * strength * eqDist;
    quad = 4 * strength * eqDist * eqDist;
}
