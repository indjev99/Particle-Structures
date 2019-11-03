#ifndef WINDOW_FUNCTIONS_H_INCLUDED
#define WINDOW_FUNCTIONS_H_INCLUDED

#include<string>
#include<GLFW/glfw3.h>

extern double mxpos;
extern double mypos;
extern int pressed;

std::string setErrorCallback();
std::string initializeGLFW();
std::string createWindow(GLFWwindow*& w);
std::string setWindowCallbacks(GLFWwindow* w);
void stopGraphics(GLFWwindow* w);

#endif //WINDOW_FUNCTIONS_H_INCLUDED
