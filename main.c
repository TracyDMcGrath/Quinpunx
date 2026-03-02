#include "constants.h"
#include "entity.h"
#include "templates.h"
#include <raylib.h>

int main() {

  InitWindow(SCREENWIDTH, SCREENHEIGHT, "Quinpunx");

  Font Gohu = LoadFontEx("assets/Gohu/GohuFontuni14NerdFontPropo-Regular.ttf",
                         14, 0, 250);

  Font Mono = LoadFontEx("assets/testfont.ttf", 14, 0, 250);

  init_entity(&PLAYER_FORM);

  SetTargetFPS(60);

  while (!WindowShouldClose()) {

    update_entities();

    BeginDrawing();

    ClearBackground(BLACK);

    draw_entities();

    EndDrawing();
  }

  return 0;
}
