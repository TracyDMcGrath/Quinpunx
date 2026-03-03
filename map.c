#include "map.h"
#include "constants.h"
#include <raylib.h>
#include <string.h>

void draw_map(Tile map[MAPWIDTH][MAPHEIGHT], Font *font) {
  for (int i = 0; i < MAPWIDTH; i++) {
    for (int j = 0; j < MAPHEIGHT; j++) {
      DrawTextEx(*font, map[i][j].symbol,
                 (Vector2){i * FONTWIDTH, j * FONTHEIGHT}, FONTSIZE, SPACING,
                 map[i][j].color);
    }
  }
}

void init_map(Tile map[MAPWIDTH][MAPHEIGHT]) {
  for (int i = 0; i < MAPWIDTH; i++) {
    for (int j = 0; j < MAPHEIGHT; j++) {
      if (i == 0 || i == (MAPWIDTH - 1) || j == 0 || j == (MAPHEIGHT - 1)) {
        map[i][j].color = GRAY;
        strcpy(map[i][j].symbol, "#");
        map[i][j].blocks_sight = 1;

      } else {
        map[i][j].color = GRAY;
        strcpy(map[i][j].symbol, ".");
        map[i][j].blocks_sight = 1;
      }
    }
  }
}
