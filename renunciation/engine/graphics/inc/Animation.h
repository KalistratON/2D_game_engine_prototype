#pragma once

#include <glm-all/ext/vector_float4.hpp>

namespace engine {

class Animation
{

public:

    Animation (size_t theWidth, size_t theHeight);
    glm::vec4 next (float theDeltaTime);
    glm::vec4 swap (float theDeltaTime);

private:

    size_t myWidth  = 1;
    size_t myHeight = 1;

    size_t myCurXFrame = 0;
    size_t myCurYFrame = 0;

    float  myX = 0.0f;
    float  myY = 0.0f;

    double myAccumulateTime  = 0.0f;
    const double myFrameRate = 0.125f;
};

}

