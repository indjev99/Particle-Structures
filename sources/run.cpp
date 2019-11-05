#include "../headers/run.h"
#include "../headers/draw.h"
#include "../headers/particle_system.h"
#include "../headers/settings.h"
#include "../headers/randomizer.h"

#include <time.h>
#ifdef DEBUG
    #include <iostream>
#endif

#include <iostream>
void changeSettings()
{
    std::cout << "Please enter new values (the current ones are shown in brackets)"<<std::endl;
    std::cout << "Number of particles ("<<numParticles<<"): ";
    std::cin >> numParticles;
    std::cout << "Number of types ("<<numTypes<<"): ";
    std::cin >> numTypes;
    std::cout << "Min force range ("<<minEqDist<<"): ";
    std::cin >> minEqDist;
    std::cout << "Max force range ("<<maxEqDist<<"): ";
    std::cin >> maxEqDist;
    std::cout << "Min force strength scale ("<<minLogStrength<<"): ";
    std::cin >> minLogStrength;
    std::cout << "Max force strength scale ("<<maxLogStrength<<"): ";
    std::cin >> maxLogStrength;
}
void changeTimeResolution()
{
    std::cout << "A higher value makes the simulation more accurate,\nbut also more computationaly expensive."<<std::endl;
    std::cout << "Please enter a new value (the current one is shown in brackets)"<<std::endl;
    std::cout << "Time resolution ("<<timeResolution<<"): ";
    std::cin >> timeResolution;
}
void help()
{
    std::cout << "Space - Pause\nR - Respawn new particles\nG - Generate new rules\n" <<
                 "S - Change some of the basic settings (this will generate new rules)\n" <<
                 "T - Change the time resolution of the simulation\n" <<
                 "Left click a particle - grab it\n" <<
                 "Left click the air - create a new particle and then grab it\n" <<
                 "Release left button - drop the held particle\n" <<
                 "Right click a particle - remove it\n" <<
                 "Middle click a particle - copy its type for particles created in the future\n" <<
                 "Middle click the air - clear the selected type (new particles are random)\n" << std::endl;
}

void run(GLFWwindow* window)
{
    help();

    #ifdef DEBUG
        time_t start = clock();
        int cnt = 0;
    #endif
    seeRandomizer(time(0));
    bool paused = false;
    ParticleSystem system(numParticles, numTypes);
    ParticleController controller = system.getController();
    while (!glfwWindowShouldClose(window))
    {
        drawParticleSystem(window, system);
        double timeDelta = 1.0 / timeResolution;
        for (int i = 0; i < timeResolution; ++i)
        {
            system.step(!paused * timeDelta);
        }
        glfwPollEvents();
        if (keyPress == -1) glfwSetWindowShouldClose(window, 1);
        if (keyPress == 1) paused = !paused;
        if (keyPress == 2) system.randomizeParticles(numParticles);
        if (keyPress == 3) system.randomize(numParticles, numTypes);
        if (keyPress == 4) { changeSettings(); system.randomize(numParticles, numTypes); }
        if (keyPress == 5) changeTimeResolution();
        controller.step(mouseClick, mousePos, mouseMoved, 1);
        keyPress = 0;
        mouseClick = 0;
        mouseMoved = false;
        #ifdef DEBUG
            ++cnt;
            if (cnt % 60 == 0)
            {
                time_t curr = clock();
                std::cerr << (curr - start) * 1.0 / CLOCKS_PER_SEC << std::endl;
                start = curr;
            }
        #endif
    }
}
