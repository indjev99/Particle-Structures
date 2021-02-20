#include "../headers/run.h"
#include "../headers/draw.h"
#include "../headers/particle_system.h"
#include "../headers/settings.h"
#include "../headers/ui.h"
#include "../headers/randomizer.h"

#include <time.h>
#ifdef DEBUG
#include <iostream>
#endif

void run(GLFWwindow* window)
{
    help();
    #ifdef DEBUG
        time_t start = clock();
        int cnt = 0;
    #endif
    currSettings.seed = time(0);
    seedRandomizer(currSettings.seed);
    bool paused = false;
    ParticleSystem system(currSettings.numParticles, currSettings.numTypes);
    ParticleController controller = system.getController();
    while (!glfwWindowShouldClose(window))
    {
        drawParticleSystem(window, system);
        double timeDelta = 1.0 / currSettings.timeResolution;
        for (int i = 0; i < currSettings.timeResolution; ++i)
        {
            system.step(!paused * timeDelta);
        }
        glfwPollEvents();
        if (keyPress == -1) glfwSetWindowShouldClose(window, 1);
        if (keyPress == 1) paused = !paused;
        if (keyPress == 2) system.randomizeParticles(currSettings.numParticles);
        if (keyPress == 3)
        {
            currSettings.seed = getRandomizerSeed();
            system.randomize(currSettings.numParticles, currSettings.numTypes);
            lastSettings = currSettings;
        }
        if (keyPress == 4) changeParameters();
        if (keyPress == 5) changeTimeResolution();
        if (keyPress == 6) saveSettings();
        if (keyPress == 7)
        {
            loadSettings();
            seedRandomizer(currSettings.seed);
            system.randomize(currSettings.numParticles, currSettings.numTypes);
            lastSettings = currSettings;
        }
        controller.step(mouseClick, mousePos, mouseMoved, 1);
        keyPress = 0;
        mouseClick = 0;
        mouseMoved = false;
        #ifdef DEBUG
            ++cnt;
            if (cnt % 60 == 0)
            {
                time_t curr = clock();
                double timeFor60Frames = (curr - start) * 1.0 / CLOCKS_PER_SEC;
                std::cerr << (int) (60 / timeFor60Frames + 0.5) << " FPS" << std::endl;
                start = curr;
            }
        #endif
    }
}
