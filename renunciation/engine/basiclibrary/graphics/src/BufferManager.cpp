#include "../inc/glCheckError.h"
#include "../inc/BufferManager.h"

using namespace engine;

static void update (size_t theVertexOffset,
                    size_t theTextureOffset,
                    size_t theColorOffset)
{
    glCheckError (glVertexAttribPointer (0,
                                         2,
                                         GL_FLOAT,
                                         GL_FALSE,
                                         2 * sizeof (float),
                                         reinterpret_cast <void*> (theVertexOffset)));
    glCheckError (glEnableVertexAttribArray (0));

    glCheckError (glVertexAttribPointer (1,
                                         2,
                                         GL_FLOAT,
                                         GL_FALSE,
                                         2 * sizeof (float),
                                         reinterpret_cast <void*> (theTextureOffset)));
    glCheckError (glEnableVertexAttribArray (1));

    glCheckError (glVertexAttribPointer (2,
                                         4,
                                         GL_FLOAT,
                                         GL_FALSE,
                                         4 * sizeof (float),
                                         reinterpret_cast <void*> (theColorOffset)));
    glCheckError (glEnableVertexAttribArray (2));
}

BufferManager::BufferManager (std::uint32_t theDrawMode) : myBufferDrawMode(theDrawMode)
{}

void BufferManager::bind()
{
    glCheckError (glBindVertexArray (myVertexxArrayID));
}

bool BufferManager::create (size_t theVertexCount)
{
    if (myVertexxArrayID) {
        return false;
    }

    glCheckError (glGenVertexArrays (1, &myVertexxArrayID));
    bind();

    const unsigned aCountOfCoordForVertex  = 2;
    const unsigned aCountOfCoordForTexture = 2;
    const unsigned aCountOfCoordForColor   = 4;
    myArrayBuffer.create (theVertexCount * sizeof (float) * (  aCountOfCoordForVertex 
                                                             + aCountOfCoordForTexture 
                                                             + aCountOfCoordForColor), 
                          myBufferDrawMode);
    std::uint32_t aCountIndecies = 6;
    myElementBuffer.create (aCountIndecies * sizeof (std::uint32_t), myBufferDrawMode);
    update(0, myArrayBuffer.myBufferSize / 4, myArrayBuffer.myBufferSize / 2);
    return true;
}

void BufferManager::replaceData (size_t theOffset,
                                 std::vector <float> theData)
{
    bind();
    myArrayBuffer.bind();
    myArrayBuffer.replaceData (theOffset, theData);
    update (0, myArrayBuffer.myBufferSize / 4, myArrayBuffer.myBufferSize / 2);
}

void BufferManager::replaceIndecies (size_t theOffset,
                                     std::vector <std::uint32_t> theIndecies)
{
    bind();
    myElementBuffer.bind();
    myElementBuffer.replaceData (theOffset, theIndecies);
    update (0, myArrayBuffer.myBufferSize / 4, myArrayBuffer.myBufferSize / 2);
    // Стоит ли обновлять VertexArrayBuffer - ?
}

