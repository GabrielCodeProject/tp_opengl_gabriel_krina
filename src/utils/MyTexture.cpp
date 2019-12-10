//
// Created by Gabri on 12/10/2019.
//

#include "MyTexture.h"
MyTexture::MyTexture(std::string path){
    this->idTexture = loadTexture(path.c_str());
}

//GLuint MyTexture::loadTextures(std::string texturePath) {
//    this->idTexture = loadTexture(texturePath.c_str());
//    return idTexture;
//}

GLuint MyTexture::getTexture() {
    return idTexture;
}