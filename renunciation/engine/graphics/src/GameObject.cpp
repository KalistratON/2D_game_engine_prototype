#include "../inc/GameObject.h"
#include "../inc/RenderManager.h"

using namespace engine;

void GameObject::draw (RenderManager& theRenderManager)
{
    mySprite.draw (theRenderManager);
}
