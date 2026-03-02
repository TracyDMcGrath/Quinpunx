#ifndef _entity_h_
#define _entity_h_
#include "constants.h"
#include <raylib.h>

typedef enum { NILL, PLAYER } Type;

typedef struct Id {
  int index;
  int gen;
} Id;

typedef struct Entity {
  Id parent;
  Id first_child;
  Id next_sibling;
  Id previous_sibling;

  char symbol[30];
  Color color;
  Type type;
  int x;
  int y;

} Entity;

Id find_next_free();
void init_entity(Entity *form);
void update_entity(Entity *ent);
void draw_entity(Entity *ent);

void update_entities();
void draw_entities();

extern int GEN[MAX_ENTITIES];
extern int USED[MAX_ENTITIES];
extern Entity ENTITIES[MAX_ENTITIES];

#endif // !_entity_h_
