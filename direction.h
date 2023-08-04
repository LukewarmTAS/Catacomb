#ifndef DIRECTION_H_INCLUDED
#define DIRECTION_H_INCLUDED

////
//// Includes
////

#include "square.h"
#include "types.h"


////
//// Types
////

enum Direction {
  DIR_E = 0, DIR_N = 1, DIR_NE = 2, DIR_NW = 3, DIR_NONE = 4
};

enum SignedDirection {
  SIGNED_DIR_E = 0, SIGNED_DIR_W = 1,
  SIGNED_DIR_N = 2, SIGNED_DIR_S = 3,
  SIGNED_DIR_NE = 4, SIGNED_DIR_SW = 5,
  SIGNED_DIR_NW = 6, SIGNED_DIR_SE = 7,
  SIGNED_DIR_NONE = 8
};


////
//// Variables
////

extern uint8_t DirectionTable[64][64];
extern uint8_t SignedDirectionTable[64][64];


////
//// Inline functions
////

inline void operator++ (Direction &d, int) { d = Direction(int(d) + 1); }

inline void operator++ (SignedDirection &d, int) {
  d = SignedDirection(int(d) + 1);
}

inline Direction direction_between_squares(Square s1, Square s2) {
  return Direction(DirectionTable[s1][s2]);
}

inline SignedDirection signed_direction_between_squares(Square s1, Square s2) {
  return SignedDirection(SignedDirectionTable[s1][s2]);
}


////
//// Prototypes
////

extern void init_direction_table();


#endif // !defined(DIRECTION_H_INCLUDED)
