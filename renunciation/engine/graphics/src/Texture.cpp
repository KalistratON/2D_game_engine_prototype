#include "../inc/glCheckError.h"
#include "../inc/Texture.h"

#include <GL/glew.h>

#define STB_IMAGE_IMPLEMENTATION
#include "../inc/stb_image.h"

using namespace engine;

static std::uint8_t* loadTexture (const std::string& theFileName, 
                                  glm::ivec2&        theTextureSize,
                                  bool&              theIsRGBA)
{
    int anAlpha;
    auto* aData = stbi_load (theFileName.c_str(),
                             &theTextureSize.x,
                             &theTextureSize.y,
                             &anAlpha,
                             0);
    if (!aData) {
        return nullptr;
    }
    theIsRGBA = static_cast <bool> (anAlpha - 3);
    return aData;
}

static void setParameters (bool theIsSmooth)
{
    glCheckError (glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER));
    glCheckError (glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER));
    glCheckError (glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, theIsSmooth ? GL_LINEAR : GL_NEAREST));
    glCheckError (glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, theIsSmooth ? GL_LINEAR : GL_NEAREST));
}

void Texture::bind()
{
    glCheckError (glBindTexture (GL_TEXTURE_2D, static_cast <GLuint> (myTextureID)));
}

void Texture::bind(std::uint32_t theID)
{
    glCheckError (glBindTexture (GL_TEXTURE_2D, static_cast <GLuint> (theID)));
}

void Texture::create (const glm::ivec2& theTextureSize)
{
    mySize = theTextureSize;

    glCheckError (glGenTextures (1, &myTextureID));
    bind (myTextureID);

    setParameters(myIsSmooth);

    glCheckError (glTexImage2D (GL_TEXTURE_2D,
                                0,
                                GL_RGBA,
                                static_cast <GLuint> (theTextureSize.x),
                                static_cast <GLuint> (theTextureSize.y),
                                0,
                                GL_RGBA,
                                GL_UNSIGNED_BYTE,
                                0));
}

void Texture::update (const std::uint8_t* thePixels,
                      const glm::ivec2&   theLeftUpCorner,
                      const glm::ivec2&   theOffset)
{
    bind (myTextureID);
    glCheckError (glTextureSubImage2D (myTextureID,
                                       0, 
                                       static_cast <GLint> (theLeftUpCorner.x * mySize.x),
                                       static_cast <GLint> (theLeftUpCorner.y * mySize.y),
                                       static_cast <GLint> (theOffset.x  * mySize.x),
                                       static_cast <GLint> (theOffset.y  * mySize.y),
                                       GL_RGB + mySourceIsRGBA,
                                       GL_UNSIGNED_BYTE,
                                       (void*) thePixels));
}

void Texture::create (const std::string& theFileName) 
{
    stbi_set_flip_vertically_on_load(true);

    auto* aData = loadTexture(theFileName, mySize, mySourceIsRGBA);
    if (!aData) {
        return;
    }

    create (mySize);
    update (aData, { 0., 0. }, {1.0, 1.0});
    stbi_image_free (aData);
}

void Texture::generateMipMaps()
{
    bind (myTextureID);
    glCheckError (glGenerateMipmap (GL_TEXTURE_2D));
    myHasMipmap = true;
    glCheckError (glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, myIsSmooth ? 
                                   GL_LINEAR_MIPMAP_LINEAR : GL_NEAREST_MIPMAP_LINEAR));
}

void Texture::setRepeat (bool theIsRepeated)
{
    myIsRepeated = theIsRepeated;

    glCheckError (glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, myIsRepeated ? GL_REPEAT : GL_CLAMP_TO_BORDER));
    glCheckError (glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, myIsRepeated ? GL_REPEAT : GL_CLAMP_TO_BORDER));
}

const glm::ivec2& Texture::getSize()
{
    return mySize;
}