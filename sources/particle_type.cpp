#include "../headers/particle_type.h"
#include "../headers/settings.h"
#include "../headers/randomizer.h"

#include <math.h>
#define PI 3.14159265359

ParticleType::ParticleType(int ID): ID(ID)
{
    randomize();
}
int ParticleType::getID() const
{
    return ID;
}
void ParticleType::randomize()
{
    mass = random_double(minMass, maxMass);
    radius = sqrt(fabs(mass / (PI * particleDensity)));

    double r = random_double(0, 1);
    double g = random_double(0, 1);
    double b = random_double(0, 1);
    color = {r, g, b};
}

