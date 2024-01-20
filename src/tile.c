#include "include/tile.h"
#include "include/game.h"

Tile* init_tile(int type, Vector2 pos, int size)
{
    Tile* tile = calloc(1, sizeof(Tile));

    tile->pos = pos;
    tile->size = size;
    tile->type = type;

    return tile;
}
void draw_tile(Texture2D tile_spritesheet, Tile* tile)
{
    DrawTexturePro(tile_spritesheet, (Rectangle){ .x = tile->type * tile->size, .y = 0, .width = tile->size, .height = tile->size },
    get_tile_rec(tile), (Vector2){ 0 }, 0, WHITE );
}
Rectangle get_tile_rec(Tile* tile)
{
    return (Rectangle){ .x = tile->pos.x, .y = tile->pos.y, .width = tile->size * SIZE_MULTIPLIER, .height = tile->size * SIZE_MULTIPLIER };
}