//
// Created by Gabri on 12/10/2019.
//

#include "Tank.h"
void cube();

Tank::Tank() {

}

float Tank::getX() {
    return x;
}

float Tank::getY() {
    return y;
}

float Tank::getZ() {
    return z;
}

void Tank::showTank() {

    glPushMatrix();
    glTranslatef(x,y,z);
    glPushMatrix();
    glRotated(angleHorizontal,0,0,1);
    glScaled(4,3,1);
    cube();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,0,2);
    glRotated(angleCanon,0,0,1);
    glColor3f(1.0,0,1.0);
    cube();
    glTranslatef(-1,0,0);
    glRotated(-90,0,1,0);
    glColor3f(1.0,0,0);
    gluCylinder(gluNewQuadric(),0.3,0.3,4,20,20);
    glPopMatrix();
    glPopMatrix();

}

void Tank::moveTank(const Uint8 *state) {
    //keyboard
    if (state[SDL_SCANCODE_W]) {
        this->y -= distance * sin(this->angleHorizontal * M_PI / 180.0);
        this->x -= distance * cos(this->angleHorizontal * M_PI / 180.0);
    }
    if (state[SDL_SCANCODE_S]) {
        this->y += distance * sin(this->angleHorizontal * M_PI / 180.0);
        this->x += distance * cos(this->angleHorizontal * M_PI / 180.0);
    }
    if (state[SDL_SCANCODE_A]) {
        angleHorizontal+=4;
    }
    if (state[SDL_SCANCODE_D]) {
        angleHorizontal-=4;
    }
    if (state[SDL_SCANCODE_LEFT])
        angleCanon+=2;
    if (state[SDL_SCANCODE_RIGHT])
        angleCanon-=2;
    if (state[SDL_SCANCODE_SPACE])
        shoot();

    if (x < 5) {
        x = 5;
    }
    if (y < 5) {
        y = 5;
    }
    if (x > 95)
        x = 95;
    if (y > 95)
        y = 95;

}

void Tank::shoot() {
    bullets.push_back(new Bullet(this->x,this->y,this->z,angleCanon));
}

float Tank::getAngleHorizontal() const {
    return angleHorizontal;
}

void Tank::setX(float x) {
    Tank::x = x;
}

void Tank::setY(float y) {
    Tank::y = y;
}

void cube(){

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