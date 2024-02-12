#pragma once

#include "BufferManager.h"
#include "Drawable.h"
#include "Texture.h"
#include "Transformable.h"

#include <glm-all/ext/vector_float2.hpp>
#include <glm-all/ext/vector_float4.hpp>


namespace engine {

class Sprite : public Drawable, public Transformable
{

public:
    
    Sprite (Texture&         theTexture,
            std::uint32_t    theDrawMode,
            const glm::vec4& theTextureRect = { 0.f, 0.f, 1.f, 1.f });
    Sprite (      Texture&   theTexture,
            const glm::vec2& theOrigin,
            const glm::vec2& theTranslation,
            const glm::vec2& theScale,
            const Angle&     theAngle,
            std::uint32_t    theDrawMode,
            const glm::vec4& theTextureRect = { 0.f, 0.f, 1.f, 1.f });

    void draw (RenderManager& theRenderManager) override;

    glm::vec4 getTextureRect();

    void setTexture     (Texture& theTexture);
    void setTextureRect (const glm::vec4& theTextureRect);

    void setOrigin      (float theX, float theY) override;
    void setTranslation (float theX, float theY) override;
    void setScale       (float theX, float theY) override;
    void setRotation    (float theRadians, bool theCounterClockwise = true) override;

    void setOrigin      (const glm::vec2& theOrigin) override;
    void setTranslation (const glm::vec2& theTranslation) override;
    void setScale       (const glm::vec2& theScale) override;
    void setRotation    (const Angle&     theRotation) override;

private:
    
    void defaultInitialization ();

private:

    glm::vec4     myTexRect;        // relative rectangle
    BufferManager myDataStorage;
    Texture&      myTexture;
};

}

