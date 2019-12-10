//
// Created by Gabri on 12/10/2019.
//

#ifndef TP_OPENGL_GAMEPAD_H
#define TP_OPENGL_GAMEPAD_H


#include <SDL2/SDL_joystick.h>
#include <SDL2/SDL.h>

class Gamepad {
public:
    bool init();
    void loadJoystick();
    void close();
    const int DEAD_ZONE = 1000;

    SDL_Joystick* gGameController = NULL;

    const int A = 0;
    const int B = 1;
    const int X = 2;
    const int Y = 3;
    const int LT = 4;
    const int RT = 5;
};


#endif //TP_OPENGL_GAMEPAD_H
