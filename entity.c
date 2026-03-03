#include "entity.h"
#include "constants.h"
#include <raylib.h>
#include <string.h>

int GEN[MAX_ENTITIES];
int USED[MAX_ENTITIES];
Entity ENTITIES[MAX_ENTITIES];

Id find_next_free() {

  for (int i = 0; i < sizeof(USED) / sizeof(USED[0]); i++) {
    if (USED[i] == 0) {
      Id next_free = {i, GEN[i] + 1};
      return next_free;
    }
  }
  Id none_free = NILL_ID;
  return none_free;
}

Id find_next_used() {

  for (int i = 0; i < sizeof(USED) / sizeof(USED[0]); i++) {
    if (USED[i] == 1) {
      return (Id){i, GEN[i]};
    }
  }
  Id none_used = NILL_ID;
  return none_used;
}

void init_entity(Entity *form, int x, int y) {
  Id next_free = find_next_free();
  memcpy(&ENTITIES[next_free.index], form, sizeof(Entity));
  USED[next_free.index] = 1;
  GEN[next_free.index]++;
  ENTITIES[next_free.index].x = x;
  ENTITIES[next_free.index].y = y;
}

void update_entity(Entity *ent) {

  if (ent->type == PLAYER) {
    if (IsKeyPressed(KEY_L)) {
      ent->x++;
    } else if (IsKeyPressed(KEY_H)) {
      ent->x--;
    } else if (IsKeyPressed(KEY_J)) {
      ent->y++;
    } else if (IsKeyPressed(KEY_K)) {
      ent->y--;
    } else if (IsKeyPressed(KEY_Y)) {
      ent->x--;
      ent->y--;
    } else if (IsKeyPressed(KEY_U)) {
      ent->x++;
      ent->y--;
    } else if (IsKeyPressed(KEY_B)) {
      ent->x--;
      ent->y++;
    } else if (IsKeyPressed(KEY_N)) {
      ent->x++;
      ent->y++;
    }
  }
}

void draw_entity(Entity *ent, Font *font) {
  DrawTextEx(*font, ent->symbol,
             (Vector2){ent->x * FONTWIDTH, ent->y * FONTHEIGHT}, FONTSIZE,
             SPACING, ent->color);
}

void update_entities() {
  for (int i = 0; i < MAX_ENTITIES; i++) {
    if (USED[i]) {
      update_entity(&ENTITIES[i]);
    }
  }
}
void draw_entities(Font *font) {
  for (int i = 0; i < MAX_ENTITIES; i++) {
    if (USED[i]) {
      draw_entity(&ENTITIES[i], font);
    }
  }
}
