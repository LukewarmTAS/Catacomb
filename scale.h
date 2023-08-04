#ifndef SCALE_H_INCLUDED
#define SCALE_H_INCLUDED

////
//// Includes
////

#include "value.h"


////
//// Types
////

enum ScaleFactor {
  SCALE_FACTOR_ZERO = 0,
  SCALE_FACTOR_NORMAL = 64,
  SCALE_FACTOR_MAX = 128,
  SCALE_FACTOR_NONE = 255
};


////
//// Inline functions
////

inline Value apply_scale_factor(Value v, ScaleFactor f) {
  return Value((v * f) / int(SCALE_FACTOR_NORMAL));
}


#endif // !defined(SCALE_H_INCLUDED)
