#include "../headers/particle_interaction.h"
#include "../headers/settings.h"
#include "../headers/randomizer.h"

#include <math.h>

ParticleInteraction::ParticleInteraction()
{
    randomize();
}
double ParticleInteraction::eval(double dist) const
{
    return lin / dist - quad / (dist * dist);
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
