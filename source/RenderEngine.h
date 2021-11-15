#ifndef OPENGLPROJECT_RENDERENGINE_H
#define OPENGLPROJECT_RENDERENGINE_H

#include "components/Window.h"
#include "components/Camera.h"
#include "components/objects/Object.h"
#include "components/ShaderManager.h"

class RenderEngine {
private:
    Window* window;
    Camera* camera;
    ShaderManager* shaderManager;

    glm::vec3 lightPosition = glm::vec3(1.2f, 1.0f, -1.0f);
    glm::vec3 lightColor = glm::vec3(1.0f, 1.0f, 1.0f);

    void loadLightData(const ShaderProgram* shaderProgram) const;

public:
    RenderEngine();
    ~RenderEngine();

    [[nodiscard]] bool windowShouldClose();
    void updateWindow();

    void render(Object* object, int shaderKey);
    void renderLight(Object* object, int shaderKey);

    void processInput();

    void loadShader(int key, const char* vertexShader, const char* fragmentShader);
};


#endif //OPENGLPROJECT_RENDERENGINE_H
