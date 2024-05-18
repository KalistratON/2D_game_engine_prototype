#include "../inc/Transformable.h"

#include <glm-all/gtx/matrix_transform_2d.hpp>

#include <cmath>


using namespace engine;

Transformable::Transformable (const glm::vec2& theOrigin) :
    myOrigin (theOrigin)
{}

Transformable::Transformable (const glm::vec2& theOrigin,
                              const glm::vec2& theTranslation,
                              const glm::vec2& theScale,
                              const Angle&     theRotation) :
    myOrigin      (theOrigin),
    myTranslation (theTranslation),
    myScale       (theScale),
    myRotation    (theRotation)
{}

void Transformable::setOrigin (float theX, float theY)
{
    myOrigin.x = theX;
    myOrigin.y = theY;
}

void Transformable::setRotation (float theRadians, bool theCounterClockwise)
{
    myRotation.radian = theRadians;
    myRotation.counterclockwise = theCounterClockwise;
}

void Transformable::setTranslation (float theX, float theY)
{
    myTranslation.x = theX;
    myTranslation.y = theY;
}

void Transformable::setScale (float theX, float theY)
{
    myScale.x = theX;
    myScale.y = theY;
}

void Transformable::setOrigin (const glm::vec2& theOrigin)
{
    myOrigin.x = theOrigin.x;
    myOrigin.y = theOrigin.y;
}

void Transformable::setRotation (const Angle& theRotation)
{
    myRotation.radian = theRotation.radian;
    myRotation.counterclockwise = theRotation.counterclockwise;
}

void Transformable::setTranslation (const glm::vec2& theTranslation)
{
    myTranslation.x = theTranslation.x;
    myTranslation.y = theTranslation.y;
}

void Transformable::setScale (const glm::vec2& theScale)
{
    myScale.x = theScale.x;
    myScale.y = theScale.y;
}

const glm::vec2& Transformable::getOrigin() const
{
    return myOrigin;
}

const Angle& Transformable::getRotation() const
{
    return myRotation;
}

const glm::vec2& Transformable::getTranslation() const
{
    return myTranslation;
}

const glm::vec2& Transformable::getScale() const
{
    return myScale;
}

glm::vec2 Transformable::TransformedPosition (const glm::vec2& thePoint) const
{
    glm::vec2 aCenter (thePoint + myOrigin);
    glm::vec2 aTranformedPosition (thePoint + myOrigin);
    
    float anAngle = myRotation.counterclockwise ? myRotation.radian : -myRotation.radian;
    aTranformedPosition.x = aCenter.x * myScale.x * std::cos (anAngle) -
                            aCenter.y * myScale.y * std::sin (anAngle) + myTranslation.x;
    aTranformedPosition.y = aCenter.x * myScale.x * std::sin (anAngle) +
                            aCenter.y * myScale.y * std::cos (anAngle) + myTranslation.y;
    return aTranformedPosition;
}

glm::mat3 Transformable::TransformedMatrix (const glm::vec2& thePoint) const
{
    glm::mat3 aModel = glm::mat3 (1.0f);
    aModel = glm::translate (aModel, thePoint + myOrigin);
    
    float anAngle = myRotation.counterclockwise ? myRotation.radian : -myRotation.radian;
    aModel = glm::scale (aModel, myScale);
    aModel = glm::rotate (aModel, anAngle);
    aModel = glm::translate (aModel, myTranslation);
    return aModel;
}