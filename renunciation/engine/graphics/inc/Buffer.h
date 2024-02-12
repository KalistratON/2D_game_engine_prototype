#pragma once

#include <vector>

namespace engine {

class BufferManager;

class Buffer
{

public:

    Buffer (std::uint32_t theBufferType);

    void create (size_t theBufferSize, std::uint32_t theDrawMode);
    
    void replaceData (size_t theOffset, std::vector <float>          theData);
    void replaceData (size_t theOffset, std::vector <std::uint32_t>  theData);

    void bind();
    void unbind();

private:
    
    std::uint32_t myBufferID;

    size_t        myBufferSize = 0;
    std::uint32_t myDrawMode   = 0;
    std::uint32_t myBufferType = 0;

friend class BufferManager;
};

}
