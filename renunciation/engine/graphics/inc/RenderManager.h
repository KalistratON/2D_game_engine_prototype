#pragma once

#include <glm-all/ext/vector_float4.hpp>

namespace engine {

class Drawable;
class GameObject;

class RenderManager
{

public:

    RenderManager();
    void clear (const glm::vec4& theColor);
    void draw  (Drawable& theEntity);
    void draw  (GameObject& theEntity);
    void draw  ();
};

}

