#include "../headers/settings.h"

Color Settings::backColor = Color(1, 1, 1);
int Settings::timeResolution = 15;
bool Settings::enableDecay = false;

int seed = 0;

int numParticles = 120;
int numTypes = 8;
int univRad = 100;

double dragCoeff = 0.01;
double particleDensity = 0.08;

double minMass = 0.5;
double maxMass = 5;

int minDecayParticles = 0;
int maxDecayParticles = 3;

double minMeanLifetime = 2000;
double maxMeanLifetime = 10000;

bool asymmetricInteractions = false;

double minEqDist = 10;
double maxEqDist = 60;

double minLogStrength = -3.5;
double maxLogStrength = -0.5;

double normalizedMaxStrength = 0.015;

Settings lastSettings;
Settings currSettings = {seed, numParticles, numTypes, univRad, dragCoeff, particleDensity,
                        minMass, maxMass, minDecayParticles, maxDecayParticles,
                        minMeanLifetime, maxMeanLifetime, asymmetricInteractions,
                        minEqDist, maxEqDist, minLogStrength, maxLogStrength, normalizedMaxStrength};
