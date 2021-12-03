#include "RenderEngine.h"
#include "scenes/AssimpScene.h"
#include <memory>

int main()
{
    /* Create Engine */
    auto engine = std::make_shared<RenderEngine>(true);

    AssimpScene scene(engine);

    /* Render Loop */
    while (!engine->shouldClose())
    {
        scene.update();

        engine->render();
    }
}