#include "../inc/Sprite.h"
#include "../inc/RenderManager.h"

#include <iostream>

using namespace engine;

void Sprite::defaultInitialization()
{
    const std::uint32_t aCountOfVerticesForRectangleSprite = 4;
    myDataStorage.create (aCountOfVerticesForRectangleSprite);
    
    myDataStorage.replaceData (0, std::vector <float> { 1.f, 1.f, 1.f, -1.f, -1.f, -1.f, -1.f, 1.f, // May be need to apply myTexRect
                                                        1.f, 1.f, 1.f,  0.f,  0.f,  0.f,  0.f, 1.f,
                                                        0.f, 0.f, 0.f, 1.f,
                                                        0.f, 0.f, 0.f, 1.f,
                                                        0.f, 0.f, 0.f, 1.f,
                                                        0.f, 0.f, 0.f, 1.f
                                                      });
    myDataStorage.replaceIndecies (0, std::vector <std::uint32_t> {0, 1, 3, 1, 2, 3});

    auto aTexSize = myTexture.getSize();
    auto aTexCoordMax = aTexSize.x > aTexSize.y ? aTexSize.x : aTexSize.y;
    myDataStorage.replaceData (0, std::vector <float> {  aTexSize.x / static_cast <float> (aTexCoordMax),
                                                         aTexSize.y / static_cast <float> (aTexCoordMax),
                                                         aTexSize.x / static_cast <float> (aTexCoordMax),
                                                        -aTexSize.y / static_cast <float> (aTexCoordMax),
                                                        -aTexSize.x / static_cast <float> (aTexCoordMax),
                                                        -aTexSize.y / static_cast <float> (aTexCoordMax),
                                                        -aTexSize.x / static_cast <float> (aTexCoordMax),
                                                         aTexSize.y / static_cast <float> (aTexCoordMax)
                                                      });
    myDataStorage.replaceData (sizeof(float) * 8, std::vector <float> { myTexRect.x + myTexRect.z,
                                                                        myTexRect.y + myTexRect.w,
                                                                        myTexRect.x + myTexRect.z,
                                                                        myTexRect.y,
                                                                        myTexRect.x,
                                                                        myTexRect.y,
                                                                        myTexRect.x,
                                                                        myTexRect.y + myTexRect.w
                                                                     });
}

Sprite::Sprite (Texture& theTexture,
                std::uint32_t theDrawMode,
                const glm::vec4& theTextureRect) :
    myDataStorage (theDrawMode),
    myTexture     (theTexture),
    myTexRect     (theTextureRect),
    Transformable::Transformable()
{
    defaultInitialization();
}

Sprite::Sprite (Texture&  theTexture,
                const glm::vec2& theOrigin,
                const glm::vec2& theTranslation,
                const glm::vec2& theScale,
                const Angle&     theAngle,
                std::uint32_t    theDrawMode,
                const glm::vec4& theTextureRect) :
    myDataStorage (theDrawMode),
    myTexture     (theTexture),
    myTexRect     (theTextureRect),
    Transformable::Transformable (theOrigin, theTranslation, theScale, theAngle)
{
    defaultInitialization();
}

void Sprite::draw (RenderManager& theRenderManager)
{
    myTexture.bind();
    
    auto aLeftDownPoint  = Transformable::TransformedPosition (glm::vec2 { -1.f, -1.f });
    auto aRightDownPoint = Transformable::TransformedPosition (glm::vec2 {  1.f, -1.f });
    auto aLeftUpPoint    = Transformable::TransformedPosition (glm::vec2 { -1.f,  1.f });
    auto aRightUpPoint   = Transformable::TransformedPosition (glm::vec2 {  1.f,  1.f });
    myDataStorage.replaceData (0, std::vector <float> { aRightUpPoint.x   ,
                                                        aRightUpPoint.y   ,
                                                        aRightDownPoint.x ,
                                                        aRightDownPoint.y ,
                                                        aLeftDownPoint.x  ,
                                                        aLeftDownPoint.y  ,
                                                        aLeftUpPoint.x    ,
                                                        aLeftUpPoint.y    ,
                                                      });
    myDataStorage.bind();
    theRenderManager.draw();
}

glm::vec4 Sprite::getTextureRect()
{
    return myTexRect;
}

void Sprite::setTexture (Texture& theTexture)
{
    myTexture = theTexture;
    // Need to update
}

void Sprite::setTextureRect (const glm::vec4& theTextureRect)
{
    myTexRect = theTextureRect;
    myDataStorage.replaceData (sizeof(float) * 8, std::vector <float> { myTexRect.x + myTexRect.z,
                                                                        myTexRect.y + myTexRect.w,
                                                                        myTexRect.x + myTexRect.z,
                                                                        myTexRect.y,
                                                                        myTexRect.x,
                                                                        myTexRect.y,
                                                                        myTexRect.x,
                                                                        myTexRect.y + myTexRect.w
                                                                     });
    // Need to update
}

void Sprite::setOrigin (float theX, float theY) 
{
    Transformable::setOrigin (theX, theY);
    // Need to update
}

void Sprite::setRotation (float theRadians, bool theCounterClockwise) 
{
    Transformable::setRotation (theRadians, theCounterClockwise);
    // Need to update
}

void Sprite::setTranslation (float theX, float theY) 
{
    Transformable::setTranslation (theX, theY);
    // Need to update
}

void Sprite::setScale (float theX, float theY) 
{
    Transformable::setScale (theX, theY);
    // Need to update
}

void Sprite::setOrigin (const glm::vec2& theOrigin) 
{
    Transformable::setOrigin (theOrigin);
    // Need to update
}

void Sprite::setRotation (const Angle& theRotation) 
{
    Transformable::setRotation (theRotation);
    // Need to update
}

void Sprite::setTranslation (const glm::vec2& theTranslation)
{
    Transformable::setTranslation (theTranslation);
    // Need to update
}

void Sprite::setScale (const glm::vec2& theScale)
{
    Transformable::setScale (theScale);
    // Need to update
}