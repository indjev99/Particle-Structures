#include "../headers/particle_interaction.h"
#include "../headers/settings.h"

#include <math.h>
#include <stdlib.h>

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
    eqDist = (rand() % 500) / 10.0 + 10; /// TODO: RANDOMIZER
    strength = 0; /// TODO?: RANDOMIZER

    //strength = baseStrength * pow(eqDist * normEqDist, logStrength);
    strength = baseStrength * pow(eqDist * normEqDist, rand() % 11 / 10.0 - 3);

    calcCoeffs();
}
void ParticleInteraction::calcCoeffs()
{
    lin = 4 * strength * eqDist;
    quad = 4 * strength * eqDist * eqDist;
}
