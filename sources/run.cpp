#include "../headers/run.h"
#include "../headers/draw.h"
#include "../headers/particle_system.h"
#include "../headers/settings.h"
#include "../headers/randomizer.h"

#include <time.h>

void run(GLFWwindow* w)
{
    seed_randomizer(time(0));

    bool paused = false;
    ParticleSystem system(numParticles, numTypes);
    while (!glfwWindowShouldClose(w))
    {
        if (!paused)
        {
            for (int i = 0; i < timeResolution; ++i)
            {
                system.step(1.0 / timeResolution);
            }
        }
        drawParticleSystem(w, system);
        glfwPollEvents();
        if (keyPress == 1) paused = !paused;
        if (keyPress == 2) system.randomizeParticles(numParticles);
        if (keyPress == 3) system.randomize(numParticles, numTypes);
        keyPress = 0;
        mouseClick = 0;
    }
}
