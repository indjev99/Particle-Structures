//IUPAC Name Generator

#include "../headers/window_functions.h"
#include "../headers/run.h"

#include<iostream>
#include<conio.h>
#include<stdlib.h>

GLFWwindow *window;

int main()
{
    system("cls");

    std::string message;

    message=setErrorCallback();
    std::cerr<<message<<std::endl;
    if (message!="GLFW error callback set successfully.") return -1;

    message=initializeGLFW();
    std::cerr<<message<<std::endl;
    if (message!="GLFW initialized successfully.") return -1;

    message=createWindow(window);
    std::cerr<<message<<std::endl;
    if (message!="Window created successfully.") return -1;

    message=setWindowCallbacks(window);
    std::cerr<<message<<std::endl;
    if (message!="Window callbacks set successfully.") return -1;

    system("cls");
    run(window);

    stopGraphics(window);

    return 0;
}
