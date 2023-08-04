#ifndef DEPTH_H_INCLUDED
#define DEPTH_H_INCLUDED

////
//// Types
////

enum Depth {
  DEPTH_ZERO = 0,
  DEPTH_MAX = 200  // 100 * OnePly;
};


////
//// Constants
////

/// Note: If OnePly is changed, the constant HistoryMax in history.h should
/// probably also be changed.

const Depth OnePly = Depth(2);


////
//// Inline functions
////

inline Depth operator+ (Depth d, int i) { return Depth(int(d) + i); }
inline Depth operator+ (Depth d1, Depth d2) { return Depth(int(d1) + int(d2)); }
inline void operator+= (Depth &d, int i) { d = Depth(int(d) + i); }
inline void operator+= (Depth &d1, Depth d2) { d1 += int(d2); }
inline Depth operator- (Depth d, int i) { return Depth(int(d) - i); }
inline Depth operator- (Depth d1, Depth d2) { return Depth(int(d1) - int(d2)); }
inline void operator-= (Depth & d, int i) { d = Depth(int(d) - i); }
inline Depth operator* (Depth d, int i) { return Depth(int(d) * i); }
inline Depth operator* (int i, Depth d) { return Depth(int(d) * i); }
inline void operator*= (Depth &d, int i) { d = Depth(int(d) * i); }
inline Depth operator/ (Depth d, int i) { return Depth(int(d) / i); }
inline void operator/= (Depth &d, int i) { d = Depth(int(d) / i); }


#endif // !defined(DEPTH_H_INCLUDED)
