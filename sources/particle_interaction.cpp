#include "../headers/particle_interaction.h"

#include <stdlib.h>

ParticleInteraction::ParticleInteraction()
{
    randomize();
}
double ParticleInteraction::eval(double dist) const
{
    return quad / (dist * dist) - lin / dist;
}
void ParticleInteraction::randomize()
{
    double neutralDist = (rand() % 500) / 10.0 + 10; /// TODO: RANDOMIZER
    calcCoeffs(neutralDist);
}
void ParticleInteraction::calcCoeffs(double neutralDist)
{
    double k = 1 / neutralDist;
    double norm = 4 / k * k;
    quad = norm;
    lin = norm * k;
}
