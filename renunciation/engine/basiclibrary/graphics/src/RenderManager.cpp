#include "../inc/Drawable.h"
#include "../inc/glCheckError.h"
#include "../inc/RenderManager.h"

#include <GL/glew.h>

using namespace engine;

RenderManager::RenderManager()
{
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void RenderManager::clear (const glm::vec4& theColor)
{
    glEnable (GL_BLEND);
    glCheckError (glClearColor (theColor.r, theColor.g, theColor.b, theColor.a));
    glCheckError (glClear (GL_COLOR_BUFFER_BIT));
}

void RenderManager::draw (Drawable& theEntity)
{
    theEntity.draw (*this);
}

void RenderManager::draw ()
{
    glCheckError (glDrawElements (GL_TRIANGLE_FAN, 6, GL_UNSIGNED_INT, 0));
}
