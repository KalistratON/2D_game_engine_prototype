#pragma once

#include "Shader.h"
#include "Sprite.h"

#include <glm-all/glm.hpp>


namespace engine {

class GameObject
{

public:

    GameObject (Shader& theShader,
                const Sprite& theSprite) :
        myShader     (theShader),
        mySprite     (theSprite)
    {};
    void draw (RenderManager& theRenderManager);

private:

    Shader&       myShader;
    Sprite       mySprite;

    std::uint32_t myDrawMode;

    friend class CharacterController;
};

};

