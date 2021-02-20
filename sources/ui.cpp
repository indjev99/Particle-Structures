#include "../headers/ui.h"
#include "../headers/settings.h"

#include <iostream>
#include <fstream>

void help()
{
    std::cout << "Space - Pause\nR - Respawn new particles\nG - Generate new rules\n" <<
                 "P - Change some of the basic parameters (most will be applied after next generation)\n" <<
                 "T - Change the time resolution of the simulation\n" <<
                 "S - Save the current simulation to a file\n" <<
                 "L - Load a simulation from a file\n" <<
                 "Left click a particle - grab it\n" <<
                 "Left click the air - create a new particle and then grab it\n" <<
                 "Release left button - drop the held particle\n" <<
                 "Right click a particle - remove it\n" <<
                 "Middle click a particle - copy its type for particles created in the future\n" <<
                 "Middle click the air - clear the selected type (new particles are random)\n" << std::endl;
}

void changeParameters()
{
    bool toEdit;

    std::cout << "Please enter new values (the current ones are shown in brackets)" << std::endl;
    std::cout << "Edit number of particles/types? (0/1): ";
    std::cin >> toEdit;
    if (toEdit)
    {
        std::cout << "Number of particles (" << currSettings.numParticles << "): ";
        std::cin >> currSettings.numParticles;
        std::cout << "Number of types (" << currSettings.numTypes << "): ";
        std::cin >> currSettings.numTypes;
    }

    std::cout << "Edit the interaction parameters? (0/1): ";
    std::cin >> toEdit;
    if (toEdit)
    {
        std::cout << "Min force range (" << currSettings.minEqDist << "): ";
        std::cin >> currSettings.minEqDist;
        std::cout << "Max force range (" << currSettings.maxEqDist << "): ";
        std::cin >> currSettings.maxEqDist;
        std::cout << "Min force strength scale (" << currSettings.minLogStrength << "): ";
        std::cin >> currSettings.minLogStrength;
        std::cout << "Max force strength scale (" << currSettings.maxLogStrength << "): ";
        std::cin >> currSettings.maxLogStrength;
        std::cout << "Enable asymmetric forces (" << currSettings.asymmetricInteractions << "): ";
        std::cin >> currSettings.asymmetricInteractions;
    }

    std::cout << "Edit the decay parameters? (0/1): ";
    std::cin >> toEdit;
    if (toEdit)
    {
        std::cout << "Min decay particles (" << currSettings.minDecayParticles << "): ";
        std::cin >> currSettings.minDecayParticles;
        std::cout << "Max decay particles (" << currSettings.maxDecayParticles << "): ";
        std::cin >> currSettings.maxDecayParticles;
        std::cout << "Min mean lifetime (" << currSettings.minMeanLifetime << "): ";
        std::cin >> currSettings.minMeanLifetime;
        std::cout << "Max mean lifetime (" << currSettings.maxMeanLifetime << "): ";
        std::cin >> currSettings.maxMeanLifetime;
    }
    std::cout << "Enable particle decay (" << currSettings.enableDecay << "): ";
    std::cin >> currSettings.enableDecay;
}

void changeTimeResolution()
{
    std::cout << "A higher value makes the simulation more accurate,\nbut also more computationaly expensive." << std::endl;
    std::cout << "Please enter a new value (the current one is shown in brackets)" << std::endl;
    std::cout << "Time resolution (" << currSettings.timeResolution << "): ";
    std::cin >> currSettings.timeResolution;
}

void saveSettings()
{
    std::string filename;
    std::cout << "Enter file name: ";
    std::cin >> filename;
    std::ofstream file(filename.c_str());
    file << lastSettings.backColor.r << ' ';
    file << lastSettings.backColor.g << ' ';
    file << lastSettings.backColor.b << ' ';
    file << lastSettings.timeResolution << ' ';
    file << lastSettings.enableDecay << ' ';
    file << lastSettings.seed << ' ';
    file << lastSettings.numParticles << ' ';
    file << lastSettings.numTypes << ' ';
    file << lastSettings.univRad << ' ';
    file << lastSettings.dragCoeff << ' ';
    file << lastSettings.particleDensity << ' ';
    file << lastSettings.minMass << ' ';
    file << lastSettings.maxMass << ' ';
    file << lastSettings.minDecayParticles << ' ';
    file << lastSettings.maxDecayParticles << ' ';
    file << lastSettings.minMeanLifetime << ' ';
    file << lastSettings.maxMeanLifetime << ' ';
    file << lastSettings.asymmetricInteractions << ' ';
    file << lastSettings.minEqDist << ' ';
    file << lastSettings.minLogStrength << ' ';
    file << lastSettings.maxLogStrength << ' ';
    file << lastSettings.normalizedMaxStrength << '\n';
}

void loadSettings()
{
    std::string filename;
    std::cout << "Enter file name: ";
    std::cin >> filename;
    std::ifstream file(filename.c_str());
    file >> currSettings.backColor.r;
    file >> currSettings.backColor.g;
    file >> currSettings.backColor.b;
    file >> currSettings.timeResolution;
    file >> currSettings.enableDecay;
    file >> currSettings.seed;
    file >> currSettings.numParticles;
    file >> currSettings.numTypes;
    file >> currSettings.univRad;
    file >> currSettings.dragCoeff;
    file >> currSettings.particleDensity;
    file >> currSettings.minMass;
    file >> currSettings.maxMass;
    file >> currSettings.minDecayParticles;
    file >> currSettings.maxDecayParticles;
    file >> currSettings.minMeanLifetime;
    file >> currSettings.maxMeanLifetime;
    file >> currSettings.asymmetricInteractions;
    file >> currSettings.minEqDist;
    file >> currSettings.minLogStrength;
    file >> currSettings.maxLogStrength;
    file >> currSettings.normalizedMaxStrength;
}
