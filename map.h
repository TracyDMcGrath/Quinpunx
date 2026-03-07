#ifndef _map_h_
#define _map_h_

#include "constants.h"
#include <raylib.h>

typedef struct Tile {
  char symbol[2];
  int blocks_sight;
  int blocks_movement;
  Color color;
} Tile;

extern Tile MAP[MAPWIDTH][MAPHEIGHT];

void draw_map(Font *font);

void init_map();

#endif // !_map_h_
