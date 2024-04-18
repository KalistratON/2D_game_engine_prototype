#pragma once

#include "Base_Helper.h"

#include <vector>

namespace engine {

class BufferManager;

class Buffer
{

public:

    _GRAPHICS_EXPORT Buffer (std::uint32_t theBufferType);

    _GRAPHICS_EXPORT void create (size_t theBufferSize, std::uint32_t theDrawMode);
    
    _GRAPHICS_EXPORT void replaceData (size_t theOffset, std::vector <float>          theData);
    _GRAPHICS_EXPORT void replaceData (size_t theOffset, std::vector <std::uint32_t>  theData);

    _GRAPHICS_EXPORT void bind();
    _GRAPHICS_EXPORT void unbind();

private:
    
    std::uint32_t myBufferID;

    size_t        myBufferSize = 0;
    std::uint32_t myDrawMode   = 0;
    std::uint32_t myBufferType = 0;

friend class BufferManager;
};

}
