//
// Created by Gabri on 12/10/2019.
//

#ifndef TP_OPENGL_TANK_H
#define TP_OPENGL_TANK_H


#include <SDL2/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <iostream>
#include <vector>
#include "Bullet.h"
//#include "../utils/opengl_util.h"


class Tank {
private :
    float x = 20, y = 20, z = 2;

    float angleHorizontal = 0;
    float distance = 1.0;
public:
    float getAngleHorizontal() const;

    void setX(float x);

    void setY(float y);

private:
    float largeur = 4;
public :

    float angleCanon = 0;
    std::vector<Bullet*> bullets;

    Tank();
    float getX();
    float getY();
    float getZ();
    void showTank();
    void moveTank(const Uint8 *state);
    void shoot();

};




#endif //TP_OPENGL_TANK_H
