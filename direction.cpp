////
//// Includes
////

#include "direction.h"
#include "square.h"


////
//// Variables
////

uint8_t DirectionTable[64][64];
uint8_t SignedDirectionTable[64][64];


////
//// Functions
////

void init_direction_table() {
  SquareDelta deltas[8] = {
    DELTA_E, DELTA_W, DELTA_N, DELTA_S, DELTA_NE, DELTA_SW, DELTA_NW, DELTA_SE
  };
  for(Square s1 = SQ_A1; s1 <= SQ_H8; s1++)
    for(Square s2 = SQ_A1; s2 <= SQ_H8; s2++) {
      DirectionTable[s1][s2] = uint8_t(DIR_NONE);
      SignedDirectionTable[s1][s2] = uint8_t(SIGNED_DIR_NONE);
      if(s1 == s2) continue;
      for(SignedDirection d = SIGNED_DIR_E; d <= SIGNED_DIR_SE; d++) {
        SquareDelta delta = deltas[d];
        Square s3, s4;
        for(s4 = s1 + delta, s3 = s1;
            square_distance(s4, s3) == 1 && s4 != s2 && square_is_ok(s4);
            s3 = s4, s4 += delta);
        if(s4 == s2 && square_distance(s4, s3) == 1) {
          SignedDirectionTable[s1][s2] = uint8_t(d);
          DirectionTable[s1][s2] = uint8_t(d/2);
          break;
        }
      }
    }
}
