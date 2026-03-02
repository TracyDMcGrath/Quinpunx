#include "constants.h"
#include "entity.h"
#include "templates.h"
#include <raylib.h>

int main() {

  InitWindow(SCREENWIDTH, SCREENHEIGHT, "Quinpunx");

  init_entity(&PLAYER_FORM);

  while (!WindowShouldClose()) {

    update_entities();

    BeginDrawing();

    ClearBackground(BLACK);

    draw_entities();

    EndDrawing();
  }

  return 0;
}
