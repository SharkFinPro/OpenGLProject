#ifndef OPENGLPROJECT_RENDERENGINE_H
#define OPENGLPROJECT_RENDERENGINE_H

#include "components/Window.h"
#include "components/Camera.h"
#include "components/ShaderManager.h"
#include "components/lighting/sources/LightSource.h"
#include "components/objects/Object.h"
#include <vector>
#include <memory>

class RenderEngine {
private:
    std::shared_ptr<Window> window;
    std::unique_ptr<Camera> camera;
    std::unique_ptr<ShaderManager> shaderManager;

    std::vector<std::pair<std::shared_ptr<Object>, int>> objects;

    std::shared_ptr<LightSource> lightSource;

    glm::vec3 skyColor;

    bool closing;

    void renderObject(const std::shared_ptr<Object>& object, int shaderKey);

public:
    RenderEngine();
    ~RenderEngine();

    void createWindow(int width, int height, const char* name, bool fullscreen = false);

    void createCamera(glm::vec3 position);

    void render();

    void loadShader(int key, const char* vertexShader, const char* fragmentShader);

    void loadObject(const std::shared_ptr<Object>& object, int shaderKey);

    void loadLightSource(const std::shared_ptr<LightSource> &source);

    [[nodiscard]] bool isClosing() const;

    void setSkyColor(glm::vec3 color);
};


#endif //OPENGLPROJECT_RENDERENGINE_H
