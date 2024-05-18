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
    _EXPORT Sprite (Texture& theTexture,
            const glm::vec4& theTextureRect = { 0.f, 0.f, 1.f, 1.f });
    _EXPORT Sprite (Texture&   theTexture,
            const glm::vec2& theOrigin,
            const glm::vec2& theTranslation,
            const glm::vec2& theScale,
            const Angle&     theAngle,
            const glm::vec4& theTextureRect = { 0.f, 0.f, 1.f, 1.f });

    _EXPORT void draw (RenderManager& theRenderManager) override;

    _EXPORT glm::vec4 getTextureRect();

    _EXPORT void setTexture     (Texture& theTexture);
    _EXPORT void setTextureRect (const glm::vec4& theTextureRect);

    _EXPORT void setOrigin      (float theX, float theY) override;
    _EXPORT void setTranslation (float theX, float theY) override;
    _EXPORT void setScale       (float theX, float theY) override;
    _EXPORT void setRotation    (float theRadians, bool theCounterClockwise = true) override;

    _EXPORT void setOrigin      (const glm::vec2& theOrigin) override;
    _EXPORT void setTranslation (const glm::vec2& theTranslation) override;
    _EXPORT void setScale       (const glm::vec2& theScale) override;
    _EXPORT void setRotation    (const Angle&     theRotation) override;

private:
    
    void defaultInitialization ();

private:

    glm::vec4     myTexRect;        // relative rectangle
    BufferManager myDataStorage;
    Texture&      myTexture;
};

}

