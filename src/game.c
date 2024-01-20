#include "include/game.h"
#include "include/ball.h"
#include "include/tile.h"
#include <time.h>

bool DEBUG = true;

#define ROWS 8
#define COLS 12
#define TILE_SIZE 16

const int WIDTH = COLS * TILE_SIZE * SIZE_MULTIPLIER;
const int HEIGHT = ROWS * TILE_SIZE * SIZE_MULTIPLIER;

Tile* tiles[COLS][ROWS];

Ball* ball = NULL;

Texture2D tile_spritesheet;

void init()
{
    srand(time(0));

    ball = init_ball(LoadTexture("assets/ball.png"), (Vector2){ .x = 300, .y = 400 }, 8);

    tile_spritesheet = LoadTexture("assets/tiles.png");

    Vector2 pos = { .x = 0, .y = 0 };
    int type = 0;

    for(int i = 0; i < COLS; i++)
    {
        pos.y = 0;
        for(int j = 0; j < ROWS; j++)
        {
            if(i % 2 == 0)
            {
                type = j % 2;
            }
            else
            {
                type = (j + 1) % 2;
            }
            tiles[i][j] = init_tile(type, pos, TILE_SIZE);
            pos.y += TILE_SIZE * SIZE_MULTIPLIER;
        }
        pos.x += TILE_SIZE * SIZE_MULTIPLIER;
    }
}
void update()
{
    update_ball(ball);
}
void late_update()
{
    for(int i = 0; i < COLS; i++)
    {
        for(int j = 0; j < ROWS; j++)
        {
            draw_tile(tile_spritesheet, tiles[i][j]);
        }
    }

    draw_ball(ball);
}
void end()
{
    free(ball);

    for(int i = 0; i < COLS; i++)
    {
        for(int j = 0; j < ROWS; j++)
        {
            free(tiles[i][j]);
        }
    }
}