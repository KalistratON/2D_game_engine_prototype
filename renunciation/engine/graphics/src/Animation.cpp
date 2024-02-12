#include "../inc/Animation.h"

using namespace engine;

Animation::Animation (size_t theWidth, size_t theHeight) :
    myWidth (theWidth),
    myHeight (theHeight)
{}

glm::vec4 Animation::next (float theDeltaTime)
{
    myAccumulateTime += theDeltaTime;
    if (myAccumulateTime >= myFrameRate) {
        myCurXFrame = myCurXFrame + 1 <= myWidth - 1 ? myCurXFrame + 1 : 0;
        myAccumulateTime = 0.0f;
    }
    
    float aXOfsset = 1.0f / myWidth;
    float aYOffset = 1.0f / myHeight;

    float aX = myCurXFrame * aXOfsset;
    float aY = myCurYFrame * aYOffset;

    return glm::vec4 (aX, aY, aXOfsset, aYOffset);
}

glm::vec4 Animation::swap (float theDeltaTime)
{
    myAccumulateTime = 0.0f;
    myCurYFrame = myCurYFrame + 1 <= myHeight - 1 ? myCurYFrame + 1 : 0;

    float aXOfsset = 1.0f / myWidth;
    float aYOffset = 1.0f / myHeight;

    float aX = myCurXFrame * aXOfsset;
    float aY = myCurYFrame * aYOffset;

    return glm::vec4 (aX, aY, aXOfsset, aYOffset);
}
