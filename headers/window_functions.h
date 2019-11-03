#ifndef WINDOW_FUNCTIONS_H_INCLUDED
#define WINDOW_FUNCTIONS_H_INCLUDED

#include "vec2d.h"

#include <string>
#include <GLFW/glfw3.h>

extern int keyPress;
extern int mouseClick;
extern Vec2D mousePos;

std::string setErrorCallback();
std::string initializeGLFW();
std::string createWindow(GLFWwindow*& w);
std::string setWindowCallbacks(GLFWwindow* w);
void stopGraphics(GLFWwindow* w);

#endif //WINDOW_FUNCTIONS_H_INCLUDED
