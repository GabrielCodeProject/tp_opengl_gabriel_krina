//
// Created by Gabri on 12/10/2019.
//

#include "Game.h"

void sleep(Uint32 dt);


Game::Game() {

    SDL_Init(SDL_INIT_VIDEO);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
    win = SDL_CreateWindow("OpenGl Test", SDL_WINDOWPOS_CENTERED,
                           SDL_WINDOWPOS_CENTERED, width, height,
                           SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
    context = SDL_GL_CreateContext(win);
    SDL_GL_SetSwapInterval(1);
    glEnable(GL_DEPTH_TEST);


}

Game::~Game() {
}


void Game::startGame() {
    initGame();
    loopGame();
    clean();
}

void Game::initGame() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(70, (double) width / height, 1, 1000);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glEnable(GL_TEXTURE_2D);
    controller = new Gamepad();
    controller->init();
    controller->loadJoystick();
    skybox = new Skybox(texturePath.skyboxPath);
    tank = new Tank();

}

void Game::loopGame() {
    int touche = 0;
    SDL_Event event;
    gluLookAt(100, 100, 50, 50, 50, 0, 0, 0, 1);
    const Uint8 *state = nullptr;
//   Uint32 start;
    //Normalized direction
    int xDir = 0;
    int yDir = 0;
    while (isRunning) {
        Uint32 start = SDL_GetTicks();
//        start = SDL_GetTicks();
        glClearColor(0.f, 0.f, 0.f, 1.f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        SDL_PollEvent(&event);

        state = SDL_GetKeyboardState(NULL);
        if (event.type == SDL_QUIT) {
            isRunning = false;
        }
        if (event.type == SDL_JOYAXISMOTION) {
            //Motion on controller 0
            if (event.jaxis.which == 0) {
                //X axis motion
                if (event.jaxis.axis == 0) {
                    //Left of dead zone
                    if (event.jaxis.value < -controller->DEAD_ZONE) {
                        xDir = -1;
                        // std::cout << xDir << std::endl;
                    }
                        //Right of dead zone
                    else if (event.jaxis.value > controller->DEAD_ZONE)//to change
                    {
                        xDir = 1;
                    } else {
                        xDir = 0;
                    }
                }
                    //Y axis motion
                else if (event.jaxis.axis == 1) {
                    //Below of dead zone
                    if (event.jaxis.value < -controller->DEAD_ZONE) {
                        yDir = -1;
                        float y = tank->getY();
                        y -= 1.0 * sin(tank->getAngleHorizontal() * M_PI / 180.0);
                        float x = tank->getX();
                        x -= 1.0 * cos(tank->getAngleHorizontal() * M_PI / 180.0);
                        tank->setY(y);
                        tank->setX(x);


                        // this->y -= distance * sin(this->angleHorizontal * M_PI / 180.0);
                        // this->x -= distance * cos(this->angleHorizontal * M_PI / 180.0);
                    }
                        //Above of dead zone
                    else if (event.jaxis.value > controller->DEAD_ZONE) {
                        yDir = 1;
                        float y = tank->getY();
                        y += 1.0 * sin(tank->getAngleHorizontal() * M_PI / 180.0);
                        float x = tank->getX();
                        x += 1.0 * cos(tank->getAngleHorizontal() * M_PI / 180.0);
                        tank->setY(y);
                        tank->setX(x);
                    } else {
                        yDir = 0;
                    }
                }
                //X axis motion
                if (event.jaxis.axis == 3) {
                    //Left of dead zone
                    if (event.jaxis.value < -controller->DEAD_ZONE) {
                        xDir = -1;
                        std::cout << xDir << " rigth joytstick left" << std::endl;
                    }
                        //Right of dead zone
                    else if (event.caxis.value > controller->DEAD_ZONE)//to change
                    {
                        xDir = 1;
                    } else {
                        xDir = 0;
                    }
                }
                    //Y axis motion
                else if (event.jaxis.axis == 4) {
                    //Below of dead zone
                    if (event.jaxis.value < -controller->DEAD_ZONE) {
                        yDir = -1;
                        // std::cout << yDir << " rigth joytstick up " << std::endl;

                    }
                        //Above of dead zone
                    else if (event.jaxis.value > controller->DEAD_ZONE) {
                        yDir = 1;
                    } else {
                        yDir = 0;
                    }
                }
            }

        }
        if (event.type == SDL_JOYBUTTONDOWN) {
            if (event.jbutton.button == controller->A) {
                std::cout << "A" << std::endl;
            }
        }
        //Calculate angle
        double joystickAngle = atan2((double) yDir, (double) xDir) * (180.0 / M_PI);

        //Correct angle
        if (xDir == 0 && yDir == 0) {
            joystickAngle = 0;
        }


        glLoadIdentity();
        gluLookAt(50, 50, 30, tank->getX(), tank->getY(), tank->getZ(), 0, 0, 1);

        glBegin(GL_QUADS);
        //violette
        glColor3f(1.0, 1.0, 1.0);
        glVertex3f(0, 0, 0);
        glVertex3f(0, 100, 0);
        glVertex3f(100, 100, 0);
        glVertex3f(100, 0, 0);
        glEnd();
        skybox->afficherCube();
        tank->moveTank(state);
        tank->showTank();

        if (tank->bullets.size() > 0) {
            for (int i = 0; i < tank->bullets.size(); i++) {
                tank->bullets[i]->move();
                tank->bullets[i]->show();
            }
        }

//        SDL_Delay(10);
        Uint32 end = SDL_GetTicks();
        //pause pour le systeme
        sleep(end - start);
        glFlush();
        SDL_GL_SwapWindow(win);

    }
}

void Game::clean() {
//vider la memoire
    controller->close();
    SDL_GL_DeleteContext(context);
    SDL_DestroyWindow(win);
    SDL_Quit();
}

void sleep(Uint32 dt) {
    if (dt < 16.6)
        SDL_Delay(16.6 - dt);
}


















