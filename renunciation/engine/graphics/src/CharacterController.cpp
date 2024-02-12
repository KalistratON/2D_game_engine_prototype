#include "../inc/CharacterController.h"
#include "../inc/KeyAssigment.h"


using namespace engine;

CharacterController::CharacterController (GameObject& theGameObject, 
                                          const glm::uvec2& theCountAnimation) :
    myObject (theGameObject),
    myAnimation ( { theCountAnimation.x, theCountAnimation.y } )
{}

void CharacterController::jump (float theDeltaTime)
{
    
}

void CharacterController::sitDown (float theDeltaTime)
{

}

void CharacterController::moveUp   (float theDeltaTime)
{

}

void CharacterController::moveLeft (float theDeltaTime)
{
    // Change Texture
    auto aTextRect = myAnimation.next (theDeltaTime);
    myObject.mySprite.setTextureRect (aTextRect);

    // Change Position
    auto aCurrentTranslation = myObject.mySprite.getTranslation();
    aCurrentTranslation.x += myLeftScale * myVelocity * theDeltaTime;
    myObject.mySprite.setTranslation (aCurrentTranslation);
}

void CharacterController::hit (float theDeltaTime)
{

}

void CharacterController::stand (float theDeltaTime)
{
    myVelocity = 0.0f;
}

void CharacterController::walk (float theDeltaTime)
{
    myVelocity = walkVelocity;
}

void CharacterController::run (float theDeltaTime)
{
    myVelocity = runVelocity;
}

void CharacterController::cameraTransform()
{
    glm::vec2 aTranslation = myObject.mySprite.getTranslation();

    glm::mat3 aCameraTransform = glm::translate (glm::mat3 (1.0f), -aTranslation);
    
    //glm::mat3 aCameraTransform = glm::mat3 (1.0f);
    myObject.myShader.setM3 ("ViewMatrix", aCameraTransform);
    myObject.myShader.useProgram();
}

void CharacterController::update (GLFWwindow* window, float theDeltaTime)
{
    const int aFull  = glfwGetKey (window, settings::KEY_ASSIGMENT::FULL);
    const int aHit   = glfwGetKey (window, settings::KEY_ASSIGMENT::HIT);
    const int aJump  = glfwGetKey (window, settings::KEY_ASSIGMENT::JUMP);
    const int aLeft  = glfwGetKey (window, settings::KEY_ASSIGMENT::LEFT);
    const int aRight = glfwGetKey (window, settings::KEY_ASSIGMENT::RIGHT);
    const int aRun   = glfwGetKey (window, settings::KEY_ASSIGMENT::RUN);
    const int aSit   = glfwGetKey (window, settings::KEY_ASSIGMENT::SIT);
    const int aStand = glfwGetKey (window, settings::KEY_ASSIGMENT::STAND);
    const int aWalk  = glfwGetKey (window, settings::KEY_ASSIGMENT::WALK);

    if (aFull == GLFW_PRESS) {
    
    }
    if (aHit == GLFW_PRESS) {

    }
    if (aJump == GLFW_PRESS) {
        
    }
    if (aStand == GLFW_PRESS) {
        stand (theDeltaTime);
    }
    if (aLeft == GLFW_PRESS) {
        
        myLeftScale = -1.0f;
        if (!IsLeft) {
            myAnimation.swap (theDeltaTime);
            IsLeft = true;
        }

       if (aRun   == GLFW_PRESS) {
            run (theDeltaTime);
       } else {
            walk (theDeltaTime);
       }

        moveLeft (theDeltaTime);
        cameraTransform();
    }
    if (aRight == GLFW_PRESS) {
        
        myLeftScale = 1.0f;
        if (IsLeft) {
            myAnimation.swap (theDeltaTime);
            IsLeft = false;
        }

        if (aRun   == GLFW_PRESS) {
            run (theDeltaTime);
       } else {
            walk (theDeltaTime);
       }

        moveLeft (theDeltaTime);
        cameraTransform();
    }
    if (aSit   == GLFW_PRESS) {

    }
}


