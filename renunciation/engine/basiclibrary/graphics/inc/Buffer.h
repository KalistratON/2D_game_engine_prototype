#pragma once

#include "Base_Helper.h"

#include <vector>

namespace engine {

class BufferManager;

class Buffer
{
public:
    _EXPORT Buffer (std::uint32_t theBufferType);

    _EXPORT void create (size_t theBufferSize, std::uint32_t theDrawMode);
    
    _EXPORT void replaceData (size_t theOffset, std::vector <float>          theData);
    _EXPORT void replaceData (size_t theOffset, std::vector <std::uint32_t>  theData);

    _EXPORT void bind();
    _EXPORT void unbind();

private:
    
    std::uint32_t myBufferID;

    size_t        myBufferSize = 0;
    std::uint32_t myDrawMode   = 0;
    std::uint32_t myBufferType = 0;

friend class BufferManager;
};

}
