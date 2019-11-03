#include "../headers/particle_interaction.h"

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
    strength = 1 / eqDist / eqDist; /// TODO?: RANDOMIZER
    calcCoeffs();
}
void ParticleInteraction::calcCoeffs()
{
    lin = 4 * strength * eqDist;
    quad = 4 * strength * eqDist * eqDist;
}
