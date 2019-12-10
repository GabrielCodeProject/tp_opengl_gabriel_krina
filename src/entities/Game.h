//
// Created by Gabri on 12/10/2019.
//

#ifndef TP_OPENGL_GAME_H
#define TP_OPENGL_GAME_H

#include <SDL2/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "../utils/Path.h"
#include "Skybox.h"
#include "Tank.h"
#include "Gamepad.h"

//#include "../utils/opengl_util.h"

class Game {
private:
    SDL_Window *win;
    SDL_GLContext context;
    Tank* tank;
    Path texturePath;
    Skybox* skybox;
    Gamepad* controller;
    int width = 800, height = 600;
    bool isRunning = true;
    void initGame();
    void loopGame();
    void clean();
public:
    Game();
    virtual ~Game();
    void startGame();
};



#endif //TP_OPENGL_GAME_H
