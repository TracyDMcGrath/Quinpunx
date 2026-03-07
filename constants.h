#ifndef _constants_h_
#define _constants_h_

#define SCREENWIDTH 1920
#define SCREENHEIGHT 1080
#define FONTSIZE 48
#define FONTHEIGHT 44
#define FONTWIDTH 24
#define MAX_ENTITIES 100
#define MAPWIDTH 80
#define MAPHEIGHT 24
#define SPACING 0.0
#define MAX_CARDNAME 30
#define MAX_DECK_SIZE 60
#define MAX_HAND_SIZE 30

#define NILL_ID {0, 0}

#define DIRECTIONS                                                             \
  (int[9][2]) {                                                                \
    {-1, -1}, {0, -1}, {1, -1}, {-1, 0}, {0, 0}, {1, 0}, {-1, 1}, {0, 1},      \
        {1, 1}                                                                 \
  }

typedef enum {
  UP_LEFT,
  UP,
  UP_RIGHT,
  LEFT,
  PLACE,
  RIGHT,
  DOWN_LEFT,
  DOWN,
  DOWN_RIGHT
} Direction;

#endif // !_constants_h_
