#pragma once

#include "Base_Helper.h"
#include <glm-all/ext/vector_int2.hpp>
#include <string>

namespace engine {

class Texture
{

public:

    _GRAPHICS_EXPORT Texture() = default;

    _GRAPHICS_EXPORT void create (const glm::ivec2&  theTextureSize);
    _GRAPHICS_EXPORT void create (const std::string& theFileName);

    _GRAPHICS_EXPORT void update (const std::uint8_t* thePixels, 
                 const glm::ivec2&   theLeftUpCorner,
                 const glm::ivec2&   theOffset);

    _GRAPHICS_EXPORT void generateMipMaps();
    _GRAPHICS_EXPORT void setRepeat (bool theIsRepeat);

    _GRAPHICS_EXPORT const glm::ivec2& getSize ();
    
    _GRAPHICS_EXPORT void bind();
    _GRAPHICS_EXPORT static void bind (std::uint32_t theID);

private:

    glm::ivec2     mySize;
    
    std::uint32_t  myTextureID;       
    
    bool           myIsSmooth     = true;        
    bool           myIsRepeated   = false;
    bool           myHasMipmap    = false;
    bool           mySourceIsRGBA = true;
};

}

