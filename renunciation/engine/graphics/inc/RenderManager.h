#pragma once

#include "Base_Helper.h"

#include <glm-all/ext/vector_float4.hpp>

namespace engine {

class Drawable;
class GameObject;

class RenderManager
{

public:

    _GRAPHICS_EXPORT RenderManager();
    _GRAPHICS_EXPORT void clear (const glm::vec4& theColor);
    _GRAPHICS_EXPORT void draw  (Drawable& theEntity);
    _GRAPHICS_EXPORT void draw  (GameObject& theEntity);
    _GRAPHICS_EXPORT void draw  ();
};

}

