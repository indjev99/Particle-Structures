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
    eqDist = randomDouble(currSettings.minEqDist, currSettings.maxEqDist);

    double power = randomDouble(currSettings.minLogStrength, currSettings.maxLogStrength);
    double base = eqDist;
    if (power < 0) base /= currSettings.minEqDist;
    else base /= currSettings.maxEqDist;
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
    double invLen = 1 / dist.length();
    return dist * ((lin - quad * invLen) * invLen * invLen);
}

Vec2D ParticleInteraction::evalGrad(const Vec2D& dist, const Vec2D& distGrad) const
{
    double invLen = 1 / dist.length();
    double invLenSq = invLen * invLen;
    double dp = dot(dist, distGrad);
    return distGrad * ((lin - quad * invLen) * invLenSq)
         - dist * ((2 * lin - 3 * quad * invLen) * dp * invLenSq * invLenSq);
}
