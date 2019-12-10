//
// Created by Gabri on 12/10/2019.
//

#ifndef TP_OPENGL_SKYBOX_H
#define TP_OPENGL_SKYBOX_H

#include <SDL2/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "../utils/MyTexture.h"
#include <iomanip>


class Skybox {
public:
    //MyTexture* idTexture;

    MyTexture texture;

    Skybox(std::string path);
    void afficherCube();
};


#endif //FIRST3D_SKYBOX_H
