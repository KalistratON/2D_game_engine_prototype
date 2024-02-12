#pragma once

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
    Transformable (const glm::vec2& theOrigin = { 0.f, 0.f });
    Transformable (const glm::vec2& theOrigin,
                   const glm::vec2& theTranslation,
                   const glm::vec2& theScale,
                   const Angle&     theAngle);

    virtual void setOrigin      (float theX, float theY);
    virtual void setTranslation (float theX, float theY);
    virtual void setScale       (float theX, float theY);
    virtual void setRotation    (float theRadians, bool theCounterClockwise = true);

    virtual void setOrigin      (const glm::vec2& theOrigin);
    virtual void setTranslation (const glm::vec2& theTranslation);
    virtual void setScale       (const glm::vec2& theScale);
    virtual void setRotation    (const Angle&     theRotation);

    const glm::vec2& getOrigin()      const;
    const glm::vec2& getTranslation() const;
    const glm::vec2& getScale()       const;
    const Angle&     getRotation()    const;

    glm::vec2 TransformedPosition (const glm::vec2& thePoint = { .0f, .0f }) const;
    glm::mat3 TransformedMatrix   (const glm::vec2& thePoint = {.0f, .0f}) const;

private:
    glm::vec2 myOrigin      = glm::vec2 (0.0f);
    glm::vec2 myTranslation = glm::vec2 (0.0f);
    glm::vec2 myScale       = glm::vec2 (1.0f);
    Angle     myRotation;
};

}

