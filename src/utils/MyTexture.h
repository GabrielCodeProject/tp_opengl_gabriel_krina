//
// Created by Gabri on 12/10/2019.
//

#ifndef TP_OPENGL_MYTEXTURE_H
#define TP_OPENGL_MYTEXTURE_H


#include <iostream>
#include "../opengl_util.h"
#include <vector>

class MyTexture {
public:
    GLuint idTexture;

    GLuint getTexture();

    MyTexture(std::string path);
    // MyTexture(std::string texturePath);
    // GLuint loadTextures(std::string texturePath);

};

#endif //TP_OPENGL_MYTEXTURE_H
