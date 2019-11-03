#include "../headers/particle_type.h"

#include <stdlib.h>

int currID = 0;

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

    color = {0, 0, 0}; /// TODO: RANDOMIZER

    double r = rand() % 101 / 100.0;
    double g = rand() % 101 / 100.0;
    double b = rand() % 101 / 100.0;
    color = {r, g, b};
}

void resetIDs()
{
    currID = 0;
}
