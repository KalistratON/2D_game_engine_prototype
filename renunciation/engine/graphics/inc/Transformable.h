#pragma once

#include "Base_Helper.h"
#include <glm-all/gtx/matrix_transform_2d.hpp>
#include <glm-all/ext/vector_float2.hpp>

namespace engine {

struct Angle {
    float radian = .0f;
    bool counterclockwise = true;
};

class Transformable
{
    
public:
    _GRAPHICS_EXPORT Transformable (const glm::vec2& theOrigin = { 0.f, 0.f });
    _GRAPHICS_EXPORT Transformable (const glm::vec2& theOrigin,
                   const glm::vec2& theTranslation,
                   const glm::vec2& theScale,
                   const Angle&     theAngle);

    _GRAPHICS_EXPORT virtual void setOrigin      (float theX, float theY);
    _GRAPHICS_EXPORT virtual void setTranslation (float theX, float theY);
    _GRAPHICS_EXPORT virtual void setScale       (float theX, float theY);
    _GRAPHICS_EXPORT virtual void setRotation    (float theRadians, bool theCounterClockwise = true);

    _GRAPHICS_EXPORT virtual void setOrigin      (const glm::vec2& theOrigin);
    _GRAPHICS_EXPORT virtual void setTranslation (const glm::vec2& theTranslation);
    _GRAPHICS_EXPORT virtual void setScale       (const glm::vec2& theScale);
    _GRAPHICS_EXPORT virtual void setRotation    (const Angle&     theRotation);

    _GRAPHICS_EXPORT const glm::vec2& getOrigin()      const;
    _GRAPHICS_EXPORT const glm::vec2& getTranslation() const;
    _GRAPHICS_EXPORT const glm::vec2& getScale()       const;
    _GRAPHICS_EXPORT const Angle&     getRotation()    const;

    _GRAPHICS_EXPORT glm::vec2 TransformedPosition (const glm::vec2& thePoint = { .0f, .0f }) const;
    _GRAPHICS_EXPORT glm::mat3 TransformedMatrix   (const glm::vec2& thePoint = {.0f, .0f}) const;

private:
    glm::vec2 myOrigin      = glm::vec2 (0.0f);
    glm::vec2 myTranslation = glm::vec2 (0.0f);
    glm::vec2 myScale       = glm::vec2 (1.0f);
    Angle     myRotation;
};

}

