#include "../headers/particle_interaction.h"
#include "../headers/settings.h"
#include "../headers/randomizer.h"
#include "../headers/my_math.h"

ParticleInteraction::ParticleInteraction()
{
    randomize();
}
void ParticleInteraction::randomize()
{
    eqDist = randomDouble(minEqDist, maxEqDist);

    double power = randomDouble(minLogStrength, maxLogStrength);
    double base = eqDist;
    if (power < 0) base /= minEqDist;
    else base /= maxEqDist;
    strength = pow(base, power);

    calcCoeffs();
}
void ParticleInteraction::scale(double a)
{
    strength *= a;
    calcCoeffs();
}
void ParticleInteraction::calcCoeffs()
{
    lin = 4 * strength * eqDist;
    quad = 4 * strength * eqDist * eqDist;
}

double ParticleInteraction::getStrength() const
{
    return strength;
}

Vec2D ParticleInteraction::eval(const Vec2D& dist) const
{
    double len = dist.length();
    return dist * ((lin - quad / len) / len / len);
}
