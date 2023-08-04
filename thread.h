#ifndef THREAD_H_INCLUDED
#define THREAD_H_INCLUDED


////
//// Includes
////

#include "lock.h"
#include "movepick.h"
#include "position.h"
#include "search.h"


////
//// Constants and variables
////

const int THREAD_MAX = 8;


////
//// Types
////

struct SplitPoint {
  SplitPoint *parent;
  Position pos;
  SearchStack sstack[THREAD_MAX][PLY_MAX];
  SearchStack *parentSstack;
  int ply;
  Depth depth;
  volatile Value alpha, beta, bestValue;
  bool pvNode;
  Bitboard dcCandidates;
  int master, slaves[THREAD_MAX];
  Lock lock;
  MovePicker *mp;
  volatile int moves;
  volatile int cpus;
  bool finished;
};


struct Thread {
  SplitPoint *splitPoint;
  int activeSplitPoints;
  uint64_t nodes;
  bool failHighPly1;
  volatile bool stop;
  volatile bool running;
  volatile bool idle;
  volatile bool workIsWaiting;
  volatile bool printCurrentLine;
  unsigned char pad[64];
};


#endif // !defined(THREAD_H_INCLUDED)
