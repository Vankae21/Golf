#ifndef GAME_H
#define GAME_H

#include "raylib.h"
#include <stdlib.h>
#include <stdio.h>

extern const int WIDTH;
extern const int HEIGHT;

#define TITLE "Golf"
#define FPS 60
#define SIZE_MULTIPLIER 4

extern bool DEBUG;

void init();
void update();
void late_update();
void end();

#endif