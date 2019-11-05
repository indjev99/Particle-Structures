#include "../headers/particle_controller.h"
#include "../headers/randomizer.h"

ParticleController::ParticleController(int& numParticles, std::vector<Particle>& particles, int& locked, const std::vector<ParticleType>& types):
    numParticles(numParticles),
    particles(particles),
    types(types),
    dragging(locked),
    copied(-1)
{}

void ParticleController::step(int mouseClick, const Vec2D& mousePos, bool mouseMoved, double timeDelta)
{
    sinceLastDrag += timeDelta;
    if ((mouseMoved || mouseClick == -1) && dragging >= 0)
    {
        particles[dragging].updatePos(mousePos + draggingOffset, sinceLastDrag);
        sinceLastDrag = 0;
    }
    if (mouseClick)
    {
        int clicked = -1;
        if (dragging >= 0) clicked = dragging;
        else
        {
            for (int i = numParticles - 1; i >= 0 ; --i)
            {
                Vec2D offset = particles[i].getPos() - mousePos;
                double dist = offset.length();
                if (dist < particles[i].getRadius())
                {
                    clicked = i;
                    draggingOffset = offset;
                    break;
                }
            }
        }

        switch (mouseClick)
        {
        case 1:
            if (clicked == -1)
            {
                if (copied == -1) particles.push_back(Particle(selectRandom(types)));
                else particles.push_back(Particle(types[copied]));
                ++numParticles;
                clicked = numParticles - 1;
                draggingOffset = zero2D;
            }
            dragging = clicked;
            particles[dragging].updatePos(mousePos + draggingOffset, 1);
            sinceLastDrag = 0;
            break;
        case 2:
            if (clicked >= 0)
            {
                particles.erase(particles.begin() + clicked);
                --numParticles;
                dragging = -1;
            }
            break;
        case 3:
            if (clicked == -1) copied = -1;
            else copied = particles[clicked].getTypeID();
            break;
        case -1:
            dragging = -1;
            break;
        default:
            break;
        }
    }

}
