#include "FileIO.h"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

namespace Engine::helpers {
    void fileToString(const char *path, std::string &output)
    {
        std::ifstream file(path);
        std::stringstream outputStream;

        outputStream << file.rdbuf();

        output = outputStream.str();
    }

    std::shared_ptr<VAO> loadModel(const char *path)
    {
        /* Load model with assimp */
        Assimp::Importer importer;
        const aiScene *scene = importer.ReadFile(path, aiProcess_Triangulate | aiProcess_GenSmoothNormals | aiProcess_FlipUVs | aiProcess_CalcTangentSpace);

        // Check for errors
        if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode)
            throw std::runtime_error("Assimp Error: " + std::string(importer.GetErrorString()));

        // Read mesh data
        std::vector<float> vertices;
        std::vector<unsigned int> indices;

        aiMesh *mesh = scene->mMeshes[0];

        for (unsigned int i = 0; i < mesh->mNumVertices; i++)
        {
            vertices.push_back(mesh->mVertices[i].x);
            vertices.push_back(mesh->mVertices[i].y);
            vertices.push_back(mesh->mVertices[i].z);

            vertices.push_back(mesh->mNormals[i].x);
            vertices.push_back(mesh->mNormals[i].y);
            vertices.push_back(mesh->mNormals[i].z);

            if (mesh->mTextureCoords[0])
            {
                vertices.push_back(mesh->mTextureCoords[0][i].x);
                vertices.push_back(mesh->mTextureCoords[0][i].y);
            }
        }

        for (unsigned int i = 0; i < mesh->mNumFaces; i++)
        {
            aiFace face = mesh->mFaces[i];
            for (unsigned int j = 0; j < face.mNumIndices; j++)
                indices.push_back(face.mIndices[j]);
        }

        /* Create VAO */
        auto vao = std::make_shared<VAO>(true, true);
        vao->loadVBO(vertices.data(), static_cast<int>(vertices.size() * sizeof(float)), vertices.size());
        vao->loadEBO(indices.data(), static_cast<int>(indices.size() * sizeof(unsigned int)), indices.size());

        // Positions
        vao->addAttribute(0, 3, 8, 0);

        // Normals
        vao->addAttribute(1, 3, 8, 3);

        // Texture Coordinates
        vao->addAttribute(2, 2, 8, 6);

        return vao;
    }
}