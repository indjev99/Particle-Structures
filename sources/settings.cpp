#include "../headers/settings.h"

Color backColor = Color(1, 1, 1);

int timeResolution = 15;

int numParticles = 120;
int numTypes = 8;
int univRad = 100;

double dragCoeff = 0.01;
double particleDensity = 0.08;

double minMass = 0.5;
double maxMass = 5;

bool enableDecay = false;

int minDecayParticles = 0;
int maxDecayParticles = 2;

double minMeanLifetime = 20 * 60;
double maxMeanLifetime = 180 * 60;

bool symmetricInteractions = true;

double minEqDist = 10;
double maxEqDist = 60;

double baseStrength = 0.0015;
double minLogStrength = -3.5;
double maxLogStrength = -0.5;
