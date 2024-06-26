#pragma once

#include "Base_Helper.h"

#include <glm-all/glm.hpp>

#include <vector>


namespace engine {

class Shader
{
private:
    void compileShader (std::int32_t theShaderType,
                        const char*  theSource);
    bool linkShader();

public:
    _EXPORT Shader (const char* theVertexShader, const char* theFragmentShader);

    _EXPORT void setBool  (const char* theName, bool  value) const;
    _EXPORT void setInt   (const char* theName, int   value) const;
    _EXPORT void setFloat (const char* theName, float value) const;
    _EXPORT void setV2    (const char* theName, const glm::vec2 theV2) const;
    _EXPORT void setV3    (const char* theName, const glm::vec3 theV3) const;
    _EXPORT void setV4    (const char* theName, const glm::vec4 theV4) const;
    _EXPORT void setM3    (const char* theName, const glm::mat3 theM3) const;
    _EXPORT void setM4    (const char* theName, const glm::mat4 theM4) const;

    _EXPORT void useProgram() const;

private:

    std::int32_t               myID;
    std::vector<std::uint32_t> myShaders;
};

};

