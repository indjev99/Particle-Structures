#include "../headers/window_size.h"
#include "../headers/window_functions.h"
#include "../headers/draw.h"

#include<iostream>
#include<GLFW/glfw3.h>

double mxpos=0;
double mypos=0;
int pressed=0;

void error_callback(int error, const char* description)
{
    std::cerr<<error<<": "<<description<<std::endl;
}
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) glfwSetWindowShouldClose(window, 1);
    if (key == GLFW_KEY_SPACE && action == GLFW_PRESS) pressed = 1;
}
void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
    if (action == GLFW_PRESS)
    {
        pressed = button;
        glfwGetCursorPos(window, &mxpos, &mypos);
        mxpos = mxpos * 2 - WINDOWS_WIDTH;
        mypos = -mypos * 2 + WINDOWS_HEIGHT;
        mxpos /= ORIGINAL_WINDOWS_HEIGHT;
        mypos /= ORIGINAL_WINDOWS_HEIGHT;
    }
}
void window_size_callback(GLFWwindow* window, int width, int height)
{
    WINDOWS_WIDTH = width;
    WINDOWS_HEIGHT = height;
}
std::string setErrorCallback()
{
    glfwSetErrorCallback(error_callback);
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
    w = glfwCreateWindow(WINDOWS_WIDTH, WINDOWS_HEIGHT, "Particles", NULL, NULL);
    if (!w)
        return "Unable to open window.";
    return "Window created successfully.";
}
std::string setWindowCallbacks(GLFWwindow* w)
{
    glfwSetKeyCallback(w, key_callback);
    glfwSetMouseButtonCallback(w, mouse_button_callback);
    glfwSetWindowSizeCallback(w, window_size_callback);
    return "Window callbacks set successfully.";
}
void stopGraphics(GLFWwindow* w)
{
    glfwDestroyWindow(w);
    glfwTerminate();
}
