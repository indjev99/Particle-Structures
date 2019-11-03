#include "../headers/run.h"
#include "../headers/particle_system.h"
#include "../headers/draw.h"
#include "../headers/window_functions.h"

#include<stdlib.h>
#include<time.h>

int numParticles = 120;
int numTypes = 8;

int timeResolution = 10;

void run(GLFWwindow* w)
{
    srand(time(0));

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

    /*

    std::chrono::high_resolution_clock::time_point start_time,curr_time;

    while (!glfwWindowShouldClose(w))
    {
        start_time=std::chrono::high_resolution_clock::now();
        if (!draw)
        {
            //for (int i=0;i<5;++i)
                //drawWindow(w,g);
        }
        if (!paused)
        {
            for (int i=0;i<15;++i)
                g.update();
        }
        if (pressed==1)
        {
            pressed=0;
            paused=!paused;
        }
        if (pressed==2)
        {
            pressed=0;
            g.randomise();
        }
        if (pressed==3)
        {
            pressed=0;
            input(g);
        }
        if (pressed==4)
        {
            pressed=0;
            stats(g);
        }
        if (pressed==5)
        {
            pressed=0;
            draw=!draw;
        }
        if (pressed==6)
        {
            ++n;
            pressed=0;
            g.reset(n);
            //g.vertices[0]={-100,-100};
            //g.vertices[n-1]={100,100};
            for (int i=0;i<n;++i)
            {
                for (int j=i+1; j<n;++j)
                {
                    //if (!(rand()%4))
                        g.addEdge(i,j);
                }
            }
        }
        do
        {
            glfwPollEvents();
            curr_time=std::chrono::high_resolution_clock::now();
        }
        while(!glfwWindowShouldClose(w) && std::chrono::duration_cast<std::chrono::duration<long double>>(curr_time-start_time).count()<0.01);
        //std::cout<<std::chrono::duration_cast<std::chrono::duration<long double>>(curr_time-start_time).count()<<"\n";
    }
    */
}
