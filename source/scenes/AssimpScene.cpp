#include "AssimpScene.h"

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include <stdexcept>
#include <string>

AssimpScene::AssimpScene(std::shared_ptr<RenderEngine> engine)
        : renderEngine(std::move(engine))
{
    /* load model with assimp */
    Assimp::Importer importer;
    const aiScene* scene = importer.ReadFile("assets/objects/cube.obj", aiProcess_Triangulate | aiProcess_GenSmoothNormals | aiProcess_FlipUVs | aiProcess_CalcTangentSpace);

    // Check for errors
    if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode)
    {
        throw std::runtime_error("ERROR::ASSIMP:: " + std::string(importer.GetErrorString()));
    }

    // Read mesh data
    aiMesh* mesh = scene->mMeshes[scene->mRootNode->mChildren[0]->mMeshes[0]];

    std::vector<float> vertices;
    std::vector<unsigned int> indices;

    for (unsigned int i = 0; i < mesh->mNumVertices; i++)
    {
        vertices.push_back(mesh->mVertices[i].x);
        vertices.push_back(mesh->mVertices[i].y);
        vertices.push_back(mesh->mVertices[i].z);

        vertices.push_back(mesh->mNormals[i].x);
        vertices.push_back(mesh->mNormals[i].y);
        vertices.push_back(mesh->mNormals[i].z);
    }

    for (unsigned int i = 0; i < mesh->mNumFaces; i++)
    {
        aiFace face = mesh->mFaces[i];
        for(unsigned int j = 0; j < face.mNumIndices; j++)
        {
            indices.push_back(face.mIndices[j]);
        }
    }

    cubeVAO = std::make_shared<VAO>(true, true);
    cubeVAO->loadVBO(vertices.data(), static_cast<int>(vertices.size() * sizeof(float)), vertices.size());
    cubeVAO->loadEBO(indices.data(), static_cast<int>(indices.size() * sizeof(unsigned int)), indices.size());
    // positions
    cubeVAO->addAttribute(0, 3, 6, 0);
    // normals
    cubeVAO->addAttribute(1, 3, 6, 3);

    // Load Shaders
    renderEngine->loadShader(0, "assets/shaders/cube/cube.vert", "assets/shaders/cube/cube.frag");
    renderEngine->loadShader(1, "assets/shaders/light objects/light.vert", "assets/shaders/light objects/light.frag");

    /* Create Graphics */
    LightMaterial cubeMaterial = { 0.4f, 0.75f, 0.5f, 32.0f};
    cube = std::make_shared<Object>(cubeMaterial, cubeVAO, glm::vec3(0, 0, 0), glm::vec3(0.9f, 0.5f, 0.75f));
    cube2 = std::make_shared<Object>(cubeMaterial, cubeVAO, glm::vec3(-3, 1, 0), glm::vec3(0.2f, 0.5f, 0.75f));

    LightMaterial lightCubeMaterial = { 0.4f, 0.75f, 1.0f, 0.0f};
    lightCube = std::make_shared<LightSource>(cubeVAO, lightCubeMaterial, glm::vec3(1.2f, 1.0f, -1.0f), glm::vec3(1.0f, 1.0f, 1.0f));

    // Load Objects
    renderEngine->loadObject(cube, 0);
    renderEngine->loadObject(cube2, 0);
    renderEngine->loadLight(lightCube, 1);
}

void AssimpScene::update()
{}