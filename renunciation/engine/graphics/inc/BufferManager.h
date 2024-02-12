#pragma once

#include "Buffer.h"

#include <GL/glew.h>

namespace engine {

class BufferManager
{
public:
    
    BufferManager (std::uint32_t theDrawMode);

    bool create (size_t theVertexCount);
    void bind();

    void replaceData     (size_t theOffset,
                          std::vector <float> theData);
    void replaceIndecies (size_t theOffset,
                          std::vector <std::uint32_t> theIndecies);

private:

    std::uint32_t myVertexxArrayID = 0;
    std::uint32_t myBufferDrawMode;

    Buffer myArrayBuffer   = Buffer (GL_ARRAY_BUFFER);
    Buffer myElementBuffer = Buffer (GL_ELEMENT_ARRAY_BUFFER);
};

};

