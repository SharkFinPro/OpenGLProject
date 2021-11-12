#ifndef OPENGLPROJECT_RENDERENGINE_H
#define OPENGLPROJECT_RENDERENGINE_H

#include "components/Window.h"
#include "components/Camera.h"

#include "components/objects/Object.h"

class RenderEngine {
private:
    Window* window;
    Camera* camera;

    glm::vec3 lightPosition = glm::vec3(1.2f, 1.0f, -1.0f);
    glm::vec3 lightColor = glm::vec3(1.0f, 1.0f, 1.0f);

    void loadLightData(ShaderProgram* shaderProgram) const;

public:
    RenderEngine();
    ~RenderEngine();

    [[nodiscard]] bool windowShouldClose();
    void updateWindow();

    void render(Object* object, ShaderProgram* shaderProgram);
    void renderLight(Object* object, ShaderProgram* shaderProgram);

    void processInput();
};


#endif //OPENGLPROJECT_RENDERENGINE_H
