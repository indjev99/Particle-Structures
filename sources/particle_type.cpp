#include "../headers/particle_type.h"
#include "../headers/settings.h"

#include <stdlib.h>
#include <math.h>

#define PI 3.14159

int currID = 0;
void ParticleType::resetIDs()
{
    currID = 0;
}
ParticleType::ParticleType()
{
    ID = currID;
    ++currID;
    randomize();
}
int ParticleType::getID() const
{
    return ID;
}
void ParticleType::randomize()
{
    mass = (rand() % 91 + 10) / 20.0; /// TODO: RANDOMIZER

    radius = sqrt(fabs(mass / (PI * particleDensity)));

    color = {0, 0, 0}; /// TODO: RANDOMIZER

    double r = rand() % 101 / 100.0;
    double g = rand() % 101 / 100.0;
    double b = rand() % 101 / 100.0;
    color = {r, g, b};
}

