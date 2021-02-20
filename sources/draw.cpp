#include "../headers/draw.h"
#include "../headers/window_size.h"
#include "../headers/settings.h"
#include "../headers/my_math.h"

const double DEG2RAD = PI / 180;

void initDraw(GLFWwindow* w)
{
    float ratio;
    int width, height;

    glfwMakeContextCurrent(w);
    glfwGetFramebufferSize(w, &width, &height);
    ratio = width / (float) height;
    glViewport(0, 0, width, height);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void drawCircle(const Vec2D& pos, double radius)
{
    glBegin(GL_TRIANGLES);
    for(int i = 0; i < 360; ++i)
    {
        double rad = i * DEG2RAD;
        double rad2 = (i+1) * DEG2RAD;

        glVertex2f(cos(rad) * radius + pos.x, sin(rad) * radius + pos.y);
        glVertex2f(cos(rad2) * radius + pos.x, sin(rad2) * radius + pos.y);
        glVertex2f(pos.x, pos.y);
    }
    glEnd();
}

void drawParticle(const Particle& particle)
{
    double scale = std::min(1.0, 1.0 * windowWidth / windowHeight) / currSettings.univRad;

    const Color& color = particle.getColor();
    double mass = particle.getMass();
    double radius = particle.getRadius();

    glColor3f(color.r, color.g, color.b);
    drawCircle(particle.getPos() * scale, radius * scale);

    if (mass < 0)
    {
        radius *= 0.8;

        glColor3f(currSettings.backColor.r, currSettings.backColor.g, currSettings.backColor.b);
        drawCircle(particle.getPos() * scale, radius * scale);
    }
}

void drawBackground(GLFWwindow* w)
{
    double widthHeightRatio = 1.0 * windowWidth / windowHeight;

    glColor3f(currSettings.backColor.r, currSettings.backColor.g, currSettings.backColor.b);

    glBegin(GL_QUADS);

    glVertex2f(-1.0 * widthHeightRatio, -1.0);
    glVertex2f(1.0 * widthHeightRatio, -1.0);
    glVertex2f(1.0 * widthHeightRatio, 1.0);
    glVertex2f(-1.0 * widthHeightRatio, 1.0);

    glEnd();
}

void drawParticleSystem(GLFWwindow* w, const ParticleSystem& particleSystem)
{
    initDraw(w);
    drawBackground(w);

    const std::vector<Particle>& particles = particleSystem.getParticles();
    int numParticles = particles.size();
    for (int i = 0; i < numParticles; ++i)
    {
        drawParticle(particles[i]);
    }

    glfwSwapBuffers(w);
}
