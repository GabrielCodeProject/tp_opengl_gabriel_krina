//
// Created by Gabri on 12/10/2019.
//

#include "Bullet.h"
void affCube();

Bullet::Bullet(float xt, float yt, float zt, float angle) {
    this->xt = xt;
    this->yt = yt;
    this->zt = zt;
    this->angle = angle;
    isAlive = true;
}

void Bullet::show() {
    if (isAlive) {
        glPushMatrix();
        glTranslatef(x, y, z);
        glTranslatef(xt, yt, zt);
        glPushMatrix();
        glTranslatef(0, 0, 2);
        glRotated(angle, 0, 0, 1);
        glTranslatef(-5, 0, 0);
        gluSphere(gluNewQuadric(),1,20,20);
        glPopMatrix();
        glPopMatrix();
    }
}

void Bullet::move() {
    if (isAlive) {
        this->y -= distance * sin(this->angle * M_PI / 180.0);
        this->x -= distance * cos(this->angle * M_PI / 180.0);

        /*if (x < 5) {
            isAlive = false;
        }
        if (y < 5) {
            isAlive = false;
        }*/
        if (x > 95)
            isAlive = false;
        if (y > 95)
            isAlive = false;

    }


}


void affCube(){

    glBegin(GL_QUADS);

    //violette
    glColor3f(1.0,0,1.0);
    glVertex3f(-1,-1,-1);
    glVertex3f(-1,1,-1);
    glVertex3f(1,1,-1);
    glVertex3f(1,-1,-1);

    //jaune
    glColor3f(1.0,1.0,0);
    glVertex3f(-1,-1,-1);
    glVertex3f(-1,1,-1);
    glVertex3f(-1,1,1);
    glVertex3f(-1,-1,1);

    //vert
    glColor3f(0,1.0,0);
    glVertex3f(-1,-1,-1);
    glVertex3f(1,-1,-1);
    glVertex3f(1,-1,1);
    glVertex3f(-1,-1,1);

    //rouge
    glColor3f(1.0,0,0);
    glVertex3f(1,-1,-1);
    glVertex3f(1,1,-1);
    glVertex3f(1,1,1);
    glVertex3f(1,-1,1);

    //blue
    glColor3f(0,0,1.0);
    glVertex3f(1,1,-1);
    glVertex3f(-1,1,-1);
    glVertex3f(-1,1,1);
    glVertex3f(1,1,1);

    glColor3f(0,1.0,1.0);
    glVertex3f(-1,-1,1);
    glVertex3f(-1,1,1);
    glVertex3f(1,1,1);
    glVertex3f(1,-1,1);

    glEnd();

}