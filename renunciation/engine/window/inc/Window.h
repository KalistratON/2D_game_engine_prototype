#pragma once

#include <GLFW/glfw3.h>

#include <cstdint>

class Window
{

public:

    Window (std::int32_t theWidth, std::int32_t theHeight);
    ~Window();

    GLFWwindow* data();

    bool shouldClose();
    void swapBuffers();

private:

    GLFWwindow* myWindow = nullptr;

    std::uint16_t myWidth   = 640;
    std::uint16_t myHeight  = 480;

};

