#include <source/RenderEngine.h>
#include "LightingScene.h"
#include <memory>

int main()
{
    /* Create Engine */
    auto engine = std::make_shared<Engine::RenderEngine>();

    LightingScene scene(engine);

    /* Render Loop */
    while (!engine->isClosing())
        engine->render();
}