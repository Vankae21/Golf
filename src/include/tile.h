#ifndef TILE_H
#define TILE_H
#include "raylib.h"
#include <stdlib.h>

typedef struct Tile
{
    Vector2 pos;
    int size;

    enum
    {
        GREEN_TILE,
        WHITE_TILE
    } type;

} Tile;

Tile* init_tile(int type, Vector2 pos, int size);
void draw_tile(Texture2D tile_spritesheet, Tile* tile);
Rectangle get_tile_rec(Tile* tile);

#endif