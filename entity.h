#ifndef _entity_h_
#define _entity_h_
#include "constants.h"
#include <raylib.h>
typedef enum { NILL, PLAYER, SNAKE } Type;

typedef struct Id {
  int index;
  int gen;
} Id;

typedef struct card Card;
typedef struct entity Entity;

struct entity {
  Id id;
  Id parent;
  Id first_child;
  Id next_sibling;
  Id previous_sibling;

  Id target;

  char symbol[30];
  Color color;
  Type type;
  int x;
  int y;

  int hp;
  int max_hp;
  int attack;
  int shield;

  int current_deck_size;
  int current_hand_size;
  int current_pile_size;

  int current_selection;
  int energy_per_turn;
  int cards_per_turn;

  Card *deck[MAX_DECK_SIZE];
  Card *hand[MAX_HAND_SIZE];
  Card *pile[MAX_DECK_SIZE];
};

struct card {
  void (*use)(Entity *ent);
  char name[MAX_CARDNAME];
};

Id find_next_free();
Id find_next_used();
Entity *get_entity_ptr(Id id);
void init_entity(Entity *form, int x, int y);
void update_entity(Entity *ent);
void auto_play(Entity *ent);
void draw_entity(Entity *ent, Font *font);

void update_entities();
void draw_entities(Font *font);

extern int GEN[MAX_ENTITIES];
extern int USED[MAX_ENTITIES];
extern int CURRENT_TURN;
extern Entity ENTITIES[MAX_ENTITIES];
extern Font MONO;

#endif // !_entity_h_
