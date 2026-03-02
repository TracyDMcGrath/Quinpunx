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

void init_entity(Entity *form) {
  Id next_free = find_next_free();
  memcpy(&ENTITIES[next_free.index], form, sizeof(Entity));
  USED[next_free.index] = 1;
  GEN[next_free.index]++;
}

void update_entity(Entity *ent) {}

void draw_entity(Entity *ent) {
  DrawText(ent->symbol, ent->x * FONTSIZE, ent->y * FONTSIZE, FONTSIZE,
           ent->color);
}

void update_entities() {
  for (int i = 0; i < MAX_ENTITIES; i++) {
    if (USED[i]) {
      update_entity(&ENTITIES[i]);
    }
  }
}
void draw_entities() {
  for (int i = 0; i < MAX_ENTITIES; i++) {
    if (USED[i]) {
      draw_entity(&ENTITIES[i]);
    }
  }
}
