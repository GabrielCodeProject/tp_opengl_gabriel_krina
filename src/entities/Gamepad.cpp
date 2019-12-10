//
// Created by Gabri on 12/10/2019.
//

#include "Gamepad.h"

bool Gamepad::init() {
    //Initialization flag
    bool success = true;

    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK) < 0) {
        printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
        success = false;
    }
    return success;
}

void Gamepad::loadJoystick() {
    //Set texture filtering to linear
    if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
        printf("Warning: Linear texture filtering not enabled!");
    }

//Check for joysticks
    if (SDL_NumJoysticks() < 1) {
        printf("Warning: No joysticks connected!\n");
    } else {
//Load joystick
        gGameController = SDL_JoystickOpen(0);
        if (gGameController == NULL) {
            printf("Warning: Unable to open game controller! SDL Error: %s\n", SDL_GetError());
        }
    }
}

void Gamepad::close() {
    //Close game controller
    SDL_JoystickClose(gGameController);
    gGameController = NULL;
}