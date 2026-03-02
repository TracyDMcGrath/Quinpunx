#include "constants.h"
#include "entity.h"
#include "templates.h"
#include <raylib.h>

int main() {

  InitWindow(SCREENWIDTH, SCREENHEIGHT, "Quinpunx");

  Font Mono = LoadFontEx("./assets/monofur/MonofurNerdFontMono-Regular.ttf", 32,
                         0, 250);

  init_entity(&PLAYER_FORM);

  SetTargetFPS(60);

  while (!WindowShouldClose()) {

    update_entities();

    BeginDrawing();

    ClearBackground(BLACK);

    draw_entities(&Mono);

    EndDrawing();
  }

  return 0;
}
