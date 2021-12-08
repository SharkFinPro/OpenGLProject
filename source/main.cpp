#include "RenderEngine.h"
#include "scenes/LightingScene.h"
#include <memory>

int main()
{
    /* Create Engine */
    auto engine = std::make_shared<RenderEngine>();

    LightingScene scene(engine);

    /* Render Loop */
    while (!engine->isClosing())
    {
        scene.update();

        engine->render();
    }
}