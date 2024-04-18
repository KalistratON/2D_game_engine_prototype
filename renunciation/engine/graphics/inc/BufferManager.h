#pragma once

#include "Base_Helper.h"
#include "Buffer.h"

#include <GL/glew.h>

namespace engine {

class BufferManager
{
public:
    
    _GRAPHICS_EXPORT BufferManager (std::uint32_t theDrawMode);

    _GRAPHICS_EXPORT bool create (size_t theVertexCount);
    _GRAPHICS_EXPORT void bind();

    _GRAPHICS_EXPORT void replaceData     (size_t theOffset,
                          std::vector <float> theData);
    _GRAPHICS_EXPORT void replaceIndecies (size_t theOffset,
                          std::vector <std::uint32_t> theIndecies);

private:

    std::uint32_t myVertexxArrayID = 0;
    std::uint32_t myBufferDrawMode;

    Buffer myArrayBuffer   = Buffer (GL_ARRAY_BUFFER);
    Buffer myElementBuffer = Buffer (GL_ELEMENT_ARRAY_BUFFER);
};

};

