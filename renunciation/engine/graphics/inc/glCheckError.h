#pragma once

namespace engine {

void _glCheckError_(const char* theFileName, unsigned int theLineNumber);

#define glCheckError(expression) expression; _glCheckError_(__FILE__, __LINE__);

}

