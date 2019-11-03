#ifndef SETTINGS_H_INCLUDED
#define SETTINGS_H_INCLUDED

#include "color.h"

extern Color backColor;

extern int timeResolution; // 1 / s

extern int numParticles; // not physical
extern int numTypes; // not physical
extern int univRad; // m

extern double dragCoeff;  // kg / (m * s)
extern double particleDensity; // kg / m^2

extern double minMass; // kg
extern double maxMass; // kg

extern bool symmetricInteractions; // not physical

extern double minEqDist; // m
extern double maxEqDist; // m

extern double baseStrength; // N
extern double minLogStrength; // dimensionless
extern double maxLogStrength; // dimensionless

#endif // SETTINGS_H_INCLUDED
