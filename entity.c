#include "entity.h"
#include "constants.h"
#include "map.h"
#include <raylib.h>
#include <stdlib.h>
#include <string.h>

int CURRENT_TURN;
int GEN[MAX_ENTITIES];
int USED[MAX_ENTITIES];
Entity ENTITIES[MAX_ENTITIES];

Id find_next_free() {

  for (int i = 1; i < sizeof(USED) / sizeof(USED[0]); i++) {
    if (USED[i] == 0) {
      Id next_free = {i, GEN[i] + 1};
      return next_free;
    }
  }
  Id none_free = NILL_ID;
  return none_free;
}

Id find_next_used() {

  for (int i = 1; i < sizeof(USED) / sizeof(USED[0]); i++) {
    if (USED[i] == 1) {
      return (Id){i, GEN[i]};
    }
  }
  Id none_used = NILL_ID;
  return none_used;
}

Entity *get_entity_ptr(Id id) {
  if (ENTITIES[id.index].id.gen == id.gen) {
    return &ENTITIES[id.index];
  } else {
    return &ENTITIES[0];
  }
}

void init_entity(Entity *form, int x, int y) {
  Id next_free = find_next_free();
  memcpy(&ENTITIES[next_free.index], form, sizeof(Entity));
  USED[next_free.index] = 1;
  GEN[next_free.index]++;
  ENTITIES[next_free.index].x = x;
  ENTITIES[next_free.index].y = y;
}

void shuffle(Entity *ent) {
  for (int i = ent->current_pile_size; i > 0; i--) {
    int randCard = (rand() % i);
    ent->deck[ent->current_deck_size] = ent->pile[randCard];
    ent->current_deck_size += 1;

    for (int i = randCard; (i + 1) < ent->current_pile_size; i++) {
      ent->pile[i] = ent->pile[i + 1];
    }

    ent->pile[ent->current_pile_size] = 0;
    ent->current_pile_size -= 1;
  }
}

void draw(Entity *ent) {
  ent->hand[ent->current_hand_size] = ent->deck[ent->current_deck_size - 1];
  ent->current_hand_size += 1;
  ent->deck[ent->current_deck_size - 1] = 0;
  ent->current_deck_size -= 1;
}

void play(Entity *ent, int card) {
  ent->hand[card]->use(ent);
  ent->pile[ent->current_pile_size] = ent->hand[card];
  ent->current_pile_size += 1;

  for (int i = card; (i + 1) < ent->current_hand_size; i++) {
    ent->hand[i] = ent->hand[i + 1];
  }

  ent->hand[ent->current_hand_size] = 0;
  ent->current_hand_size -= 1;
}

void auto_play(Entity *ent) {
  for (int i = 0; i < ent->cards_per_turn; i++) {
    draw(ent);
  }

  for (int i = 0; i < ent->energy_per_turn; i++) {
    play(ent, rand() % ent->current_hand_size);
  }
}

void attack(Entity *ent) {
  Entity *target = get_entity_ptr(ent->target);
  target->shield -= ent->attack;
  if (target->shield < 0) {
    target->hp += target->shield;
    target->shield = 0;
  }
}

void move(Entity *ent, Direction dir) {
  if (MAP[ent->x + DIRECTIONS[dir][0]][ent->y + DIRECTIONS[dir][1]]
          .blocks_movement) {
    return;
  }
  for (int i = 0; i < MAX_ENTITIES; i++) {
    if (ENTITIES[i].id.index != ent->id.index) {
    } else if (ENTITIES[i].y == ent->y + DIRECTIONS[dir][1]) {
      if (ENTITIES[i].x == ent->x + DIRECTIONS[dir][0]) {
        ent->target = ENTITIES[i].id;
        attack(ent);
        return;
      }
    }
  }
  ent->x += DIRECTIONS[dir][0];
  ent->y += DIRECTIONS[dir][1];
  return;
}
void update_entity(Entity *ent) {

  if (ent->type == PLAYER) {
    if (IsKeyPressed(KEY_L)) {
      move(ent, RIGHT);
    } else if (IsKeyPressed(KEY_H)) {
      move(ent, LEFT);
    } else if (IsKeyPressed(KEY_J)) {
      move(ent, DOWN);
    } else if (IsKeyPressed(KEY_K)) {
      move(ent, UP);
    } else if (IsKeyPressed(KEY_Y)) {
      move(ent, UP_LEFT);
    } else if (IsKeyPressed(KEY_U)) {
      move(ent, UP_RIGHT);
    } else if (IsKeyPressed(KEY_B)) {
      move(ent, DOWN_LEFT);
    } else if (IsKeyPressed(KEY_N)) {
      move(ent, DOWN_RIGHT);
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
