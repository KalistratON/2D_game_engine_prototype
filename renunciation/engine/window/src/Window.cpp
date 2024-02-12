#include <GL/glew.h>

#include "../inc/Window.h"

#include <cstdlib>

Window::Window (std::int32_t theWidth, std::int32_t theHeight) :
    myWidth  (theWidth),
    myHeight (theHeight)
{
    if (!glfwInit()) {
        std::exit (-1);
    }
    
    glfwWindowHint (GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint (GLFW_CONTEXT_VERSION_MINOR, 4);
    glfwWindowHint (GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint (GLFW_RESIZABLE, GL_TRUE);

    myWindow = glfwCreateWindow (theWidth, theHeight, "Game", NULL, NULL);
    if (!myWindow) {
        glfwTerminate();
        std::exit (-1);
    }
    glfwMakeContextCurrent (myWindow);

    glewExperimental = GL_TRUE;
    glewInit();

    glfwGetFramebufferSize (myWindow, &theWidth, &theHeight);
    glViewport (0, 0, theWidth, theHeight);
}

Window::~Window()
{
    glfwTerminate();
}

bool Window::shouldClose()
{
    return glfwWindowShouldClose (myWindow);
}

GLFWwindow* Window::data()
{
    return myWindow;
}

void Window::swapBuffers()
{
    glfwSwapBuffers (myWindow);
    glfwPollEvents();
}