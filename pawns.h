#ifndef PAWNS_H_INCLUDED
#define PAWNS_H_INCLUDED

////
//// Includes
////

#include "position.h"


////
//// Types
////

/// PawnInfo is a class which contains various information about a pawn 
/// structure.  Currently, it only includes a middle game and an end game
/// pawn structure evaluation, and a bitboard of passed pawns.  We may want
/// to add further information in the future.  A lookup to the pawn hash table
/// (performed by calling the get_pawn_info method in a PawnInfoTable object)
/// returns a pointer to a PawnInfo object.

class PawnInfo {

  friend class PawnInfoTable;

public:
  Value mg_value() const;
  Value eg_value() const;
  Value kingside_storm_value(Color c) const;
  Value queenside_storm_value(Color c) const;
  Bitboard passed_pawns() const;
  bool file_is_half_open(Color c, File f) const;
  bool has_open_file_to_left(Color c, File f) const;
  bool has_open_file_to_right(Color c, File f) const;

private:
  void clear();

  Key key;
  Bitboard passedPawns;
  int16_t mgValue, egValue;
  int8_t ksStormValue[2], qsStormValue[2];
  uint8_t halfOpenFiles[2];
};


/// The PawnInfoTable class represents a pawn hash table.  It is basically
/// just an array of PawnInfo objects and a few methods for accessing these
/// objects.  The most important method is get_pawn_info, which looks up a
/// position in the table and returns a pointer to a PawnInfo object.

class PawnInfoTable {

public:
  PawnInfoTable(unsigned numOfEntries);
  ~PawnInfoTable();
  void clear();
  PawnInfo *get_pawn_info(const Position &pos);

private:
  unsigned size;
  PawnInfo *entries;
};


////
//// Inline functions
////

inline Value PawnInfo::mg_value() const {
  return Value(mgValue);
}

inline Value PawnInfo::eg_value() const {
  return Value(egValue);
}

inline Bitboard PawnInfo::passed_pawns() const {
  return passedPawns;
}

inline Value PawnInfo::kingside_storm_value(Color c) const {
  return Value(ksStormValue[c]);
}

inline Value PawnInfo::queenside_storm_value(Color c) const {
  return Value(qsStormValue[c]);
}

inline bool PawnInfo::file_is_half_open(Color c, File f) const {
  return (halfOpenFiles[c] & (1 << int(f)));
}

inline bool PawnInfo::has_open_file_to_left(Color c, File f) const {
  return halfOpenFiles[c] & ((1 << int(f)) - 1);
}

inline bool PawnInfo::has_open_file_to_right(Color c, File f) const {
  return halfOpenFiles[c] & ~((1 << int(f+1)) - 1);
}

inline void PawnInfo::clear() {
  mgValue = egValue = 0;
  passedPawns = EmptyBoardBB;
  ksStormValue[WHITE] = ksStormValue[BLACK] = 0;
  qsStormValue[WHITE] = qsStormValue[BLACK] = 0;
  halfOpenFiles[WHITE] = halfOpenFiles[BLACK] = 0xFF;
}


#endif // !defined(PAWNS_H_INCLUDED)
