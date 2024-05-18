#include "../inc/glCheckError.h"

#include <GL/glew.h>

#include <iostream>
#include <string>


void engine::_glCheckError_(const char* theFileName, unsigned int theLineNumber)
{
    GLenum anErrorCode;
    while ((anErrorCode = glGetError()) != GL_NO_ERROR)
    {
        std::string anError;
        switch (anErrorCode)
        {
        case GL_INVALID_ENUM:                  anError = "INVALID_ENUM";                    break;
        case GL_INVALID_VALUE:                 anError = "INVALID_VALUE";                   break;
        case GL_INVALID_OPERATION:             anError = "INVALID_OPERATION";               break;
        case GL_STACK_OVERFLOW:                anError = "STACK_OVERFLOW";                  break;
        case GL_STACK_UNDERFLOW:               anError = "STACK_UNDERFLOW";                 break;
        case GL_OUT_OF_MEMORY:                 anError = "OUT_OF_MEMORY";                   break;
        case GL_INVALID_FRAMEBUFFER_OPERATION: anError = "INVALID_FRAMEBUFFER_OPERATION";   break;
        }
        std::cout << anError << " | " << theFileName << " (" << theLineNumber << ")" << std::endl;
    }
}



