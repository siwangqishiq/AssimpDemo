/**
 * @file 
 * 
 * main.cpp
 * 
 * Assimp library (ver: 5.4.3)
 * 
 * 
 */

#include <iostream>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

struct Vertex{
    float pos1;
    int index;
    short test;
};

void LoadModel(const std::string &path){
    Assimp::Importer importer;
    const aiScene* scene = importer.ReadFile(path , aiProcess_Triangulate | aiProcess_FlipUVs);
    if(scene == nullptr 
        || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE == 1 
        || scene->mRootNode == nullptr){
        std::cerr << "open model file Failed :" << importer.GetErrorString() <<std::endl;
        return;
    }

    std::cout << "Open Success!" <<std::endl;

    std::cout << "Mesh Count : " << scene->mNumMeshes << std::endl;
    std::cout << "Material Count : " << scene->mNumMaterials << std::endl;
    std::cout << "Texture Count : " << scene->mNumTextures << std::endl;
    std::cout << "Camera Count : " << scene->mNumCameras << std::endl;

    aiNode* rootNode = scene->mRootNode;
    std::cout << "child Node Count: " << rootNode->mNumChildren << std::endl;
}

int main(){
    std::cout << "Test Assimp Library version: 5.4.3\n";
    std::cout << offsetof(Vertex, pos1) << std::endl;
    std::cout << offsetof(Vertex, index) << std::endl;
    std::cout << offsetof(Vertex, test) << std::endl;
    LoadModel("E:/assets/model/mario/source/mario_mp10/Mario.FBX");
    return 0;
}


