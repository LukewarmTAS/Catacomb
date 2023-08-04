#ifndef TT_H_INCLUDED
#define TT_H_INCLUDED

////
//// Includes
////

#include "depth.h"
#include "position.h"
#include "value.h"


////
//// Types
////

/// The TTEntry class is the class of transposition table entries.

class TTEntry {

public:
  TTEntry();
  TTEntry(Key k, Value v, ValueType t, Depth d, Move m, int generation);
  Key key() const;
  Depth depth() const;
  Move move() const;
  Value value() const;
  ValueType type() const;
  int generation() const;

private:  
  Key key_;
  uint32_t data;
  int16_t value_;
  int16_t depth_;
};


/// The transposition table class.  This is basically just a huge array
/// containing TTEntry objects, and a few methods for writing new entries
/// and reading new ones.

class TranspositionTable {

public:
  TranspositionTable(unsigned mbSize);
  ~TranspositionTable();
  void set_size(unsigned mbSize);
  void clear();
  void store(const Position &pos, Value v, Depth d, Move m, ValueType type);
  bool retrieve(const Position &pos, Value *value, Depth *d, Move *move,
                ValueType *type) const;
  void new_search();
  void insert_pv(const Position &pos, Move pv[]);
  int full();

private:
  unsigned size;
  int writes;
  TTEntry* entries;
  uint8_t generation;
};


////
//// Constants and variables
////

// Default transposition table size, in megabytes:
const int TTDefaultSize = 32;


#endif // !defined(TT_H_INCLUDED)
