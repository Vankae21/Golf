#include "include/ball.h"
#include "include/game.h"
#include <math.h>

Ball* init_ball(Texture2D tex, Vector2 pos, int size)
{
    Ball* ball = calloc(1, sizeof(Ball));

    ball->pos = pos;
    ball->size = size;
    ball->tex = tex;

    // defaults
    ball->velocity = (Vector2){ 0, 0 };

    return ball;
}
void update_ball(Ball* ball)
{
    ball->pos.x += ball->velocity.x;
    ball->pos.y += ball->velocity.y;

    if(ball->pos.x <= 0 || ball->pos.x + ball->size * SIZE_MULTIPLIER >= WIDTH)
    {
        ball->velocity.x *= -1;
    }
    if(ball->pos.y <= 0 || ball->pos.y + ball->size * SIZE_MULTIPLIER >= HEIGHT)
    {
        ball->velocity.y *= -1;
    }

    Vector2 mousePos = GetMousePosition();

    float angle = atan2(mousePos.y - ball->pos.y - ball->size * SIZE_MULTIPLIER / 2, mousePos.x - ball->pos.x - ball->size * SIZE_MULTIPLIER / 2 );
    angle = angle * (180.0f / PI);

}
void draw_ball(Ball* ball)
{
    DrawRectangleRec(get_ball_rec(ball), BLACK);
    // DrawTexture(ball->tex, ball->pos.x, ball->pos.y, WHITE);
    DrawTexturePro(ball->tex, (Rectangle){ .x = 0, .y = 0, .height = ball->size, .width = ball->size }, get_ball_rec(ball), (Vector2){ 0 }, 0, WHITE);
}
Rectangle get_ball_rec(Ball* ball)
{
    return (Rectangle){ .x = ball->pos.x, .y = ball->pos.y, .height = ball->size * SIZE_MULTIPLIER, .width = ball->size * SIZE_MULTIPLIER };
}