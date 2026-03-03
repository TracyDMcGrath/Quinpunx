#include "templates.h"
#include "constants.h"
#include "entity.h"
#include <raylib.h>

Entity NILL_FORM = {};

Entity PLAYER_FORM = {NILL_ID,  NILL_ID, NILL_ID, NILL_ID, "@",
                      RAYWHITE, PLAYER,  1,       1};

Entity SNAKE_FORM = {NILL_ID, NILL_ID, NILL_ID, NILL_ID, "s",
                     GREEN,   SNAKE,   1,       1};
