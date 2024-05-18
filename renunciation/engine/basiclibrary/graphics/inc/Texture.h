#pragma once

#include "Base_Helper.h"
#include <glm-all/ext/vector_int2.hpp>
#include <string>

namespace engine {

class Texture
{
public:
    _EXPORT Texture() = default;

    _EXPORT void create (const glm::ivec2&  theTextureSize);
    _EXPORT void create (const std::string& theFileName);

    _EXPORT void update (const std::uint8_t* thePixels, 
                 const glm::ivec2&   theLeftUpCorner,
                 const glm::ivec2&   theOffset);

    _EXPORT void generateMipMaps();
    _EXPORT void setRepeat (bool theIsRepeat);

    _EXPORT const glm::ivec2& getSize ();
    
    _EXPORT void bind();
    _EXPORT static void bind (std::uint32_t theID);

private:

    glm::ivec2     mySize;
    
    std::uint32_t  myTextureID;       
    
    bool           myIsSmooth     = true;        
    bool           myIsRepeated   = false;
    bool           myHasMipmap    = false;
    bool           mySourceIsRGBA = true;
};

}

