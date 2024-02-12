#include "../inc/glCheckError.h"
#include "../inc/Shader.h"

#include <GL/glew.h>
#include <glm-all/gtc/type_ptr.hpp>

#include <iostream>
#include <fstream>
#include <sstream>

using namespace engine;

static std::string ReadFile (const char* thePath)
{
    std::string aSource;
    std::ifstream aFile;

    aFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try {
        aFile.open(thePath);
        std::stringstream aStream;
        aStream << aFile.rdbuf();
        aFile.close();
        aSource = aStream.str();
    }
    catch (std::ifstream::failure e) {
        std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ : " << e.what() <<  std::endl;
    }
    return aSource;
}

void Shader::compileShader (std::int32_t theShaderType, const char* theSource)
{
    GLuint aShader = glCreateShader(theShaderType);

    glCheckError (glShaderSource(aShader, 1, &theSource, NULL));
    glCheckError (glCompileShader(aShader));

    GLint aSuccessIndicator = 1;
    GLchar anInfoLog[512];
    *anInfoLog = '\0';
    glCheckError (glGetShaderiv (aShader, GL_COMPILE_STATUS, &aSuccessIndicator));
    if (aSuccessIndicator) {
        myShaders.push_back(aShader);
    }
    else {
        glCheckError (glGetShaderInfoLog(aShader, 512, NULL, anInfoLog));
        std::cerr << "Shader_ID : " << theShaderType << " - " <<anInfoLog << std::endl;
    }        
}

bool Shader::linkShader()
{
    myID = glCreateProgram();
    for (const auto& shader : myShaders) {
        glCheckError (glAttachShader(myID, shader));
    }
    glCheckError (glLinkProgram(myID));

    GLint aSuccessIndicator = 1;
    GLchar anInfoLog[512];
    *anInfoLog = '\0';
    glCheckError (glGetProgramiv(myID, GL_LINK_STATUS, &aSuccessIndicator));

    if (!aSuccessIndicator) {
        glCheckError (glGetProgramInfoLog(myID, 512, NULL, anInfoLog));
        std::cerr << "LINK ERROR : " << anInfoLog << std::endl;
        return GL_FALSE;
    }

    for (auto& shader : myShaders) {
        glCheckError (glDeleteShader(shader));
    }
    myShaders.clear();
    return GL_TRUE;
}

Shader::Shader (const std::vector<std::int32_t>& theTypeList, const std::vector<const char*>& thePathList)
{
    if (theTypeList.size() == thePathList.size()) {
        for (size_t i = 0; i < theTypeList.size(); ++i) {
            auto aSource = ReadFile(thePathList.at(i));
            compileShader(theTypeList.at(i), aSource.c_str());
        }
    }
    if (!linkShader()) {
        throw std::exception ("LINK ERROR");
    }
}

void Shader::setBool  (const char* theName, bool value) const
{
    glCheckError (glUniform1i (glGetUniformLocation(myID, theName), static_cast<int>(value)));
}
void Shader::setInt   (const char* theName, int value) const
{
    glCheckError (glUniform1i (glGetUniformLocation(myID, theName), value));
}
void Shader::setFloat (const char* theName, float value) const
{
    glCheckError (glUniform1i (glGetUniformLocation(myID, theName), value));
}

void Shader::useProgram() const
{
    glCheckError (glUseProgram (myID));
}

void Shader::setV2 (const char* theName, const glm::vec2 theV2) const
{
    glCheckError (glUniform2f (glGetUniformLocation (myID, theName), theV2.x, theV2.y));
}

void Shader::setV3 (const char* theName, const glm::vec3 theV3) const
{
    glCheckError (glUniform3f (glGetUniformLocation (myID, theName), theV3.x, theV3.y, theV3.z));
}

void Shader::setV4 (const char* theName, const glm::vec4 theV4) const
{
    glCheckError (glUniform4f (glGetUniformLocation (myID, theName), theV4.x, theV4.y, theV4.z, theV4.w));
}

void Shader::setM3(const char* theName, const glm::mat3 theM3) const
{
    glCheckError (glUniformMatrix3fv (glGetUniformLocation (myID, theName), 1, GL_FALSE, glm::value_ptr (theM3)));
}

void Shader::setM4(const char* theName, const glm::mat4 theM4) const
{
    glCheckError (glUniformMatrix4fv (glGetUniformLocation (myID, theName), 1, GL_FALSE, glm::value_ptr(theM4)));
}
