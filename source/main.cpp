#include "RenderEngine.h"
#include "scenes/Scene1.h"
#include <memory>

int main()
{
    /* Create Engine */
    auto engine = std::make_shared<RenderEngine>(true);

    Scene1 scene1(engine);

    /* Render Loop */
    while (!engine->shouldClose())
    {
        scene1.update();

        engine->render();
    }
}