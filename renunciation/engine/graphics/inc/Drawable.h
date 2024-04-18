#pragma once

#include "Base_Helper.h"

namespace engine {

class RenderManager;

class Drawable
{
public:
    _GRAPHICS_EXPORT virtual void draw (RenderManager& theRenderManager) = 0;
};

}

