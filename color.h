#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

////
//// Includes
////

#include "misc.h"


////
//// Types
////

enum Color {
  WHITE, 
  BLACK, 
  COLOR_NONE
};


////
//// Inline functions
////

inline Color operator+ (Color c, int i) { return Color(int(c) + i); }
inline void operator++ (Color &c, int i) { c = Color(int(c) + 1); }

inline Color opposite_color(Color c) {
  return Color(int(c) ^ 1);
}


////
//// Prototypes
////

extern bool color_is_ok(Color c);


#endif // !defined(COLOR_H_INCLUDED)
