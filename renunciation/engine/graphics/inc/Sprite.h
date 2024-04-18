#pragma once

#include "Base_Helper.h"
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
    
    _GRAPHICS_EXPORT Sprite (Texture&         theTexture,
            std::uint32_t    theDrawMode,
            const glm::vec4& theTextureRect = { 0.f, 0.f, 1.f, 1.f });
    _GRAPHICS_EXPORT Sprite (      Texture&   theTexture,
            const glm::vec2& theOrigin,
            const glm::vec2& theTranslation,
            const glm::vec2& theScale,
            const Angle&     theAngle,
            std::uint32_t    theDrawMode,
            const glm::vec4& theTextureRect = { 0.f, 0.f, 1.f, 1.f });

    _GRAPHICS_EXPORT void draw (RenderManager& theRenderManager) override;

    _GRAPHICS_EXPORT glm::vec4 getTextureRect();

    _GRAPHICS_EXPORT void setTexture     (Texture& theTexture);
    _GRAPHICS_EXPORT void setTextureRect (const glm::vec4& theTextureRect);

    _GRAPHICS_EXPORT void setOrigin      (float theX, float theY) override;
    _GRAPHICS_EXPORT void setTranslation (float theX, float theY) override;
    _GRAPHICS_EXPORT void setScale       (float theX, float theY) override;
    _GRAPHICS_EXPORT void setRotation    (float theRadians, bool theCounterClockwise = true) override;

    _GRAPHICS_EXPORT void setOrigin      (const glm::vec2& theOrigin) override;
    _GRAPHICS_EXPORT void setTranslation (const glm::vec2& theTranslation) override;
    _GRAPHICS_EXPORT void setScale       (const glm::vec2& theScale) override;
    _GRAPHICS_EXPORT void setRotation    (const Angle&     theRotation) override;

private:
    
    void defaultInitialization ();

private:

    glm::vec4     myTexRect;        // relative rectangle
    BufferManager myDataStorage;
    Texture&      myTexture;
};

}

