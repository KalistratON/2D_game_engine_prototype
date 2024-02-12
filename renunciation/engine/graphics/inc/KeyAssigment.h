#pragma once

#include <GLFW/glfw3.h>

namespace engine {

namespace settings {

enum KEY_ASSIGMENT {
    
    STAND   = -2,
    WALK    = -1,
    RUN     = GLFW_KEY_LEFT_SHIFT,
    
    FULL    = GLFW_KEY_W,
    SIT     = GLFW_KEY_S,

    JUMP    = GLFW_KEY_SPACE,

    LEFT    = GLFW_KEY_A,
    RIGHT   = GLFW_KEY_D,

    HIT     = GLFW_MOUSE_BUTTON_LEFT

};

};

}
