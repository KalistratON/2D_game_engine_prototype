#pragma once

#include "Base_Helper.h"

#include <glm-all/ext/vector_float4.hpp>

namespace engine {

class Drawable;

class RenderManager
{
public:
    _EXPORT RenderManager();
    _EXPORT void clear (const glm::vec4& theColor);
    _EXPORT void draw  (Drawable& theEntity);
    _EXPORT void draw  ();
};

}

