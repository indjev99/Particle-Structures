#include "../headers/window_functions.h"
#include "../headers/window_size.h"
#include "../headers/draw.h"

#include <iostream>
#include <GLFW/glfw3.h>

const int START_WINDOW_SIZE = 720;

int windowWidth = START_WINDOW_SIZE;
int windowHeight = START_WINDOW_SIZE;

int keyPress = 0;
int mouseClick = 0;
Vec2D mousePos = {0, 0};

void errorCallback(int error, const char* description)
{
    std::cerr << error << ": " << description << std::endl;
}
void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) glfwSetWindowShouldClose(window, 1);
    if (key == GLFW_KEY_SPACE && action == GLFW_PRESS) keyPress = 1;
    if (key == GLFW_KEY_R && action == GLFW_PRESS) keyPress = 2;
    if (key == GLFW_KEY_G && action == GLFW_PRESS) keyPress = 3;
}
void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
    if (action == GLFW_PRESS)
    {
        mouseClick = button + 1;
        glfwGetCursorPos(window, &mousePos.x, &mousePos.y);
    }
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
    glfwSetWindowSizeCallback(w, windowSizeCallback);
    return "Window callbacks set successfully.";
}
void stopGraphics(GLFWwindow* w)
{
    glfwDestroyWindow(w);
    glfwTerminate();
}
