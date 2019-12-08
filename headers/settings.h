#ifndef SETTINGS_H_INCLUDED
#define SETTINGS_H_INCLUDED

#include "color.h"

struct Settings
{
    static Color backColor; // not physical
    static int timeResolution; // 1 / s
    static bool enableDecay; // not physical

    int seed; // not physical

    int numParticles; // not physical
    int numTypes; // not physical
    int univRad; // m

    double dragCoeff;  // kg / (m * s)
    double particleDensity; // kg / m^2

    double minMass; // kg
    double maxMass; // kg

    int minDecayParticles; // dimensionless
    int maxDecayParticles; // dimensionless

    double minMeanLifetime; // s
    double maxMeanLifetime; // s

    bool asymmetricInteractions; // not physical

    double minEqDist; // m
    double maxEqDist; // m

    double minLogStrength; // dimensionless
    double maxLogStrength; // dimensionless

    double normalizedMaxStrength; // N
};

extern Settings currSettings;
extern Settings lastSettings;

#endif // SETTINGS_H_INCLUDED
