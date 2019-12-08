#include "../headers/particle_type.h"
#include "../headers/settings.h"
#include "../headers/randomizer.h"
#include "../headers/my_math.h"

ParticleType::ParticleType(int ID):
    ID(ID)
{
    randomize();
}
int ParticleType::getID() const
{
    return ID;
}
double ParticleType::getMass() const
{
    return mass;
}
double ParticleType::getRadius() const
{
    return radius;
}
const Color& ParticleType::getColor() const
{
    return color;
}
void ParticleType::randomize()
{
    mass = randomDouble(currSettings.minMass, currSettings.maxMass);
    radius = sqrt(fabs(mass / (PI * currSettings.particleDensity)));

    double r = randomDouble(0, 1);
    double g = randomDouble(0, 1);
    double b = randomDouble(0, 1);
    color = Color(r, g, b);
}

