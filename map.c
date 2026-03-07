#include "map.h"
#include "constants.h"
#include <raylib.h>
#include <string.h>

Tile MAP[MAPWIDTH][MAPHEIGHT];

void draw_map(Font *font) {
  for (int i = 0; i < MAPWIDTH; i++) {
    for (int j = 0; j < MAPHEIGHT; j++) {
      DrawTextEx(*font, MAP[i][j].symbol,
                 (Vector2){i * FONTWIDTH, j * FONTHEIGHT}, FONTSIZE, SPACING,
                 MAP[i][j].color);
    }
  }
}

void init_map() {
  for (int i = 0; i < MAPWIDTH; i++) {
    for (int j = 0; j < MAPHEIGHT; j++) {
      if (i == 0 || i == (MAPWIDTH - 1) || j == 0 || j == (MAPHEIGHT - 1)) {
        MAP[i][j].color = GRAY;
        strcpy(MAP[i][j].symbol, "#");
        MAP[i][j].blocks_sight = 1;
        MAP[i][j].blocks_movement = 1;

      } else {
        MAP[i][j].color = GRAY;
        strcpy(MAP[i][j].symbol, ".");
        MAP[i][j].blocks_sight = 1;
      }
    }
  }
}
