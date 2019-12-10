//
// Created by Gabri on 12/10/2019.
//

#ifndef TP_OPENGL_BULLET_H
#define TP_OPENGL_BULLET_H


#include <SDL2/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <iostream>

class Bullet {
private:
    float x = 0, y = 0, z = 0;
    float xt,yt,zt;
    float angle;
    float distance = 2.0;
    bool isAlive;
    GLUquadric* quad;

public :

    Bullet(float xt, float yt, float zt, float angle);
    void show();
    void move();

};



#endif //TP_OPENGL_BULLET_H
