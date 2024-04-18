#pragma once

#include "Base_Helper.h"
#include "Shader.h"
#include "Sprite.h"

#include <glm-all/glm.hpp>


namespace engine {

class GameObject
{

public:

    _GRAPHICS_EXPORT GameObject (Shader& theShader,
                const Sprite& theSprite) :
        myShader     (theShader),
        mySprite     (theSprite)
    {};
    _GRAPHICS_EXPORT void draw (RenderManager& theRenderManager);

private:

    Shader&       myShader;
    Sprite       mySprite;

    std::uint32_t myDrawMode;

    friend class CharacterController;
};

};

