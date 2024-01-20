#ifndef BALL_H
#define BALL_H
#include "raylib.h"
#include <stdlib.h>

typedef struct Ball
{
    Vector2 pos;
    int size;
    Vector2 velocity;
    Texture2D tex;
} Ball;

Ball* init_ball(Texture2D tex, Vector2 pos, int size);
void update_ball(Ball* ball);
void draw_ball(Ball* ball);
Rectangle get_ball_rec(Ball* ball);

#endif