#ifndef _map_h_
#define _map_h_

#include "constants.h"
#include <raylib.h>

typedef struct Tile {
  char symbol[2];
  int blocks_sight;
  Color color;
} Tile;

void draw_map(Tile map[MAPWIDTH][MAPHEIGHT], Font *font);

void init_map(Tile map[MAPWIDTH][MAPHEIGHT]);

#endif // !_map_h_
