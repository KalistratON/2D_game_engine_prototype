#pragma once

namespace engine {

class RenderManager;

class Drawable
{
public:
    virtual void draw (RenderManager& theRenderManager) = 0;
};

}

