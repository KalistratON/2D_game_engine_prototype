#pragma once

#include "Animation.h"
#include "GameObject.h"
#include "OpenGL.h"

#include <glm-all/ext/vector_float2.hpp>
#include <glm-all/ext/vector_uint2.hpp>

#include <memory>


namespace engine {

class CharacterController
{
    // Input
    

private:

    void jump    (float theDeltaTime);
    void sitDown (float theDeltaTime);

    void moveUp   (float theDeltaTime);
    void moveLeft (float theDeltaTime);

    void hit (float theDeltaTime);
    
    void stand (float theDeltaTime);
    void run   (float theDeltaTime);
    void walk  (float theDeltaTime);

    void cameraTransform();

public:

    CharacterController (GameObject& theGameObject, 
                         const glm::uvec2& theCountAnimation);
    void update (GLFWwindow* window, float theDeltaTime);

private:
    
    GameObject& myObject;
    
    Animation myAnimation      = { 1, 1};
    glm::vec2 myCameraPosition = glm::vec2 (0.0f);

    float myVelocity = 0.0f;

    float myUpScale     = 1.f;
    float myLeftScale   = 1.f;

    bool IsLeft = true;
    bool IsUp   = true;
    bool IsJump = true;

    const float walkVelocity = 0.25f;
    const float runVelocity  = 0.50f;
};

}

