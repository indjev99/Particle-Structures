#include "../headers/window_functions.h"
#include "../headers/window_size.h"
#include "../headers/draw.h"
#include "../headers/settings.h"

#include <iostream>
#include <GLFW/glfw3.h>

const int START_WINDOW_SIZE = 720;

int windowWidth = START_WINDOW_SIZE;
int windowHeight = START_WINDOW_SIZE;

int keyPress = 0;
int mouseClick = 0;
bool mouseMoved = false;
Vec2D mousePos = zero2D;

void errorCallback(int error, const char* description)
{
    std::cerr << error << ": " << description << std::endl;
}
void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) keyPress = -1;
    if (key == GLFW_KEY_SPACE && action == GLFW_PRESS) keyPress = 1;
    if (key == GLFW_KEY_R && action == GLFW_PRESS) keyPress = 2;
    if (key == GLFW_KEY_G && action == GLFW_PRESS) keyPress = 3;
    if (key == GLFW_KEY_S && action == GLFW_PRESS) keyPress = 4;
    if (key == GLFW_KEY_T && action == GLFW_PRESS) keyPress = 5;
}
void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
    if (button == GLFW_MOUSE_BUTTON_LEFT) mouseClick = 1;
    if (button == GLFW_MOUSE_BUTTON_RIGHT) mouseClick = 2;
    if (button == GLFW_MOUSE_BUTTON_MIDDLE) mouseClick = 3;
    if (action == GLFW_RELEASE) mouseClick *= -1;
}
void mousePositionCallback(GLFWwindow* window, double xpos, double ypos)
{
    mouseMoved = true;
    xpos -= windowWidth / 2.0;
    ypos -= windowHeight / 2.0;;
    double scale = 2.0 * univRad / std::min(windowWidth, windowHeight);
    mousePos = {xpos * scale, -ypos * scale};
}
void windowSizeCallback(GLFWwindow* window, int width, int height)
{
    windowWidth = width;
    windowHeight = height;
}
std::string setErrorCallback()
{
    glfwSetErrorCallback(errorCallback);
    return "GLFW error callback set successfully.";
}
std::string initializeGLFW()
{
    if (!glfwInit())
        return "Unable to initialize GLFW.";
    return "GLFW initialized successfully.";
}
std::string createWindow(GLFWwindow*& w)
{
    w = glfwCreateWindow(windowWidth, windowHeight, "Particles", NULL, NULL);
    if (!w)
        return "Unable to open window.";
    return "Window created successfully.";
}
std::string setWindowCallbacks(GLFWwindow* w)
{
    glfwSetKeyCallback(w, keyCallback);
    glfwSetMouseButtonCallback(w, mouseButtonCallback);
    glfwSetCursorPosCallback(w, mousePositionCallback);
    glfwSetWindowSizeCallback(w, windowSizeCallback);
    return "Window callbacks set successfully.";
}
void stopGraphics(GLFWwindow* w)
{
    glfwDestroyWindow(w);
    glfwTerminate();
}
