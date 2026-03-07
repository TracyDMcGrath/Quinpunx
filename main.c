#include "constants.h"
#include "entity.h"
#include "map.h"
#include "templates.h"
#include <raylib.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {

  srand(time(NULL));

  InitWindow(SCREENWIDTH, SCREENHEIGHT, "Quinpunx");

  Font Mono = LoadFontEx("./assets/monofur/MonofurNerdFontMono-Regular.ttf",
                         FONTSIZE, 0, 250);

  init_entity(&PLAYER_FORM, 10, 10);
  init_entity(&PLAYER_FORM, 11, 11);
  init_entity(&PLAYER_FORM, 12, 12);
  init_entity(&PLAYER_FORM, 10, 12);
  init_entity(&PLAYER_FORM, 12, 10);
  strcpy(ENTITIES[1].symbol, "1");
  strcpy(ENTITIES[2].symbol, "2");
  strcpy(ENTITIES[3].symbol, "3");
  strcpy(ENTITIES[4].symbol, "4");
  strcpy(ENTITIES[5].symbol, "5");

  init_entity(&SNAKE_FORM, rand() % (MAPWIDTH - 2) + 1,
              rand() % (MAPHEIGHT - 2) + 1);

  init_map();

  SetTargetFPS(60);

  while (!WindowShouldClose()) {

    update_entities();

    BeginDrawing();

    ClearBackground(BLACK);

    draw_map(&Mono);
    draw_entities(&Mono);

    EndDrawing();
  }

  return 0;
}
