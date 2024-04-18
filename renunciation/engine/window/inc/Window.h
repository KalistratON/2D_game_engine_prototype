#pragma once

#include "Base_Helper.h"

#include <GLFW/glfw3.h>

#include <cstdint>

class Window
{

public:

    _WINDOW_EXPORT Window (std::int32_t theWidth, std::int32_t theHeight);
    _WINDOW_EXPORT ~Window();

    _WINDOW_EXPORT GLFWwindow* data();

    _WINDOW_EXPORT bool shouldClose();
    _WINDOW_EXPORT void swapBuffers();

private:

    GLFWwindow* myWindow = nullptr;

    std::uint16_t myWidth   = 640;
    std::uint16_t myHeight  = 480;

};

