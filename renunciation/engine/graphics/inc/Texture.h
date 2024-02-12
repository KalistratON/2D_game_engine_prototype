#pragma once

#include <glm-all/ext/vector_int2.hpp>
#include <string>

namespace engine {

class Texture
{

public:

    Texture() = default;

    void create (const glm::ivec2&  theTextureSize);
    void create (const std::string& theFileName);

    void update (const std::uint8_t* thePixels, 
                 const glm::ivec2&   theLeftUpCorner,
                 const glm::ivec2&   theOffset);

    void generateMipMaps();
    void setRepeat (bool theIsRepeat);

    const glm::ivec2& getSize ();
    
    void bind();
    static void bind (std::uint32_t theID);

private:

    glm::ivec2     mySize;
    
    std::uint32_t  myTextureID;       
    
    bool           myIsSmooth     = true;        
    bool           myIsRepeated   = false;
    bool           myHasMipmap    = false;
    bool           mySourceIsRGBA = true;
};

}

