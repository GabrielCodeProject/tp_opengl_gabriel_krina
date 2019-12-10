//
// Created by Gabri on 12/10/2019.
//

#include "Skybox.h"

Skybox::Skybox(std::string path) : texture(path) { //list dinitialisation
// idTexture = new MyTexture(path);
}

void Skybox::afficherCube() {

    glBindTexture(GL_TEXTURE_2D, texture.getTexture());
    glBegin(GL_QUADS);

    glColor3f(1.0, 1.0, 1.0);
    //bas
    glTexCoord2f(0.25,0.33); glVertex3f(0, 0, 1);
    glTexCoord2f(0.25,0); glVertex3f(100, 0, 1);
    glTexCoord2f(0.5,0); glVertex3f(100, 100, 1);
    glTexCoord2f(0.5,0.33); glVertex3f(0, 100, 1);

    //leftside
    glTexCoord2f(0.25,0.33);    glVertex3f(0,0,0);
    glTexCoord2f(0.5,0.66);      glVertex3f(0,0,100);
    glTexCoord2f(0,0.66);        glVertex3f(100,0,100);
    glTexCoord2f(0,0.33);       glVertex3f(100,0,0);

    //back
    glTexCoord2f(0.75,0.33); glVertex3f(0,0,0);
    glTexCoord2f(1,0.33); glVertex3f(0,100,0);
    glTexCoord2f(1,0.66); glVertex3f(0,100,100);
    glTexCoord2f(0.75,0.66); glVertex3f(0,0,100);

    //right
    glTexCoord2f(0.75,0.33); glVertex3f(0,100,0);
    glTexCoord2f(1,0.33); glVertex3f(100,100,0);
    glTexCoord2f(1,0.66); glVertex3f(100,100,100);
    glTexCoord2f(0.75,0.66); glVertex3f(0,100,100);

    //face
    glTexCoord2f(0.25,0.33);    glVertex3f(100,0,0);
    glTexCoord2f(0.5,0.33);     glVertex3f(100,100,0);
    glTexCoord2f(0.5,0.66);     glVertex3f(100,100,100);
    glTexCoord2f(0.25,0.66);    glVertex3f(100,0,100);

    //top
    glTexCoord2f(0.25,1);       glVertex3f(0,0,100);
    glTexCoord2f(0.25,0.66);    glVertex3f(100,0,100);
    glTexCoord2f(0.5,0.66);     glVertex3f(100,100,100);
    glTexCoord2f(0.5,1);        glVertex3f(0,100,100);
    glEnd();
}


