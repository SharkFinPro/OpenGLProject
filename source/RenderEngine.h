#ifndef OPENGLPROJECT_RENDERENGINE_H
#define OPENGLPROJECT_RENDERENGINE_H

#include "components/Window.h"
#include "components/Camera.h"
#include "components/objects/Object.h"
#include "components/ShaderManager.h"
#include <vector>
#include <memory>

class RenderEngine {
private:
    std::shared_ptr<Window> window;
    std::unique_ptr<Camera> camera;
    std::unique_ptr<ShaderManager> shaderManager;

    std::vector<std::pair<std::shared_ptr<Object>, int>> objects;
    std::vector<std::pair<std::shared_ptr<Object>, int>> lights;

    glm::vec3 lightPosition = glm::vec3(1.2f, 1.0f, -1.0f);
    glm::vec3 lightColor = glm::vec3(1.0f, 1.0f, 1.0f);
    glm::vec3 skyColor = glm::vec3(0.2f, 0.2f, 0.2f);

    void loadLightData(std::shared_ptr<ShaderProgram> shaderProgram) const;

    void renderObject(std::shared_ptr<Object> object, int shaderKey) const;
    void renderLight(std::shared_ptr<Object> object, int shaderKey) const;

public:
    RenderEngine();
    ~RenderEngine();

    void render();

    void loadShader(int key, const char* vertexShader, const char* fragmentShader);

    void loadObject(std::shared_ptr<Object> object, int shaderKey);
    void loadLight(std::shared_ptr<Object> object, int shaderKey);
};


#endif //OPENGLPROJECT_RENDERENGINE_H
