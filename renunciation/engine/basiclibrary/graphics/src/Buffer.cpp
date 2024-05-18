#include "../inc/glCheckError.h"
#include "../inc/Buffer.h"

#include <GL/glew.h>

using namespace engine;

Buffer::Buffer (std::uint32_t theBufferType) : myBufferType (theBufferType)
{}

void Buffer::bind()
{
    glCheckError (glBindBuffer(myBufferType, myBufferID));
}

void Buffer::create (size_t theBufferSize, std::uint32_t theDrawMode)
{
    myBufferSize = theBufferSize;
    myDrawMode   = theDrawMode;

    glCheckError (glGenBuffers (1, &myBufferID));
    bind();

    glCheckError (glBufferData (myBufferType, myBufferSize, 0, myDrawMode));
}

void Buffer::unbind()
{
    glCheckError (glBindBuffer (myBufferType, 0));
}

void Buffer::replaceData (size_t theOffset, std::vector <float> theData)
{
    bind();
    glCheckError (glBufferSubData (myBufferType, theOffset, sizeof (float) * theData.size(), theData.data()));
}

void Buffer::replaceData (size_t theOffset, std::vector <std::uint32_t> theData)
{
    bind();
    glCheckError (glBufferSubData (myBufferType, theOffset, sizeof(std::uint32_t) * theData.size(), theData.data()));
}

